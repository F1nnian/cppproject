#pragma once

class Score
{
public:
    Score() = default;
    void addScore(int candiesMatched);
    int getScore();
    void reset();

private:
    int score = 0;
};