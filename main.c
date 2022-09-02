#include "include/raylib.h"
#include "headers/board.h"
#include <stdlib.h>
#include <stdbool.h>

// Compile with: gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

/*

*/

int playerLine, playerColumn;
int turn = 1;

int main()
{
	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "Connect 4");

	Board board;

	board.size = 600;
	board.x = (GetScreenWidth() - board.size) / 2;
	board.y = (GetScreenHeight() - board.size) / 2;;

	ResetBoard(&board);

	SetTargetFPS(144);

	InitAudioDevice();

	while (!WindowShouldClose())
	{
		if (PlayerHasClickedOnBoard(board))
		{
			playerLine = GetPlayerLineCoordinate(board);
			playerColumn = GetPlayerColumnCoordinate(board);

			if (turn == 1)
			{
				board.canvas[playerLine][playerColumn] = 1;
				turn = 2;
			}

			else if (turn == 2)
			{
				board.canvas[playerLine][playerColumn] = 2;
				turn = 1;
			}
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawBoard(board);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
