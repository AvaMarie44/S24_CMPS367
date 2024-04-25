//
//  main.cpp
//  Assignment 2
//
//  Created by Ava Chacon on 4/24/24.
//

#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

// Define a struct to group variables
struct Calculator {
    string input;
    char choice;
};

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

float applyOperation(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

float evaluateExpression(const string& expression) {
    stack<float> values;
    stack<char> operators;

    for (char c : expression) {
        if (isdigit(c) || c == '.') {
            values.push(c - '0');
        } else if (isOperator(c)) {
            while (!operators.empty() && operators.top() != '(' && (c == '*' || c == '/') && (operators.top() == '+' || operators.top() == '-')) {
                float b = values.top(); values.pop();
                float a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(c);
        } else if (c == '(') {
            operators.push(c);
        } else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                float b = values.top(); values.pop();
                float a = values.top(); values.pop();
                char op = operators.top(); operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop(); // Pop '('
        }
    }

    while (!operators.empty()) {
        float b = values.top(); values.pop();
        float a = values.top(); values.pop();
        char op = operators.top(); operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();
}

int main() {
    Calculator calc;
    cout << "Enter a problem to solve: ";
    getline(cin, calc.input);

    float result = evaluateExpression(calc.input);
    cout << "Result: " << result << endl;

    calc.choice = 'Y';
    while (calc.choice == 'Y' || calc.choice == 'y') {
        cout << "Would you like to solve another problem? (Y/N) ";
        cin >> calc.choice;
        cin.ignore();
    }

    cout << "Thank you for using this calculator!" << endl;

    
    
    
    
    
    
// Problem 2
    //
    //
    //
    //
    //
    //
#include <iostream>
#include <string>

using namespace std;

// Define a struct to group variables
struct BirthdayInfo {
    int month;
    int day;
    int year;
    char choice;
};

// Function prototypes
void displayMonthMeaning(int month);
void displayDayMeaning(int day);
void displayYearMeaning(int year);


    cout << "Welcome to Birthday Date Meaning Generator!" << endl;

    BirthdayInfo info;
    info.choice = 'Y';

    while (info.choice == 'Y' || info.choice == 'y') {
        cout << "Please enter the month of your birthday: ";
        cin >> info.month;
        cout << "Please enter the day of your birthday: ";
        cin >> info.day;
        cout << "Please enter the year of your birthday: ";
        cin >> info.year;

        cout << "The month of ";
        displayMonthMeaning(info.month);
        cout << " means ";
        displayMonthMeaning(info.month);
        cout << endl;

        cout << "The " << info.day;
        switch (info.day) {
            case 1: case 21: case 31: cout << "st"; break;
            case 2: case 22: cout << "nd"; break;
            case 3: case 23: cout << "rd"; break;
            default: cout << "th"; break;
        }
        cout << " of ";
        displayMonthMeaning(info.month);
        cout << " means ";
        displayDayMeaning(info.day);
        cout << endl;

        if (info.year >= 2000 && info.year <= 2023) {
            cout << "The year of " << info.year << " means that you are a millennial" << endl;
        }

        cout << "Would you like to try another one? (Y/N) ";
        cin >> info.choice;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}

void displayMonthMeaning(int month) {
    switch (month) {
        case 1: cout << "January"; break;
        case 2: cout << "February"; break;
        case 3: cout << "March"; break;
        case 4: cout << "April"; break;
        case 5: cout << "May"; break;
        case 6: cout << "June"; break;
        case 7: cout << "July"; break;
        case 8: cout << "August"; break;
        case 9: cout << "September"; break;
        case 10: cout << "October"; break;
        case 11: cout << "November"; break;
        case 12: cout << "December"; break;
        default: cout << "Invalid Month"; break;
    }
}

void displayDayMeaning(int day) {
    switch (day) {
        case 1: cout << "Self-Started"; break;
        case 2: cout << "Balance"; break;
        case 3: cout << "Expression"; break;
        // Add more meanings as desired
        default: cout << "Unknown"; break;
    }

    
    
    
    
    
    // Problem 3
    
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Define a struct to group variables
struct BMIInfo {
    string name;
    string gender;
    int age;
    int height_feet;
    int height_inches;
    int weight;
    double bmi;
    string bmi_category;
};

// Function prototype
void calculateBMI(BMIInfo &info);

int main() {
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        BMIInfo info;

        // Ask the user for input
        cout << "Please enter your name: ";
        getline(cin, info.name);

        cout << "Please enter your age: ";
        cin >> info.age;

        cout << "Please enter your gender: ";
        cin.ignore();
        getline(cin, info.gender);

        cout << "Please enter your height in feet: ";
        cin >> info.height_feet;

        cout << "Please enter your height in inches: ";
        cin >> info.height_inches;

        cout << "Please enter your weight in pounds: ";
        cin >> info.weight;

        // Calculate BMI
        calculateBMI(info);

        // Output the result
        cout << "\nHi " << info.name << ",\n";
        cout << "You are a " << info.gender << ". You are " << info.age << " years old.\n";
        cout << "You are currently " << info.height_feet << "'" << info.height_inches << "\" and you currently weigh " << info.weight << " pounds.\n";
        cout << "Your BMI is " << info.bmi << ", which is " << info.bmi_category << ".\n";
        cout << "Thank you for using the BMI Calculator!\n";

        cout << "Do you want to calculate BMI for another person? (Y/N): ";
        cin >> choice;
        cin.ignore(); // Ignore newline character from previous cin
    }

    cout << "Thank you for using the BMI Calculator!" << endl;

    return 0;
}

void calculateBMI(BMIInfo &info) {
    // Calculate total height in inches
    double height_total = (info.height_feet * 12) + info.height_inches;
    // Calculate BMI
    info.bmi = (info.weight * 703.0) / (height_total * height_total);

    // Determine BMI category
    if (info.bmi < 18.5) {
        info.bmi_category = "underweight";
    } else if (info.bmi < 25.0) {
        info.bmi_category = "normal weight";
    } else if (info.bmi < 30.0) {
        info.bmi_category = "overweight";
    } else {
        info.bmi_category = "obese";
    }

    
    
    
    
    // Problem 4
    //
    //
#include <iostream>

using namespace std;

// Define a struct to group variables
struct MultiplicationTable {
    int start_range;
    int end_range;
    int start_multiply;
    int end_multiply;
    char choice;
};

// Function prototypes
void generateMultiplicationTable(MultiplicationTable &table);

int main() {
    MultiplicationTable table;
    table.choice = 'Y';

    while (table.choice == 'Y' || table.choice == 'y') {
        generateMultiplicationTable(table);

        cout << "Do you want to create another multiplication table? (Y/N) ";
        cin >> table.choice;
    }

    cout << "Thank you for using the multiplication table generator!" << endl;

    return 0;
}

void generateMultiplicationTable(MultiplicationTable &table) {
    cout << "Enter the starting range for Multiplication Table: ";
    cin >> table.start_range;

    cout << "Enter the ending range for Multiplication Table: ";
    cin >> table.end_range;

    cout << "Enter the starting range for multiplying the numbers in Multiplication Table: ";
    cin >> table.start_multiply;

    cout << "Enter the ending range for multiplying the numbers in Multiplication Table: ";
    cin >> table.end_multiply;

    // Displaying the multiplication table
    cout << "Here is the multiplication table for " << table.start_range << " to " << table.end_range << " in the range of " << table.start_multiply << " to " << table.end_multiply << endl;
    cout << "X ";
    for (int i = table.start_multiply; i <= table.end_multiply; ++i) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = table.start_range; i <= table.end_range; ++i) {
        cout << i << " ";
        for (int j = table.start_multiply; j <= table.end_multiply; ++j) {
            cout << i * j << " ";
        }
        cout << endl;
    }

    
    
    
    // Problem 5
    //
    //
    //
    //
#include <iostream>
#include <cmath>

using namespace std;

// Define a struct to group variables
struct Calculator {
    char operand;
    double operand1;
    double operand2;
    double result;
};

// Function prototypes
void solveProblem(Calculator &calc);
void calculateResult(Calculator &calc);

int main() {
    char choice = 'Y';
    while (choice == 'Y' || choice == 'y') {
        Calculator calc;
        solveProblem(calc);

        cout << "Do you want to solve another problem? (Y/N): ";
        cin >> choice;
    }

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}

void solveProblem(Calculator &calc) {
    cout << "Enter the problem to solve (operand operand1 operand2): ";
    cin >> calc.operand >> calc.operand1 >> calc.operand2;

    calculateResult(calc);

    cout << "Result: " << calc.result << endl;
}

void calculateResult(Calculator &calc) {
    switch (calc.operand) {
        case '+': calc.result = calc.operand1 + calc.operand2; break;
        case '-': calc.result = calc.operand1 - calc.operand2; break;
        case '*': calc.result = calc.operand1 * calc.operand2; break;
        case '/':
            if (calc.operand2 != 0) calc.result = calc.operand1 / calc.operand2;
            else cout << "Error: Division by zero" << endl;
            break;
        case '%':
            if (calc.operand2 != 0) calc.result = fmod(calc.operand1, calc.operand2);
            else cout << "Error: Modulus by zero" << endl;
            break;
        case '^': calc.result = pow(calc.operand1, calc.operand2); break;
        case 's': calc.result = sin(calc.operand1); break;
        case 'c': calc.result = cos(calc.operand1); break;
        case 't': calc.result = tan(calc.operand1); break;
        case 'a':
            switch (calc.operand2) {
                case 's': calc.result = asin(calc.operand1); break;
                case 'c': calc.result = acos(calc.operand1); break;
                case 't': calc.result = atan(calc.operand1); break;
                default: cout << "Invalid operand" << endl; return;
            }
            break;
        case 'l':
            switch (calc.operand2) {
                case 'n': calc.result = log(calc.operand1); break;
                case 'g': calc.result = log10(calc.operand1); break;
                case '2': calc.result = log2(calc.operand1); break;
                default: cout << "Invalid operand" << endl; return;
            }
            break;
        default:
            cout << "Invalid operand" << endl;
            return;
    }
}
    return 0;
}
