typedef struct
{
    int x, y;
    int size;
    int canvas[3][3];
} Board;

void ResetBoard(Board *);
void DrawBoard(Board);
int GetPlayerLineCoordinate(Board);
int GetPlayerColumnCoordinate(Board);
Rectangle GetBoardRec(Board);
bool PlayerHasClickedOnBoard(Board);

void ResetBoard(Board *board)
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board->canvas[i][j] = 0;
        }
    }
}

void DrawBoard(Board board)
{
    int i, j;
    int space = board.size / 3;
    int startX, startY, endX, endY;
    int crossSize = 80;

    //DrawRectangleLines(board.x, board.y, board.size, board.size, BLACK);

    for (i = 1; i < 3; i++)
    {
        startX = board.x;
        startY = board.y + i * space;

        endX = board.x + 3 * space;
        endY = startY;

        DrawLine(startX, startY, endX, endY, DARKGRAY);
    }

    for (j = 1; j < 3; j++)
    {
        startX = board.x + j * space;
        startY = board.y;

        endX = startX;
        endY = board.y + 3 * space;

        DrawLine(startX, startY, endX, endY, DARKGRAY);
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (board.canvas[i][j] == 1)
            {
                DrawCross(board.x + i * space + (space - crossSize) / 2,
                          board.y + j * space + (space - crossSize) / 2,
                          crossSize, 2.0);
            }
            else if (board.canvas[i][j] == 2)
            {

                DrawCircleLines(board.x + i * space + space / 2,
                                board.y + j * space + space / 2,
                                (float)(crossSize / 2),
                                DARKGRAY);

                DrawCircleLines(board.x + i * space + space / 2,
                                board.y + j * space + space / 2,
                                (float)(crossSize / 2 + 1),
                                DARKGRAY);

                DrawCircleLines(board.x + i * space + space / 2,
                                board.y + j * space + space / 2,
                                (float)(crossSize / 2 + 2),
                                DARKGRAY);
            }
        }
    }
}

int GetPlayerLineCoordinate(Board board)
{
    return (GetMouseX() - board.x) / (board.size / 3);
}

int GetPlayerColumnCoordinate(Board board)
{
    return (GetMouseY() - board.y) / (board.size / 3);
}

Rectangle GetBoardRec(Board board)
{
    return (Rectangle){board.x,
                       board.y,
                       board.size,
                       board.size};
}

bool PlayerHasClickedOnBoard(Board board)
{
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
           CheckCollisionPointRec(GetMousePosition(), GetBoardRec(board));
}