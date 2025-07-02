#include "score.h"

Score::Score() : counter(0), myScore(-1)
{}

void Score::resetScore()
{
    myScore = -1;
    counter = 0;
}

void Score::addScore(float newScore)
{
    myScore *= counter;
    myScore += newScore;
    counter++;
    myScore /= counter;
}

float Score::getScore()
{
    return myScore;
}

void Score::setScore(float newScore)
{
    myScore = newScore;
}

int Score::getCounter()
{
    return counter;
}

void Score::setCounter(int newCounter)
{
    counter = newCounter;
}
