void DrawTimePassed();

void DrawTimePassed()
{
    int fontSize = 20;
    int x, y;

    x = (GetScreenWidth() - MeasureText("Game TIED! No one has won ...", fontSize)) / 2;
    y = 10.5 * GetScreenHeight() / 12;

    DrawText(TextFormat("Total time played: %d seconds", (int)GetTime()), x, y, fontSize, DARKGRAY);
}