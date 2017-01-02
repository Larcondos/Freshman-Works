#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
using namespace std;

// Function Declaration Function Declaration Function Declaration Function Declaration Function Declaration Function Declaration Function Declaration

void CheckSave();
void FinalRoomDoor();
void CheckInventory();
void MainRoomScene();
void GeneralChoice();
void ClearScreen();
void Cheat();
void Intro();
void SaveKeysCheck();
void ChooseDoor();
void FinalRoom();
void FireRoom();
void IceRoom();
void GrassRoom();
void WaterRoom();
void ReadPause();
void SaveItemsCheck();
void DeleteSave();
void Win();

// Variables Variables Variables Variables Variables Variables Variables Variables Variables Variables Variables Variables Variables Variables

double mod;
double i;
static int decision;

int FinalDoorOpen = 0;
int firekey = 0;
int firekeygrab = 0;
int waterkey = 0;
int waterkeygrab = 0;
int grasskey = 0;
int grasskeygrab = 0;
int icekey = 0;
int icekeygrab = 0;

int wood = 0;                          // 1 means it exists.
int torch = 0;                         // 1 means it exists, 2 means it is lit
int bucket = 0;                        // 1 means it exists, 2 means it is full.
int swim = 0;                          // 0 means you cant swim, 1 means you can.

string name;
string data;

ifstream inFile;
ofstream outFile;

// IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain IntMain

int main()
{
    CheckSave();
    Intro();
    GeneralChoice();
    FinalRoom();
    Win();
    return 3;

}

// Functions Functions Functions Functions Functions Functions Functions Functions Functions Functions Functions Functions Functions Functions

void CheckSave()                    //Checks to see if Save exists.
{

    inFile.open("Save.txt");

    if (inFile.fail())
    {

        cout << "No save detected, you must be new!" << endl;
        cout << "Please input your name!\n";
            cin >> name;
        cout << "Alright then " << name << ", we made a save for you!";
        outFile.open("Save.txt");
            outFile << name;
        outFile.close();
        inFile.close();
        inFile.open("Save.txt");
            ReadPause();
        ClearScreen();

    }
    cout << "Save has been detected! Welcome back ";

    inFile >> data;
    cout << data << "!";

    inFile.close();


    SaveKeysCheck();
    SaveItemsCheck();

    ReadPause();
    ClearScreen();
}

void ChooseDoor()                   //Choice of door to open, and goes to that room.
{
    cout << "Which door would you like to enter?\n"
         << "0. Nevermind, I don't want to enter a room.\n"
         << "1. The Door surrounded in flame.\n"
         << "2. The Door under the water.\n"
         << "3. The Door covered in plants.\n"
         << "4. The Door covered with ice.\n";

        cin >> decision;

        switch(decision)
        {
            case 0:
                cout << "Returning to the main room.\n\n";
                Sleep(2500);
                break;
            case 1:
                cout << "You walk through the flames...\n\n";
                Sleep(2500);
                FireRoom();
                break;
            case 2:

                if (swim == 1)
                {
                cout << "You dive into the water and enter the door...\n\n";
                Sleep(2500);
                WaterRoom();
                }
                else
                {
                    cout << "\nYou jump into the water, but can't swim well so you climb back out.\n";
                    Sleep(2500);
                    break;
                }
                break;
            case 3:
                cout << "Brushing aside a few plants, you enter the door...\n\n";
                Sleep(2500);
                GrassRoom();
                break;
            case 4:
                cout << "You twist the handle and the ice breaks off around the hidges, and you enter...\n\n";
                Sleep(2500);
                IceRoom();
                break;
            default:
                cout << "That's not a valid option.";
                Sleep(2500);
        }
        ClearScreen();
}

