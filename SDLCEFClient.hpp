#ifndef CEFCLIENT_H_INC
#define CEFCLIENT_H_INC

#include <cef_app.h>
#include <cef_client.h>

#include "SDLCEFRender.hpp"

class SDLCEFClient : public CefClient{
public:
    SDLCEFClient(){}
    void SetRender(CefRefPtr<SDLCEFRender> render){sdl_cefrender_ = std::move(render);}
    virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override {return sdl_cefrender_;}
protected:
    int id;
    CefRefPtr<SDLCEFRender> sdl_cefrender_ = nullptr;
    IMPLEMENT_REFCOUNTING(SDLCEFClient);
};

#endif
