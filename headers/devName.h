void DrawDevName();

void DrawDevName()
{
    int fontSize = 20;
    int x, y;

    x = (GetScreenWidth() - MeasureText("Developed by Gustavo Azevedo Naldoni at 09/02/2022", fontSize)) / 2;
    y = 11 * (GetScreenHeight() / 12);

    DrawText(TextFormat("Developed by Gustavo Azevedo Naldoni at 09/02/2022"), x, y, fontSize, DARKGRAY);
}