void GeneralChoice()                //The general method used to decide what to do. AKA Main Room
{
    while (FinalDoorOpen != 1)
    {
    cout << "\nWhat would you like to do? (Input Number next to decision)"
         << "\n1. Enter a door."
         << "\n2. Examine the Room."
         << "\n3. Check my inventory."
         << "\n4. Open that giant door."
         << "\n5. Exit the game.\n"
         << "\n9. Delete your save...\n";

    cin >> decision;
    cout << endl;

    ClearScreen();

    switch(decision)
        {
            case 1:
                ChooseDoor();
                break;
            case 2:
                cout << "You look around the room.\n";
                if (swim == 0)
                {
                    cout << "You notice a book on the floor titled, 'How to swim in 10 easy seconds', would you like to read it?\n"
                         << "\n1. Yes \n2. No\n";
                    cin >> decision;

                    switch (decision)
                    {
                        case 1:
                        {
                            cout << "\nYou read the manual in about 10 seconds, and feel confident you can swim now!\n";
                            ofstream outFile("swim.txt");
                            swim = 1;
                        }
                            break;
                        case 2:
                            cout << "\nYou ignore the book, wondering why it is here.\n";
                    }

                }
                else
                    cout << "You find nothing of interest, other than the four doors.\n";
                break;
            case 3:
                CheckInventory();
                break;
            case 4:
            decision = 1;
                FinalRoomDoor();
                break;
            case 5:
                cout << "Thank you for playing!\n\n";
                exit(1);
                break;
            case 9:
                cout << "Are you sure you want to delete save???"
                     << "\n1. Yes\n2. No";
                     cin >> decision;
                     if (decision == 1)
                        {
                            DeleteSave();
                        }
                break;
            case 8675309:
                Cheat();
                break;
            default:
                cout << "That's not a valid option.";
        }

    }
return;
}

void CheckInventory()                    //Used at any time to check inventory.
{
    if (firekey == 0 && grasskey == 0 && icekey == 0 && waterkey == 0 && bucket == 0 && bucket == 0 && torch == 0 && torch == 0 && wood == 0)
    {
        cout << "Your inventory is empty currently.\n";
    }
    if (firekey == 1 && waterkey == 1 && grasskey == 1 && icekey == 1)
    {
        cout << "You have all the keys! Might want to open that giant door...\n\n";
    }
    else if (firekey == 1 || waterkey == 1 || grasskey == 1 || icekey == 1)
        {
            cout << "You currently have the ";
        if (firekey == 1)
        {
            cout << "Fire Key.  ";
        }
        if (grasskey == 1)
        {
            cout << "Grass Key.  ";
        }
        if (icekey == 1)
        {
            cout << "Ice Key.  ";
        }
        if (waterkey == 1)
        {
            cout << "Water Key.";
        }
            cout << "\n";
        }
    if (bucket == 1 || bucket == 2 || torch == 1 || torch == 2 || wood == 1)
    {
        cout << "\nYou are currently equipped with...\n";
        if (bucket == 1)
        {
            cout << "A fine bucket.  ";
        }
        if (bucket == 2)
        {
            cout << "A fine bucket full of water.  ";
        }
        if (torch == 1)
        {
            cout << "An unlit torch.  ";
        }
        if (torch == 2)
        {
            cout << "A lit torch, careful it's hot!  ";
        }
        if (wood == 1)
        {
            cout << "A bundle of firewood.";
        }
        cout << "\n";
    }
}

void FinalRoomDoor()                //Used to check if you can open final door.
{
    if (firekey == 1 && waterkey == 1 && grasskey == 1 && icekey == 1)
    {
        cout << "You have all keys! The door opens...";
        Sleep(2500);
        FinalDoorOpen = 1;

    }
    else
    {
    cout << "You appear to be missing some keys...\n";
    if (firekey == 0 && grasskey == 0 && icekey == 0 && waterkey == 0)
    {
        cout << "\nYou don't have any keys yet!\n";
    }
    if (firekey == 0)
    {
        cout << "\nYou're missing the Fire Key.";
    }
    if (grasskey == 0)
    {
        cout << "\nYou're missing the Grass Key.";
    }
    if (icekey == 0)
    {
        cout << "\nYou're missing the Ice Key.";
    }
    if (waterkey == 0)
    {
        cout << "\nYou're missing the Water Key.\n";
    }

    }
}

void ClearScreen()                  //Used to Clear Screen (wow who would have guessed it)
{
    system("CLS");
}

void Cheat()                        //Used to unlock final door at any time.
{
    cout << "Congratulations! You've actually magically found all the keys on the floor!\n";

    firekey = 1;
    waterkey = 1;
    grasskey = 1;
    icekey = 1;

    return;
}

