void DrawCross(int, int, int, float);
void DrawOptionToRestartGame();
int GenerateRandomNumber(int, int);
bool RandomProbabilityManipulation(int);

void DrawCross(int x, int y, int size, float thick)
{
    DrawLineEx((Vector2){x, y}, (Vector2){x + size, y + size}, thick, DARKGRAY);
    DrawLineEx((Vector2){x, y + size}, (Vector2){x + size, y}, thick, DARKGRAY);
}

void DrawOptionToRestartGame()
{
    int fontSize = 20;
    int x, y;

    x = (GetScreenWidth() - MeasureText("Press SPACE to play again", fontSize)) / 2;
    y = 1.5 * (GetScreenHeight() / 12);

    DrawText(TextFormat("Press SPACE to play again"), x, y, fontSize, DARKGRAY);
}

int GenerateRandomNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

bool RandomProbabilityManipulation(int percentage)
{
    int n;

    n = (rand() % 100) + 1;

    return n <= percentage;
}