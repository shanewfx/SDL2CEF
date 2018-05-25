#ifndef SDLCEFHELPER_H_INC
#define SDLCEFHELPER_H_INC

#include <SDL2/SDL.h>
#include <cef_app.h>
#include <vector>

// From ui/events/keycodes/keyboard_codes_posix.h.
enum KeyboardCode {
    VKEY_BACK = 0x08,
    VKEY_TAB = 0x09,
    VKEY_BACKTAB = 0x0A,
    VKEY_CLEAR = 0x0C,
    VKEY_RETURN = 0x0D,
    VKEY_SHIFT = 0x10,
    VKEY_CONTROL = 0x11,
    VKEY_MENU = 0x12,
    VKEY_PAUSE = 0x13,
    VKEY_CAPITAL = 0x14,
    VKEY_KANA = 0x15,
    VKEY_HANGUL = 0x15,
    VKEY_JUNJA = 0x17,
    VKEY_FINAL = 0x18,
    VKEY_HANJA = 0x19,
    VKEY_KANJI = 0x19,
    VKEY_ESCAPE = 0x1B,
    VKEY_CONVERT = 0x1C,
    VKEY_NONCONVERT = 0x1D,
    VKEY_ACCEPT = 0x1E,
    VKEY_MODECHANGE = 0x1F,
    VKEY_SPACE = 0x20,
    VKEY_PRIOR = 0x21,
    VKEY_NEXT = 0x22,
    VKEY_END = 0x23,
    VKEY_HOME = 0x24,
    VKEY_LEFT = 0x25,
    VKEY_UP = 0x26,
    VKEY_RIGHT = 0x27,
    VKEY_DOWN = 0x28,
    VKEY_SELECT = 0x29,
    VKEY_PRINT = 0x2A,
    VKEY_EXECUTE = 0x2B,
    VKEY_SNAPSHOT = 0x2C,
    VKEY_INSERT = 0x2D,
    VKEY_DELETE = 0x2E,
    VKEY_HELP = 0x2F,
    VKEY_0 = 0x30,
    VKEY_1 = 0x31,
    VKEY_2 = 0x32,
    VKEY_3 = 0x33,
    VKEY_4 = 0x34,
    VKEY_5 = 0x35,
    VKEY_6 = 0x36,
    VKEY_7 = 0x37,
    VKEY_8 = 0x38,
    VKEY_9 = 0x39,
    VKEY_A = 0x41,
    VKEY_B = 0x42,
    VKEY_C = 0x43,
    VKEY_D = 0x44,
    VKEY_E = 0x45,
    VKEY_F = 0x46,
    VKEY_G = 0x47,
    VKEY_H = 0x48,
    VKEY_I = 0x49,
    VKEY_J = 0x4A,
    VKEY_K = 0x4B,
    VKEY_L = 0x4C,
    VKEY_M = 0x4D,
    VKEY_N = 0x4E,
    VKEY_O = 0x4F,
    VKEY_P = 0x50,
    VKEY_Q = 0x51,
    VKEY_R = 0x52,
    VKEY_S = 0x53,
    VKEY_T = 0x54,
    VKEY_U = 0x55,
    VKEY_V = 0x56,
    VKEY_W = 0x57,
    VKEY_X = 0x58,
    VKEY_Y = 0x59,
    VKEY_Z = 0x5A,
    VKEY_LWIN = 0x5B,
    VKEY_COMMAND = VKEY_LWIN,  // Provide the Mac name for convenience.
    VKEY_RWIN = 0x5C,
    VKEY_APPS = 0x5D,
    VKEY_SLEEP = 0x5F,
    VKEY_NUMPAD0 = 0x60,
    VKEY_NUMPAD1 = 0x61,
    VKEY_NUMPAD2 = 0x62,
    VKEY_NUMPAD3 = 0x63,
    VKEY_NUMPAD4 = 0x64,
    VKEY_NUMPAD5 = 0x65,
    VKEY_NUMPAD6 = 0x66,
    VKEY_NUMPAD7 = 0x67,
    VKEY_NUMPAD8 = 0x68,
    VKEY_NUMPAD9 = 0x69,
    VKEY_MULTIPLY = 0x6A,
    VKEY_ADD = 0x6B,
    VKEY_SEPARATOR = 0x6C,
    VKEY_SUBTRACT = 0x6D,
    VKEY_DECIMAL = 0x6E,
    VKEY_DIVIDE = 0x6F,
    VKEY_F1 = 0x70,
    VKEY_F2 = 0x71,
    VKEY_F3 = 0x72,
    VKEY_F4 = 0x73,
    VKEY_F5 = 0x74,
    VKEY_F6 = 0x75,
    VKEY_F7 = 0x76,
    VKEY_F8 = 0x77,
    VKEY_F9 = 0x78,
    VKEY_F10 = 0x79,
    VKEY_F11 = 0x7A,
    VKEY_F12 = 0x7B,
    VKEY_F13 = 0x7C,
    VKEY_F14 = 0x7D,
    VKEY_F15 = 0x7E,
    VKEY_F16 = 0x7F,
    VKEY_F17 = 0x80,
    VKEY_F18 = 0x81,
    VKEY_F19 = 0x82,
    VKEY_F20 = 0x83,
    VKEY_F21 = 0x84,
    VKEY_F22 = 0x85,
    VKEY_F23 = 0x86,
    VKEY_F24 = 0x87,
    VKEY_NUMLOCK = 0x90,
    VKEY_SCROLL = 0x91,
    VKEY_LSHIFT = 0xA0,
    VKEY_RSHIFT = 0xA1,
    VKEY_LCONTROL = 0xA2,
    VKEY_RCONTROL = 0xA3,
    VKEY_LMENU = 0xA4,
    VKEY_RMENU = 0xA5,
    VKEY_BROWSER_BACK = 0xA6,
    VKEY_BROWSER_FORWARD = 0xA7,
    VKEY_BROWSER_REFRESH = 0xA8,
    VKEY_BROWSER_STOP = 0xA9,
    VKEY_BROWSER_SEARCH = 0xAA,
    VKEY_BROWSER_FAVORITES = 0xAB,
    VKEY_BROWSER_HOME = 0xAC,
    VKEY_VOLUME_MUTE = 0xAD,
    VKEY_VOLUME_DOWN = 0xAE,
    VKEY_VOLUME_UP = 0xAF,
    VKEY_MEDIA_NEXT_TRACK = 0xB0,
    VKEY_MEDIA_PREV_TRACK = 0xB1,
    VKEY_MEDIA_STOP = 0xB2,
    VKEY_MEDIA_PLAY_PAUSE = 0xB3,
    VKEY_MEDIA_LAUNCH_MAIL = 0xB4,
    VKEY_MEDIA_LAUNCH_MEDIA_SELECT = 0xB5,
    VKEY_MEDIA_LAUNCH_APP1 = 0xB6,
    VKEY_MEDIA_LAUNCH_APP2 = 0xB7,
    VKEY_OEM_1 = 0xBA,
    VKEY_OEM_PLUS = 0xBB,
    VKEY_OEM_COMMA = 0xBC,
    VKEY_OEM_MINUS = 0xBD,
    VKEY_OEM_PERIOD = 0xBE,
    VKEY_OEM_2 = 0xBF,
    VKEY_OEM_3 = 0xC0,
    VKEY_OEM_4 = 0xDB,
    VKEY_OEM_5 = 0xDC,
    VKEY_OEM_6 = 0xDD,
    VKEY_OEM_7 = 0xDE,
    VKEY_OEM_8 = 0xDF,
    VKEY_OEM_102 = 0xE2,
    VKEY_OEM_103 = 0xE3,  // GTV KEYCODE_MEDIA_REWIND
    VKEY_OEM_104 = 0xE4,  // GTV KEYCODE_MEDIA_FAST_FORWARD
    VKEY_PROCESSKEY = 0xE5,
    VKEY_PACKET = 0xE7,
    VKEY_DBE_SBCSCHAR = 0xF3,
    VKEY_DBE_DBCSCHAR = 0xF4,
    VKEY_ATTN = 0xF6,
    VKEY_CRSEL = 0xF7,
    VKEY_EXSEL = 0xF8,
    VKEY_EREOF = 0xF9,
    VKEY_PLAY = 0xFA,
    VKEY_ZOOM = 0xFB,
    VKEY_NONAME = 0xFC,
    VKEY_PA1 = 0xFD,
    VKEY_OEM_CLEAR = 0xFE,
    VKEY_UNKNOWN = 0,

