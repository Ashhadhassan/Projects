#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <float.h>

int SIDE;
int MINES;
int HINTS;
int difficultyLevel;
time_t startTime;

// ANSI CODES
#define RED "\x1b[31m"
#define ORANGE "\x1b[38;5;208m"
#define LIGHT_ORANGE "\x1b[38;5;215m"
#define LIGHT_GREEN "\x1b[92m"
#define DARK_GREEN "\x1b[32m"
#define BLUE "\x1b[34m"
#define RESET_COLOR "\x1b[0m"

void startTimer()
{
    time(&startTime);
}

double stopTimer()
{
    time_t endTime;
    time(&endTime);
    return difftime(endTime, startTime);
}

void loadFastestTimes(double *fastestTimes)
{
    FILE *file = fopen("fastest_times.txt", "r");

    if (file != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            fscanf(file, "%lf", &fastestTimes[i]);
        }

        fclose(file);
    }
}

void saveFastestTimes(double *fastestTimes)
{
    FILE *file = fopen("fastest_times.txt", "w");

    if (file != NULL)
    {
        for (int i = 0; i < 4; i++)
        {
            fprintf(file, "%.2f\n", fastestTimes[i]);
        }

        fclose(file);
    }
}

bool isValid(int row, int col)
{
    if (row < 0 || col < 0 || row >= SIDE || col >= SIDE)
    {
        return false;
    }
    return true;
}

bool isMine(int row, int col, char **board)
{
    if (board[row][col] == '*')
    {
        return true;
    }
    return false;
}

void makeMove(int *x, int *y)
{
    printf("Enter -1 -1 for Hint.\n");
    printf("Enter your move, (row, column) -> ");
    scanf("%d %d", x, y);
}

void initialise(char **realBoard, char **myBoard)
{
    int i, j;
    for (i = 0; i < SIDE; i++)
    {
        for (j = 0; j < SIDE; j++)
        {
            myBoard[i][j] = realBoard[i][j] = '-';
        }
    }
}

void printColoredNumber(int count)
{
    switch (count)
    {
    case 0:
        printf(DARK_GREEN "%d" RESET_COLOR, count);
        break;
    case 1:
        printf(LIGHT_GREEN "%d" RESET_COLOR, count);
        break;
    case 2:
        printf(LIGHT_ORANGE "%d" RESET_COLOR, count);
        break;
    case 3:
        printf(ORANGE "%d" RESET_COLOR, count);
        break;
    case 4:
        printf(RED "%d" RESET_COLOR, count);
        break;
    default:
        printf("%d", count);
        break;
    }
}

