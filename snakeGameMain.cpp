#include <iostream>
#include <raylib.h>

using namespace std;

#define BOARD = 20
const int SCREEN_WIDTH= 1920;
const int SCREEN_HEIGHT = 1080;
typedef enum GameScreen {TITLE, GAMEPLAY, ENDING } GameScreen;

int main(){
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Snake Game");
    SetTargetFPS(60);


    //main game loop
    int snakeLength;
    int headX, headY;
    return 0;
}