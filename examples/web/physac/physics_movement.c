/*******************************************************************************************
*
*   Physac - Physics movement
*
*   NOTE 1: Physac requires multi-threading, when InitPhysics() a second thread is created to manage physics calculations.
*   NOTE 2: Physac requires static C library linkage to avoid dependency on MinGW DLL (-static -lpthread)
*
*   Use the following line to compile:
*
*   gcc -o $(NAME_PART).exe $(FILE_NAME) -s $(RAYLIB_DIR)\raylib\raylib_icon -static -lraylib -lpthread
*   -lglfw3 -lopengl32 -lgdi32 -lopenal32 -lwinmm -std=c99 -Wl,--subsystem,windows -Wl,-allow-multiple-definition
*
*   Copyright (c) 2017 Victor Fisac
*
********************************************************************************************/

#include "raylib.h"

#define PHYSAC_IMPLEMENTATION
#include "physac.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#define VELOCITY    0.5f

//----------------------------------------------------------------------------------
// Global Variables Definition
//----------------------------------------------------------------------------------
const int screenWidth = 800;
const int screenHeight = 450;

// Physac logo drawing position
int logoX = 0;
int logoY = 15;

PhysicsBody body = { 0 };

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
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Physac [raylib] - Physics movement");

    // Physac logo drawing position
    logoX = screenWidth - MeasureText("Physac", 30) - 10;

    // Initialize physics and default physics bodies
    InitPhysics();

    // Create ground and walls rectangle physics body
    PhysicsBody ground = CreatePhysicsBodyRectangle((Vector2){ screenWidth/2, screenHeight }, screenWidth, 100, 10);
    PhysicsBody platformLeft = CreatePhysicsBodyRectangle((Vector2){ screenWidth*0.25f, screenHeight*0.6f }, screenWidth*0.25f, 10, 10);
    PhysicsBody platformRight = CreatePhysicsBodyRectangle((Vector2){ screenWidth*0.75f, screenHeight*0.6f }, screenWidth*0.25f, 10, 10);
    PhysicsBody wallLeft = CreatePhysicsBodyRectangle((Vector2){ -5, screenHeight/2 }, 10, screenHeight, 10);
    PhysicsBody wallRight = CreatePhysicsBodyRectangle((Vector2){ screenWidth + 5, screenHeight/2 }, 10, screenHeight, 10);

    // Disable dynamics to ground and walls physics bodies
    ground->enabled = false;
    platformLeft->enabled = false;
    platformRight->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;

    // Create movement physics body
    body = CreatePhysicsBodyRectangle((Vector2){ screenWidth/2, screenHeight/2 }, 50, 50, 1);
    body->freezeOrient = true;  // Constrain body rotation to avoid little collision torque amounts


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
    ClosePhysics();       // Uninitialize physics

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
    if (IsKeyPressed('R'))    // Reset physics input
    {
        // Reset movement physics body position, velocity and rotation
        body->position = (Vector2){ screenWidth/2, screenHeight/2 };
        body->velocity = (Vector2){ 0, 0 };
        SetPhysicsBodyRotation(body, 0);
    }

    // Horizontal movement input
    if (IsKeyDown(KEY_RIGHT)) body->velocity.x = VELOCITY;
    else if (IsKeyDown(KEY_LEFT)) body->velocity.x = -VELOCITY;

    // Vertical movement input checking if player physics body is grounded
    if (IsKeyDown(KEY_UP) && body->isGrounded) body->velocity.y = -VELOCITY*4;
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(BLACK);

        DrawFPS(screenWidth - 90, screenHeight - 30);

        // Draw created physics bodies
        int bodiesCount = GetPhysicsBodiesCount();
        for (int i = 0; i < bodiesCount; i++)
        {
            PhysicsBody body = GetPhysicsBody(i);

            int vertexCount = GetPhysicsShapeVerticesCount(i);
            for (int j = 0; j < vertexCount; j++)
            {
                // Get physics bodies shape vertices to draw lines
                // Note: GetPhysicsShapeVertex() already calculates rotation transformations
                Vector2 vertexA = GetPhysicsShapeVertex(body, j);

                int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);   // Get next vertex or first to close the shape
                Vector2 vertexB = GetPhysicsShapeVertex(body, jj);

                DrawLineV(vertexA, vertexB, GREEN);     // Draw a line between two vertex positions
            }
        }

        DrawText("Use 'ARROWS' to move player", 10, 10, 10, WHITE);
        DrawText("Press 'R' to reset example", 10, 30, 10, WHITE);

        DrawText("Physac", logoX, logoY, 30, WHITE);
        DrawText("Powered by", logoX + 50, logoY - 7, 10, WHITE);

    EndDrawing();
    //----------------------------------------------------------------------------------
}

