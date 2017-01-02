#include <iostream>

using namespace std;

int main()
{

    double dblNum1, dblNum2, dblresult;
    int intOption;

    do
    {

    cout << "\n\nPlease select an operator: " << endl;
    cout << "0 - Exit.\n";
    cout << "1 - Addition.\n";
    cout << "2 - Subtraction.\n";
    cout << "3 - Multiplication.\n";
    cout << "4 - Division.\n";

    cin >> intOption;

    if (intOption < 0 || intOption > 4)
        {
            cout << "An invalid option was selected, try again.";
            continue;
        }

        if (intOption == 0)
            {
                break;
            }

            cout << "Please select 2 numbers seperated by a space: ";
            cin >> dblNum1 >> dblNum2;


            if (intOption == 1)
            {
                dblresult = dblNum1 + dblNum2;
                cout << "You have selected Addition.\n";
                cout << "The answer is: " << dblresult;
            }
            else if (intOption == 2)
            {
                dblresult = dblNum1 - dblNum2;
                cout << "You have selected Subtraction.\n";
                cout << "The answer is: " << dblresult;
            }
            else if (intOption == 3)
            {
                dblresult = dblNum1 * dblNum2;
                cout << "You have selected Multiplication.\n";
                cout << "The answer is: " << dblresult;
            }
            else if (intOption == 4)
            {

                if (dblNum2 == 0)
                    cout << "You can't divide by zero. Nice try.";
                    continue;

                dblresult = dblNum1 / dblNum2;
                cout << "You have selected Division.\n";
                cout << "The answer is: " << dblresult;
            }
            else
                cout << "Invalid option, try again.";




    } while(1);
    return 0;
}