void Intro()                        //The intro which displays the games title and countdown to start.
{
    for (i = 10.0; i > 0; --i)
    {
    cout << "The game will start in " << i << " seconds!" << endl;
    i= i +0.50;

    double i2 = 1;

    mod = fmod(i,i2);

    if (mod == 0)
    cout <<  " .----------------.  .----------------.  .----------------.  .----------------." << endl <<
            "  | .--------------. || .--------------. || .--------------. || .--------------. |" << endl <<
            "  | |  ___  ____   | || |  _________   | || |  ____  ____  | || |    _______   | |" << endl <<
            "  | | |_  ||_  _|  | || | |_   ___  |  | || | |_  _||_  _| | || |   /  ___  |  | |" << endl <<
            "  | |   | |_/ /    | || |   | |_  \\_|  | || |   \\ \\  / /   | || |  |  (__ \\_|  | |" << endl <<
            "  | |   |  __'.    | || |   |  _|  _   | || |    \\ \\/ /    | || |   '.___`-.   | |" << endl <<
            "  | |  _| |  \\ \\_  | || |  _| |___/ |  | || |    _|  |_    | || |  |`\\____) |  | |" << endl <<
            "  | | |____||____| | || | |_________|  | || |   |______|   | || |  |_______.'  | |" << endl <<
            "  | |              | || |              | || |              | || |              | |" << endl <<
            "  | '--------------' || '--------------' || '--------------' || '--------------' |" << endl <<
            "  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
    else
    cout <<  "       .----------------.  .----------------.  .----------------.  .----------------." << endl <<
            "        | .--------------. || .--------------. || .--------------. || .--------------. |" << endl <<
            "        | |  ___  ____   | || |  _________   | || |  ____  ____  | || |    _______   | |" << endl <<
            "        | | |_  ||_  _|  | || | |_   ___  |  | || | |_  _||_  _| | || |   /  ___  |  | |" << endl <<
            "        | |   | |_/ /    | || |   | |_  \\_|  | || |   \\ \\  / /   | || |  |  (__ \\_|  | |" << endl <<
            "        | |   |  __'.    | || |   |  _|  _   | || |    \\ \\/ /    | || |   '.___`-.   | |" << endl <<
            "        | |  _| |  \\ \\_  | || |  _| |___/ |  | || |    _|  |_    | || |  |`\\____) |  | |" << endl <<
            "        | | |____||____| | || | |_________|  | || |   |______|   | || |  |_______.'  | |" << endl <<
            "        | |              | || |              | || |              | || |              | |" << endl <<
            "        | '--------------' || '--------------' || '--------------' || '--------------' |" << endl <<
            "        '----------------'  '----------------'  '----------------'  '----------------' " << endl;

    Sleep (500);
    ClearScreen();
    }

    cout << " What began as an average day, turned into a disaster.\n I was washing my hair with shampoo, "
    << "when I accidentally dropped the shampoo onto my cat.\n The cat then began multiplying, "
    << "apparently the cat was allergic to my shampoo, and the side effect\n was splitting of the "
    << "cat\'s cells to multiply rapidly. Fearing for my life, I\n ran outside when I suddenly "
    << "fell into a deep hole in the backyard. The sunlight faded, and when\n I awoke I found "
    << "myself inside a dimly lit room, with 4 strange doors, and one very large door..."
    << "\n\n Press Enter to begin your escape...";
    cin.ignore();

    ClearScreen();
return;
}

void SaveKeysCheck()                //Checks save file to see if you have any keys.
{
    inFile.open("firekey.txt");

    if (inFile.good())
    {
        firekey = 1;
        inFile.close();
    }inFile.open("icekey.txt");

    if (inFile.good())
    {
        icekey = 1;
        inFile.close();
    }inFile.open("grasskey.txt");

    if (inFile.good())
    {
        grasskey = 1;
        inFile.close();
    }inFile.open("waterkey.txt");

    if (inFile.good())
    {
        waterkey = 1;
        inFile.close();
    }
}

void FinalRoom()                    //The final room of the game's contents.                          INCOMPLETE
{
   ClearScreen();
   cout << "You walk into the large door, taking note of your surroundings.\n" ;
   cout << "A giant golem walks up to you, and begins talking.\n\n";

   cout << "SO. YOU HAVE MADE IT TO THE EXIT. BUT YOU MUST PASS MY FINAL TEST.\n"
        << "TELL ME YOUNG WARRIOR, WHAT IS 2 PLUS 2??? ANSWER CORRECTLY OR DIE.\n";
        cin >> decision;
        if (decision == 4)
        {
            cout << "CONGRATULATIONS MORTAL, YOU ARE A WINNER. WALK THROUGH."
                 << "\n\nYou walk past the golem, looking back as he smiles at you. \nYou walk into the open plain, and have escaped...";
                 Sleep(10000);
            return;
        }
        else
        {
            cout << "YOU ARE WRONG.\n"
                 << "These are the last words you hear, before a giant fist smashes you.\n"
                 << "You are dead, please try again.\n\n";
                 exit(2);
        }

    return;
}

