#include <iostream>

using namespace std;

class Calculator {
public:
    static void run() {
        double num1, num2;

        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose an operation (+, -, *, /): ";
        char operatorChar;
        cin >> operatorChar;

        double result;

        switch (operatorChar) {
            case '+':
                result = num1 + num2;
                break;

            case '-':
                result = num1 - num2;
                break;

            case '*':
                result = num1 * num2;
                break;

            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return;
                }
                result = num1 / num2;
                break;

            default:
                cout << "Invalid operator." << endl;
                return;
        }

        cout << "Result: " << result << endl;
    }
};

int main() {
    Calculator::run();
    return 0;
}
