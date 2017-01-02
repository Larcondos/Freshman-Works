#include <iostream>

using namespace std;

/*void add(double, double);
void subtract(double, double);
void multiply(double, double);
void divide(double, double); */

int dblresult;


template<class T>
T add(T x, T y)
{
    return x + y;
}
template<class T>
T subtract(T x, T y)
{
    return x - y;
}
template<class T>
T multiply(T x, T y)
{
    return x * y;
}
template<class T>
T divide(T x, T y)
{
    return x / y;
}


int main()
{
    double dblNum1, dblNum2;
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
            break;

            cout << "Please select 2 numbers seperated by a space: ";
            cin >> dblNum1 >> dblNum2;

            if (intOption == 1)
            {
                cout << "The result of the addition is: "
                      << add(dblNum1, dblNum2);
            }
            else if (intOption == 2)
            {
                cout << "The result of the subtraction is: "
                      << subtract(dblNum1, dblNum2);
            }
            else if (intOption == 3)
            {
                cout << "The result of the multiplication is: "
                      << multiply(dblNum1, dblNum2);
            }
            else if (intOption == 4)
            {
                if (dblNum2 == 0)
                {
                    cout << "You can't divide by zero. Nice try, nerd.";
                    continue;
                }
                else
                    cout << "The result of the division is: "
                      << divide(dblNum1, dblNum2);
            }
            else
                cout << "Invalid option, try again.";

    } while(1);

    return 0;
}
/*
void add(double x, double y)
{
    double dblresult;

    dblresult = x + y;
    cout << "You have selected Addition.\n";
    cout << "The answer is: " << dblresult;
    return;
}

void subtract(double x, double y)
{
    double dblresult;

    dblresult = x - y;
    cout << "You have selected Subtraction.\n";
    cout << "The answer is: " << dblresult;
    return;
}
template<class T>
T add(T x, T y)
{
    return x + y;
}
void multiply(double x, double y)
{
    double dblresult;

    dblresult = x * y;
    cout << "You have selected Multiplication.\n";
    cout << "The answer is: " << dblresult;
    return;
}template<class T>
T add(T x, T y)
{
    return x + y;
}

void divide(double x, double y)
{
    double dblresult;

    dblresult = x / y;
    cout << "You have selected Division.\n";
    cout << "The answer is: " << dblresult;
    return;
}
*/
