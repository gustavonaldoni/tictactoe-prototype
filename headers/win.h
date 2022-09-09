bool CheckWin(Board, int, Vector2 *, Vector2 *);
void DrawWinMessage(int);
void DrawWinLine(Vector2, Vector2);
Vector2 GetCenteredWinCoordinates(Board board, int, int, int);

bool CheckWin(Board board, int playerNumber, Vector2 *winCoordinatesP1, Vector2 *winCoordinatesP2)
{
    int i, j;
    int space = board.size / 3;

    // Check horizontal win
    for (i = 0; i < 3; i++)
    {
        j = 0;

        if (board.canvas[i][j] == board.canvas[i][j + 1] &&
            board.canvas[i][j + 1] == board.canvas[i][j + 2] &&
            board.canvas[i][j] == playerNumber)
        {
            *winCoordinatesP1 = GetCenteredWinCoordinates(board, i, j, space);
            *winCoordinatesP2 = GetCenteredWinCoordinates(board, i, j + 2, space);
            return true;
        }
    }

    // Check vertical win
    for (j = 0; j < 3; j++)
    {
        i = 0;

        if (board.canvas[i][j] == board.canvas[i + 1][j] &&
            board.canvas[i + 1][j] == board.canvas[i + 2][j] &&
            board.canvas[i][j] == playerNumber)
        {
            *winCoordinatesP1 = GetCenteredWinCoordinates(board, i, j, space);
            *winCoordinatesP2 = GetCenteredWinCoordinates(board, i + 2, j, space);
            return true;
        }
    }

    // Check diagonal win -> left to right
    i = 0;
    j = 0;

    if (board.canvas[i][j] == board.canvas[i + 1][j + 1] &&
        board.canvas[i + 1][j + 1] == board.canvas[i + 2][j + 2] &&
        board.canvas[i][j] == playerNumber)
    {
        *winCoordinatesP1 = GetCenteredWinCoordinates(board, i, j, space);
        *winCoordinatesP2 = GetCenteredWinCoordinates(board, i + 2, j + 2, space);
        return true;
    }

    // Check diagonal win -> right to left
    i = 0;
    j = 2;

    if (board.canvas[i][j] == board.canvas[i + 1][j - 1] &&
        board.canvas[i + 1][j - 1] == board.canvas[i + 2][j - 2] &&
        board.canvas[i][j] == playerNumber)
    {
        *winCoordinatesP1 = GetCenteredWinCoordinates(board, i, j, space);
        *winCoordinatesP2 = GetCenteredWinCoordinates(board, i + 2, j - 2, space);
        return true;
    }

    return false;
}

void DrawWinMessage(int playerNumber)
{
    int fontSize = 30;
    int x, y;

    if (playerNumber == 1)
    {
        x = (GetScreenWidth() - MeasureText("Player X WINS!!", fontSize)) / 2;
        y = GetScreenHeight() / 12;

        DrawText(TextFormat("Player X WINS!!"), x, y, fontSize, DARKGRAY);
    }

    else if (playerNumber == 2)
    {
        x = (GetScreenWidth() - MeasureText("Player O WINS!!", fontSize)) / 2;
        y = GetScreenHeight() / 12;

        DrawText(TextFormat("Player 0 WINS!!"), x, y, fontSize, DARKGRAY);
    }
}

void DrawWinLine(Vector2 winCoordinatesP1, Vector2 winCoordinatesP2)
{
    DrawLineEx(winCoordinatesP1, winCoordinatesP2, 5.0, DARKGRAY);
}

Vector2 GetCenteredWinCoordinates(Board board, int i, int j, int space)
{
    Vector2 result = {0,0};

    result.x = board.x + (space * i + space / 2);
    result.y = board.y + (space * j + space / 2);

    return result;
}
