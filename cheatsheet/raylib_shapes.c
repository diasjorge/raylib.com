
    // Basic shapes drawing functions
    void DrawPixel(int posX, int posY, Color color);                                                    // Draw a pixel
    void DrawPixelV(Vector2 position, Color color);                                                     // Draw a pixel (Vector version)
    void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color);                 // Draw a line
    void DrawLineV(Vector2 startPos, Vector2 endPos, Color color);                                      // Draw a line (Vector version)
    void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color);                        // Draw a line defining thickness
    void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color);                    // Draw a line using cubic-bezier curves in-out
    void DrawCircle(int centerX, int centerY, float radius, Color color);                               // Draw a color-filled circle
    void DrawCircleSector(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color);      // Draw a piece of a circle
    void DrawCircleSectorLines(Vector2 center, float radius, int startAngle, int endAngle, int segments, Color color); // Draw circle sector outline
    void DrawCircleGradient(int centerX, int centerY, float radius, Color color1, Color color2);        // Draw a gradient-filled circle
    void DrawCircleV(Vector2 center, float radius, Color color);                                        // Draw a color-filled circle (Vector version)
    void DrawCircleLines(int centerX, int centerY, float radius, Color color);                          // Draw circle outline
    void DrawRing(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color);      // Draw ring
    void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, int startAngle, int endAngle, int segments, Color color); // Draw ring outline
    void DrawRectangle(int posX, int posY, int width, int height, Color color);                         // Draw a color-filled rectangle
    void DrawRectangleV(Vector2 position, Vector2 size, Color color);                                   // Draw a color-filled rectangle (Vector version)
    void DrawRectangleRec(Rectangle rec, Color color);                                                  // Draw a color-filled rectangle
    void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);                  // Draw a color-filled rectangle with pro parameters
    void DrawRectangleGradientV(int posX, int posY, int width, int height, Color color1, Color color2); // Draw a vertical-gradient-filled rectangle
    void DrawRectangleGradientH(int posX, int posY, int width, int height, Color color1, Color color2); // Draw a horizontal-gradient-filled rectangle
    void DrawRectangleGradientEx(Rectangle rec, Color col1, Color col2, Color col3, Color col4);        // Draw a gradient-filled rectangle with custom vertex colors
    void DrawRectangleLines(int posX, int posY, int width, int height, Color color);                    // Draw rectangle outline
    void DrawRectangleLinesEx(Rectangle rec, int lineThick, Color color);                               // Draw rectangle outline with extended parameters
    void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color);               // Draw rectangle with rounded edges
    void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, int lineThick, Color color); // Draw rectangle with rounded edges outline
    void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color);                                 // Draw a color-filled triangle
    void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color);                            // Draw triangle outline
    void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color);                // Draw a regular polygon (Vector version)
    void DrawPolyEx(Vector2 *points, int numPoints, Color color);                                       // Draw a closed polygon defined by points
    void DrawPolyExLines(Vector2 *points, int numPoints, Color color);                                  // Draw polygon lines

    void SetShapesTexture(Texture2D texture, Rectangle source);                                         // Define default texture used to draw shapes

    // Basic shapes collision detection functions
    bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);                                            // Check collision between two rectangles
    bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2);         // Check collision between two circles
    bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec);                          // Check collision between circle and rectangle
    Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2);                                          // Get collision rectangle for two rectangles collision
    bool CheckCollisionPointRec(Vector2 point, Rectangle rec);                                          // Check if point is inside rectangle
    bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius);                        // Check if point is inside circle
    bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);                // Check if point is inside a triangle

