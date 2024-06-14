#include <iostream>
using namespace std;

int main() {
    int firstNumber, secondNumber, choice;
    char repeat; // Change the data type to char

    do {
        cout << "Enter the first number: ";
        cin >> firstNumber;
        cout << "Enter the second number: ";
        cin >> secondNumber;

        cout << "Choose an operation:" << endl;
        cout << "(1) Addition" << endl;
        cout << "(2) Subtraction" << endl;
        cout << "(3) Multiplication" << endl;
        cout << "(4) Division" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Addition result: " << firstNumber + secondNumber << endl;
                break;
            case 2:
                cout << "Subtraction result: " << firstNumber - secondNumber << endl;
                break;
            case 3:
                cout << "Multiplication result: " << firstNumber * secondNumber << endl;
                break;
            case 4:
                if (secondNumber != 0) {
                    cout << "Division result: " << static_cast<double>(firstNumber) / secondNumber << endl;
                } else {
                    cout << "Error: Cannot divide by zero!" << endl;
                }
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "Do you want to calculate again? (y/n): ";
        cin >> repeat;
    } while (tolower(repeat) == 'y'); // Continue as long as 'y' is entered

    cout << "Thank you for using the calculator!" << endl;
    return 0;
}