void FireRoom()                     //The room of fire's contents.                                    FINISHED -- USE AS TEMPLATE VVV
{
    ClearScreen();

    cout << "\nYou are in the Fire Room, what would you like to do? (Input Number next to decision)"
         << "\n1. Return to Main Room."
         << "\n2. Examine the Room."
         << "\n3. Attempt to grab the room's key.\n";

         cin >> decision;

         ClearScreen();

         switch (decision)
         {
             case 1:
                cout << "\nHeading back to the main room...\n";
                ReadPause();
                GeneralChoice();
                break;
             case 2:
                if (torch == 1)
                {
                    cout << "You realize if you put your torch into the lava a little, it would probably catch fire, would you like to?"
                         << "\n1. Yes \n2. No\n";
                         cin >> decision;
                    if (decision == 1)
                    {
                        cout << "You light your torch.";
                        Sleep(2500);
                        ofstream outFile("torch2.txt");
                        torch = 2;
                    }
                    else
                    cout << "You don't light torch.";
                }
                if (firekey == 1)
                {
                    cout << "The pedestal where the key was is now empty, and there is a path to the pedestal.";
                    Sleep (2500);
                    FireRoom();
                }
                else if (firekeygrab == 1)
                    {
                        cout << "There is a nice path to the key. You could probably take it.";
                        Sleep(2500);
                        FireRoom();
                    }
                else if (bucket == 2)
                {
                    cout << "\nYou look around and notice that the floor is lava, except right where you are standing.\n";
                    cout << "Your bucket is full of water, would you like to throw it? (1 for no, 2 for yes)\n";
                    cin >> decision;

                    if (decision == 2)
                    {
                        cout << "\nYou toss the water, and it cools off a path straight to the key!\n";
                        Sleep(2500);
                        firekeygrab = 1;
                    }
                    else
                        cout << "\nYou don't throw your water.\n";
                }
                else
                    {
                    cout << "\nYou look around and notice that the floor is lava, except right where you are standing.\n";
                    Sleep(2500);
                    FireRoom();
                    }


                FireRoom();
             case 3:
                if (firekey == 1)
                {
                    cout << "\nYou have already taken the key!";
                    Sleep(2500);
                    FireRoom();
                }
                else if (firekeygrab == 1)
                    {
                    cout << "\nYou successfully snatch the key, and return to the main room.\n";
                    ReadPause();
                    firekey = 1;
                    ofstream outFile("firekey.txt");
                    firekeygrab = 0;
                    GeneralChoice();
                    }
                else
                    cout << "\nYou try to grab the key, but there is lava everywhere, so you can't grab it.\n";
                    ReadPause();
                    FireRoom();
         }



return;
}

