
    // Font loading/unloading functions
    Font GetFontDefault(void);                                                                        // Get the default Font
    Font LoadFont(const char *fileName);                                                              // Load font from file into GPU memory (VRAM)
    Font LoadFontEx(const char *fileName, int fontSize, int *fontChars, int charsCount);              // Load font from file with extended parameters
    Font LoadFontFromImage(Image image, Color key, int firstChar);                                    // Load font from Image (XNA style)
    CharInfo *LoadFontData(const char *fileName, int fontSize, int *fontChars, int charsCount, int type); // Load font data for further use
    Image GenImageFontAtlas(CharInfo *chars, int charsCount, int fontSize, int padding, int packMethod);  // Generate image font atlas using chars info
    void UnloadFont(Font font);                                                                       // Unload Font from GPU memory (VRAM)

    // Text drawing functions
    void DrawFPS(int posX, int posY);                                                                 // Shows current FPS
    void DrawText(const char *text, int posX, int posY, int fontSize, Color color);                   // Draw text (using default font)
    void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint);                // Draw text using font and additional parameters
    void DrawTextRec(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint);   // Draw text using font inside rectangle limits
    void DrawTextRecEx(Font font, const char *text, Rectangle rec, float fontSize, float spacing, bool wordWrap, Color tint,
                         int selectStart, int selectLength, Color selectText, Color selectBack);      // Draw text using font inside rectangle limits with support for text selection

    // Text misc. functions
    int MeasureText(const char *text, int fontSize);                                                  // Measure string width for default font
    Vector2 MeasureTextEx(Font font, const char *text, float fontSize, float spacing);                // Measure string size for Font
    int GetGlyphIndex(Font font, int character);                                                      // Get index position for a unicode character on font

    // Text strings management functions
    // NOTE: Some strings allocate memory internally for returned strings, just be careful!
    bool TextIsEqual(const char *text1, const char *text2);                                           // Check if two text string are equal
    unsigned int TextLength(const char *text);                                                        // Get text length, checks for '\0' ending
    const char *TextFormat(const char *text, ...);                                                    // Text formatting with variables (sprintf style)
    const char *TextSubtext(const char *text, int position, int length);                              // Get a piece of a text string
    const char *TextReplace(char *text, const char *replace, const char *by);                         // Replace text string (memory should be freed!)
    const char *TextInsert(const char *text, const char *insert, int position);                       // Insert text in a position (memory should be freed!)
    const char *TextJoin(const char **textList, int count, const char *delimiter);                    // Join text strings with delimiter
    const char **TextSplit(const char *text, char delimiter, int *count);                             // Split text into multiple strings
    void TextAppend(char *text, const char *append, int *position);                                   // Append text at specific position and move cursor!
    int TextFindIndex(const char *text, const char *find);                                            // Find first text occurrence within a string
    const char *TextToUpper(const char *text);                                                        // Get upper case version of provided string
    const char *TextToLower(const char *text);                                                        // Get lower case version of provided string
    const char *TextToPascal(const char *text);                                                       // Get Pascal case notation version of provided string
    int TextToInteger(const char *text);                                                              // Get integer value from text (negative values not supported)

