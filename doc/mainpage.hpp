////////////////////////////////////////////////////////////
/// \mainpage
///
/// \section welcome Welcome
/// Welcome to the official SFML documentation for C. Here you will find a detailed
/// view of all the SFML <a href="./globals_func.htm">functions</a>, as well as source
/// <a href="./files.htm">files</a>. <br/>
/// If you are looking for tutorials, you can visit the official website
/// at <a href="http://www.sfml-dev.org/tutorials/">www.sfml-dev.org</a>.
///
/// \section example Short example
/// Here is a short example, to show you how simple it is to use SFML in C :
///
/// \code
///
/// #include <SFML/Audio.h>
/// #include <SFML/Graphics.h>
/// 
/// int main()
/// {
///     sfVideoMode mode = {800, 600, 32};
///     sfRenderWindow* window;
///     sfTexture* texture;
///     sfSprite* sprite;
///     sfFont* font;
///     sfText* text;
///     sfMusic* music;
///     sfEvent event;
///
///     /* Create the main window */
///     window = sfRenderWindow_Create(mode, "SFML window", sfResize | sfClose, NULL);
///     if (!window)
///         return EXIT_FAILURE;
///
///     /* Load a sprite to display */
///     texture = sfTexture_CreateFromFile("cute_image.jpg");
///     if (!texture)
///         return EXIT_FAILURE;
///     sprite = sfSprite_Create();
///     sfSprite_SetTexture(sprite, texture, sfTrue);
/// 
///     /* Create a graphical text to display */
///     font = sfFont_CreateFromFile("arial.ttf");
///     if (!font)
///         return EXIT_FAILURE;
///     text = sfText_Create();
///     sfText_SetString(text, "Hello SFML");
///     sfText_SetFont(text, font);
///     sfText_SetCharacterSize(text, 50);
/// 
///     /* Load a music to play */
///     music = sfMusic_CreateFromFile("nice_music.ogg");
///     if (!music)
///         return EXIT_FAILURE;
///
///     /* Play the music */
///     sfMusic_Play(music);
/// 
///     /* Start the game loop */
///     while (sfRenderWindow_IsOpen(window))
///     {
///         /* Process events */
///         while (sfRenderWindow_PollEvent(window, &event))
///         {
///             /* Close window : exit */
///             if (event.Type == sfEvtClosed)
///                 sfRenderWindow_Close(window);
///         }
/// 
///         /* Clear the screen */
///         sfRenderWindow_Clear(window, sfBlack);
/// 
///         /* Draw the sprite */
///         sfRenderWindow_DrawSprite(window, sprite, NULL);
/// 
///         /* Draw the text */
///         sfRenderWindow_DrawText(window, text, NULL);
/// 
///         /* Update the window */
///         sfRenderWindow_Display(window);
///     }
/// 
///     /* Cleanup resources */
///     sfMusic_Destroy(music);
///     sfText_Destroy(text);
///     sfFont_Destroy(font);
///     sfSprite_Destroy(sprite);
///     sfTexture_Destroy(texture);
///     sfRenderWindow_Destroy(window);
/// 
///     return EXIT_SUCCESS;
/// }
/// \endcode
////////////////////////////////////////////////////////////
