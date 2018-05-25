#include "SDLCEFRender.hpp"
#include <wrapper/cef_helpers.h>

SDLCEFRender::SDLCEFRender(SDL_Renderer *sdl_renderer, uint32 w, uint32 h) {
    width_ = w;
    height_ = h;
    sdl_renderer_ = sdl_renderer;
    cef_texture = SDL_CreateTexture(sdl_renderer_, SDL_PIXELFORMAT_BGRA32, SDL_TEXTUREACCESS_STREAMING, w, h);
}

SDLCEFRender::~SDLCEFRender() {
    if(cef_texture != nullptr){
        SDL_DestroyTexture(cef_texture);
    }
}

bool SDLCEFRender::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect &rect) {
    rect = CefRect(0,0,width_,height_);
    return true;
}

void SDLCEFRender::OnPaint(CefRefPtr<CefBrowser> browser, CefRenderHandler::PaintElementType type,
                           const CefRenderHandler::RectList &dirtyRects, const void *buffer, int w, int h) {
    if(cef_texture != nullptr){
        unsigned char* data = nullptr;
        int pitch = 0;
        for (auto rect : dirtyRects) {
            SDL_Rect sdl_rect = {rect.x,rect.y,rect.width,rect.height};
            SDL_LockTexture(cef_texture,&sdl_rect,(void**)&data,&pitch);
            auto offset = (width_ * rect.y + rect.x) * 4;
            memcpy(data,(const char*)buffer + offset,(width_ * height_ * 4) - offset);
            SDL_UnlockTexture(cef_texture);
        }
    }
}