void WaterRoom()                     //The room of water's contents.
{
    ClearScreen();

    cout << "\nYou are in the Water Room, what would you like to do? (Input Number next to decision)"
         << "\n1. Return to Main Room."
         << "\n2. Examine the Room."
         << "\n3. Attempt to grab the room's key.\n";

         cin >> decision;

         ClearScreen();

         switch (decision)
         {
             case 1:
                cout << "\nHeading back to the main room...\n";
                ReadPause();
                GeneralChoice();
                break;
             case 2:
                if (bucket == 0)
                {
                    cout << "You notice a small bucket on the floor, and take it with you.";
                    Sleep(2500);
                    ofstream outFile("bucket1.txt");
                    bucket = 1;
                }
                if (bucket == 1)
                {
                    cout << "\nYour bucket is currently empty, and you feel the need to fill it with water.\n";
                    cout << "Would you like to fill your bucket? (1 for no, 2 for yes)\n";
                    cin >> decision;

                    if (decision == 2)
                    {
                        cout << "\nYou scoop down and fill your bucket with water.";
                        ofstream outFile("bucket2.txt");
                        bucket = 2;
                    }
                    else
                        cout << "\nYou don't fill your bucket.\n";
                }
                if (waterkey == 1)
                {
                    cout << "The pedstal where the key was is empty.";
                    Sleep (2500);
                    WaterRoom();
                }
                else if (swim == 1)
                    {
                        cout << "You're a good swimmer, and could probably grab the key.";
                        Sleep(2500);
                        WaterRoom();
                    }
                else
                    {
                    cout << "\nYou look around and notice the room has a giant pool.\n";
                    Sleep(2500);
                    WaterRoom();
                    }


                WaterRoom();
             case 3:
                if (waterkey == 1)
                {
                    cout << "\nYou have already taken the key!";
                    Sleep(2500);
                    WaterRoom();
                }
                else if (swim == 1)
                    {
                    cout << "\nYou swim across, successfully snatch the key, and return to the main room.\n";
                    ReadPause();
                    waterkey = 1;
                    ofstream outFile("waterkey.txt");
                    waterkeygrab = 0;
                    GeneralChoice();
                    }
                else
                    cout << "\nYou try to grab the key, but you aren't a good swimmer, so you swim back to the ledge you were on.\n";
                    ReadPause();
                    WaterRoom();
         }



return;
}

void GrassRoom()                     //The room of grass's contents.
{
    ClearScreen();

    cout << "\nYou are in the Grass Room, what would you like to do? (Input Number next to decision)"
         << "\n1. Return to Main Room."
         << "\n2. Examine the Room."
         << "\n3. Attempt to grab the room's key.\n";

         cin >> decision;

         ClearScreen();

         switch (decision)
         {
             case 1:
                cout << "\nHeading back to the main room...\n";
                ReadPause();
                GeneralChoice();
                break;
             case 2:
                if (wood == 0)
                {
                    cout << "\nYou notice a bundle of firewood, and decide to take it with you.\n";
                    Sleep(2500);
                    ofstream outFile("wood.txt");
                    wood = 1;
                }
                if (grasskey == 1)
                {
                    cout << "The pedestal where the key was is now empty.";
                    Sleep (2500);
                    GrassRoom();
                }
                else if (grasskeygrab == 1)
                    {
                        cout << "The plants are all gone around the key, and you could probably grab it.";
                        Sleep(2500);
                        GrassRoom();
                    }
                else if (torch == 2)
                {
                    cout << "\nYou look around and notice that the key is surrounded by poisonous plants, and grabbing it would kill you.\n";
                    cout << "Your torch looks at you, feeling like it wants to be thrown at the plants. Will you let it?\n"
                         << "\n1. Yes \n2. No\n";
                    cin >> decision;

                    if (decision == 1)
                    {
                        cout << "\nYou throw your torch at the plants, which burst into flames.\nNow the key is vulnerable.\n";
                        Sleep(2500);
                        grasskeygrab = 1;
                        torch = 1;
                    }
                    else
                        cout << "\nYou don't throw your torch.\n";
                }
                else
                    {
                    cout << "\nYou look around and notice that the key is surrounded by poisonous plants, and grabbing it would kill you.\n";
                    Sleep(2500);
                    GrassRoom();
                    }


                GrassRoom();
             case 3:
                if (grasskey == 1)
                {
                    cout << "\nYou have already taken the key!";
                    Sleep(2500);
                    GrassRoom();
                }
                else if (grasskeygrab == 1)
                    {
                    cout << "\nYou successfully snatch the key, and return to the main room.\n";
                    ReadPause();
                    grasskey = 1;
                    ofstream outFile("grasskey.txt");
                    grasskeygrab = 0;
                    GeneralChoice();
                    }
                else
                    cout << "\nYou try to grab the key, but the plants are there, so you can't grab it.\n";
                    ReadPause();
                    GrassRoom();
         }



return;
}

