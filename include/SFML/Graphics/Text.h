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

#ifndef SFML_TEXT_H
#define SFML_TEXT_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// sfText styles
////////////////////////////////////////////////////////////
typedef enum
{
    sfTextRegular    = 0,      ///< Regular characters, no style
    sfTextBold       = 1 << 0, ///< Characters are bold
    sfTextItalic     = 1 << 1, ///< Characters are in italic
    sfTextUnderlined = 1 << 2  ///< Characters are underlined
} sfTextStyle;


////////////////////////////////////////////////////////////
/// \brief Create a new text
///
/// \return A new sfText object, or NULL if it failed
///
////////////////////////////////////////////////////////////
CSFML_API sfText* sfText_Create(void);

////////////////////////////////////////////////////////////
/// \brief Copy an existing text
///
/// \param text Text to copy
///
/// \return Copied object
///
////////////////////////////////////////////////////////////
CSFML_API sfText* sfText_Copy(sfText* text);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing text
///
/// \param text Text to delete
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_Destroy(sfText* text);

////////////////////////////////////////////////////////////
/// \brief Set the position of a text
///
/// This function completely overwrites the previous position.
/// See sfText_Move to apply an offset based on the previous position instead.
/// The default position of a text object is (0, 0).
///
/// \param text Text object
/// \param x    X coordinate of the new position
/// \param y    Y coordinate of the new position
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetPosition(sfText* text, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of a text
///
/// This function completely overwrites the previous rotation.
/// See sfText_Rotate to add an angle based on the previous rotation instead.
/// The default rotation of a text object is 0.
///
/// \param text  Text object
/// \param angle New rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetRotation(sfText* text, float angle);

////////////////////////////////////////////////////////////
/// \brief Set the scale factors of a text
///
/// This function completely overwrites the previous scale.
/// See sfText_Scale to add a factor based on the previous scale instead.
/// The default scale of a text object is (1, 1).
///
/// \param text    Text object
/// \param factorX New horizontal scale factor
/// \param factorY New vertical scale factor
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetScale(sfText* text, float factorX, float factorY);

////////////////////////////////////////////////////////////
/// \brief Set the local origin of a text
///
/// The origin of an object defines the center point for
/// all transformations (position, scale, rotation).
/// The coordinates of this point must be relative to the
/// top-left corner of the object, and ignore all
/// transformations (position, scale, rotation).
/// The default origin of a text object is (0, 0).
///
/// \param text Text object
/// \param x    X coordinate of the new origin
/// \param y    Y coordinate of the new origin
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetOrigin(sfText* text, float x, float y);

////////////////////////////////////////////////////////////
/// \brief Get the position of a text
///
/// \param text Text object
///
/// \return Current position
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_GetPosition(const sfText* text, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the orientation of a text
///
/// The rotation is always in the range [0, 360].
///
/// \param text Text object
///
/// \return Current rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_API float sfText_GetRotation(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the current scale of a text
///
/// \param text Text object
///
/// \return Current scale factors
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_GetScale(const sfText* text, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Get the local origin of a text
///
/// \param text Text object
///
/// \return Current origin
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_GetOrigin(const sfText* text, float* x, float* y);

////////////////////////////////////////////////////////////
/// \brief Move a text by a given offset
///
/// This function adds to the current position of the object,
/// unlike sfText_SetPosition which overwrites it.
///
/// \param text    Text object
/// \param offsetX X offset
/// \param offsetY Y offset
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_Move(sfText* text, float offsetX, float offsetY);

////////////////////////////////////////////////////////////
/// \brief Rotate a text
///
/// This function adds to the current rotation of the object,
/// unlike sfText_SetRotation which overwrites it.
///
/// \param text  Text object
/// \param angle Angle of rotation, in degrees
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_Rotate(sfText* text, float angle);

////////////////////////////////////////////////////////////
/// \brief Scale a text
///
/// This function multiplies the current scale of the object,
/// unlike sfText_SetScale which overwrites it.
///
/// \param text    Text object
/// \param factorX Horizontal scale factor
/// \param factorY Vertical scale factor
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_Scale(sfText* text, float factorX, float factorY);

////////////////////////////////////////////////////////////
/// \brief Get the combined transform of a text
///
/// \param text Text object
///
/// \return Transform combining the position/rotation/scale/origin of the object
///
////////////////////////////////////////////////////////////
CSFML_API const sfTransform* sfText_GetTransform(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the inverse of the combined transform of a text
///
/// \param text Text object
///
/// \return Inverse of the combined transformations applied to the object
///
////////////////////////////////////////////////////////////
CSFML_API const sfTransform* sfText_GetInverseTransform(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Set the string of a text (from an ANSI string)
///
/// A text's string is empty by default.
///
/// \param text   Text object
/// \param string New string
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetString(sfText* text, const char* string);

////////////////////////////////////////////////////////////
/// \brief Set the string of a text (from a unicode string)
///
/// \param text   Text object
/// \param string New string
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetUnicodeString(sfText* text, const sfUint32* string);

////////////////////////////////////////////////////////////
/// \brief Set the font of a text
///
/// The \a font argument refers to a texture that must
/// exist as long as the text uses it. Indeed, the text
/// doesn't store its own copy of the font, but rather keeps
/// a pointer to the one that you passed to this function.
/// If the font is destroyed and the text tries to
/// use it, the behaviour is undefined.
/// Texts have a valid font by default, which the built-in
/// sfFont_GetDefaultFont().
///
/// \param text Text object
/// \param font New font
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetFont(sfText* text, const sfFont* font);

////////////////////////////////////////////////////////////
/// \brief Set the character size of a text
///
/// The default size is 30.
///
/// \param text Text object
/// \param size New character size, in pixels
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetCharacterSize(sfText* text, unsigned int size);

////////////////////////////////////////////////////////////
/// \brief Set the style of a text
///
/// You can pass a combination of one or more styles, for
/// example sfTextBold | sfTextItalic.
/// The default style is sfTextRegular.
///
/// \param text  Text object
/// \param style New style
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetStyle(sfText* text, sfUint32 style);

////////////////////////////////////////////////////////////
/// \brief Set the global color of a text
///
/// By default, the text's color is opaque white.
///
/// \param text  Text object
/// \param color New color of the text
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_SetColor(sfText* text, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Get the text of a text (returns an ANSI string)
///
/// \param text Text object
///
/// \return String an a locale-dependant ANSI string
///
////////////////////////////////////////////////////////////
CSFML_API const char* sfText_GetString(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the string of a text (returns a unicode string)
///
/// \param text Text object
///
/// \return String as UTF-32
///
////////////////////////////////////////////////////////////
CSFML_API const sfUint32* sfText_GetUnicodeString(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the font used by a text
///
/// \param text Text object
///
/// \return Pointer to the font
///
////////////////////////////////////////////////////////////
CSFML_API const sfFont* sfText_GetFont(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the size of the characters of a text
///
/// \param text Text object
///
/// \return Size of the characters
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfText_GetCharacterSize(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the style of a text
///
/// \param text Text object
///
/// \return Current string style (see sfTextStyle enum)
///
////////////////////////////////////////////////////////////
CSFML_API sfUint32 sfText_GetStyle(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Get the global color of a text
///
/// \param text Text object
///
/// \return Global color of the text
///
////////////////////////////////////////////////////////////
CSFML_API sfColor sfText_GetColor(const sfText* text);

////////////////////////////////////////////////////////////
/// \brief Return the position of the \a index-th character in a text
///
/// This function computes the visual position of a character
/// from its index in the string. The returned position is
/// in global coordinates (translation, rotation, scale and
/// origin are applied).
/// If \a index is out of range, the position of the end of
/// the string is returned.
///
/// \param text  Text object
/// \param index Index of the character
/// \param x     The returned x position of the character
/// \param y     The returned y position of the character
///
////////////////////////////////////////////////////////////
CSFML_API void sfText_FindCharacterPos(const sfText* text, size_t index, float* x, float* y);


#endif // SFML_TEXT_H
