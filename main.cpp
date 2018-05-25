#include <cef_app.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>
#include "SDLCEFClient.hpp"
#include "SDLCEFHelper.hpp"

int main(int argc, char ** argv) {
  CefMainArgs args(argc,argv);

  int exit_code = CefExecuteProcess(args, nullptr, nullptr);
  if (exit_code >= 0){
    return exit_code;
  }

  CefSettings settings;
  settings.windowless_rendering_enabled = true;

  CefString(&settings.resources_dir_path) = SDL_GetBasePath();
  CefString(&settings.cache_path) = "/tmp";

  bool result = CefInitialize(args,settings, nullptr, nullptr);

  if(!result){
      std::cout << "CefInitialize error" << std::endl;
      return -1;
  }

  //For now initialize SDL

  if (SDL_Init(SDL_INIT_VIDEO) < 0){
      std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
      return -2;
  }

  uint32 width = 800;
  uint32 height = 600;

  auto window = SDL_CreateWindow("CEFSDL",0,0,width,height,SDL_WINDOW_ALLOW_HIGHDPI);
  if(window != nullptr){
      auto renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if(renderer  != nullptr){
          SDL_Event e;


          CefRefPtr<SDLCEFRender> render = new SDLCEFRender(renderer,width,height);
          CefRefPtr<CefBrowser> browser;
          CefRefPtr<SDLCEFClient> client = new SDLCEFClient();

          client->SetRender(render);

          CefWindowInfo window_info;
          CefBrowserSettings browser_settings;
          browser_settings.windowless_frame_rate = 60;
          window_info.SetAsWindowless(0);

          browser = CefBrowserHost::CreateBrowserSync(window_info,client.get(),"http://madebyevan.com/webgl-water/", browser_settings, nullptr);

          bool shutdown = false;

          SDL_StartTextInput();
          while (!shutdown){
              while (SDL_PollEvent(&e) != 0){

                  switch (e.type){
                      case SDL_QUIT:
                          shutdown = true;
                          browser->GetHost()->CloseBrowser(false);
                          break;
                      case SDL_MOUSEMOTION:{
                          CefMouseEvent event;
                          event.x = e.motion.x;
                          event.y = e.motion.y;
                          browser->GetHost()->SendMouseMoveEvent(event, false);
                          break;
                      }

                      case SDL_MOUSEBUTTONUP:{
                          CefMouseEvent event;
                          event.x = e.button.x;
                          event.y = e.button.y;

                          browser->GetHost()->SendMouseClickEvent(event, GetMouseButtonFromSDL(e.button), true, 1);
                          break;
                      }

                      case SDL_MOUSEBUTTONDOWN:{
                          CefMouseEvent event;
                          event.x = e.button.x;
                          event.y = e.button.y;

                          browser->GetHost()->SendMouseClickEvent(event, GetMouseButtonFromSDL(e.button), false, 1);
                          break;
                      }

                      case SDL_KEYDOWN:{
                          CefKeyEvent event;
                          event.modifiers = GetModifiersFromSDL(e.key.keysym.mod);
                          event.windows_key_code = GetWindowsKeycodeFromSDLKeycode(e.key.keysym.scancode);
                          event.native_key_code = e.key.keysym.scancode;

                          event.type = KEYEVENT_RAWKEYDOWN;
                          browser->GetHost()->SendKeyEvent(event);
                          break;
                      }
                      case SDL_KEYUP:{
                          CefKeyEvent event;
                          event.modifiers = GetModifiersFromSDL(e.key.keysym.mod);
                          event.windows_key_code = GetWindowsKeycodeFromSDLKeycode(e.key.keysym.scancode);
                          event.native_key_code = e.key.keysym.scancode;

                          event.type = KEYEVENT_KEYUP;
                          browser->GetHost()->SendKeyEvent(event);
                          break;
                      }

                      case SDL_TEXTINPUT:{
                          CefString input_text = e.text.text;
                          CefRange range;
                          range.from = -1;
                          browser->GetHost()->ImeCommitText(input_text,range,0);
                      }

                      case SDL_TEXTEDITING:{
                          //@todo
                          //Use browser->GetHost()->ImeSetComposition()
                      }

                  }
              }
              CefDoMessageLoopWork();

              SDL_RenderClear(renderer);
              SDL_RenderCopy(renderer,render->GetSDLTexture(), nullptr, nullptr);
              SDL_RenderPresent(renderer);
          }


      }else{
          std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
      }
  }else{
      std::cerr << "SDL_Error: " << SDL_GetError() << std::endl;
  }

  return 0;
}
