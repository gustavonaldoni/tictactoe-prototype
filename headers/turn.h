void DrawTurnMessage(int);

void DrawTurnMessage(int turn)
{
    int fontSize = 30;
    int x, y;

    if (turn == 1)
    {
        x = (GetScreenWidth() - MeasureText("Turn: Player X", fontSize)) / 2;
        y = GetScreenHeight() / 12;

        DrawText(TextFormat("Turn: Player X"), x, y, fontSize, DARKGRAY);
    }

    else if (turn == 2)
    {
        x = (GetScreenWidth() - MeasureText("Turn: Player O", fontSize)) / 2;
        y = GetScreenHeight() / 12;

        DrawText(TextFormat("Turn: Player O"), x, y, fontSize, DARKGRAY);
    }
}