////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from 
// the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it 
// freely,
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

#include "WindowImplEmscripten.hpp"

namespace sf
{
namespace priv
{

WindowImplEmscripten::WindowImplEmscripten(WindowHandle)
: m_size(800, 600)
, m_hasFocus(true)
{
}

WindowImplEmscripten::WindowImplEmscripten(VideoMode mode, const String&, unsigned long, const ContextSettings&)
: m_size(mode.width, mode.height)
, m_hasFocus(true)
{
}

WindowImplEmscripten::~WindowImplEmscripten()
{
}

WindowHandle WindowImplEmscripten::getSystemHandle() const
{
    return 0; // Dummy handle
}

void WindowImplEmscripten::processEvents()
{
    // No-op
}

Vector2i WindowImplEmscripten::getPosition() const
{
    return Vector2i(0,0);
}

void WindowImplEmscripten::setPosition(const Vector2i&)
{
    // No-op
}

Vector2u WindowImplEmscripten::getSize() const
{
    return m_size;
}

void WindowImplEmscripten::setSize(const Vector2u&)
{
    // No-op
}

void WindowImplEmscripten::setTitle(const String&)
{
    // No-op
}

void WindowImplEmscripten::setIcon(unsigned int, unsigned int, const Uint8*)
{
    // No-op
}

void WindowImplEmscripten::setVisible(bool)
{
    // No-op
}

void WindowImplEmscripten::setMouseCursorVisible(bool)
{
    // No-op
}

void WindowImplEmscripten::setMouseCursorGrabbed(bool)
{
    // No-op
}

void WindowImplEmscripten::setMouseCursor(const CursorImpl&)
{
    // No-op
}

void WindowImplEmscripten::setKeyRepeatEnabled(bool)
{
    // No-op
}

void WindowImplEmscripten::requestFocus()
{
    // No-op
}

bool WindowImplEmscripten::hasFocus() const
{
    return m_hasFocus;
}

} // namespace priv
} // namespace sf
