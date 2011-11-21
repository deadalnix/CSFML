////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2009 Laurent Gomila (laurent.gom@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_WINDOW_H
#define SFML_WINDOW_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Types.h>


////////////////////////////////////////////////////////////
/// \brief Enumeration of window creation styles
///
////////////////////////////////////////////////////////////
enum
{
    sfNone         = 0,      ///< No border / title bar (this flag and all others are mutually exclusive)
    sfTitlebar     = 1 << 0, ///< Title bar + fixed border
    sfResize       = 1 << 1, ///< Titlebar + resizable border + maximize button
    sfClose        = 1 << 2, ///< Titlebar + close button
    sfFullscreen   = 1 << 3, ///< Fullscreen mode (this flag and all others are mutually exclusive)
    sfDefaultStyle = sfTitlebar | sfResize | sfClose ///< Default window style
};


////////////////////////////////////////////////////////////
/// \brief Structure defining the window's creation settings
///
////////////////////////////////////////////////////////////
typedef struct
{
    unsigned int DepthBits;         ///< Bits of the depth buffer
    unsigned int StencilBits;       ///< Bits of the stencil buffer
    unsigned int AntialiasingLevel; ///< Level of antialiasing
    unsigned int MajorVersion;      ///< Major number of the context version to create
    unsigned int MinorVersion;      ///< Minor number of the context version to create
} sfContextSettings;


////////////////////////////////////////////////////////////
/// \brief Construct a new window
///
/// This function creates the window with the size and pixel
/// depth defined in \a mode. An optional style can be passed to
/// customize the look and behaviour of the window (borders,
/// title bar, resizable, closable, ...). If \a style contains
/// sfFullscreen, then \a mode must be a valid video mode.
///
/// The fourth parameter is a pointer to a structure specifying
/// advanced OpenGL context settings such as antialiasing,
/// depth-buffer bits, etc.
///
/// \param mode     Video mode to use (defines the width, height and depth of the rendering area of the window)
/// \param title    Title of the window
/// \param style    Window style
/// \param settings Additional settings for the underlying OpenGL context
///
/// \return A new sfWindow object
///
////////////////////////////////////////////////////////////
CSFML_API sfWindow* sfWindow_Create(sfVideoMode mode, const char* title, sfUint32 style, const sfContextSettings* settings);

////////////////////////////////////////////////////////////
/// \brief Construct a window from an existing control
///
/// Use this constructor if you want to create an OpenGL
/// rendering area into an already existing control.
///
/// The second parameter is a pointer to a structure specifying
/// advanced OpenGL context settings such as antialiasing,
/// depth-buffer bits, etc.
///
/// \param handle   Platform-specific handle of the control
/// \param settings Additional settings for the underlying OpenGL context
///
/// \return A new sfWindow object
///
////////////////////////////////////////////////////////////
CSFML_API sfWindow* sfWindow_CreateFromHandle(sfWindowHandle handle, const sfContextSettings* settings);

