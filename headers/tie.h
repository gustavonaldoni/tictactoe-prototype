bool CheckTie(Board, int);
void DrawTieMessage();

bool CheckTie(Board board, int totalPlays)
{
    if (totalPlays == 9 &&
        CheckWin(board, 1) == false &&
        CheckWin(board, 2) == false)
        return true;

    return false;
}

void DrawTieMessage()
{
    int fontSize = 30;
    int x, y;

    x = (GetScreenWidth() - MeasureText("Game TIED! No one has won ...", fontSize)) / 2;
    y = GetScreenHeight() / 12;

    DrawText(TextFormat("Game TIED! No one has won ..."), x, y, fontSize, DARKGRAY);
}