#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include "ExpressionChecker.h"
#include "Node.h"
#include "List.h"

using namespace std;

void menu() {
    
    string equation;
    const char delimeter = ' ';
    vector <string> expression;
    ExpressionChecker* ec1 = new ExpressionChecker();
    List* pila = new List();

    // Entrada
    getline(cin, equation);

    // Verification
    ec1->splitString(equation, delimeter, expression);

    bool valid = ec1->checker(expression, pila);

    if (valid) {
        
        string result = ec1->calculation(expression, pila);
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << "The answer is: ";
        cout << result << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        
    } else {
        cout << "Task Failed..." << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
    }
}

int main(){
    
    while (true) {
        cout << "Enter the expression to calculate (PREFIX NOTATION):" << endl;
        menu();
        cout << "Do you want to calculate another expression? (Y/N)" << endl;
        string answer;
        getline(cin, answer);
        if (answer == "N" || answer == "n") {
            break;
        }
    }
    cout << "---------------------------------------------END----------------------------------------------" << endl;

    return 0;
}