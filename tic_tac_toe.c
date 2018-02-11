#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int b[10] = {-11, -11, -11, -11, -11, -11, -11, -11, -11, -11};
int p=1, f;

void menu();
void draw();
void drawSampleBoard();
void putValue(int pos);
void setValue();
void play();
int checkDraw();
int checkWin();


COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main()
{
    char ch = 'Y';

    while(ch == 'Y' || ch == 'y')
    {
        if(f == 1)
        {
            int i;
            for(i=0; i<10; i++)
                b[i] = -11;

            f = 0;
            p = 1;
        }

        play();

        gotoxy(25, 30);
        printf("Do you want to play again? (Y/N) ");
        ch = getchar();
        ch = getche();
        if(ch == 'Y' || ch == 'y')
            f = 1;
    }


    system("cls");
    gotoxy(25, 15);
    printf("Thanks for Playing our game!");
    getch();

    return 0;
}

void menu()
{
    system("cls");
    gotoxy(35, 5);
    printf("Player 1 : X\n");
    gotoxy(35, 6);
    printf("Player 2 : O\n");
}

void drawSampleBoard()
{
    int i, j, k=1, c=1;

    gotoxy(4, 7);
    printf("Board positions\n");
    printf("   -----------------");


    for(i=10; i<21; i++)
    {
        gotoxy(7, i);
        printf("|     |");
    }

    gotoxy(2, 13);
    printf("-----------------");
    gotoxy(2, 17);
    printf("-----------------");

    for(j=11; k<10; j=j+4)
    {
        for(i=4; i<20; i=i+6)
        {
            gotoxy(i, j);
            printf("%d", k++);
        }
    }
}

void draw()
{
    drawSampleBoard();

    int i;

    for(i=10; i<21; i++)
    {
        gotoxy(37, i);
        printf("|     |");
    }

    gotoxy(32, 13);
    printf("-----------------");
    gotoxy(32, 17);
    printf("-----------------");

    for(i = 1; i < 10; i++)
        putValue(i);
}

void putValue(int pos)
{
    char ch = ' ';

    if(b[pos] == 1)
        ch = 'X';
    else if(b[pos] == 0)
        ch = 'O';

    switch(pos)
    {
        case 1:
            gotoxy(34, 11);
            printf("%c", ch);
            break;
        case 2:
            gotoxy(40, 11);
            printf("%c", ch);
            break;
        case 3:
            gotoxy(46, 11);
            printf("%c", ch);
            break;
        case 4:
            gotoxy(34, 15);
            printf("%c", ch);
            break;
        case 5:
            gotoxy(40, 15);
            printf("%c", ch);
            break;
        case 6:
            gotoxy(46, 15);
            printf("%c", ch);
            break;
        case 7:
            gotoxy(34, 19);
            printf("%c", ch);
            break;
        case 8:
            gotoxy(40, 19);
            printf("%c", ch);
            break;
        case 9:
            gotoxy(46, 19);
            printf("%c", ch);
            break;
    }
}

void setValue()
{
    system("cls");
    menu();
    draw();

    int position;

    if(p % 2 == 1)
    {
        gotoxy(25, 25);
        printf("Choose a position (Player 1) : ");
        scanf("%d", &position);

        if(position < 1 || position > 9)
        {
            while(position < 1 || position > 9)
            {
                system("cls");
                menu();
                draw();
                gotoxy(25, 26);
                printf("Choose a position between 1 to 9.");
                gotoxy(25, 25);
                printf("Choose a position (Player 1) : ");
                scanf("%d", &position);
            }
        }

        if(b[position] == -11)
            b[position] = 1;
        else
        {
            while(b[position] != -11)
            {
                system("cls");
                menu();
                draw();
                gotoxy(25, 26);
                printf("Choose a free cell! ");
                gotoxy(25, 25);
                printf("Choose a position (Player 1) : ");
                scanf("%d", &position);
            }

            b[position] = 1;
        }
    }
    else
    {
        gotoxy(25, 25);
        printf("Choose a position (Player 2) : ");
        scanf("%d", &position);

        if(position < 1 || position > 9)
        {
            while(position < 1 || position > 9)
            {
                system("cls");
                menu();
                draw();
                gotoxy(25, 26);
                printf("Choose a position between 1 to 9.");
                gotoxy(25, 25);
                printf("Choose a position (Player 2) : ");
                scanf("%d", &position);
            }
        }

        if(b[position] == -11)
            b[position] = 0;
        else
        {
            while(b[position] != -11)
            {
                system("cls");
                menu();
                draw();
                gotoxy(25, 26);
                printf("Choose a free cell!");
                gotoxy(25, 25);
                printf("Choose a position (Player 2) : ");
                scanf("%d", &position);
            }

            b[position] = 0;
        }
    }

    p++;
}

void play()
{
    int gameValue;

    system("cls");
    menu();
    draw();
    setValue();
    draw();

    gameValue = checkWin();
    if(gameValue == 0)
    {
        gotoxy(55, 15);
        printf("MATCH IS DRAW!");
    }
    else if(gameValue == 1)
    {
        gotoxy(55, 15);
        printf("PLAYER 1 WIN!");
    }
    else if(gameValue == 2)
    {
        gotoxy(55, 15);
        printf("PLAYER 2 WIN!");
    }
    else
        play();
}


int checkDraw()
{
    if(p > 9)
        return 0;
}

int checkWin()
{
    int v;

    if(p > 9)
        return 0;

    v = b[1] + b[2] + b[3];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[4] + b[5] + b[6];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[7] + b[8] + b[9];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[1] + b[4] + b[7];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[2] + b[5] + b[8];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[3] + b[6] + b[9];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[1] + b[5] + b[9];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

    v = b[3] + b[5] + b[7];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;

        v = b[9] + b[3] + b[6];
    if(v == 3)
        return 1;
    if(v == 0)
        return 2;
}
