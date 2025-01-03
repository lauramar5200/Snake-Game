#include <raylib.h>
#include <raymath.h>

#include <deque>
#include <iostream>

#include "globalVar.h"

using namespace std;

class Snake
{
public:
    int length = 3;
    Vector2 dir = {1, 0};
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};

    void draw()
    {
        for (int i = 0; i < length; i++)
        {
            float xCurr = body[i].x;
            float yCurr = body[i].y;
            Rectangle recCurr = {xCurr * CELL_SIZE, yCurr * CELL_SIZE, (float)CELL_SIZE, (float)CELL_SIZE};
            DrawRectangleRounded(recCurr, 0.2, 4, colDark);
        }
    }

    void update()
    {
        body.pop_back();
        body.push_front(Vector2Add(body[0], dir));
    }
};
