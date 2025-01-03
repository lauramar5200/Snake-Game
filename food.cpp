#include <raylib.h>
#include <raymath.h>

#include <iostream>
#include <deque>

#include "globalVar.h"
// #include "snake.cpp"

using namespace std;

class Food
{
public:
    Vector2 pos;
    Food(deque<Vector2> snakeBody) { pos = randomPos(snakeBody); }

    void
    draw()
    {
        Rectangle rec = {pos.x * CELL_SIZE, pos.y * CELL_SIZE, (float)CELL_SIZE, (float)CELL_SIZE};
        DrawRectangleRounded(rec, 0.4, 4, {222, 89, 93, 255});
    }

    bool findElement(Vector2 element, deque<Vector2> deque)
    {
        for (int i = 0; i < deque.size(); i++)
        {
            if (Vector2Equals(element, deque[i]))
            {
                return true;
            }
        }
        return false;
    }

    Vector2 generateRandomVector()
    {
        float randX = GetRandomValue(0, (COL - 1));
        float randY = GetRandomValue(0, (ROW - 1));
        return Vector2{round(randX), round(randY)};
    }

    Vector2 randomPos(deque<Vector2> snakeBody)
    {
        Vector2 newPos = generateRandomVector();
        while (findElement(newPos, snakeBody))
        {
            newPos = generateRandomVector();
        }
        return newPos;
    }
};
