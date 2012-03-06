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

#ifndef SFML_SPRITE_H
#define SFML_SPRITE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/BlendMode.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>


////////////////////////////////////////////////////////////
/// \brief Create a new sprite
///
/// \return A new sfSprite object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfSprite* sfSprite_Create(void);

////////////////////////////////////////////////////////////
/// \brief Copy an existing sprite
///
/// \param sprite Sprite to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfSprite* sfSprite_Copy(sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing sprite
///
/// \param sprite Sprite to delete
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_Destroy(sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Set the position of a sprite
///
/// This function completely overwrites the previous position.
/// See sfSprite_Move to apply an offset based on the previous position instead.
/// The default position of a sprite object is (0, 0).
///
/// \param sprite Sprite object
/// \param x      X coordinate of the new position
/// \param y      Y coordinate of the new position
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetPosition(sfSprite* sprite, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of a sprite
///
/// This function completely overwrites the previous rotation.
/// See sfSprite_Rotate to add an angle based on the previous rotation instead.
/// The default rotation of a sprite object is 0.
///
/// \param sprite Sprite object
/// \param angle  New rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetRotation(sfSprite* sprite, float angle);

////////////////////////////////////////////////////////////
/// \brief Set the scale factors of a sprite
///
/// This function completely overwrites the previous scale.
/// See sfSprite_Scale to add a factor based on the previous scale instead.
/// The default scale of a sprite object is (1, 1).
///
/// \param sprite  Sprite object
/// \param factorX New horizontal scale factor
/// \param factorY New vertical scale factor
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetScale(sfSprite* sprite, float factorX, float factorY);

////////////////////////////////////////////////////////////
/// \brief Set the local origin of a sprite
///
/// The origin of an object defines the center point for
/// all transformations (position, scale, rotation).
/// The coordinates of this point must be relative to the
/// top-left corner of the object, and ignore all
/// transformations (position, scale, rotation).
/// The default origin of a sprite object is (0, 0).
///
/// \param sprite Sprite object
/// \param x      X coordinate of the new origin
/// \param y      Y coordinate of the new origin
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetOrigin(sfSprite* sprite, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Get the position of a sprite
///
/// \param sprite Sprite object
///
/// \return Current position
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_GetPosition(const sfSprite* sprite, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the orientation of a sprite
///
/// The rotation is always in the range [0, 360].
///
/// \param sprite Sprite object
///
/// \return Current rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API float sfSprite_GetRotation(const sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Get the current scale of a sprite
///
/// \param sprite Sprite object
///
/// \return Current scale factors
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_GetScale(const sfSprite* sprite, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the local origin of a sprite
///
/// \param sprite Sprite object
///
/// \return Current origin
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_GetOrigin(const sfSprite* sprite, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Move a sprite by a given offset
///
/// This function adds to the current position of the object,
/// unlike sfSprite_SetPosition which overwrites it.
///
/// \param sprite  Sprite object
/// \param offsetX X offset
/// \param offsetY Y offset
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_Move(sfSprite* sprite, float offsetX, float offsetY);

////////////////////////////////////////////////////////////
/// \brief Rotate a sprite
///
/// This function adds to the current rotation of the object,
/// unlike sfSprite_SetRotation which overwrites it.
///
/// \param sprite Sprite object
/// \param angle  Angle of rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_Rotate(sfSprite* sprite, float angle);

////////////////////////////////////////////////////////////
/// \brief Scale a sprite
///
/// This function multiplies the current scale of the object,
/// unlike sfSprite_SetScale which overwrites it.
///
/// \param sprite  Sprite object
/// \param factorX Horizontal scale factor
/// \param factorY Vertical scale factor
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_Scale(sfSprite* sprite, float factorX, float factorY);

////////////////////////////////////////////////////////////
/// \brief Get the combined transform of a sprite
///
/// \param sprite Sprite object
///
/// \return Transform combining the position/rotation/scale/origin of the object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTransform* sfSprite_GetTransform(const sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Get the inverse of the combined transform of a sprite
///
/// \param sprite Sprite object
///
/// \return Inverse of the combined transformations applied to the object
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTransform* sfSprite_GetInverseTransform(const sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Change the source texture of a sprite
///
/// The \a texture argument refers to a texture that must
/// exist as long as the sprite uses it. Indeed, the sprite
/// doesn't store its own copy of the texture, but rather keeps
/// a pointer to the one that you passed to this function.
/// If the source texture is destroyed and the sprite tries to
/// use it, the behaviour is undefined.
/// If \a resetRect is true, the TextureRect property of
/// the sprite is automatically adjusted to the size of the new
/// texture. If it is false, the texture rect is left unchanged.
///
/// \param sprite    Sprite object
/// \param texture   New texture
/// \param resetRect Should the texture rect be reset to the size of the new texture?
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetTexture(sfSprite* sprite, const sfTexture* texture, sfBool resetRect);

////////////////////////////////////////////////////////////
/// \brief Set the sub-rectangle of the texture that a sprite will display
///
/// The texture rect is useful when you don't want to display
/// the whole texture, but rather a part of it.
/// By default, the texture rect covers the entire texture.
///
/// \param sprite    Sprite object
/// \param rectangle Rectangle defining the region of the texture to display
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetTextureRect(sfSprite* sprite, sfIntRect rectangle);

////////////////////////////////////////////////////////////
/// \brief Set the global color of a sprite
///
/// This color is modulated (multiplied) with the sprite's
/// texture. It can be used to colorize the sprite, or change
/// its global opacity.
/// By default, the sprite's color is opaque white.
///
/// \param sprite Sprite object
/// \param color  New color of the sprite
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API void sfSprite_SetColor(sfSprite* sprite, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Get the source texture of a sprite
///
/// If the sprite has no source texture, a NULL pointer is returned.
/// The returned pointer is const, which means that you can't
/// modify the texture when you retrieve it with this function.
///
/// \param sprite Sprite object
///
/// \return Pointer to the sprite's texture
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API const sfTexture* sfSprite_GetTexture(const sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Get the sub-rectangle of the texture displayed by a sprite
///
/// \param sprite Sprite object
///
/// \return Texture rectangle of the sprite
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfIntRect sfSprite_GetTextureRect(const sfSprite* sprite);

////////////////////////////////////////////////////////////
/// \brief Get the global color of a sprite
///
/// \param sprite Sprite object
///
/// \return Global color of the sprite
///
////////////////////////////////////////////////////////////
CSFML_GRAPHICS_API sfColor sfSprite_GetColor(const sfSprite* sprite);


#endif // SFML_SPRITE_H
