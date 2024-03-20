#pragma once
#include "raylib.h"

class AudioRenderer
{
private:
    Sound select;
    Music music;
    Sound match;
    Sound fall;
    Sound gameOver;
public:
    AudioRenderer();
    void playSelect();
    void playSwap();
    void playMatch();
    void playFall();
    void playGameOver();
    void loadSounds();
    void startMusic();
    void updateMusic();
};