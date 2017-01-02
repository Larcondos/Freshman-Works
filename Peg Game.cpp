#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>

//Peg Game Program
//Jonathan Bennett, Brian Duricy, Montana Gessler
using namespace std;

//Functions
void Board_Output();
void Board_Start();
void Move();
void cls();
bool Check_Moves();
void High_Score(string, int);
bool IntCheck(string);

//Global Variables
char board[7][7];
bool quit;


int main()
{
    int numPegs;
    char start;
    bool b=true, check;
    string name, initials;

    //This outputs the rules
    cout<<" _____            _____               "<<endl
        <<"|  _  |___ ___   |   __|___ _____ ___ "<<endl
        <<"|   __| -_| . |  |  |  | .'|     | -_|"<<endl
        <<"|__|  |___|_  |  |_____|__,|_|_|_|___|"<<endl
        <<"          |___|                       "<<endl<<endl;

    cout<<"Rules"<<endl<<endl
        << "The aim of this game is to end with as few pegs left as possible." << endl
        << endl
        << "To do this, you must follow these rules: " << endl
        << endl
        << "1. Choose a peg you'd like to move. This peg must have an open slot, marked by a 'O', two spaces away in any direction." << endl
        << "2. Once you have chosen which row and column numbers are assigned to the peg, note the space's coordinates you want to  move to." << endl
        << "   2a. This action will eliminate the peg jumped over, and you are on your way to (possible) victory!" << endl
        << "3. You can only move pegs horizontally or vertically." << endl
        << "4. Spaces marked by an 'x' cannot be moved to." << endl
        << "   4a. Any number not between 1 and 7, inclusive, can also not be moved to." << endl
        << "5. If you would like to quit the game, press '00' for the moving peg." << endl
        << "The game will notify you when you have no possible moves left." << endl
        << "To avoid this dilemma, a hint is to play as close to the middle as possible." << endl
        << endl;

    //do-while loop for new games
    do{
        //Asks if you want start or quits and breaks out of loop
        cout<<"Hit any key to start or hit q to quit: ";
        cin>>start;

        if(start=='q')
        {
            break;
        }

        //Initials for high score
        cout<<"Enter your initials (3 Letters): ";
        cin >>name;
        initials=name.substr(0,3);

        //Clear screen and initialize board
        cls();
        numPegs=32;
        Board_Start();
        Board_Output();
        quit=false;

            //do-while loop to move
            do{
                Move();
                cls();

                //Checks to see if the player quit in the move function
                if(quit==false)
                {
                Board_Output();
                check=Check_Moves();
                numPegs--;
                }
                else
                {
                    //breaks out of moving loop to quit game
                    //numPegs=numPegs-28;
                    break;
                }
            }while(check==true);

    //Checks number of pegs left after there are no more moves
        if(numPegs==1)
        {
            cout<<" __     ______  _    _  "<<endl
                <<" \\ \\   / / __ \\| |  | | "<<endl
                <<"  \\ \\_/ / |  | | |  | | "<<endl
                <<"   \\   /| |  | | |  | | "<<endl
                <<"    | | | |__| | |__| | "<<endl
                <<"__  |_|  \\____/_\\____/  _ "<<endl
                <<"\\ \\        / /_   _| \\ | |"<<endl
                <<" \\ \\  /\\  / /  | | |  \\| |"<<endl
                <<"  \\ \\/  \\/ /   | | | . ` |"<<endl
                <<"   \\  /\\  /   _| |_| |\\  |"<<endl
                <<"    \\/  \\/   |_____|_| \\_|"<<endl<<endl;
        }
        else if (numPegs > 1 && numPegs <= 4)
        {
            cout << "         GAME OVER" << endl
                 << "Good job! Almost there =)" << endl
                 << "You had " << numPegs << " pegs remaining" << endl;
        }
        else if (numPegs > 4 && numPegs <= 10)
        {
            cout << "         GAME OVER" << endl
                 << "Nice try! Keep practicing" << endl
                 << "You had " << numPegs << " pegs remaining" << endl;
        }
        else if (numPegs > 10 && numPegs <=15)
        {
            cout << "         GAME OVER" << endl
                 << "Practice is Key - Keep trying!" << endl
                 << "You had " << numPegs << " pegs remaining" << endl;
        }
        else
        {
            cout<<"      GAME OVER =( "<<endl
                << "You had " << numPegs << " pegs remaining" << endl;
        }

        //High Score
        High_Score(initials,numPegs);

    }while(b==true);

    //Thanks the player and ends program
    cout<<"Thank you for playing!"<<endl;
    return 0;
}

void Board_Start()
{
    //Nested for loops to initialize the board

    //Loops for the first 2 rows
    for(int row=0;row<2;row++)
    {
        for(int col=0;col<7;col++)
        {
            //Puts x's on the edges and T's on in the middle
            if(col<2 || col>4)
            {
                board[row][col]='x';
            }
            else
            {
                board[row][col]='T';
            }
        }
    }

    //For loops for the middle 3 rows
    for(int row=2;row<5;row++)
    {
        for(int col=0;col<7;col++)
        {
            //creates 3 rows of T's with a O in the middle
            if(col==3 && row==3)
            {
                board[row][col]='O';
            }
            else
            {
                board[row][col]='T';
            }
        }
    }

    //For loops for the last 2 rows
    for(int row=5;row<7;row++)
    {
        for(int col=0;col<7;col++)
        {
            if(col<2 || col>4)
            {
                board[row][col]='x';
            }
            else
            {
                board[row][col]='T';
            }
        }
    }
    return;
}

