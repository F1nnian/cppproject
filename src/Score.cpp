// This class implements the score. It contains information about the player's score and methods to add to and reset the score.

#include "Score.h"

int Score::getScore()
{
    return score;
}

// Add to the score based on the number of candies matched
void Score::addScore(int candiesMatched)
{
    score += candiesMatched * 10 * candiesMatched / 3 * candiesMatched;
}

void Score::reset()
{
    score = 0;
}