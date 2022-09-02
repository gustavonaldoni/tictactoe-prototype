bool PlayIsValid(Board, int, int);

bool PlayIsValid(Board board, int lineNumber, int columnNumber)
{
    return board.canvas[lineNumber][columnNumber] == 0 &&
           lineNumber >= 0 && lineNumber < 3 &&
           columnNumber >= 0 && columnNumber < 3;
}