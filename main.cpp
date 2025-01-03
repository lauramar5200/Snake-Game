#include <iostream>

#include "food.cpp"
#include "snake.cpp"
#include "globalVar.h"
#include "raylib.h"
#include <raymath.h>

using namespace std;

// Global variables
Color colLight = {170, 205, 124, 255};
Color colDark = {105, 140, 70, 255};
const int COL = 20;
const int ROW = 20;
const int CELL_SIZE = 30;

double lastUpdateTime = 0;
bool eventTriggered(double interval);

class Game
{
public:
	Snake snake = Snake();
	Food apple = Food(snake.body);

	void draw()
	{
		apple.draw();
		snake.draw();
	}

	void update()
	{
		snake.update();
		checkCollision();
	}

	void checkCollision()
	{
		if (Vector2Equals(snake.body[0], apple.pos))
		{
			apple.pos = apple.randomPos(snake.body);
		}
	}
};

int main()
{
	cout << "Starting game..." << endl;
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);
	InitWindow(ROW * CELL_SIZE, COL * CELL_SIZE, "Snake Game");
	SetTargetFPS(60);

	Game game = Game();

	// GAME LOOP
	while (!WindowShouldClose())
	{
		// GAME UPDATES
		if (eventTriggered(0.2))
		{
			game.update();
		}

		if (IsKeyPressed(KEY_UP) && game.snake.dir.y != 1)
		{
			game.snake.dir = {0, -1};
		}
		if (IsKeyPressed(KEY_DOWN) && game.snake.dir.y != -1)
		{
			game.snake.dir = {0, 1};
		}
		if (IsKeyPressed(KEY_RIGHT) && game.snake.dir.x != -1)
		{
			game.snake.dir = {1, 0};
		}
		if (IsKeyPressed(KEY_LEFT) && game.snake.dir.x != 1)
		{
			game.snake.dir = {-1, 0};
		}

		// DRAWING
		BeginDrawing();
		ClearBackground(colLight);
		game.draw();

		EndDrawing();
	}

	// cleanup, unload any textures if used.

	CloseWindow();
	return 0;
}

bool eventTriggered(double interval)
{
	double time = GetTime();
	if (time - lastUpdateTime >= interval)
	{
		lastUpdateTime = time;
		return true;
	}
	else
	{
		return false;
	}
}