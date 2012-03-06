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

#ifndef SFML_MUSIC_H
#define SFML_MUSIC_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <stddef.h>


////////////////////////////////////////////////////////////
/// \brief Create a new music and load it from a file
///
/// This function doesn't start playing the music (call
/// sfMusic_Play to do so).
/// Here is a complete list of all the supported audio formats:
/// ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
/// w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
///
/// \param filename Path of the music file to open
///
/// \return A new sfMusic object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_API sfMusic* sfMusic_CreateFromFile(const char* filename);

////////////////////////////////////////////////////////////
/// \brief Create a new music and load it from a file in memory
///
/// This function doesn't start playing the music (call
/// sfMusic_Play to do so).
/// Here is a complete list of all the supported audio formats:
/// ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
/// w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
///
/// \param data        Pointer to the file data in memory
/// \param sizeInBytes Size of the data to load, in bytes
///
/// \return A new sfMusic object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_API sfMusic* sfMusic_CreateFromMemory(const void* data, size_t sizeInBytes);

////////////////////////////////////////////////////////////
/// \brief Create a new music and load it from a custom stream
///
/// This function doesn't start playing the music (call
/// sfMusic_Play to do so).
/// Here is a complete list of all the supported audio formats:
/// ogg, wav, flac, aiff, au, raw, paf, svx, nist, voc, ircam,
/// w64, mat4, mat5 pvf, htk, sds, avr, sd2, caf, wve, mpc2k, rf64.
///
/// \param stream Source stream to read from
///
/// \return A new sfMusic object (NULL if failed)
///
////////////////////////////////////////////////////////////
CSFML_API sfMusic* sfMusic_CreateFromStream(sfInputStream* stream);

