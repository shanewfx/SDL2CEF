#ifndef CEFRENDER_H_INC
#define CEFRENDER_H_INC

#include <cstdint>
#include <cef_render_handler.h>
#include <SDL2/SDL.h>

class SDLCEFRender : public CefRenderHandler{
public:
    SDLCEFRender(SDL_Renderer* sdl_renderer,uint32 w,uint32 h);
    ~SDLCEFRender();

    bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect &rect) override ;
    void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList &dirtyRects, const void * buffer, int w, int h) override ;
    SDL_Texture* GetSDLTexture(){return cef_texture;}
protected:
    SDL_Renderer* sdl_renderer_ = nullptr;
    SDL_Texture* cef_texture = nullptr;
    uint32 width_ = 0;
    uint32 height_ = 0;

    IMPLEMENT_REFCOUNTING(SDLCEFRender);
};


#endif
