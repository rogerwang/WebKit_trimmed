/*
 * Copyright (C) 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WebInputEvent_h
#define WebInputEvent_h

#include "../../../Platform/chromium/public/WebCommon.h"
#include "../../../Platform/chromium/public/WebRect.h"
#include "WebTouchPoint.h"

#include <string.h>

namespace WebKit {

// The classes defined in this file are intended to be used with
// WebWidget's handleInputEvent method.  These event types are cross-
// platform and correspond closely to WebCore's Platform*Event classes.
//
// WARNING! These classes must remain PODs (plain old data).  They are
// intended to be "serializable" by copying their raw bytes, so they must
// not contain any non-bit-copyable member variables!
//
// Furthermore, the class members need to be packed so they are aligned
// properly and don't have paddings/gaps, otherwise memory check tools
// like Valgrind will complain about uninitialized memory usage when
// transferring these classes over the wire.

#pragma pack(push, 4)

// WebInputEvent --------------------------------------------------------------

class WebInputEvent {
public:
    WebInputEvent(unsigned sizeParam = sizeof(WebInputEvent))
    {
        memset(this, 0, sizeParam);
        timeStampSeconds = 0.0;
        size = sizeParam;
        type = Undefined;
        modifiers = 0;
    }

    // When we use an input method (or an input method editor), we receive
    // two events for a keypress. The former event is a keydown, which
    // provides a keycode, and the latter is a textinput, which provides
    // a character processed by an input method. (The mapping from a
    // keycode to a character code is not trivial for non-English
    // keyboards.)
    // To support input methods, Safari sends keydown events to WebKit for
    // filtering. WebKit sends filtered keydown events back to Safari,
    // which sends them to input methods.
    // Unfortunately, it is hard to apply this design to Chrome because of
    // our multiprocess architecture. An input method is running in a
    // browser process. On the other hand, WebKit is running in a renderer
    // process. So, this design results in increasing IPC messages.
    // To support input methods without increasing IPC messages, Chrome
    // handles keyboard events in a browser process and send asynchronous
    // input events (to be translated to DOM events) to a renderer
    // process.
    // This design is mostly the same as the one of Windows and Mac Carbon.
    // So, for what it's worth, our Linux and Mac front-ends emulate our
    // Windows front-end. To emulate our Windows front-end, we can share
    // our back-end code among Windows, Linux, and Mac.
    // TODO(hbono): Issue 18064: remove the KeyDown type since it isn't
    // used in Chrome any longer.

    enum Type {
        Undefined = -1,

        // WebMouseEvent
        MouseDown,
        MouseUp,
        MouseMove,
        MouseEnter,
        MouseLeave,
        ContextMenu,

        // WebMouseWheelEvent
        MouseWheel,

        // WebKeyboardEvent
        RawKeyDown,
        KeyDown,
        KeyUp,
        Char,

        // WebGestureEvent
        GestureScrollBegin,
        GestureScrollEnd,
        GestureScrollUpdate,
        GestureScrollUpdateWithoutPropagation,
        GestureFlingStart,
        GestureFlingCancel,
        GestureTap,
        GestureTapDown,
        GestureTapCancel,
        GestureDoubleTap,
        GestureTwoFingerTap,
        GestureLongPress,
        GestureLongTap,
        GesturePinchBegin,
        GesturePinchEnd,
        GesturePinchUpdate,

        // WebTouchEvent
        TouchStart,
        TouchMove,
        TouchEnd,
        TouchCancel,
    };

    enum Modifiers {
        // modifiers for all events:
        ShiftKey         = 1 << 0,
        ControlKey       = 1 << 1,
        AltKey           = 1 << 2,
        MetaKey          = 1 << 3,

        // modifiers for keyboard events:
        IsKeyPad         = 1 << 4,
        IsAutoRepeat     = 1 << 5,

        // modifiers for mouse events:
        LeftButtonDown   = 1 << 6,
        MiddleButtonDown = 1 << 7,
        RightButtonDown  = 1 << 8,

        // Toggle modifiers for all events. Danger: these are not reflected
        // into WebCore, so round-tripping from WebInputEvent to a WebCore
        // event and back will not preserve these flags.
        CapsLockOn       = 1 << 9,
        NumLockOn        = 1 << 10,

        // Left/right modifiers for keyboard events.
        IsLeft           = 1 << 11,
        IsRight          = 1 << 12,

        // Last input event to be sent for the current vsync interval. If this
        // flag is set, the sender guarantees that no more input events will be
        // delivered until the next vsync and the receiver can schedule
        // rendering accordingly. If it isn't set, the receiver should not make
        // any assumptions about the delivery times of future input events
        // w.r.t. vsync.
        IsLastInputEventForCurrentVSync = 1 << 13,
    };

    static const int InputModifiers = ShiftKey | ControlKey | AltKey | MetaKey;

    double timeStampSeconds; // Seconds since epoch.
    unsigned size; // The size of this structure, for serialization.
    Type type;
    int modifiers;

    // Returns true if the WebInputEvent |type| is a mouse event.
    static bool isMouseEventType(int type)
    {
        return type == MouseDown
            || type == MouseUp
            || type == MouseMove
            || type == MouseEnter
            || type == MouseLeave
            || type == ContextMenu;
    }

    // Returns true if the WebInputEvent |type| is a keyboard event.
    static bool isKeyboardEventType(int type)
    {
        return type == RawKeyDown
            || type == KeyDown
            || type == KeyUp
            || type == Char;
    }

    // Returns true if the WebInputEvent |type| is a touch event.
    static bool isTouchEventType(int type)
    {
        return type == TouchStart
            || type == TouchMove
            || type == TouchEnd
            || type == TouchCancel;
    }

    // Returns true if the WebInputEvent |type| should be handled as user gesture.
    static bool isUserGestureEventType(int type)
    {
        return isKeyboardEventType(type)
            || type == MouseDown
            || type == MouseUp
            || type == TouchStart
            || type == TouchEnd;
    }

    // Returns true if the WebInputEvent is a gesture event.
    static bool isGestureEventType(int type)
    {
        return type == GestureScrollBegin
            || type == GestureScrollEnd
            || type == GestureScrollUpdate
            || type == GestureScrollUpdateWithoutPropagation
            || type == GestureFlingStart
            || type == GestureFlingCancel
            || type == GesturePinchBegin
            || type == GesturePinchEnd
            || type == GesturePinchUpdate
            || type == GestureTap
            || type == GestureTapDown
            || type == GestureTapCancel
            || type == GestureDoubleTap
            || type == GestureTwoFingerTap
            || type == GestureLongPress
            || type == GestureLongTap
            || type == GesturePinchBegin
            || type == GesturePinchEnd
            || type == GesturePinchUpdate;
    }
};

// WebKeyboardEvent -----------------------------------------------------------

class WebKeyboardEvent : public WebInputEvent {
public:
    // Caps on string lengths so we can make them static arrays and keep
    // them PODs.
    static const size_t textLengthCap = 4;

    // http://www.w3.org/TR/DOM-Level-3-Events/keyset.html lists the
    // identifiers.  The longest is 18 characters, so we round up to the
    // next multiple of 4.
    static const size_t keyIdentifierLengthCap = 20;

    // |windowsKeyCode| is the Windows key code associated with this key
    // event.  Sometimes it's direct from the event (i.e. on Windows),
    // sometimes it's via a mapping function.  If you want a list, see
    // WebCore/platform/chromium/KeyboardCodes* . Note that this should
    // ALWAYS store the non-locational version of a keycode as this is
    // what is returned by the Windows API. For example, it should
    // store VK_SHIFT instead of VK_RSHIFT. The location information
    // should be stored in |modifiers|.
    int windowsKeyCode;

    // The actual key code genenerated by the platform.  The DOM spec runs
    // on Windows-equivalent codes (thus |windowsKeyCode| above) but it
    // doesn't hurt to have this one around.
    int nativeKeyCode;

    // This identifies whether this event was tagged by the system as being
    // a "system key" event (see
    // http://msdn.microsoft.com/en-us/library/ms646286(VS.85).aspx for
    // details). Other platforms don't have this concept, but it's just
    // easier to leave it always false than ifdef.
    // See comment at the top of the file for why an int is used here.
    bool isSystemKey;

    // |text| is the text generated by this keystroke.  |unmodifiedText| is
    // |text|, but unmodified by an concurrently-held modifiers (except
    // shift).  This is useful for working out shortcut keys.  Linux and
    // Windows guarantee one character per event.  The Mac does not, but in
    // reality that's all it ever gives.  We're generous, and cap it a bit
    // longer.
    WebUChar text[textLengthCap];
    WebUChar unmodifiedText[textLengthCap];

    // This is a string identifying the key pressed.
    char keyIdentifier[keyIdentifierLengthCap];

    WebKeyboardEvent(unsigned sizeParam = sizeof(WebKeyboardEvent))
        : WebInputEvent(sizeParam)
        , windowsKeyCode(0)
        , nativeKeyCode(0)
        , isSystemKey(false)
    {
        memset(&text, 0, sizeof(text));
        memset(&unmodifiedText, 0, sizeof(unmodifiedText));
        memset(&keyIdentifier, 0, sizeof(keyIdentifier));
    }

    // Sets keyIdentifier based on the value of windowsKeyCode.  This is
    // handy for generating synthetic keyboard events.
    WEBKIT_EXPORT void setKeyIdentifierFromWindowsKeyCode();

    static int windowsKeyCodeWithoutLocation(int keycode);
    static int locationModifiersFromWindowsKeyCode(int keycode);
};

// WebMouseEvent --------------------------------------------------------------

class WebMouseEvent : public WebInputEvent {
public:
    // These values defined for WebCore::MouseButton
    enum Button {
        ButtonNone = -1,
        ButtonLeft,
        ButtonMiddle,
        ButtonRight
    };

    Button button;
    int x;
    int y;
    int windowX;
    int windowY;
    int globalX;
    int globalY;
    int movementX;
    int movementY;
    int clickCount;

    WebMouseEvent(unsigned sizeParam = sizeof(WebMouseEvent))
        : WebInputEvent(sizeParam)
        , button(ButtonNone)
        , x(0)
        , y(0)
        , windowX(0)
        , windowY(0)
        , globalX(0)
        , globalY(0)
        , movementX(0)
        , movementY(0)
        , clickCount(0)
    {
    }
};

// WebMouseWheelEvent ---------------------------------------------------------

class WebMouseWheelEvent : public WebMouseEvent {
public:
    enum Phase {
        PhaseNone        = 0,
        PhaseBegan       = 1 << 0,
        PhaseStationary  = 1 << 1,
        PhaseChanged     = 1 << 2,
        PhaseEnded       = 1 << 3,
        PhaseCancelled   = 1 << 4,
        PhaseMayBegin    = 1 << 5,
    };

    float deltaX;
    float deltaY;
    float wheelTicksX;
    float wheelTicksY;

    float accelerationRatioX;
    float accelerationRatioY;

    // See comment at the top of the file for why an int is used here.
    int scrollByPage;

    // See comment at the top of the file for why an int is used here.
    int hasPreciseScrollingDeltas;
    Phase phase;
    Phase momentumPhase;

    WebMouseWheelEvent(unsigned sizeParam = sizeof(WebMouseWheelEvent))
        : WebMouseEvent(sizeParam)
        , deltaX(0.0f)
        , deltaY(0.0f)
        , wheelTicksX(0.0f)
        , wheelTicksY(0.0f)
        , accelerationRatioX(1.0f)
        , accelerationRatioY(1.0f)
        , scrollByPage(false)
        , hasPreciseScrollingDeltas(false)
        , phase(PhaseNone)
        , momentumPhase(PhaseNone)
    {
    }
};

// WebGestureEvent --------------------------------------------------------------

class WebGestureEvent : public WebInputEvent {
public:
    enum SourceDevice {
        Touchpad,
        Touchscreen,
    };

    int x;
    int y;
    int globalX;
    int globalY;
    SourceDevice sourceDevice;

    union {
        struct {
            int tapCount;
            float width;
            float height;
        } tap;

        struct {
            float width;
            float height;
        } tapDown;

        struct {
            float width;
            float height;
        } longPress;

        struct {
            float firstFingerWidth;
            float firstFingerHeight;
        } twoFingerTap;

        struct {
            float deltaX;
            float deltaY;
            float velocityX;
            float velocityY;
        } scrollUpdate;

        struct {
            float velocityX;
            float velocityY;
            // FIXME: Remove this when Chromium uses the top-level field.
            SourceDevice sourceDevice;
        } flingStart;

        struct {
            float scale;
        } pinchUpdate;
    } data;

    WebGestureEvent(unsigned sizeParam = sizeof(WebGestureEvent))
        : WebInputEvent(sizeParam)
        , x(0)
        , y(0)
        , globalX(0)
        , globalY(0)
    {
        memset(&data, 0, sizeof(data));
    }
};

// WebTouchEvent --------------------------------------------------------------

class WebTouchEvent : public WebInputEvent {
public:
    // Maximum number of simultaneous touches supported on
    // Ash/Aura.
    enum { touchesLengthCap = 12 };

    unsigned touchesLength;
    // List of all touches which are currently down.
    WebTouchPoint touches[touchesLengthCap];

    unsigned changedTouchesLength;
    // List of all touches whose state has changed since the last WebTouchEvent
    WebTouchPoint changedTouches[touchesLengthCap];

    unsigned targetTouchesLength;
    // List of all touches which are currently down and are targeting the event recipient.
    WebTouchPoint targetTouches[touchesLengthCap];

    WebTouchEvent(unsigned sizeParam = sizeof(WebTouchEvent))
        : WebInputEvent(sizeParam)
        , touchesLength(0)
        , changedTouchesLength(0)
        , targetTouchesLength(0)
    {
    }
};

#pragma pack(pop)

} // namespace WebKit

#endif