    // POSIX specific VKEYs. Note that as of Windows SDK 7.1, 0x97-9F, 0xD8-DA,
    // and 0xE8 are unassigned.
            VKEY_WLAN = 0x97,
    VKEY_POWER = 0x98,
    VKEY_BRIGHTNESS_DOWN = 0xD8,
    VKEY_BRIGHTNESS_UP = 0xD9,
    VKEY_KBD_BRIGHTNESS_DOWN = 0xDA,
    VKEY_KBD_BRIGHTNESS_UP = 0xE8,

    // Windows does not have a specific key code for AltGr. We use the unused 0xE1
    // (VK_OEM_AX) code to represent AltGr, matching the behaviour of Firefox on
    // Linux.
            VKEY_ALTGR = 0xE1,
    // Windows does not have a specific key code for Compose. We use the unused
    // 0xE6 (VK_ICO_CLEAR) code to represent Compose.
            VKEY_COMPOSE = 0xE6,
};

CefBrowserHost::MouseButtonType GetMouseButtonFromSDL(const SDL_MouseButtonEvent& event){
    CefBrowserHost::MouseButtonType button;
    switch (event.button){
        case SDL_BUTTON_LEFT:
        case SDL_BUTTON_X1:
            button = MBT_LEFT;
            break;

        case SDL_BUTTON_MIDDLE:
            button = MBT_MIDDLE;
            break;

        case SDL_BUTTON_RIGHT:
        case SDL_BUTTON_X2:
            button = MBT_RIGHT;
            break;
        default:
            button = MBT_LEFT;

    }

    return button;
}