void IceRoom()                     //The room of ice's contents.
{
    ClearScreen();

    cout << "\nYou are in the Ice Room, what would you like to do? (Input Number next to decision)"
         << "\n1. Return to Main Room."
         << "\n2. Examine the Room."
         << "\n3. Attempt to grab the room's key.\n";

         cin >> decision;

         ClearScreen();

         switch (decision)
         {
             case 1:
                cout << "\nHeading back to the main room...\n";
                ReadPause();
                GeneralChoice();
                break;
             case 2:
                if (torch == 0)
                {
                    cout << "You notice an unlit torch on the wall, and take it with you.";
                    Sleep(2500);
                    ofstream outFile("torch1.txt");
                    torch = 1;
                }
                if (icekey == 1)
                {
                    cout << "The pedestal where the key was is now empty.";
                    Sleep (2500);
                    IceRoom();
                }
                else if (icekeygrab == 1)
                    {
                        cout << "They room's ice has mostly melted, and the key is sitting on a pedestal.";
                        Sleep(2500);
                        icekeygrab = 1;
                        IceRoom();
                    }
                else if (torch == 2 && wood == 1)
                {
                    cout << "\nYou have a brilliant idea - You should light a fire to melt the room's ice!";
                    cout << "\n1. Yes \n2. No\n";
                    cin >> decision;

                    if (decision == 1)
                    {
                        cout << "\nYou light the fire with your torch and wood, and the ice begins melting.\n";
                        Sleep(2500);
                        icekeygrab = 1;
                        torch = 1;
                        wood = 0;
                    }
                    else
                        cout << "\nYou keep your torch and wood.\n";
                }
                else
                    {
                    cout << "\nThe whole room is covered in ice, including the key, which is frozen to the pedestal.\n";
                    Sleep(2500);
                    IceRoom();
                    }


                IceRoom();
             case 3:
                if (icekey == 1)
                {
                    cout << "\nYou have already taken the key!";
                    Sleep(2500);
                    IceRoom();
                }
                else if (icekeygrab == 1)
                    {
                    cout << "\nYou successfully snatch the key, and return to the main room.\n";
                    ReadPause();
                    icekey = 1;
                    ofstream outFile("icekey.txt");
                    icekeygrab = 0;
                    GeneralChoice();
                    }
                else
                    cout << "\nYou try to grab the key, but it is frozen solid to the pedestal.\n";
                    ReadPause();
                    IceRoom();
         }



return;
}

void ReadPause()                    //A short pause
{
    Sleep(5000);
}

void SaveItemsCheck()               //checks save file to see if you have items
{
    inFile.open("torch1.txt");

    if (inFile.good())
    {
        torch = 1;
        inFile.close();
    }
    inFile.open("torch2.txt");

    if (inFile.good())
    {
        torch = 2;
        inFile.close();
    }
    inFile.open("wood.txt");

    if (inFile.good())
    {
        wood = 1;
        inFile.close();
    }
    inFile.open("bucket1.txt");

    if (inFile.good())
    {
        bucket = 1;
        inFile.close();
    }
    inFile.open("bucket2.txt");

    if (inFile.good())
    {
        bucket = 2;
        inFile.close();
    }
    inFile.open("swim.txt");

    if (inFile.good())
    {
        swim = 1;
        inFile.close();
    }
}

void DeleteSave()                        //Deletes Save
{
    ClearScreen();

    FinalDoorOpen = 0;
    firekey = 0;
    firekeygrab = 0;
    waterkey = 0;
    waterkeygrab = 0;
    grasskey = 0;
    grasskeygrab = 0;
    icekey = 0;
    icekeygrab = 0;

    wood = 0;
    torch = 0;
    bucket = 0;
    swim = 0;

    remove("save.txt");
    remove("icekey.txt");
    remove("grasskey.txt");
    remove("waterkey.txt");
    remove("firekey.txt");
    remove("bucket1.txt");
    remove("bucket2.txt");
    remove("swim.txt");
    remove("torch1.txt");
    remove("torch2.txt");
    remove("wood.txt");

    cout << "Your save has been deleted. Restart the game to continue.";

    exit(4);
}

void Win()
{
    ClearScreen();

    cout << " __          _______ _   _ _   _ ______ _____   " << endl
         << " \\ \\        / /_   _| \\ | | \\ | |  ____|  __ \\  " << endl
         << "  \\ \\  /\\  / /  | | |  \\| |  \\| | |__  | |__) | " << endl
         << "   \\ \\/  \\/ /   | | | . ` | . ` |  __| |  _  /  " << endl
         << "    \\  /\\  /   _| |_| |\\  | |\\  | |____| | \\ \\  " << endl
         << "     \\/  \\/   |_____|_| \\_|_| \\_|______|_|  \\_\\ " << endl << endl;

         cout << "Thank you for playing, I hope you had fun!\n\n";


}
