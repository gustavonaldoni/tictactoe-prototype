#include <stdlib.h>
#include <stdbool.h>
#include "include/raylib.h"
#include "headers/utils.h"
#include "headers/board.h"
#include "headers/win.h"
#include "headers/tie.h"
#include "headers/turn.h"
#include "headers/play.h"
#include "headers/devName.h"
#include "headers/timePassed.h"

// Compile with: gcc main.c -o game.exe -O1 -Wall -std=c99 -Wno-missing-braces -I include/ -L lib -lraylib -lopengl32 -lgdi32 -lwinmm

int playerLine, playerColumn;
int turn = 1;
int totalPlays = 0;

Vector2 winCoordinatesP1 = {0, 0};
Vector2 winCoordinatesP2 = {1200, 900};

int main()
{
	int screenConstant = 300;
	InitWindow(4 * screenConstant, 3 * screenConstant, "Tic Tac Toe");

	Board board;

	board.size = 500;
	board.x = (GetScreenWidth() - board.size) / 2;
	board.y = (GetScreenHeight() - board.size) / 2;

	ResetBoard(&board);

	SetTargetFPS(144);
	InitAudioDevice();

	srand(time(NULL));

	while (!WindowShouldClose())
	{
		if (PlayerHasClickedOnBoard(board) &&
			totalPlays <= 9 &&
			CheckTie(board, totalPlays, winCoordinatesP1, winCoordinatesP2) == false)
		{
			playerLine = GetPlayerLineCoordinate(board);
			playerColumn = GetPlayerColumnCoordinate(board);

			if (PlayIsValid(board, playerLine, playerColumn))
			{
				totalPlays += 1;

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
		}

		BeginDrawing();
		ClearBackground(RAYWHITE);

		DrawBoard(board);
		DrawDevName();
		DrawTimePassed();

		if (totalPlays <= 9 && CheckTie(board, totalPlays, winCoordinatesP1, winCoordinatesP2) == false)
		{
			DrawTurnMessage(turn);
		}

		if (CheckWin(board, 1, &winCoordinatesP1, &winCoordinatesP2))
		{
			DrawWinMessage(1);
			DrawWinLine(winCoordinatesP1, winCoordinatesP2);
			totalPlays = 10;
		}

		if (CheckWin(board, 2, &winCoordinatesP1, &winCoordinatesP2))
		{
			DrawWinMessage(2);
			DrawWinLine(winCoordinatesP1, winCoordinatesP2);
			totalPlays = 10;
		}

		if (CheckTie(board, totalPlays, winCoordinatesP1, winCoordinatesP2))
		{
			DrawTieMessage();
		}

		if (CheckWin(board, 1, &winCoordinatesP1, &winCoordinatesP2) || CheckWin(board, 2, &winCoordinatesP1, &winCoordinatesP2) || CheckTie(board, totalPlays, winCoordinatesP1, winCoordinatesP2))
		{
			DrawOptionToRestartGame();

			if (IsKeyPressed(KEY_SPACE))
			{
				ResetBoard(&board);
				totalPlays = 0;
				turn = (rand() % 2) + 1;
			}
		}

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
}
