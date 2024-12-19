////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// This is a dummy WebGLContext for Emscripten/WebAssembly environments.
//
// It provides stub implementations of the methods expected by the SFML
// GlContext interface, but does not actually create or manage a real context.
// The goal is solely to allow the code to compile.
//
////////////////////////////////////////////////////////////

#ifndef SFML_WEBGLCONTEXT_HPP
#define SFML_WEBGLCONTEXT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/GlContext.hpp>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Window/WindowImpl.hpp> // For the WindowImpl pointer in constructor

namespace sf
{
namespace priv
{

class WebGLContext : public GlContext
{
public:
    ////////////////////////////////////////////////////////////
    /// \brief Create a new context not associated to a window
    ///
    /// \param shared Context to share the new one with (can be NULL)
    ///
    ////////////////////////////////////////////////////////////
    WebGLContext(WebGLContext* /*shared*/)
    {
    }

    ////////////////////////////////////////////////////////////
    /// \brief Create a new context attached to a window
    ///
    /// \param shared       Context to share the new one with
    /// \param settings     Creation parameters
    /// \param owner        Pointer to the owner window
    /// \param bitsPerPixel Pixel depth, in bits per pixel
    ///
    ////////////////////////////////////////////////////////////
    WebGLContext(WebGLContext* /*shared*/, const ContextSettings& /*settings*/, const WindowImpl* /*owner*/, unsigned int /*bitsPerPixel*/)
    {
    }

    ////////////////////////////////////////////////////////////
    /// \brief Create a new context that embeds its own rendering target
    ///
    /// \param shared   Context to share the new one with
    /// \param settings Creation parameters
    /// \param width    Back buffer width, in pixels
    /// \param height   Back buffer height, in pixels
    ///
    ////////////////////////////////////////////////////////////
    WebGLContext(WebGLContext* /*shared*/, const ContextSettings& /*settings*/, unsigned int /*width*/, unsigned int /*height*/)
    {
    }

    ////////////////////////////////////////////////////////////
    /// \brief Destructor
    ///
    ////////////////////////////////////////////////////////////
    ~WebGLContext()
    {
    }

    ////////////////////////////////////////////////////////////
    /// \brief Get the address of an OpenGL function
    ///
    /// \param name Name of the function to get the address of
    ///
    /// \return Address of the OpenGL function, or null on failure
    ///
    ////////////////////////////////////////////////////////////
    static GlFunctionPointer getFunction(const char* /*name*/)
    {
        return nullptr;
    }

    ////////////////////////////////////////////////////////////
    /// \brief Activate the context as the current target for rendering
    ///
    /// \param current True to activate, false to deactivate
    ///
    /// \return True on success, false on failure
    ///
    ////////////////////////////////////////////////////////////
    virtual bool makeCurrent(bool /*current*/) override
    {
        return true; // Just return true for now
    }

    ////////////////////////////////////////////////////////////
    /// \brief Display what has been rendered so far
    ///
    ////////////////////////////////////////////////////////////
    virtual void display() override
    {
        // No-op
    }

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable vertical synchronization
    ///
    /// \param enabled True to enable v-sync, false to disable
    ///
    ////////////////////////////////////////////////////////////
    virtual void setVerticalSyncEnabled(bool /*enabled*/) override
    {
        // No-op
    }

    ////////////////////////////////////////////////////////////
    /// \brief Update the creation settings from the chosen context
    ///
    /// In a real implementation, this updates GlContext's m_settings.
    ////////////////////////////////////////////////////////////
    void updateSettings()
    {
        // No-op
    }

private:
    // No member data needed for the dummy implementation
};

} // namespace priv
} // namespace sf

#endif // SFML_WEBGLCONTEXT_HPP
