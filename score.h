#ifndef SCORE_H
#define SCORE_H

class Score
{
private:
    int counter;
    float myScore;

public:
    Score();
    void resetScore();
    void addScore(float newScore);
    float getScore();
    void setScore(float newScore);
    int getCounter();
    void setCounter(int newCounter);
    //void showScore(); // This should change later. (Showing this straight to IU or not.)
};

#endif // SCORE_H
