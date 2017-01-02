#include <iostream>
#include <stdlib.h>

using namespace std;
char place[6][7];
void board();
int drop(int b, char player);
bool check(int a, int b);
void cls();

int main()
{
    cout << " ______  ______  _    _  _    _  ______  ______  _______ " << endl;
    cout << "| _____||  __  || " << char(92) << "  | || " << char(92) << "  | ||  ____|| _____||___ ___|" << endl;
    cout << "| |     | |  | ||  " << char(92) << " | ||  " << char(92) << " | || |____ | |        | |   " << endl;
    cout << "| |     | |  | || " << char(92) << " " << char(92) << "| || " << char(92) << " " << char(92) << "| ||  ____|| |        | |   " << endl;
    cout << "| |____ | |__| || |" << char(92) << "   || |" << char(92) << "   || |____ | |____    | |   " << endl;
    cout << "|______||______||_| " << char(92) << "__||_| " << char(92) << "__||______||______|   |_|   " << endl;
    cout << endl;
    cout << "             ______  ______  _    _  ______              " << endl;
    cout << "            |  ____||  __  || |  | ||  __  |             " << endl;
    cout << "            | |___  | |  | || |  | || |__| |             " << endl;
    cout << "            |  ___| | |  | || |  | ||     _|             " << endl;
    cout << "            | |     | |__| || |__| || |" << char(92) << "  " << char(92) << "              " << endl;
    cout << "            |_|     |______||______||_| " << char(92) << "__" << char(92) << "             " << endl;

    cout << "\n\nPress Enter to Play!";

    cin.ignore();

    cls();

    board();

for(int a =0;a <= 5; a++) //Opens place for pieces
    {
        for(int b = 0; b<=6; b++)
            place[a][b] = ' ';
    }



    int column;//Holds user row choice
    int columnx = 0;//Holds selection value
    int charsPlaced = 0;//Number of pieces dropped so can end game if a draw
    bool gameWon = false;//Ends the Game
    char player = 'x';

    while(!gameWon)
    {
        if(columnx != -1)//Lets the player choose again if theres an error
        {

            if(player == 'x')
            {
                cout<<"Player 1 (o), please choose a column to drop a piece: ";
                player = 'o';
            }

            else
            {
                cout<<"Player 2 (x), please choose a column to drop a piece: ";
                player = 'x';
            }
        }

        while(true)//Input check
        {
            if(charsPlaced == 42)//Full board
                break;

            cin>>column;
            column--;

            if(column <=6 && column>= 0)
                break;

            else cout<< "\nPlease enter a value between 1 and 7 :";

            if (cin.fail()) //catch a non number
            {
                cin.clear();
                char newInt;
                cin>>newInt;
            }


        }

        if(charsPlaced == 42) break;//Checks for a Tie
            columnx = drop(column,player);//drops the piece

        if(columnx == -1) cout<<"Column is full\nPlease enter another number between 1 and 7:";

        else
        {
            gameWon = check(columnx, column);//checks for a winner
            charsPlaced ++;//another character has been successfully placed

            cls();
            board();//displayed updated board
        }
    }



    if(charsPlaced == 42)
    {
        cout<<"\n\nNo winner, Game was draw\n";

        return 0;
    }

    if(player == 'x')
        cout<<"The Winner is: Player 2!\n";

    else cout<<"The Winner is: Player 1!\n";

    return 0;

}

void board()
{
    cout << " 1  2  3  4  5  6  7\n";
    for(int a=0; a <=5; a++)
    {
        for (int b=0; b <=6; b++)
            cout << char(32) << char (32) << char (32);
            cout << endl;
        for (int b=0; b <=6 ; b++)
            cout << char(40) << place[a][b] << char (41);
            cout << endl;
         for (int b=0; b <=6; b++)
            cout << char(32) << char (32) << char (32);
            cout << endl;
    }
}

void cls()
{
    system("CLS");
    return;
}

    bool check(int a, int b)
{
    int vertical = 1;
    int horizontal = 1;
    int diagonalLeft = 1;
    int diagonalRight = 1;
    char player = place[a][b];
    int i, k;

    for(i = a +1; place[i][b] == player && i <= 5; i++, vertical++);//Check down
    for(i = a -1; place[i][b] == player && i >= 0; i--, vertical++);//Check up
    if(vertical >= 4)
        return true;

    for(k = b -1; place[a][k] == player && k >= 0; k--, horizontal++);//Check left
    for(k = b +1; place[a][k] == player && k <= 6; k++, horizontal++);//Check right
    if(horizontal >= 4)
        return true;

    for(i = a -1, k= b -1; place[i][k] == player && i>=0 && k >=0; diagonalLeft++, i --, k--);//up and left
    for(i = a +1, k = b+1; place[i][k] == player && i<=5 && k <=6; diagonalLeft++, i ++, k++);//down and right
    if(diagonalLeft >= 4)
        return true;

    for(i = a -1, k= b +1; place[i][k] == player && i>=0 && k <= 6; diagonalRight++, i--, k++);//up and right
    for(i = a +1, k= b -1; place[i][k] == player && i<=5 && k >=0; diagonalRight++, i++, k--);//down and left
    if(diagonalRight >= 4)
        return true;

    return false;

}

int drop(int b, char player)
{
    if(b>=0 && b<=6)
    {
        if(place[0][b] == ' ')
        {
            int i;
            for(i = 0; place[i][b] == ' '; i++)
                if(i == 5)
                {
                    place[i][b] = player;
                    return i;
                }
                i--;
                place[i][b] =player;
                return i;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}
