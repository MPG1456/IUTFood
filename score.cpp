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
    if(newScore > 5 && newScore < 0)
        return;

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
    if(newScore > 5 && newScore < 0)
        return;

    myScore = newScore;
}

int Score::getCounter()
{
    return counter;
}

void Score::setCounter(int newCounter)
{
    if(newCounter < 0)
        return;

    counter = newCounter;
}
