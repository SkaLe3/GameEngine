#pragma once


namespace Engine {

	using KeyCode = int16_t;

	namespace Key {

        enum : KeyCode
        {
            // From SFML/Window/Keyboard.hpp

            KEY_A = 0,        //!< The A key
            KEY_B,            //!< The B key
            KEY_C,            //!< The C key
            KEY_D,            //!< The D key
            KEY_E,            //!< The E key
            KEY_F,            //!< The F key
            KEY_G,            //!< The G key
            KEY_H,            //!< The H key
            KEY_I,            //!< The I key
            KEY_J,            //!< The J key
            KEY_K,            //!< The K key
            KEY_L,            //!< The L key
            KEY_M,            //!< The M key
            KEY_N,            //!< The N key
            KEY_O,            //!< The O key
            KEY_P,            //!< The P key
            KEY_Q,            //!< The Q key
            KEY_R,            //!< The R key
            KEY_S,            //!< The S key
            KEY_T,            //!< The T key
            KEY_U,            //!< The U key
            KEY_V,            //!< The V key
            KEY_W,            //!< The W key
            KEY_X,            //!< The X key
            KEY_Y,            //!< The Y key
            KEY_Z,            //!< The Z key
            KEY_KP_0,         //!< The 0 key
            KEY_KP_1,         //!< The 1 key
            KEY_KP_2,         //!< The 2 key
            KEY_KP_3,         //!< The 3 key
            KEY_KP_4,         //!< The 4 key
            KEY_KP_5,         //!< The 5 key
            KEY_KP_6,         //!< The 6 key
            KEY_KP_7,         //!< The 7 key
            KEY_KP_8,         //!< The 8 key
            KEY_KP_9,         //!< The 9 key
            KEY_ESCAPE,       //!< The Escape key
            KEY_LEFT_CONTROL,     //!< The left Control key
            KEY_LEFT_SHIFT,       //!< The left Shift key
            KEY_LEFT_ALT,         //!< The left Alt key
            KEY_LEFT_SYSTEM,      //!< The left OS specific key: window (Windows and Linux), apple (MacOS X), ...
            KEY_RIGHT_CONTROL,     //!< The right Control key
            KEY_RIGHT_SHIFT,       //!< The right Shift key
            KEY_RIGHT_ALT,         //!< The right Alt key
            KEY_RIGHT_SYSTEM,      //!< The right OS specific key: window (Windows and Linux), apple (MacOS X), ...
            KEY_MENU,         //!< The Menu key
            KEY_LEFT_BRACKET,     //!< The [ key
            KEY_RIGHT_BRACKET,     //!< The ] key
            KEY_SEMICOLON,    //!< The ; key
            KEY_COMMA,        //!< The , key
            KEY_PERIOD,       //!< The . key
            KEY_APOSTROPHE,   //!< The ' key
            KEY_SLASH,        //!< The / key
            KEY_BACKSLASH,    //!< The \ key
            KEY_TILDE,        //!< The ~ key
            KEY_EQUAL,        //!< The = key
            KEY_MINUS,       //!< The - key (hyphen)
            KEY_SPACE,        //!< The Space key
            KEY_ENTER,        //!< The Enter/Return keys
            KEY_BACKSPACE,    //!< The Backspace key
            KEY_TAB,          //!< The Tabulation key
            KEY_PAGE_UP,       //!< The Page up key
            KEY_PAGE_DOWN,     //!< The Page down key
            KEY_END,          //!< The End key
            KEY_HOME,         //!< The Home key
            KEY_INSERT,       //!< The Insert key
            KEY_DELETE,       //!< The Delete key
            KEY_KP_ADD,          //!< The + key
            KEY_KP_SUBSTRACT,     //!< The - key (minus, usually from numpad)
            KEY_KP_MULTIPLY,     //!< The * key
            KEY_KP_DIVIDE,       //!< The / key
            KEY_LEFT,         //!< Left arrow
            KEY_RIGHT,        //!< Right arrow
            KEY_UP,           //!< Up arrow
            KEY_DOWN,         //!< Down arrow
            KEY_KP_0,      //!< The numpad 0 key
            KEY_KP_1,      //!< The numpad 1 key
            KEY_KP_2,      //!< The numpad 2 key
            KEY_KP_3,      //!< The numpad 3 key
            KEY_KP_4,      //!< The numpad 4 key
            KEY_KP_5,      //!< The numpad 5 key
            KEY_KP_6,      //!< The numpad 6 key
            KEY_KP_7,      //!< The numpad 7 key
            KEY_KP_8,      //!< The numpad 8 key
            KEY_KP_9,      //!< The numpad 9 key
            KEY_F1,           //!< The F1 key
            KEY_F2,           //!< The F2 key
            KEY_F3,           //!< The F3 key
            KEY_F4,           //!< The F4 key
            KEY_F5,           //!< The F5 key
            KEY_F6,           //!< The F6 key
            KEY_F7,           //!< The F7 key
            KEY_F8,           //!< The F8 key
            KEY_F9,           //!< The F9 key
            KEY_F10,          //!< The F10 key
            KEY_F11,          //!< The F11 key
            KEY_F12,          //!< The F12 key
            KEY_F13,          //!< The F13 key
            KEY_F14,          //!< The F14 key
            KEY_F15,          //!< The F15 key
            KEY_PAUSE,        //!< The Pause key

            KeyCount //!< Keep last -- the total number of keyboard keys
        };
	}
	
}	