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
    void playSelect();
    void playMatch();
    void playGameOver();
    void loadSounds();
    void startMusic();
    void updateMusic();
};