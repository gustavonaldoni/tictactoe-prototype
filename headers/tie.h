bool CheckTie(Board, int, Vector2, Vector2);
void DrawTieMessage();

bool CheckTie(Board board, int totalPlays, Vector2 winCoordinatesP1, Vector2 winCoordinatesP2)
{
    if (totalPlays == 9 &&
        CheckWin(board, 1, &winCoordinatesP1, &winCoordinatesP2) == false &&
        CheckWin(board, 2, &winCoordinatesP1, &winCoordinatesP2) == false)
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