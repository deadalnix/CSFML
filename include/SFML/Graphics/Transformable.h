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

#ifndef SFML_TRANSFORMABLE_H
#define SFML_TRANSFORMABLE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Types.h>


////////////////////////////////////////////////////////////
/// \brief Create a new transformable
///
/// \return A new sfTransformable object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransformable* sfTransformable_Create(void);

////////////////////////////////////////////////////////////
/// \brief Copy an existing transformable
///
/// \param transformable Transformable to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransformable* sfTransformable_Copy(sfTransformable* transformable);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing transformable
///
/// \param transformable Transformable to delete
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_Destroy(sfTransformable* transformable);

////////////////////////////////////////////////////////////
/// \brief Set the position of a transformable
///
/// This function completely overwrites the previous position.
/// See sfTransformable_Move to apply an offset based on the previous position instead.
/// The default position of a transformable object is (0, 0).
///
/// \param transformable Transformable object
/// \param x             X coordinate of the new position
/// \param y             Y coordinate of the new position
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_SetPosition(sfTransformable* transformable, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of a transformable
///
/// This function completely overwrites the previous rotation.
/// See sfTransformable_Rotate to add an angle based on the previous rotation instead.
/// The default rotation of a transformable object is 0.
///
/// \param transformable Transformable object
/// \param angle         New rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_SetRotation(sfTransformable* transformable, float angle);

////////////////////////////////////////////////////////////
/// \brief Set the scale factors of a transformable
///
/// This function completely overwrites the previous scale.
/// See sfTransformable_Scale to add a factor based on the previous scale instead.
/// The default scale of a transformable object is (1, 1).
///
/// \param transformable Transformable object
/// \param factorX       New horizontal scale factor
/// \param factorY       New vertical scale factor
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_SetScale(sfTransformable* transformable, float factorX, float factorY);

////////////////////////////////////////////////////////////
/// \brief Set the local origin of a transformable
///
/// The origin of an object defines the center point for
/// all transformations (position, scale, rotation).
/// The coordinates of this point must be relative to the
/// top-left corner of the object, and ignore all
/// transformations (position, scale, rotation).
/// The default origin of a transformable object is (0, 0).
///
/// \param transformable Transformable object
/// \param x             X coordinate of the new origin
/// \param y             Y coordinate of the new origin
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_SetOrigin(sfTransformable* transformable, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Get the position of a transformable
///
/// \param transformable Transformable object
///
/// \return Current position
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_GetPosition(const sfTransformable* transformable, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the orientation of a transformable
///
/// The rotation is always in the range [0, 360].
///
/// \param transformable Transformable object
///
/// \return Current rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API float sfTransformable_GetRotation(const sfTransformable* transformable);

////////////////////////////////////////////////////////////
/// \brief Get the current scale of a transformable
///
/// \param transformable Transformable object
///
/// \return Current scale factors
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_GetScale(const sfTransformable* transformable, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the local origin of a transformable
///
/// \param transformable Transformable object
///
/// \return Current origin
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_GetOrigin(const sfTransformable* transformable, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Move a transformable by a given offset
///
/// This function adds to the current position of the object,
/// unlike sfTransformable_SetPosition which overwrites it.
///
/// \param transformable Transformable object
/// \param offsetX       X offset
/// \param offsetY       Y offset
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_Move(sfTransformable* transformable, float offsetX, float offsetY);

////////////////////////////////////////////////////////////
/// \brief Rotate a transformable
///
/// This function adds to the current rotation of the object,
/// unlike sfTransformable_SetRotation which overwrites it.
///
/// \param transformable Transformable object
/// \param angle         Angle of rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_Rotate(sfTransformable* transformable, float angle);

////////////////////////////////////////////////////////////
/// \brief Scale a transformable
///
/// This function multiplies the current scale of the object,
/// unlike sfTransformable_SetScale which overwrites it.
///
/// \param transformable Transformable object
/// \param factorX       Horizontal scale factor
/// \param factorY       Vertical scale factor
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransformable_Scale(sfTransformable* transformable, float factorX, float factorY);

////////////////////////////////////////////////////////////
/// \brief Get the combined transform of a transformable
///
/// \param transformable Transformable object
///
/// \return Transform combining the position/rotation/scale/origin of the object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTransform* sfTransformable_GetTransform(const sfTransformable* transformable);

////////////////////////////////////////////////////////////
/// \brief Get the inverse of the combined transform of a transformable
///
/// \param transformable Transformable object
///
/// \return Inverse of the combined transformations applied to the object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTransform* sfTransformable_GetInverseTransform(const sfTransformable* transformable);


#endif // SFML_TRANSFORMABLE_H
