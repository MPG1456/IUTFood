#ifndef SCORE_H
#define SCORE_H

#include <QDataStream>

class Score
{

private:
    int counter;
    float myScore;

public:
    Score();
    Score(const Score &copyScore);
    void resetScore();
    void addScore(float newScore);
    float getScore();
    void setScore(float newScore);
    int getCounter();
    void setCounter(int newCounter);
    //void showScore(); // This should change later. (Showing this straight to IU or not.)
    Score& operator=(Score & other)=default;
};

#endif // SCORE_H
