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

#include <SFML/Window/SensorImpl.hpp>

namespace sf
{
namespace priv
{

void SensorImpl::initialize()
{
    // No actual initialization needed for the stub
}

void SensorImpl::cleanup()
{
    // No cleanup needed for the stub
}

bool SensorImpl::isAvailable(Sensor::Type /*sensor*/)
{
    // Always return false for now
    return false;
}

bool SensorImpl::open(Sensor::Type /*sensor*/)
{
    // Return true just for it to compile, no real implementation
    m_sensor = nullptr;
    m_index = 0;
    return true;
}

void SensorImpl::close()
{
    // No action needed
}

Vector3f SensorImpl::update()
{
    // Return a default vector
    return Vector3f(0, 0, 0);
}

void SensorImpl::setEnabled(bool /*enabled*/)
{
    // No action needed
}

const ASensor* SensorImpl::getDefaultSensor(Sensor::Type /*sensor*/)
{
    // Return nullptr for now
    return nullptr;
}

int SensorImpl::processSensorEvents(int /*fd*/, int /*events*/, void* /*data*/)
{
    // Just return 1 to indicate we continue
    return 1;
}

} // namespace priv
} // namespace sf