////////////////////////////////////////////////////////////
/// \brief Destroy a window
///
/// \param window Window to destroy
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_Destroy(sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Close a window and destroy all the attached resources
///
/// After calling this function, the sfWindow object remains
/// valid, you must call sfWindow_Destroy to actually delete it.
/// All other functions such as sfWindow_PollEvent or sfWindow_Display
/// will still work (i.e. you don't have to test sfWindow_IsOpened
/// every time), and will have no effect on closed windows.
///
/// \param window Window object
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_Close(sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a window is opened
///
/// This function returns whether or not the window exists.
/// Note that a hidden window (sfWindow_Show(sfFalse)) will return
/// sfTrue.
///
/// \param window Window object
///
/// \return sfTrue if the window is opened, sfFalse if it has been closed
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfWindow_IsOpened(const sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Get the width of the rendering region of a window
///
/// The width doesn't include the titlebar and borders
/// of the window.
///
/// \param window Window object
///
/// \return Width in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfWindow_GetWidth(const sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Get the height of the rendering region of a window
///
/// The height doesn't include the titlebar and borders
/// of the window.
///
/// \param window Window object
///
/// \return Height in pixels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfWindow_GetHeight(const sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Get the settings of the OpenGL context of a window
///
/// Note that these settings may be different from what was
/// passed to the sfWindow_Create function,
/// if one or more settings were not supported. In this case,
/// SFML chose the closest match.
///
/// \param window Window object
///
/// \return Structure containing the OpenGL context settings
///
////////////////////////////////////////////////////////////
CSFML_API sfContextSettings sfWindow_GetSettings(const sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Pop the event on top of events stack, if any, and return it
///
/// This function is not blocking: if there's no pending event then
/// it will return false and leave \a event unmodified.
/// Note that more than one event may be present in the events stack,
/// thus you should always call this function in a loop
/// to make sure that you process every pending event.
///
/// \param window Window object
/// \param event  Event to be returned
///
/// \return sfTrue if an event was returned, or sfFalse if the events stack was empty
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfWindow_PollEvent(sfWindow* window, sfEvent* event);

////////////////////////////////////////////////////////////
/// \brief Wait for an event and return it
///
/// This function is blocking: if there's no pending event then
/// it will wait until an event is received.
/// After this function returns (and no error occured),
/// the \a event object is always valid and filled properly.
/// This function is typically used when you have a thread that
/// is dedicated to events handling: you want to make this thread
/// sleep as long as no new event is received.
///
/// \param window Window object
/// \param event  Event to be returned
///
/// \return sfFalse if any error occured
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfWindow_WaitEvent(sfWindow* window, sfEvent* event);

////////////////////////////////////////////////////////////
/// \brief Enable or disable vertical synchronization
///
/// Activating vertical synchronization will limit the number
/// of frames displayed to the refresh rate of the monitor.
/// This can avoid some visual artifacts, and limit the framerate
/// to a good value (but not constant across different computers).
///
/// \param window  Window object
/// \param enabled sfTrue to enable v-sync, sfFalse to deactivate
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_EnableVerticalSync(sfWindow* window, sfBool enabled);

////////////////////////////////////////////////////////////
/// \brief Show or hide the mouse cursor
///
/// \param window Window object
/// \param show   sfTrue to show, sfFalse to hide
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_ShowMouseCursor(sfWindow* window, sfBool show);

////////////////////////////////////////////////////////////
/// \brief Change the position of a window on screen
///
/// This function only works for top-level windows
/// (i.e. it will be ignored for windows created from
/// the handle of a child window/control).
///
/// \param window Window object
/// \param x      Left position
/// \param y      Top position
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_SetPosition(sfWindow* window, int left, int top);

////////////////////////////////////////////////////////////
/// \brief Change the size of the rendering region of a window
///
/// \param window Window object
/// \param width  New width, in pixels
/// \param height New height, in pixels
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_SetSize(sfWindow* window, unsigned int width, unsigned int height);

////////////////////////////////////////////////////////////
/// \brief Change the title of a window
///
/// \param window Window object
/// \param title  New title
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_SetTitle(sfWindow* window, const char* title);

////////////////////////////////////////////////////////////
/// \brief Show or hide a window
///
/// \param window Window object
/// \param show   sfTrue to show, sfFalse to hide
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_Show(sfWindow* window, sfBool show);

////////////////////////////////////////////////////////////
/// \brief Enable or disable automatic key-repeat
///
/// If key repeat is enabled, you will receive repeated
/// KeyPress events while keeping a key pressed. If it is disabled,
/// you will only get a single event when the key is pressed.
///
/// Key repeat is enabled by default.
///
/// \param window  Window object
/// \param enabled sfTrue to enable, sfFalse to disable
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_EnableKeyRepeat(sfWindow* window, sfBool enabled);

////////////////////////////////////////////////////////////
/// \brief Change a window's icon
///
/// \a pixels must be an array of \a width x \a height pixels
/// in 32-bits RGBA format.
///
/// \param window Window object
/// \param width  Icon's width, in pixels
/// \param height Icon's height, in pixels
/// \param pixels Pointer to the array of pixels in memory
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_SetIcon(sfWindow* window, unsigned int width, unsigned int height, const sfUint8* pixels);

////////////////////////////////////////////////////////////
/// \brief Activate or deactivate a window as the current target
///        for OpenGL rendering
///
/// A window is active only on the current thread, if you want to
/// make it active on another thread you have to deactivate it
/// on the previous thread first if it was active.
/// Only one window can be active on a thread at a time, thus
/// the window previously active (if any) automatically gets deactivated.
///
/// \param window Window object
/// \param active sfTrue to activate, sfFalse to deactivate
///
/// \return sfTrue if operation was successful, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfWindow_SetActive(sfWindow* window, sfBool active);

////////////////////////////////////////////////////////////
/// \brief Display on screen what has been rendered to the
///        window so far
///
/// This function is typically called after all OpenGL rendering
/// has been done for the current frame, in order to show
/// it on screen.
///
/// \param window Window object
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_Display(sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Limit the framerate to a maximum fixed frequency
///
/// If a limit is set, the window will use a small delay after
/// each call to sfWindow_Display to ensure that the current frame
/// lasted long enough to match the framerate limit.
///
/// \param window Window object
/// \param limit  Framerate limit, in frames per seconds (use 0 to disable limit)
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_SetFramerateLimit(sfWindow* window, unsigned int limit);

////////////////////////////////////////////////////////////
/// \brief Get the duration of the last frame
///
/// This function returns the time elapsed between the last
/// two calls to sfWindow_Display.
/// This can be useful for calculating the framerate, or for
/// updating the application's objects.
///
/// \param window Window object
///
/// \return Time elapsed in last frame, in milliseconds
///
////////////////////////////////////////////////////////////
CSFML_API sfUint32 sfWindow_GetFrameTime(const sfWindow* window);

////////////////////////////////////////////////////////////
/// \brief Change the joystick threshold
///
/// The joystick threshold is the value below which
/// no JoyMoved event will be generated.
///
/// \param window    Window object
/// \param threshold New threshold, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_API void sfWindow_SetJoystickThreshold(sfWindow* window, float threshold);

////////////////////////////////////////////////////////////
/// \brief Get the OS-specific handle of the window
///
/// The type of the returned handle is sfWindowHandle,
/// which is a typedef to the handle type defined by the OS.
/// You shouldn't need to use this function, unless you have
/// very specific stuff to implement that SFML doesn't support,
/// or implement a temporary workaround until a bug is fixed.
///
/// \param window Window object
///
/// \return System handle of the window
///
////////////////////////////////////////////////////////////
CSFML_API sfWindowHandle sfWindow_GetSystemHandle(const sfWindow* window);


#endif // SFML_WINDOW_H
