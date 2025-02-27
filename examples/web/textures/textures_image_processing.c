/*******************************************************************************************
*
*   raylib [textures] example - Image processing
*
*   NOTE: Images are loaded in CPU memory (RAM); textures are loaded in GPU memory (VRAM)
*
*   This example has been created using raylib 1.4 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#include <stdlib.h>     // Required for: free()

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#define NUM_PROCESSES    8

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;

typedef enum {
    NONE = 0,
    COLOR_GRAYSCALE,
    COLOR_TINT,
    COLOR_INVERT,
    COLOR_CONTRAST,
    COLOR_BRIGHTNESS,
    FLIP_VERTICAL,
    FLIP_HORIZONTAL
} ImageProcess;

static const char *processText[] = {
    "NO PROCESSING",
    "COLOR GRAYSCALE",
    "COLOR TINT",
    "COLOR INVERT",
    "COLOR CONTRAST",
    "COLOR BRIGHTNESS",
    "FLIP VERTICAL",
    "FLIP HORIZONTAL"
};

Image image = { 0 };
Texture2D texture = { 0 };

int currentProcess = NONE;
bool textureReload = false;

Rectangle selectRecs[NUM_PROCESSES] = { 0 };

//----------------------------------------------------------------------------------
// Module Functions Declaration
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void);     // Update and Draw one frame

//----------------------------------------------------------------------------------
// Program Main Entry Point
//----------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "raylib [textures] example - image processing");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)

    image = LoadImage("resources/parrots.png");   // Loaded in CPU memory (RAM)
    ImageFormat(&image, UNCOMPRESSED_R8G8B8A8);   // Format image to RGBA 32bit (required for texture update)
    texture = LoadTextureFromImage(image);        // Image converted to texture, GPU memory (VRAM)

    for (int i = 0; i < NUM_PROCESSES; i++) selectRecs[i] = (Rectangle){ 40, 50 + 32*i, 150, 30 };

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateDrawFrame();
    }
#endif

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);       // Unload texture from VRAM
    UnloadImage(image);           // Unload image from RAM

    CloseWindow();                // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module Functions Definition
//----------------------------------------------------------------------------------
void UpdateDrawFrame(void)
{
    // Update
    //----------------------------------------------------------------------------------
    if (IsKeyPressed(KEY_DOWN))
    {
        currentProcess++;
        if (currentProcess > 7) currentProcess = 0;
        textureReload = true;
    }
    else if (IsKeyPressed(KEY_UP))
    {
        currentProcess--;
        if (currentProcess < 0) currentProcess = 7;
        textureReload = true;
    }

    if (textureReload)
    {
        UnloadImage(image);                         // Unload current image data
        image = LoadImage("resources/parrots.png"); // Re-load image data

        // NOTE: Image processing is a costly CPU process to be done every frame,
        // If image processing is required in a frame-basis, it should be done
        // with a texture and by shaders
        switch (currentProcess)
        {
            case COLOR_GRAYSCALE: ImageColorGrayscale(&image); break;
            case COLOR_TINT: ImageColorTint(&image, GREEN); break;
            case COLOR_INVERT: ImageColorInvert(&image); break;
            case COLOR_CONTRAST: ImageColorContrast(&image, -40); break;
            case COLOR_BRIGHTNESS: ImageColorBrightness(&image, -80); break;
            case FLIP_VERTICAL: ImageFlipVertical(&image); break;
            case FLIP_HORIZONTAL: ImageFlipHorizontal(&image); break;
            default: break;
        }

        Color *pixels = GetImageData(image);        // Get pixel data from image (RGBA 32bit)
        UpdateTexture(texture, pixels);             // Update texture with new image data
        free(pixels);                               // Unload pixels data from RAM

        textureReload = false;
    }
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("IMAGE PROCESSING:", 40, 30, 10, DARKGRAY);

        // Draw rectangles
        for (int i = 0; i < NUM_PROCESSES; i++)
        {
            if (i == currentProcess)
            {
                DrawRectangleRec(selectRecs[i], SKYBLUE);
                DrawRectangleLines(selectRecs[i].x, selectRecs[i].y, selectRecs[i].width, selectRecs[i].height, BLUE);
                DrawText(processText[i], selectRecs[i].x + selectRecs[i].width/2 - MeasureText(processText[i], 10)/2, selectRecs[i].y + 11, 10, DARKBLUE);
            }
            else
            {
                DrawRectangleRec(selectRecs[i], LIGHTGRAY);
                DrawRectangleLines(selectRecs[i].x, selectRecs[i].y, selectRecs[i].width, selectRecs[i].height, GRAY);
                DrawText(processText[i], selectRecs[i].x + selectRecs[i].width/2 - MeasureText(processText[i], 10)/2, selectRecs[i].y + 11, 10, DARKGRAY);
            }
        }

        DrawTexture(texture, screenWidth - texture.width - 60, screenHeight/2 - texture.height/2, WHITE);
        DrawRectangleLines(screenWidth - texture.width - 60, screenHeight/2 - texture.height/2, texture.width, texture.height, BLACK);

    EndDrawing();
    //----------------------------------------------------------------------------------
}