void printBoard(char **myBoard)
{
    int i, j;
    printf("    ");
    if (SIDE > 9)
    {
        printf(" ");
    }
    for (i = 0; i < SIDE; i++)
    {
        printf("%d ", i);
    }
    printf("\n\n");

    for (i = 0; i < SIDE; i++)
    {
        printf("%d   ", i);
        if (SIDE > 9 && i <= 9)
        {
            printf(" ");
        }
        for (j = 0; j < SIDE; j++)
        {
            if (isMine(i, j, myBoard))
            {
                printf(BLUE "* " RESET_COLOR);
            }
            else if (myBoard[i][j] >= '0' && myBoard[i][j] <= '8')
            {
                printColoredNumber(myBoard[i][j] - '0');
                printf(" ");
            }
            else
            {
                printf("%c ", myBoard[i][j]);
            }
            if (j > 9)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void placeMines(int **mines, char **realBoard)
{
    bool *mark = (bool *)malloc(SIDE * SIDE * sizeof(bool));
    memset(mark, false, SIDE * SIDE * sizeof(bool));
    int i;
    for (i = 0; i < MINES;)
    {
        int random = rand() % (SIDE * SIDE);
        int x = random / SIDE;
        int y = random % SIDE;

        if (!mark[random])
        {
            mines[i][0] = x;
            mines[i][1] = y;

            realBoard[mines[i][0]][mines[i][1]] = '*';
            mark[random] = true;
            i++;
        }
    }
    free(mark);
}

int countAdjacentMines(int row, int col, int **mines, char **realBoard)
{
    int i;
    int count = 0;
    int row_directions[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int col_directions[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (i = 0; i < 8; i++)
    {
        if (isValid(row + row_directions[i], col + col_directions[i]))
        {
            if (isMine(row + row_directions[i], col + col_directions[i], realBoard))
            {
                count++;
            }
        }
    }
    return count;
}

void giveHint(char **myBoard, char **realBoard, int **mines, int *movesLeft, int *x, int *y)
{
    int i, j;
    for (i = 0; i < SIDE; i++)
    {
        for (j = 0; j < SIDE; j++)
        {
            if (realBoard[i][j] == '-' && myBoard[i][j] == '-')
            {
                *x = i, *y = j;
                printf("\nHint: Revealing a safe cell at (%d, %d)\n", i, j);
                return;
            }
        }
    }
}

bool playMinesweeperUtil(char **myBoard, char **realBoard, int **mines, int row, int col, int *movesLeft)
{
    if (myBoard[row][col] != '-')
    {
        return false;
    }

    int i, j;

    if (realBoard[row][col] == '*')
    {
        myBoard[row][col] = '*';

        for (i = 0; i < MINES; i++)
        {
            myBoard[mines[i][0]][mines[i][1]] = '*';
        }

        printBoard(myBoard);
        printf("\nYou lost!\n");
        return true;
    }
    else
    {
        int count = countAdjacentMines(row, col, mines, realBoard);
        (*movesLeft)--;

        myBoard[row][col] = count + '0';

        int row_directions[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int col_directions[] = {0, 1, 1, 1, 0, -1, -1, -1};

        if (count == 0)
        {
            for (i = 0; i < 8; i++)
            {
                if (isValid(row + row_directions[i], col + col_directions[i]) == true)
                {
                    if (isMine(row + row_directions[i], col + col_directions[i], realBoard) == false)
                    {
                        playMinesweeperUtil(myBoard, realBoard, mines, row + row_directions[i], col + col_directions[i], movesLeft);
                    }
                }
            }
        }
        return false;
    }
}

void playMinesweeper()
{
    bool gameOver = false;
    char **realBoard = (char **)malloc(SIDE * sizeof(char *));
    char **myBoard = (char **)malloc(SIDE * sizeof(char *));
    int **mines = (int **)malloc(MINES * sizeof(int *));

    int i;

    for (i = 0; i < SIDE; i++)
    {
        realBoard[i] = (char *)malloc(SIDE * sizeof(char));
        myBoard[i] = (char *)malloc(SIDE * sizeof(char));
    }

    for (i = 0; i < MINES; i++)
    {
        mines[i] = (int *)malloc(2 * sizeof(int));
    }

    int movesLeft = (SIDE * SIDE) - MINES, x, y;

    double fastestTimes[4] = {DBL_MAX, DBL_MAX, DBL_MAX, DBL_MAX};
    loadFastestTimes(fastestTimes);
    initialise(realBoard, myBoard);
    placeMines(mines, realBoard);
    startTimer();

    while (!gameOver)
    {
        printf("Current Status of Board : \n");
        printBoard(myBoard);
        makeMove(&x, &y);

        while (!isValid(x, y))
        {
            if (x == -1 && y == -1)
            {
                break;
            }
            printf("Invalid Move\n");
            makeMove(&x, &y);
        }

        if (x == -1 && y == -1)
        {
            if (HINTS > 0)
            {
                giveHint(myBoard, realBoard, mines, &movesLeft, &x, &y);
                HINTS--;
            }
            else
            {
                printf("Out of Hints :( \n");
                while ((x == -1 && y == -1) || !isValid(x, y))
                {
                    makeMove(&x, &y);
                }
            }
        }

        gameOver = playMinesweeperUtil(myBoard, realBoard, mines, x, y, &movesLeft);

        if (!gameOver && movesLeft == 0)
        {
            printf("\nYou won!\n");
            gameOver = true;
            double elapsedTime = stopTimer();
            if (elapsedTime < fastestTimes[difficultyLevel])
            {
                printf("New fastest time!\n");
                fastestTimes[difficultyLevel] = elapsedTime;
                saveFastestTimes(fastestTimes);
            }
            printf("\nTime taken: %.2f seconds\n", elapsedTime);
        }
    }

    for (i = 0; i < SIDE; i++)
    {
        free(realBoard[i]);
        free(myBoard[i]);
    }
    free(realBoard);
    free(myBoard);

    for (i = 0; i < MINES; i++)
    {
        free(mines[i]);
    }
    free(mines);
}

bool chooseDifficultyLevel()
{
    int level;
    printf("Enter the Difficulty Level\n");
    printf("Press 0 for BEGINNER (9 * 9 Cells and 10 Mines)\n");
    printf("Press 1 for INTERMEDIATE (16 * 16 Cells and 40 Mines)\n");
    printf("Press 2 for ADVANCED (24 * 24 Cells and 99 Mines)\n");
    printf("Press 3 for CUSTOM\n");

    scanf("%d", &level);

    if (level == 0)
    {
        difficultyLevel = 0;
        SIDE = 9;
        MINES = 10;
        HINTS = 3;
        return true;
    }
    else if (level == 1)
    {
        difficultyLevel = 1;
        SIDE = 16;
        MINES = 40;
        HINTS = 10;
        return true;
    }
    else if (level == 2)
    {
        difficultyLevel = 2;
        SIDE = 24;
        MINES = 99;
        HINTS = 30;
        return true;
    }
    else if (level == 3)
    {
        printf("Enter the size of the matrix, the number of mines and the number of hints: ");
        scanf("%d %d %d", &SIDE, &MINES, &HINTS);

        if (SIDE <= 0 || MINES <= 0 || MINES >= SIDE * SIDE || HINTS < 0 || HINTS >= MINES)
        {
            printf("Invalid custom input.\n");
            SIDE = 9;
            MINES = 10;
            return false;
        }

        difficultyLevel = 3;
        return true;
    }
    else
    {
        printf("Invalid Option!!!\n");
        return false;
    }
}

int main()
{
    srand(time(NULL));
    bool flag = false;

    printf("\n\n\t\t\tWELCOME TO MINESWEEPER\n\n\n");

    while (!flag)
    {
        flag = chooseDifficultyLevel();
    }

    playMinesweeper();

    return 0;
}
