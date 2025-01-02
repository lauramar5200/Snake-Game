#include <iostream>
using namespace std;

class Snake{
    public:
        int length, posX, posY;
        Snake* next;
        void updatePos(int xCurr, int yCurr);
        int increaseLength(int l, Snake* tail);
};

//if not head, want to follow direction of previous snake.
//if head, want to move in direction of input
void Snake::updatePos(int xCurr, int yCurr){
    posX = xCurr + 1;
    posY = yCurr + 1;

}

int increaseLength(int l, Snake* tail){

}