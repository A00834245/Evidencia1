#include <iostream>
using namespace std;

int main()
{
    int num1, num2, sum;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    sum = num1 + num2;

    cout << "The sum of " << num1 << " and " << num2 << " is " << sum << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << "Queso" << endl;
    }

    switch (sum)
    {
    case 1:
        cout << "Uno" << endl;
        break;
    case 2:
        cout << "Dos" << endl;
        break;
    case 3:
        cout << "Tres" << endl;
        break;
    default:
        cout << "Nada" << endl;
        break;
    }

    return 0;
}