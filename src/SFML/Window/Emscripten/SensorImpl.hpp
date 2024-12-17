////////////////////////////////////////////////////////////
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2023 Laurent Gomila
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

#ifndef SFML_SENSORIMPLEMSCRIPTEN_HPP
#define SFML_SENSORIMPLEMSCRIPTEN_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Window/Sensor.hpp>
#include <SFML/System/Vector3.hpp>

// Forward declarations, no need to include Android headers
struct ASensor;

namespace sf
{
namespace priv
{
////////////////////////////////////////////////////////////
/// \brief Emscripten stub implementation of sensors
///
////////////////////////////////////////////////////////////
class SensorImpl
{
public:

    ////////////////////////////////////////////////////////////
    /// \brief Perform the global initialization of the sensor module
    ///
    ////////////////////////////////////////////////////////////
    static void initialize();

    ////////////////////////////////////////////////////////////
    /// \brief Perform the global cleanup of the sensor module
    ///
    ////////////////////////////////////////////////////////////
    static void cleanup();

    ////////////////////////////////////////////////////////////
    /// \brief Check if a sensor is available
    ///
    /// \param sensor Sensor to check
    ///
    /// \return True if the sensor is available, false otherwise
    ///
    ////////////////////////////////////////////////////////////
    static bool isAvailable(Sensor::Type sensor);

    ////////////////////////////////////////////////////////////
    /// \brief Open the sensor
    ///
    /// \param sensor Type of the sensor
    ///
    /// \return True on success, false on failure
    ///
    ////////////////////////////////////////////////////////////
    bool open(Sensor::Type sensor);

    ////////////////////////////////////////////////////////////
    /// \brief Close the sensor
    ///
    ////////////////////////////////////////////////////////////
    void close();

    ////////////////////////////////////////////////////////////
    /// \brief Update the sensor and get its new value
    ///
    /// \return Sensor value
    ///
    ////////////////////////////////////////////////////////////
    Vector3f update();

    ////////////////////////////////////////////////////////////
    /// \brief Enable or disable the sensor
    ///
    /// \param enabled True to enable, false to disable
    ///
    ////////////////////////////////////////////////////////////
    void setEnabled(bool enabled);

private:

    ////////////////////////////////////////////////////////////
    /// \brief Get the default Emscripten sensor matching the sensor type
    ///
    /// \param type Type of the sensor
    ///
    /// \return The default Emscripten sensor, nullptr otherwise
    ///
    ////////////////////////////////////////////////////////////
    static const ASensor* getDefaultSensor(Sensor::Type sensor);

    ////////////////////////////////////////////////////////////
    /// \brief Process the pending sensor data available (dummy function)
    ///
    /// \param fd     File descriptor (unused)
    /// \param events Bitmask of the poll events that were triggered (unused)
    /// \param data   Data pointer supplied (unused)
    ///
    /// \return 1 to continue
    ///
    ////////////////////////////////////////////////////////////
    static int processSensorEvents(int fd, int events, void* data);

    ////////////////////////////////////////////////////////////
    // Member data
    ////////////////////////////////////////////////////////////
    const ASensor* m_sensor; ///< Emscripten sensor structure (unused)
    unsigned int   m_index;  ///< Index of the sensor (unused)
};

} // namespace priv

} // namespace sf

#endif // SFML_SENSORIMPLEMSCRIPTEN_HPP
