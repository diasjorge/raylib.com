/*******************************************************************************************
*
*   raylib [models] example - Detect basic 3d collisions (box vs sphere vs box) (adapted for HTML5 platform)
*
*   This example has been created using raylib 1.3 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2015 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;


// Define the camera to look into our 3d world
Camera camera = {{ 0.0f, 10.0f, 10.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, 45.0f };

Vector3 playerPosition = { 0.0f, 1.0f, 2.0f };
Vector3 playerSize = { 1.0f, 2.0f, 1.0f };
Color playerColor = GREEN;

Vector3 enemyBoxPos = { -4.0f, 1.0f, 0.0f };
Vector3 enemyBoxSize = { 2.0f, 2.0f, 2.0f };

Vector3 enemySpherePos = { 4.0f, 0.0f, 0.0f };
float enemySphereSize = 1.5f;

bool collision = false;

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
    InitWindow(screenWidth, screenHeight, "raylib [models] example - box collisions");

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
    CloseWindow();        // Close window and OpenGL context
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

    // Move player
    if (IsKeyDown(KEY_RIGHT)) playerPosition.x += 0.2f;
    else if (IsKeyDown(KEY_LEFT)) playerPosition.x -= 0.2f;
    else if (IsKeyDown(KEY_DOWN)) playerPosition.z += 0.2f;
    else if (IsKeyDown(KEY_UP)) playerPosition.z -= 0.2f;

    collision = false;

    // Check collisions player vs enemy-box
    if (CheckCollisionBoxes(
        (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                 playerPosition.y - playerSize.y/2,
                                 playerPosition.z - playerSize.z/2 },
                      (Vector3){ playerPosition.x + playerSize.x/2,
                                 playerPosition.y + playerSize.y/2,
                                 playerPosition.z + playerSize.z/2 }},
        (BoundingBox){(Vector3){ enemyBoxPos.x - enemyBoxSize.x/2,
                                 enemyBoxPos.y - enemyBoxSize.y/2,
                                 enemyBoxPos.z - enemyBoxSize.z/2 },
                      (Vector3){ enemyBoxPos.x + enemyBoxSize.x/2,
                                 enemyBoxPos.y + enemyBoxSize.y/2,
                                 enemyBoxPos.z + enemyBoxSize.z/2 }})) collision = true;

    // Check collisions player vs enemy-sphere
    if (CheckCollisionBoxSphere(
        (BoundingBox){(Vector3){ playerPosition.x - playerSize.x/2,
                                 playerPosition.y - playerSize.y/2,
                                 playerPosition.z - playerSize.z/2 },
                      (Vector3){ playerPosition.x + playerSize.x/2,
                                 playerPosition.y + playerSize.y/2,
                                 playerPosition.z + playerSize.z/2 }},
        enemySpherePos, enemySphereSize)) collision = true;

    if (collision) playerColor = RED;
    else playerColor = GREEN;
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

            // Draw enemy-box
            DrawCube(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, GRAY);
            DrawCubeWires(enemyBoxPos, enemyBoxSize.x, enemyBoxSize.y, enemyBoxSize.z, DARKGRAY);

            // Draw enemy-sphere
            DrawSphere(enemySpherePos, enemySphereSize, GRAY);
            DrawSphereWires(enemySpherePos, enemySphereSize, 16, 16, DARKGRAY);

            // Draw player
            DrawCubeV(playerPosition, playerSize, playerColor);

            DrawGrid(10, 1.0f);        // Draw a grid

        EndMode3D();

        DrawText("Move player with cursors to collide", 220, 40, 20, GRAY);

        DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------

}