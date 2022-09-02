bool CheckWin(Board, int);
bool CheckTie(Board, int);
void DrawWinMessage(int);
void DrawTieMessage();

bool CheckWin(Board board, int playerNumber)
{
    int i, j;

    // Check horizontal win
    for (i = 0; i < 3; i++)
    {
        j = 0;

        if (board.canvas[i][j] == board.canvas[i][j + 1] &&
            board.canvas[i][j + 1] == board.canvas[i][j + 2] &&
            board.canvas[i][j] == playerNumber)
            return true;
    }

    // Check vertical win
    for (j = 0; j < 3; j++)
    {
        i = 0;

        if (board.canvas[i][j] == board.canvas[i + 1][j] &&
            board.canvas[i + 1][j] == board.canvas[i + 2][j] &&
            board.canvas[i][j] == playerNumber)
            return true;
    }

    // Check diagonal win -> left to right
    i = 0;
    j = 0;

    if (board.canvas[i][j] == board.canvas[i + 1][j + 1] &&
        board.canvas[i + 1][j + 1] == board.canvas[i + 2][j + 2] &&
        board.canvas[i][j] == playerNumber)
        return true;

    // Check diagonal win -> right to left
    i = 0;
    j = 2;

    if (board.canvas[i][j] == board.canvas[i + 1][j - 1] &&
        board.canvas[i + 1][j - 1] == board.canvas[i + 2][j - 2] &&
        board.canvas[i][j] == playerNumber)
        return true;

    return false;
}

bool CheckTie(Board board, int totalPlays)
{
    if (totalPlays == 9 && 
        CheckWin(board, 1) == false &&
        CheckWin(board, 2) == false)
        return true;

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

void DrawTieMessage()
{
    int fontSize = 30;
    int x, y;

    x = (GetScreenWidth() - MeasureText("Game TIED! No one has won ...", fontSize)) / 2;
    y = GetScreenHeight() / 12;

    DrawText(TextFormat("Game TIED! No one has won ..."), x, y, fontSize, DARKGRAY);
}