int GetWindowsKeycodeFromSDLKeycode(SDL_Scancode code){
    if(code >= SDL_SCANCODE_1 && code <= SDL_SCANCODE_9){
        return VKEY_1 + (code - SDL_SCANCODE_1);
    } else if(code >= SDL_SCANCODE_A && code <= SDL_SCANCODE_Z){
        return VKEY_A + (code - SDL_SCANCODE_A);
    } else if(code >= SDL_SCANCODE_F1 && code <= SDL_SCANCODE_F24){
        return VKEY_F1 + (code - SDL_SCANCODE_F1);
    }

    switch (code){
        case SDL_SCANCODE_0:
            return SDL_SCANCODE_0;
        case SDL_SCANCODE_LSHIFT:
        case SDL_SCANCODE_RSHIFT:
            return VKEY_CONTROL;
        case SDL_SCANCODE_LCTRL:
        case SDL_SCANCODE_RCTRL:
            return VKEY_CONTROL;
        case SDL_SCANCODE_LALT:
        case SDL_SCANCODE_RALT:
            return VKEY_ALTGR;
        case SDL_SCANCODE_BACKSPACE:
            return VKEY_BACK;
        case SDL_SCANCODE_RETURN:
            return VKEY_RETURN;
        case SDL_SCANCODE_HOME:
            return VKEY_HOME;
        case SDL_SCANCODE_INSERT:
            return VKEY_INSERT;
        case SDL_SCANCODE_END:
            return VKEY_END;
        case SDL_SCANCODE_SCROLLLOCK:
            return VKEY_SCROLL;
        case SDL_SCANCODE_DELETE:
            return VKEY_DELETE;
        case SDL_SCANCODE_TAB:
            return VKEY_TAB;
        case SDL_SCANCODE_SPACE:
            return VKEY_SPACE;
        case SDL_SCANCODE_COMMA:
            return VKEY_COMMAND;
        case SDL_SCANCODE_LGUI:
            return VKEY_LWIN;
        case SDL_SCANCODE_CAPSLOCK:
            return VKEY_CAPITAL;
        case SDL_SCANCODE_UP:
            return VKEY_UP;
        case SDL_SCANCODE_DOWN:
            return VKEY_DOWN;
        case SDL_SCANCODE_LEFT:
            return VKEY_LEFT;
        case SDL_SCANCODE_RIGHT:
            return VKEY_RIGHT;
        case SDL_SCANCODE_PAGEUP:
            return VKEY_PRIOR;
        case SDL_SCANCODE_PAGEDOWN:
            return VKEY_NEXT;
        case SDL_SCANCODE_EQUALS:
            return VKEY_OEM_PLUS;
        case SDL_SCANCODE_MINUS:
            return VKEY_OEM_MINUS;
        default:
            return VKEY_UNKNOWN;
    }
}

int GetModifiersFromSDL(uint16_t mod){
    int result = EVENTFLAG_NONE;

    if (mod & KMOD_NUM) {
        result |= EVENTFLAG_NUM_LOCK_ON;
    }

    if (mod & KMOD_CAPS) {
        result |= EVENTFLAG_CAPS_LOCK_ON;
    }

    if (mod & KMOD_CTRL) {
        result |= EVENTFLAG_CONTROL_DOWN;
    }

    if (mod & KMOD_SHIFT) {
        result |= EVENTFLAG_SHIFT_DOWN;
    }

    if (mod & KMOD_ALT) {
        result |= EVENTFLAG_ALT_DOWN;
    }

    return result;
}


#endif