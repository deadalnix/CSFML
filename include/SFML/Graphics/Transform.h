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

#ifndef SFML_TRANSFORM_H
#define SFML_TRANSFORM_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>


////////////////////////////////////////////////////////////
/// \brief Create a new transform
///
/// This function creates an identity transform.
///
/// \return A new sfTransform object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransform* sfTransform_Create(void);

////////////////////////////////////////////////////////////
/// \brief Create a new transform from a matrix
///
/// \param a00 Element (0, 0) of the matrix
/// \param a01 Element (0, 1) of the matrix
/// \param a02 Element (0, 2) of the matrix
/// \param a10 Element (1, 0) of the matrix
/// \param a11 Element (1, 1) of the matrix
/// \param a12 Element (1, 2) of the matrix
/// \param a20 Element (2, 0) of the matrix
/// \param a21 Element (2, 1) of the matrix
/// \param a22 Element (2, 2) of the matrix
///
/// \return A new sfTransform object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransform* sfTransform_CreateFromMatrix(float a00, float a01, float a02,
                                                    float a10, float a11, float a12,
                                                    float a20, float a21, float a22);

////////////////////////////////////////////////////////////
/// \brief Copy an existing transform
///
/// \param transform Transform to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfTransform* sfTransform_Copy(sfTransform* transform);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing transform
///
/// \param transform Transform to delete
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_Destroy(sfTransform* transform);

////////////////////////////////////////////////////////////
/// \brief Return the 4x4 matrix of a transform
///
/// This function returns a pointer to an array of 16 floats
/// containing the transform elements as a 4x4 matrix, which
/// is directly compatible with OpenGL functions.
///
/// \code
/// sfTransform* transform = ...;
/// glLoadMatrixf(sfTransform_GetMatrix(transform));
/// \endcode
///
/// \param transform Transform object
///
/// \return Pointer to a 4x4 matrix
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const float* sfTransform_GetMatrix(const sfTransform* transform);

////////////////////////////////////////////////////////////
/// \brief Return the inverse of a transform
///
/// If the inverse cannot be computed, a new identity transform
/// is returned.
///
/// \param transform Transform object
/// \param result Returned inverse matrix
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_GetInverse(const sfTransform* transform, sfTransform* result);

////////////////////////////////////////////////////////////
/// \brief Apply a transform to a 2D point
///
/// \param transform    Transform object
/// \param x            X coordinate of the point to transform
/// \param y            Y coordinate of the point to transform
/// \param transformedX X coordinate of the transformed point
/// \param transformedY Y coordinate of the transformed point
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_TransformPoint(const sfTransform* transform, float x, float y, float* transformedX, float* transformedY);

////////////////////////////////////////////////////////////
/// \brief Apply a transform to a rectangle
///
/// Since SFML doesn't provide support for oriented rectangles,
/// the result of this function is always an axis-aligned
/// rectangle. Which means that if the transform contains a
/// rotation, the bounding rectangle of the transformed rectangle
/// is returned.
///
/// \param transform            Transform object
/// \param rectangle            Rectangle to transform
/// \param transformedRectangle Transformed rectangle
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_TransformRect(const sfTransform* transform, sfFloatRect rectangle, sfFloatRect* transformedRectangle);

////////////////////////////////////////////////////////////
/// \brief Combine two transforms
///
/// The result is a transform that is equivalent to applying
/// \a transform followed by \a other. Mathematically, it is
/// equivalent to a matrix multiplication.
///
/// \param transform Transform object
/// \param right     Transform to combine to \a transform
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_Combine(sfTransform* transform, const sfTransform* other);

////////////////////////////////////////////////////////////
/// \brief Combine a transform with a translation
///
/// \param transform Transform object
/// \param x         Offset to apply on X axis
/// \param y         Offset to apply on Y axis
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_Translate(sfTransform* transform, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Combine the current transform with a rotation
///
/// \param transform Transform object
/// \param angle     Rotation angle, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_Rotate(sfTransform* transform, float angle);

////////////////////////////////////////////////////////////
/// \brief Combine the current transform with a rotation
///
/// The center of rotation is provided for convenience as a second
/// argument, so that you can build rotations around arbitrary points
/// more easily (and efficiently) than the usual
/// [Translate(-center), Rotate(angle), Translate(center)].
///
/// \param transform Transform object
/// \param angle     Rotation angle, in degrees
/// \param centerX   X coordinate of the center of rotation
/// \param centerY   Y coordinate of the center of rotation
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_RotateWithCenter(sfTransform* transform, float angle, float centerX, float centerY);

////////////////////////////////////////////////////////////
/// \brief Combine the current transform with a scaling
///
/// \param transform Transform object
/// \param scaleX    Scaling factor on the X axis
/// \param scaleY    Scaling factor on the Y axis
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_Scale(sfTransform* transform, float scaleX, float scaleY);

////////////////////////////////////////////////////////////
/// \brief Combine the current transform with a scaling
///
/// The center of scaling is provided for convenience as a second
/// argument, so that you can build scaling around arbitrary points
/// more easily (and efficiently) than the usual
/// [Translate(-center), Scale(factors), Translate(center)]
///
/// \param transform Transform object
/// \param scaleX    Scaling factor on X axis
/// \param scaleY    Scaling factor on Y axis
/// \param centerX   X coordinate of the center of scaling
/// \param centerY   Y coordinate of the center of scaling
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfTransform_ScaleWithCenter(sfTransform* transform, float scaleX, float scaleY, float centerX, float centerY);


#endif // SFML_TRANSFORM_H
