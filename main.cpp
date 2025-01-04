#include <iostream>

#include "food.cpp"
#include "snake.cpp"
#include "globalVar.h"
#include "raylib.h"
#include <raymath.h>

using namespace std;

// Global Graphics Variables
Color colLight = {127, 179, 68, 255};
Color colDark = {102, 149, 47, 255};
Color colFood = {162, 245, 80, 255};
const int COL = 20;
const int ROW = 20;
const int CELL_SIZE = 30;

// Game Variables
int score = 0;
double lastUpdateTime = 0;
bool gameOver, pause = false;
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
		checkCollisionFood();
		checkCollisionEdges();
	}

	void checkCollisionFood()
	{
		if (Vector2Equals(snake.body[0], apple.pos))
		{
			apple.pos = apple.randomPos(snake.body);
			snake.addSegment = true;
			score++;
		}
	}
	void checkCollisionEdges()
	{
		if (snake.body[0].x < 0 || snake.body[0].x > COL || snake.body[0].y < 0 || snake.body[0].y > ROW)
		{
			gameOver = true;
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
		if (eventTriggered(0.2) && !gameOver && !pause)
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
		if (IsKeyPressed('P') && !pause)
		{
			pause = true;
		}
		else if (IsKeyPressed('P') && pause)
		{
			pause = false;
		}

		// DRAWING
		BeginDrawing();
		ClearBackground(DARKGRAY);

		if (!gameOver)
		{
			// Draw grid lines
			for (int i = 0; i < COL; i++)
			{
				DrawLine(i * CELL_SIZE, 0, i * CELL_SIZE, 800, {0, 0, 0, 50});
				for (int j = 0; j < ROW; j++)
				{
					DrawLine(0, j * CELL_SIZE, 800, j * CELL_SIZE, {0, 0, 0, 50});
				}
			}
			game.draw();
			if (pause)
			{
				DrawRectangle(0, 0, COL * CELL_SIZE, ROW * CELL_SIZE, {0, 0, 0, 100});
				DrawText("Paused", GetScreenWidth() / 2 - MeasureText("Paused", 20) / 2, GetScreenHeight() / 2 - 50, 20, WHITE);
			}
		}
		else
		{
			DrawText("Game Over!", GetScreenWidth() / 2 - MeasureText("Game Over!", 20) / 2, GetScreenHeight() / 2 - 50, 20, WHITE);
		}
		EndDrawing();
	}
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
