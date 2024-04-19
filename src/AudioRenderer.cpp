// This class is responsible for rendering audio in the game. It uses raylib's audio functions to load and play sounds and music.

#include "AudioRenderer.h"
#include <iostream>

void AudioRenderer::loadSounds()
{
    InitAudioDevice(); // Initialize audio device
    // Load sounds and set volume
    select = LoadSound("../resources/audio/select.wav");
    match = LoadSound("../resources/audio/match.wav");
    gameOver = LoadSound("../resources/audio/gameover.wav");
    SetSoundVolume(gameOver, 0.1f);
    music = LoadMusicStream("../resources/audio/music.mp3");
    SetMusicVolume(music, 0.1f);
}

void AudioRenderer::playSelect()
{
    PlaySound(select);
}

void AudioRenderer::playMatch()
{
    PlaySound(match);
}

void AudioRenderer::playGameOver()
{
    PlaySound(gameOver);
}

void AudioRenderer::startMusic()
{
    PlayMusicStream(music);
}

void AudioRenderer::updateMusic()
{
    UpdateMusicStream(music);
}