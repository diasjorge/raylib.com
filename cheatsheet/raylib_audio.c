
    // Audio device management functions
    void InitAudioDevice(void);                                                     // Initialize audio device and context
    void CloseAudioDevice(void);                                                    // Close the audio device and context (and music stream)
    bool IsAudioDeviceReady(void);                                                  // Check if audio device is ready
    void SetMasterVolume(float volume);                                             // Set master volume (listener)

    // Wave/Sound loading/unloading functions
    Wave LoadWave(const char *fileName);                                            // Load wave data from file
    Wave LoadWaveEx(void *data, int sampleCount, int sampleRate, int sampleSize, int channels); // Load wave data from raw array data
    Sound LoadSound(const char *fileName);                                          // Load sound from file
    Sound LoadSoundFromWave(Wave wave);                                             // Load sound from wave data
    void UpdateSound(Sound sound, const void *data, int samplesCount);              // Update sound buffer with new data
    void UnloadWave(Wave wave);                                                     // Unload wave data
    void UnloadSound(Sound sound);                                                  // Unload sound
    void ExportWave(Wave wave, const char *fileName);                               // Export wave data to file
    void ExportWaveAsCode(Wave wave, const char *fileName);                         // Export wave sample data to code (.h)

    // Wave/Sound management functions
    void PlaySound(Sound sound);                                                    // Play a sound
    void PauseSound(Sound sound);                                                   // Pause a sound
    void ResumeSound(Sound sound);                                                  // Resume a paused sound
    void StopSound(Sound sound);                                                    // Stop playing a sound
    bool IsSoundPlaying(Sound sound);                                               // Check if a sound is currently playing
    void SetSoundVolume(Sound sound, float volume);                                 // Set volume for a sound (1.0 is max level)
    void SetSoundPitch(Sound sound, float pitch);                                   // Set pitch for a sound (1.0 is base level)
    void WaveFormat(Wave *wave, int sampleRate, int sampleSize, int channels);      // Convert wave data to desired format
    Wave WaveCopy(Wave wave);                                                       // Copy a wave to a new wave
    void WaveCrop(Wave *wave, int initSample, int finalSample);                     // Crop a wave to defined samples range
    float *GetWaveData(Wave wave);                                                  // Get samples data from wave as a floats array

    // Music management functions
    Music LoadMusicStream(const char *fileName);                                    // Load music stream from file
    void UnloadMusicStream(Music music);                                            // Unload music stream
    void PlayMusicStream(Music music);                                              // Start music playing
    void UpdateMusicStream(Music music);                                            // Updates buffers for music streaming
    void StopMusicStream(Music music);                                              // Stop music playing
    void PauseMusicStream(Music music);                                             // Pause music playing
    void ResumeMusicStream(Music music);                                            // Resume playing paused music
    bool IsMusicPlaying(Music music);                                               // Check if music is playing
    void SetMusicVolume(Music music, float volume);                                 // Set volume for music (1.0 is max level)
    void SetMusicPitch(Music music, float pitch);                                   // Set pitch for a music (1.0 is base level)
    void SetMusicLoopCount(Music music, int count);                                 // Set music loop count (loop repeats)
    float GetMusicTimeLength(Music music);                                          // Get music time length (in seconds)
    float GetMusicTimePlayed(Music music);                                          // Get current music time played (in seconds)

    // AudioStream management functions
    AudioStream InitAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels); // Init audio stream (to stream raw audio pcm data)
    void UpdateAudioStream(AudioStream stream, const void *data, int samplesCount); // Update audio stream buffers with data
    void CloseAudioStream(AudioStream stream);                                      // Close audio stream and free memory
    bool IsAudioBufferProcessed(AudioStream stream);                                // Check if any audio stream buffers requires refill
    void PlayAudioStream(AudioStream stream);                                       // Play audio stream
    void PauseAudioStream(AudioStream stream);                                      // Pause audio stream
    void ResumeAudioStream(AudioStream stream);                                     // Resume audio stream
    bool IsAudioStreamPlaying(AudioStream stream);                                  // Check if audio stream is playing
    void StopAudioStream(AudioStream stream);                                       // Stop audio stream
    void SetAudioStreamVolume(AudioStream stream, float volume);                    // Set volume for audio stream (1.0 is max level)
    void SetAudioStreamPitch(AudioStream stream, float pitch);                      // Set pitch for audio stream (1.0 is base level)
    
