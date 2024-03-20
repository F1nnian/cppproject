#include "AudioRenderer.h"
#include <iostream>

AudioRenderer::AudioRenderer()
{
    
}

void AudioRenderer::loadSounds()
{
    InitAudioDevice();
    select = LoadSound("../resources/audio/select.wav");
    match = LoadSound("../resources/audio/match.wav");
    gameOver = LoadSound("../resources/audio/gameover.wav");
    SetSoundVolume(gameOver, 0.1f);
    music = LoadMusicStream("../resources/audio/music.mp3");
    SetMusicVolume(music, 0.01f);
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