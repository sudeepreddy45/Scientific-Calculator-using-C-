#include <iostream>
#include <cmath>
#include <limits>
using namespace std;


class ScientificCalculator {
public:
   
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    
    double divide(double a, double b) {
        if (b == 0) {
            throw runtime_error("Error: Division by zero!");
        }
        return a / b;
    }

    int modulo(int a, int b) {
        if (b == 0) {
            throw runtime_error("Error: Modulo by zero!");
        }
        return a % b;
    }

    double power(double base, double exponent) { return pow(base, exponent); }
    
    double logarithm(double value) {
        if (value <= 0) {
            throw runtime_error("Error: Logarithm undefined for non-positive values!");
        }
        return log(value);
    }


    double logBase(double x, double base) {
        if (x <= 0 || base <= 0 || base == 1) {
            throw runtime_error("Error: Logarithm undefined for these values!");
        }
        return log(x) / log(base);
    }

 
    double sine(double angle) { return sin(angle); }
    double cosine(double angle) { return cos(angle); }
    double tangent(double angle) { return tan(angle); }

    
    void clearInputBuffer() {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n          Scientific Calculator             \n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulo\n";
    cout << "6. Power (x^y)\n";
    cout << "7. Logarithm (ln x)\n";
    cout << "8. Logarithm (log_x to base y)\n";
    cout << "9. Sine (sin x)\n";
    cout << "10. Cosine (cos x)\n";
    cout << "11. Tangent (tan x)\n";
    cout << "12. Exit\n";
    cout << "Enter your choice: ";
}



int main() {
    ScientificCalculator calc;
    int choice;
    double num1, num2;

    while (true) {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a number.\n";
            calc.clearInputBuffer();
            continue;
        }

        try {
            switch (choice) {
                case 1: // Addition
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.add(num1, num2) << endl;
                    break;

                case 2: // Subtraction
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.subtract(num1, num2) << endl;
                    break;

                case 3: // Multiplication
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.multiply(num1, num2) << endl;
                    break;

                case 4: // Division
                    cout << "Enter two numbers: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.divide(num1, num2) << endl;
                    break;

                case 5: // Modulo
                    int int1, int2;
                    cout << "Enter two integers: ";
                    cin >> int1 >> int2;
                    cout << "Result: " << calc.modulo(int1, int2) << endl;
                    break;

                case 6: // Power
                    cout << "Enter base and exponent: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.power(num1, num2) << endl;
                    break;

                case 7: // Logarithm (ln x)
                    cout << "Enter a number: ";
                    cin >> num1;
                    cout << "Result: " << calc.logarithm(num1) << endl;
                    break;

                case 8: // Logarithm (log_x to base y)
                    cout << "Enter x and base y: ";
                    cin >> num1 >> num2;
                    cout << "Result: " << calc.logBase(num1, num2) << endl;
                    break;

                case 9: // Sine
                    cout << "Enter an angle (in radians): ";
                    cin >> num1;
                    cout << "Result: " << calc.sine(num1) << endl;
                    break;

                case 10: // Cosine
                    cout << "Enter an angle (in radians): ";
                    cin >> num1;
                    cout << "Result: " << calc.cosine(num1) << endl;
                    break;

                case 11: // Tangent
                    cout << "Enter an angle (in radians): ";
                    cin >> num1;
                    cout << "Result: " << calc.tangent(num1) << endl;
                    break;

                case 12: // Exit
                    cout << "Exiting calculator. Thank you!\n";
                    return 0;

                default:
                    cout << "Invalid choice! Please select from 1 to 12.\n";
            }
        } catch (const exception &e) {
            cout << e.what() << endl;
            calc.clearInputBuffer();
        }
    }

    return 0;
}
