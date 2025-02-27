
    // Shader loading/unloading functions
    char *LoadText(const char *fileName);                                                               // Load chars array from text file
    Shader LoadShader(const char *vsFileName, const char *fsFileName);                                  // Load shader from files and bind default locations
    Shader LoadShaderCode(char *vsCode, char *fsCode);                                                  // Load shader from code strings and bind default locations
    void UnloadShader(Shader shader);                                                                   // Unload shader from GPU memory (VRAM)
                                
    Shader GetShaderDefault(void);                                                                      // Get default shader
    Texture2D GetTextureDefault(void);                                                                  // Get default texture
                                
    // Shader configuration functions                               
    int GetShaderLocation(Shader shader, const char *uniformName);                                      // Get shader uniform location
    void SetShaderValue(Shader shader, int uniformLoc, const void *value, int uniformType);             // Set shader uniform value
    void SetShaderValueV(Shader shader, int uniformLoc, const void *value, int uniformType, int count); // Set shader uniform value vector
    void SetShaderValueMatrix(Shader shader, int uniformLoc, Matrix mat);                               // Set shader uniform value (matrix 4x4)
    void SetShaderValueTexture(Shader shader, int uniformLoc, Texture2D texture);                       // Set shader uniform value for texture
    void SetMatrixProjection(Matrix proj);                                                              // Set a custom projection matrix (replaces internal projection matrix)
    void SetMatrixModelview(Matrix view);                                                               // Set a custom modelview matrix (replaces internal modelview matrix)
    Matrix GetMatrixModelview();                                                                        // Get internal modelview matrix

    // Shading begin/end functions
    void BeginShaderMode(Shader shader);                                                                // Begin custom shader drawing
    void EndShaderMode(void);                                                                           // End custom shader drawing (use default shader)
    void BeginBlendMode(int mode);                                                                      // Begin blending mode (alpha, additive, multiplied)
    void EndBlendMode(void);                                                                            // End blending mode (reset to default: alpha blending)
    void BeginScissorMode(int x, int y, int width, int height);                                         // Begin scissor mode (define screen area for following drawing)
    void EndScissorMode(void);                                                                          // End scissor mode

    // VR control functions
    void InitVrSimulator(void);                                                                         // Init VR simulator for selected device parameters
    void CloseVrSimulator(void);                                                                        // Close VR simulator for current device
    void UpdateVrTracking(Camera *camera);                                                              // Update VR tracking (position and orientation) and camera
    void SetVrConfiguration(VrDeviceInfo info, Shader distortion);                                      // Set stereo rendering configuration parameters 
    bool IsVrSimulatorReady(void);                                                                      // Detect if VR simulator is ready
    void ToggleVrMode(void);                                                                            // Enable/Disable VR experience
    void BeginVrDrawing(void);                                                                          // Begin VR simulator stereo rendering
    void EndVrDrawing(void);                                                                            // End VR simulator stereo rendering
    
