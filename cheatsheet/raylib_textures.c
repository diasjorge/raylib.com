
    // Image/Texture2D data loading/unloading/saving functions
    Image LoadImage(const char *fileName);                                                              // Load image from file into CPU memory (RAM)
    Image LoadImageEx(Color *pixels, int width, int height);                                            // Load image from Color array data (RGBA - 32bit)
    Image LoadImagePro(void *data, int width, int height, int format);                                  // Load image from raw data with parameters
    Image LoadImageRaw(const char *fileName, int width, int height, int format, int headerSize);        // Load image from RAW file data
    void ExportImage(Image image, const char *fileName);                                                // Export image data to file
    void ExportImageAsCode(Image image, const char *fileName);                                          // Export image as code file defining an array of bytes
    Texture2D LoadTexture(const char *fileName);                                                        // Load texture from file into GPU memory (VRAM)
    Texture2D LoadTextureFromImage(Image image);                                                        // Load texture from image data
    TextureCubemap LoadTextureCubemap(Image image, int layoutType);                                     // Load cubemap from image, multiple image cubemap layouts supported
    RenderTexture2D LoadRenderTexture(int width, int height);                                           // Load texture for rendering (framebuffer)
    void UnloadImage(Image image);                                                                      // Unload image from CPU memory (RAM)
    void UnloadTexture(Texture2D texture);                                                              // Unload texture from GPU memory (VRAM)
    void UnloadRenderTexture(RenderTexture2D target);                                                   // Unload render texture from GPU memory (VRAM)
    Color *GetImageData(Image image);                                                                   // Get pixel data from image as a Color struct array
    Vector4 *GetImageDataNormalized(Image image);                                                       // Get pixel data from image as Vector4 array (float normalized)
    int GetPixelDataSize(int width, int height, int format);                                            // Get pixel data size in bytes (image or texture)
    Image GetTextureData(Texture2D texture);                                                            // Get pixel data from GPU texture and return an Image
    Image GetScreenData(void);                                                                          // Get pixel data from screen buffer and return an Image (screenshot)
    void UpdateTexture(Texture2D texture, const void *pixels);                                          // Update GPU texture with new data
                                                                                                        
    // Image manipulation functions                                                                     
    Image ImageCopy(Image image);                                                                       // Create an image duplicate (useful for transformations)
    void ImageToPOT(Image *image, Color fillColor);                                                     // Convert image to POT (power-of-two)
    void ImageFormat(Image *image, int newFormat);                                                      // Convert image data to desired format
    void ImageAlphaMask(Image *image, Image alphaMask);                                                 // Apply alpha mask to image
    void ImageAlphaClear(Image *image, Color color, float threshold);                                   // Clear alpha channel to desired color
    void ImageAlphaCrop(Image *image, float threshold);                                                 // Crop image depending on alpha value
    void ImageAlphaPremultiply(Image *image);                                                           // Premultiply alpha channel
    void ImageCrop(Image *image, Rectangle crop);                                                       // Crop an image to a defined rectangle
    void ImageResize(Image *image, int newWidth, int newHeight);                                        // Resize image (Bicubic scaling algorithm)
    void ImageResizeNN(Image *image, int newWidth,int newHeight);                                       // Resize image (Nearest-Neighbor scaling algorithm)
    void ImageResizeCanvas(Image *image, int newWidth, int newHeight, int offsetX, int offsetY, Color color);  // Resize canvas and fill with color
    void ImageMipmaps(Image *image);                                                                    // Generate all mipmap levels for a provided image
    void ImageDither(Image *image, int rBpp, int gBpp, int bBpp, int aBpp);                             // Dither image data to 16bpp or lower (Floyd-Steinberg dithering)
    Color *ImageExtractPalette(Image image, int maxPaletteSize, int *extractCount);                     // Extract color palette from image to maximum size (memory should be freed)
    Image ImageText(const char *text, int fontSize, Color color);                                       // Create an image from text (default font)
    Image ImageTextEx(Font font, const char *text, float fontSize, float spacing, Color tint);          // Create an image from text (custom sprite font)
    void ImageDraw(Image *dst, Image src, Rectangle srcRec, Rectangle dstRec);                          // Draw a source image within a destination image
    void ImageDrawRectangle(Image *dst, Rectangle rec, Color color);                                    // Draw rectangle within an image
    void ImageDrawRectangleLines(Image *dst, Rectangle rec, int thick, Color color);                    // Draw rectangle lines within an image
    void ImageDrawText(Image *dst, Vector2 position, const char *text, int fontSize, Color color);      // Draw text (default font) within an image (destination)
    void ImageDrawTextEx(Image *dst, Vector2 position, Font font, const char *text, float fontSize, float spacing, Color color); // Draw text (custom sprite font) within an image (destination)
    void ImageFlipVertical(Image *image);                                                               // Flip image vertically
    void ImageFlipHorizontal(Image *image);                                                             // Flip image horizontally
    void ImageRotateCW(Image *image);                                                                   // Rotate image clockwise 90deg
    void ImageRotateCCW(Image *image);                                                                  // Rotate image counter-clockwise 90deg
    void ImageColorTint(Image *image, Color color);                                                     // Modify image color: tint
    void ImageColorInvert(Image *image);                                                                // Modify image color: invert
    void ImageColorGrayscale(Image *image);                                                             // Modify image color: grayscale
    void ImageColorContrast(Image *image, float contrast);                                              // Modify image color: contrast (-100 to 100)
    void ImageColorBrightness(Image *image, int brightness);                                            // Modify image color: brightness (-255 to 255)
    void ImageColorReplace(Image *image, Color color, Color replace);                                   // Modify image color: replace color
                                                                                                        
    // Image generation functions                                                                       
    Image GenImageColor(int width, int height, Color color);                                            // Generate image: plain color
    Image GenImageGradientV(int width, int height, Color top, Color bottom);                            // Generate image: vertical gradient
    Image GenImageGradientH(int width, int height, Color left, Color right);                            // Generate image: horizontal gradient
    Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer);       // Generate image: radial gradient
    Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2);     // Generate image: checked
    Image GenImageWhiteNoise(int width, int height, float factor);                                      // Generate image: white noise
    Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale);            // Generate image: perlin noise
    Image GenImageCellular(int width, int height, int tileSize);                                        // Generate image: cellular algorithm. Bigger tileSize means bigger cells
                                                                                                        
    // Texture2D configuration functions                                                                
    void GenTextureMipmaps(Texture2D *texture);                                                         // Generate GPU mipmaps for a texture
    void SetTextureFilter(Texture2D texture, int filterMode);                                           // Set texture scaling filter mode
    void SetTextureWrap(Texture2D texture, int wrapMode);                                               // Set texture wrapping mode
                                                                                                        
    // Texture2D drawing functions                                                                      
    void DrawTexture(Texture2D texture, int posX, int posY, Color tint);                                // Draw a Texture2D
    void DrawTextureV(Texture2D texture, Vector2 position, Color tint);                                 // Draw a Texture2D with position defined as Vector2
    void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint);   // Draw a Texture2D with extended parameters
    void DrawTextureRec(Texture2D texture, Rectangle sourceRec, Vector2 position, Color tint);          // Draw a part of a texture defined by a rectangle
    void DrawTextureQuad(Texture2D texture, Vector2 tiling, Vector2 offset, Rectangle quad, Color tint);  // Draw texture quad with tiling and offset parameters
    void DrawTexturePro(Texture2D texture, Rectangle sourceRec, Rectangle destRec, Vector2 origin, float rotation, Color tint);       // Draw a part of a texture defined by a rectangle with 'pro' parameters
    void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle destRec, Vector2 origin, float rotation, Color tint);  // Draws a texture (or part of it) that stretches or shrinks nicely

