#include <iostream>
#include <stdlib.h>
using namespace std;

int checkWin();

char square[10]= {'0','1','2','3','4','5','6','7','8','9'};

void drawBoard(void);
void clearscreen (void);
void bell(void);

int main()
{
    int player = 1, i = -1, choice;
    char mark;


    do
    {

        player = (player % 2)? 1:2 ;

        drawBoard();

        cout << "Player " << player << ", enter a number: ";
        cin >> choice;

        if (player == 1)
            mark = 'X';
        else
            mark = '0';

        if (choice == 1 && square [1] == '1')
            square[1] = mark;
        else if (choice == 2 && square [2] == '2')
            square[2] = mark;
        else if (choice == 3 && square [3] == '3')
            square[3] = mark;
        else if (choice == 4 && square [4] == '4')
            square[4] = mark;
        else if (choice == 5 && square [5] == '5')
            square[5] = mark;
        else if (choice == 6 && square [6] == '6')
            square[6] = mark;
        else if (choice == 7 && square [7] == '7')
            square[7] = mark;
        else if (choice == 8 && square [8] == '8')
            square[8] = mark;
        else if (choice == 9 && square [9] == '9')
            square[9] = mark;
        else
        {
            cout <<"Invalid move.";
            bell;
            player--;

        }
        i = checkWin();
        player++;

     } while(i==-1);

    drawBoard();

    if (i == 1)
        cout << "PLAYER " << --player << " IS THE WINNER";
    else
    cout << "==>Game Draw";


    return 0;
}

int checkWin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] == '1' && square[2] == '2' && square[3] == '3' &&
             square[4] == '4' && square[5] == '5' && square[6] == '6' &&
             square[7] == '7' && square[8] == '8' && square[9] == '9')
        return 0;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;

}

void clearscreen()
{
    system("CLS");
}

void bell()
{
    cout << "\a";
}

void drawBoard()
{
    clearscreen();

    cout << "\n\nTic Tac Toe Game\n\n";
    cout << "Player 1 (X) -  Player 2 (0)\n\n\n";
    cout << "     |     |     " << endl;
    cout << "  " << square[1] <<"  |  " << square[2] <<"  |  " << square[3] <<"  " << endl;
    cout << "     |     |     " << endl;
    cout << "-----------------" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] <<"  |  " << square[5] <<"  |  " << square[6] <<"  " << endl;
    cout << "     |     |     " << endl;
    cout << "-----------------" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] <<"  |  " << square[8] <<"  |  " << square[9] <<"  " << endl;
}
