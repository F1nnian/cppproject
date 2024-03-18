#include "Score.h"

int Score::getScore()
{
    return score;
}

void Score::addScore(int candiesMatched)
{
    score += candiesMatched * 10 * candiesMatched/3 * candiesMatched;
}

void Score::resetScore()
{
    score = 0;
}