void Board_Output()
{
    //Out puts the board on the screen

    //This puts column numbers on above the board
    cout<<"   ";
    for(int x=1;x<8;x++)
    {
        cout<<x<<" ";
    }
    cout<<endl<<endl;

    //Creates each row of board
    for(int i=0;i<7;i++)
    {
        //This adds the row numbers on the side of the board
        cout<<i+1<<"  ";
        for(int j=0;j<7;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void Move()
{
    //This function moves the pegs around the board. It takes an incoming peg's coordinates and the desired location to move

    //variables for the moving peg's location with a for loop condition
    string smrow, smcol;
    int mrow, mcol, t=0;
    bool mricheck, mcicheck;

    //Asks for the peg to move and checks if it is a valid peg to move
    do{
        //Asks for the to move's location
        cout<<"Enter the moving peg's row then column number: ";
        cin>>smrow;
        cin>>smcol;

        //Checks to see if the inputs are valid integers and not characters (They will break the program)
        mricheck=IntCheck(smrow);
        mcicheck=IntCheck(smcol);

        //If statement that continues if both the row and col can be integers
        if(mricheck==true && mcicheck==true)
        {
            //makes and int out of the string row and col
            mrow=atoi(smrow.c_str());
            mcol=atoi(smcol.c_str());

            //decrements the incoming coordinates to match with the array coordinates
            mrow--;
            mcol--;

            //Checks for quit command
            if(mrow==-1 && mcol==-1)
            {
                break;
            }
            else
            {
                //Checks if the moving peg location is on the board
                if(mrow>-1 && mrow<7 && mcol>-1 && mcol<7)
                {
                    //Checks if there is a peg there
                    if(board[mrow][mcol]=='T')
                    {
                        //Checks to see if there is a valid move from the location
                        if((board[mrow+1][mcol] == 'T' && board[mrow+2][mcol] == 'O') || (board[mrow-1][mcol] == 'T' && board[mrow-2][mcol] == 'O') || (board[mrow][mcol+1] == 'T' && board[mrow][mcol+2] == 'O') || (board[mrow][mcol-1] == 'T' && board[mrow][mcol-2] == 'O'))
                        {
                            t=1;
                        }
                        else
                        {
                            cout<<"There are no moves for that peg. Try again. "<<endl;
                        }
                    }
                    else
                    {
                        cout<<"\nSorry there is no peg there. Try again."<<endl;
                    }
                }
                else
                {
                    cout<<"\nInvalid move. Can only use numbers 1-7."<<endl;
                }
            }
        }
        else
        {
            cout<<"\n Invalid entry. Needs to be a number 1-7 and not a character or string."<<endl;
        }
    }while(t==0);

    //Continues with initial quit and changes the quit variable
    if(mrow==-1 && mcol==-1)
        {
            quit=true;
        }
    else{
        //Variables for desired location's coordinates
        string slrow, slcol;
        int lrow, lcol, rowdiff, coldiff;
        bool lricheck, lcicheck;
        t=0;

        //Asks and checks to see if the location is valid
        do{
            //Asks for desired location's coordinates
            cout<<"Enter the desired location row then column number: ";
            cin>>slrow;
            cin>>slcol;

            //Checks to see if the row and col can be integers
            lricheck=IntCheck(slrow);
            lcicheck=IntCheck(slcol);

            //if statement that requires both row and col to be able to be integers
            if(lricheck==true && lcicheck==true)
            {
                //converts the string row and col to integers
                lrow=atoi(slrow.c_str());
                lcol=atoi(slcol.c_str());

                //decrements the incoming coordinates to match with the array coordinates
                lrow--;
                lcol--;

                //The difference between the moving peg and location
                rowdiff=mrow-lrow;
                coldiff=mcol-lcol;

                //Checks to see if the location is on the board
                if(lrow>-1 && lrow<7 && lcol>-1 && lcol<7)
                {
                    //Checks to see if location is empty
                    if(board[lrow][lcol]=='O')
                    {
                        //checks if the location is 2 away
                        if(((rowdiff==2 || rowdiff==-2) && coldiff==0) || ((coldiff==2 || coldiff==-2) && rowdiff==0))
                        {
                            //checks if a peg 1 away is being jumped
                            if(board[mrow-(rowdiff/2)][mcol-(coldiff/2)]=='T')
                            {
                                t=1;
                            }
                            else
                            {
                                cout<<"Error. No peg is being jumped. Please, try again."<<endl;
                            }
                        }
                        else
                        {
                            cout<<"Error. Invalid Move. Please, try again."<<endl;
                        }
                    }
                    else
                    {
                        cout<<"\nSorry there is a peg there. Try again."<<endl;
                    }
                }
                else
                {
                    cout<<"\nInvalid move. Can only use numbers 1-7."<<endl;
                }
            }
            else
            {
                cout<<"\n Invalid entry. Needs to be a number 1-7 and not a character or string."<<endl;
            }
        }while(t==0);

        //"Moves the pegs" - changes the characters in the locations
        board[mrow][mcol]='O';
        board[mrow-(rowdiff/2)][mcol-(coldiff/2)]='O';
        board[lrow][lcol]='T';
    }
    return;
}

void cls()
{
    //Clear screen
    system("CLS");
    return;
}

 bool Check_Moves()
 {
    //Checks to see if there are moves available

    //Variable that answers if there are any moves
    bool moves=false;

    //loops that check each spot for at least one move
    for(int crow=0;crow<7;crow++)
    {
        for(int ccol=0;ccol<7;ccol++)
        {
            //Checks if a location has a peg
            if(board[crow][ccol]=='T')
            {
                //Checks if surrounding location of peg creates one move
                if((board[crow+1][ccol] == 'T' && board[crow+2][ccol] == 'O') || (board[crow-1][ccol] == 'T' && board[crow-2][ccol] == 'O') || (board[crow][ccol+1] == 'T' && board[crow][ccol+2] == 'O') || (board[crow][ccol-1] == 'T' && board[crow][ccol-2] == 'O'))
                {
                      moves = true;
                }
            }

        }
    }
    return(moves);
}

void High_Score(string name, int intpegs)
{

    //Variable initialization
    const int NUM=10;
    int intDelim, i, intPos, place, lastplace;
    string pegs, strRead, strPlayer, score;
    string playersort[NUM][2];
    string HighScores[NUM][2];
    int scores[NUM];


    //Changes intpegs into a string pegs
    stringstream convert;
    convert<<intpegs;
    pegs=convert.str();

    intPos=0;

    //Reads in the High Scores text file
    ifstream inFile;
    inFile.open("HighScores.txt");

    //Reads in the names and high scores
    while (getline(inFile, strRead))
    {
        intDelim=-1;

        for(i=0; i<strRead.length(); i++)
        {
            if(strRead[i]==':')
            {
                intDelim=i;
                break;
            }
        }
        HighScores[intPos][0]=strRead.substr(0,intDelim);

        HighScores[intPos][1]=strRead.substr(intDelim+1, strRead.length()-(intDelim+1));
        intPos++;
    }
    inFile.close();


    //Removes the lowest score and sorts the list if the new score is a high score
    //Makes an integer of the last one on the list
    lastplace=atoi(HighScores[NUM-1][1].c_str());
    //Checks to see if there is a high score
    if(intpegs<lastplace)
    {
        //Replaces worst high score with the newest
        HighScores[NUM-1][1]=pegs;
        HighScores[NUM-1][0]=name;

        //Turns the string scores into int scores
        for(int k=0;k<NUM;k++)
        {
            scores[k]=atoi(HighScores[k][1].c_str());

            //Sets the sorting array to 0
            playersort[k][1]="0";
        }

        //Sorts the high score array by creating a new array
        for(i=0;i<NUM;i++)
        {
            //This is the place in the list
            place=0;

            //compares one value to another
            for(int j=0;j<NUM;j++)
            {
                if(scores[i]>scores[j])
                {
                    place++;
                }
            }

            //If a score is equal to another, this prevents that place from being overwritten and a place from being empty
            while(playersort[place][1]!="0")
            {
                place++;
            }
            //Places the name and score into the correct order
            playersort[place][1]=HighScores[i][1];
            playersort[place][0]=HighScores[i][0];
        }

        //Outputs newly sorted scores
        cout<<"\nCongratulations! New High Score!"<<endl<<endl
            <<"        High Scores"<<endl
            <<"        -----------"<<endl;
        for(i=0; i<NUM;i++)
        {
            cout<<"        "<<playersort[i][0]<<"......"<<playersort[i][1]<<endl;
        }


        //saves the new sorted file
        ofstream outFile;
        outFile.open("HighScores.txt");

        for(i=0;i<NUM;i++)
        {
            outFile<<playersort[i][0]<<':'<<playersort[i][1]<<endl;
        }
        outFile.close();
    }
    else
    {
        //Outputs scores with no changes
        cout<<"        High Scores"<<endl
            <<"        -----------"<<endl;
        for(i=0; i<NUM;i++)
        {
            cout<<"        "<<HighScores[i][0]<<"......"<<HighScores[i][1]<<endl;
        }
    }
    return;
}

bool IntCheck(string rc)
{
    bool strIsNum=false;

        //loop to look at each individual char in the string
        for(int i=0;i<rc.length();i++)
        {
            //checks to see if the char is 0-9
            if( (static_cast<int>(rc[i]))>47 && (static_cast<int>(rc[i]))<58)
            {
                strIsNum=true;
            }
            else
            {
                //if one char is not 0-9 it makes the string an invalid int
                strIsNum=false;
                break;
            }
        }
    return strIsNum;
}
