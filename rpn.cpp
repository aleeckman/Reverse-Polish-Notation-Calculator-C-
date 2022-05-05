#include <iostream>
#include "rpn.h"

using namespace std;

int main() {

    // Input 1: Operands and Operator Array
    string input[] = {"2", "12", "6", "-", "/", "5", "3", "+", "*"};

    // Input 2: Length of Array
    int n = 9;

    // Input 3: -l (Needed to Print Structure of RPN Calculation)
    bool dash_l = true;

    // Calculate the Result of RPN Inputs
    double result = rpn(input, n, dash_l);

    // Print Result
    cout.precision(2);
    cout << fixed << result << endl;
}