////////////////////////////////////////////////////////////
/// \brief Destroy a music
///
/// \param music Music to destroy
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_Destroy(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Set whether or not a music should loop after reaching the end
///
/// If set, the music will restart from beginning after
/// reaching the end and so on, until it is stopped or
/// sfMusic_SetLoop(music, sfFalse) is called.
/// The default looping state for musics is false.
///
/// \param music Music object
/// \param loop  sfTrue to play in loop, sfFalse to play once
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetLoop(sfMusic* music, sfBool loop);

////////////////////////////////////////////////////////////
/// \brief Tell whether or not a music is in loop mode
///
/// \param music Music object
///
/// \return sfTrue if the music is looping, sfFalse otherwise
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfMusic_GetLoop(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the total duration of a music
///
/// \param music Music object
///
/// \return Music duration
///
////////////////////////////////////////////////////////////
CSFML_API sfTime sfMusic_GetDuration(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Start or resume playing a music
///
/// This function starts the music if it was stopped, resumes
/// it if it was paused, and restarts it from beginning if it
/// was it already playing.
/// This function uses its own thread so that it doesn't block
/// the rest of the program while the music is played.
///
/// \param music Music object
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_Play(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Pause a music
///
/// This function pauses the music if it was playing,
/// otherwise (music already paused or stopped) it has no effect.
///
/// \param music Music object
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_Pause(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Stop playing a music
///
/// This function stops the music if it was playing or paused,
/// and does nothing if it was already stopped.
/// It also resets the playing position (unlike sfMusic_Pause).
///
/// \param music Music object
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_Stop(sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Return the number of channels of a music
///
/// 1 channel means a mono sound, 2 means stereo, etc.
///
/// \param music Music object
///
/// \return Number of channels
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfMusic_GetChannelCount(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the sample rate of a music
///
/// The sample rate is the number of audio samples played per
/// second. The higher, the better the quality.
///
/// \param music Music object
///
/// \return Sample rate, in number of samples per second
///
////////////////////////////////////////////////////////////
CSFML_API unsigned int sfMusic_GetSampleRate(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the current status of a music (stopped, paused, playing)
///
/// \param music Music object
///
/// \return Current status
///
////////////////////////////////////////////////////////////
CSFML_API sfSoundStatus sfMusic_GetStatus(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the current playing position of a music
///
/// \param music Music object
///
/// \return Current playing position
///
////////////////////////////////////////////////////////////
CSFML_API sfTime sfMusic_GetPlayingOffset(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Set the pitch of a music
///
/// The pitch represents the perceived fundamental frequency
/// of a sound; thus you can make a music more acute or grave
/// by changing its pitch. A side effect of changing the pitch
/// is to modify the playing speed of the music as well.
/// The default value for the pitch is 1.
///
/// \param music Music object
/// \param pitch New pitch to apply to the music
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetPitch(sfMusic* music, float pitch);

////////////////////////////////////////////////////////////
/// \brief Set the volume of a music
///
/// The volume is a value between 0 (mute) and 100 (full volume).
/// The default value for the volume is 100.
///
/// \param music  Music object
/// \param volume Volume of the music
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetVolume(sfMusic* music, float volume);

////////////////////////////////////////////////////////////
/// \brief Set the 3D position of a music in the audio scene
///
/// Only musics with one channel (mono musics) can be
/// spatialized.
/// The default position of a music is (0, 0, 0).
///
/// \param music Music object
/// \param x     X coordinate of the position of the music in the scene
/// \param y     Y coordinate of the position of the music in the scene
/// \param z     Z coordinate of the position of the music in the scene
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetPosition(sfMusic* music, float x, float y, float z);

////////////////////////////////////////////////////////////
/// \brief Make a musics's position relative to the listener or absolute
///
/// Making a music relative to the listener will ensure that it will always
/// be played the same way regardless the position of the listener.
/// This can be useful for non-spatialized musics, musics that are
/// produced by the listener, or musics attached to it.
/// The default value is false (position is absolute).
///
/// \param music    Music object
/// \param relative sfTrue to set the position relative, sfFalse to set it absolute
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetRelativeToListener(sfMusic* music, sfBool relative);

////////////////////////////////////////////////////////////
/// \brief Set the minimum distance of a music
///
/// The "minimum distance" of a music is the maximum
/// distance at which it is heard at its maximum volume. Further
/// than the minimum distance, it will start to fade out according
/// to its attenuation factor. A value of 0 ("inside the head
/// of the listener") is an invalid value and is forbidden.
/// The default value of the minimum distance is 1.
///
/// \param music    Music object
/// \param distance New minimum distance of the music
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetMinDistance(sfMusic* music, float distance);

////////////////////////////////////////////////////////////
/// \brief Set the attenuation factor of a music
///
/// The attenuation is a multiplicative factor which makes
/// the music more or less loud according to its distance
/// from the listener. An attenuation of 0 will produce a
/// non-attenuated music, i.e. its volume will always be the same
/// whether it is heard from near or from far. On the other hand,
/// an attenuation value such as 100 will make the music fade out
/// very quickly as it gets further from the listener.
/// The default value of the attenuation is 1.
///
/// \param music       Music object
/// \param attenuation New attenuation factor of the music
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetAttenuation(sfMusic* music, float attenuation);

////////////////////////////////////////////////////////////
/// \brief Change the current playing position of a music
///
/// The playing position can be changed when the music is
/// either paused or playing.
///
/// \param music      Music object
/// \param timeOffset New playing position, in milliseconds
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_SetPlayingOffset(sfMusic* music, sfUint32 timeOffset);

////////////////////////////////////////////////////////////
/// \brief Get the pitch of a music
///
/// \param music Music object
///
/// \return Pitch of the music
///
////////////////////////////////////////////////////////////
CSFML_API float sfMusic_GetPitch(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the volume of a music
///
/// \param music Music object
///
/// \return Volume of the music, in the range [0, 100]
///
////////////////////////////////////////////////////////////
CSFML_API float sfMusic_GetVolume(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the 3D position of a music in the audio scene
///
/// \param music Music object
/// \param x     X position of the music in the world
/// \param y     Y position of the music in the world
/// \param z     Z position of the music in the world
///
////////////////////////////////////////////////////////////
CSFML_API void sfMusic_GetPosition(const sfMusic* music, float* x, float* y, float* z);

////////////////////////////////////////////////////////////
/// \brief Tell whether a music's position is relative to the
///        listener or is absolute
///
/// \param music Music object
///
/// \return sfTrue if the position is relative, sfFalse if it's absolute
///
////////////////////////////////////////////////////////////
CSFML_API sfBool sfMusic_IsRelativeToListener(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the minimum distance of a music
///
/// \param music Music object
///
/// \return Minimum distance of the music
///
////////////////////////////////////////////////////////////
CSFML_API float sfMusic_GetMinDistance(const sfMusic* music);

////////////////////////////////////////////////////////////
/// \brief Get the attenuation factor of a music
///
/// \param music Music object
///
/// \return Attenuation factor of the music
///
////////////////////////////////////////////////////////////
CSFML_API float sfMusic_GetAttenuation(const sfMusic* music);


#endif // SFML_MUSIC_H
