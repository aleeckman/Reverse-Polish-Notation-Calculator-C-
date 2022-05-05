//
// Created by Andrew Eeckman on 10/8/21.
//

#ifndef RPN_RPN_H
#define RPN_RPN_H

#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// Expression tree data structure referenced from: https://www.geeksforgeeks.org/expression-tree/
struct Node {
    string oper;
    Node *left_child;
    Node *right_child;

    Node(string op, Node *left, Node *right) {
        oper = op;
        left_child = left;
        right_child = right;
    }
};

double execOperation(const string& str_i, stack<double>& operands);
bool isOperator(const string input);
void structureMaster(const string* strs, int n);
void structurePrint(Node* node, int num_of_tabs);

double rpn(string *strs, int n, bool dash_l) {

    double result = 0.0;
    stack<double> operands;

    for (int i = 0; i < n; i++) {

        bool is_oper = isOperator(strs[i]);
        double oper = 0.0;


        if (!is_oper) {
            try {oper = stod(strs[i]);}
            catch (exception& e) {
                cout << "Error: Invalid Operator" << endl;
                exit(-1);
            }
        }

        else oper = execOperation(strs[i], operands);

        operands.push(oper);
    }

    if(operands.size() > 1) {
        cout << "Error: Too Many Operands Given For Listed Operators" << endl;
        exit(-1);
    }

    result = operands.top();
    operands.pop();

    if (dash_l) structureMaster(strs, n);

    return result;
}

double execOperation(const string& str_i, stack<double> &operands) {

    double res = 0.0;

    if (str_i == "+" || str_i == "-" || str_i == "*" || str_i == "/" || str_i == "**") {

        if(operands.size() < 2) {
            cout << "Error: Incorrect Number of Operands" << endl;
            exit(-1);
        }

        double operB = operands.top();
        operands.pop();

        double operA = operands.top();
        operands.pop();

        if(str_i == "+") res = operA + operB;
        else if(str_i == "-") res = operA - operB;
        else if(str_i == "*") res = operA * operB;
        else if(str_i == "/") {

            if(operB == 0 || operB == 0.0) {
                cout << "Error: Division By Zero" << endl;
                exit(-1);
            }

            res = operA / operB;

        } else if(str_i == "**") {

            if((operA == 0.0 || operA == 0) && (operB == 0.0 || operB == 0)) {
                cout << "Error: 0 to the Power of 0 is Undefined" << endl;
                exit(-1);
            }

            if((operA == -1.0 || operA == -1) &&  operB == 0.5) {
                cout << "Error: -1 to the Power of 0.5 yields imaginary number i" << endl;
                exit(-1);
            }

            if((operA == 0.0 || operA == 0) &&  operB < 0.0) {
                cout << "Error: 0 to the Power of a Negative Number is Undefined" << endl;
                exit(-1);
            }

            res = pow(operA, operB);
        }

    } else { // Operator is either floor or ceiling

        if(operands.size() < 1) {
            cout << "Error: Incorrect Number of Operands" << endl;
            exit(-1);
        }

        double oper = operands.top();
        operands.pop();

        if (str_i == "<") res = floor(oper);
        else if (str_i == ">") res = ceil(oper);

        else {
            cout << "Error: Invalid Operator" << endl;
            exit(-1);
        }
    }

    return res;
}

bool isOperator(const string input) {

    string valid_operators ="+-*/<>";

    if(input.length() == 1) return valid_operators.find_first_of(input) != string::npos;
    else if(input == "**") return true;
    else return false;
}

void structureMaster(const string* strs, int n) {

    stack<Node*> oper;

    for(int i = 0; i < n; i++) {

        bool isoper = isOperator(strs[i]);

        Node* left_child = nullptr;
        Node* right_child = nullptr;

        if(isoper) {

            if(strs[i] == ">" || strs[i] == "<") {

                right_child = oper.top();
                oper.pop();

            } else {

                right_child = oper.top();
                oper.pop();

                left_child = oper.top();
                oper.pop();

            }
        }

        Node* new_node = new Node(strs[i], left_child, right_child);
        oper.push(new_node);
    }

    structurePrint(oper.top(), 0);
}

void structurePrint(Node* node, int num_of_tabs) {

    if(node) {

        bool isoper = isOperator(node->oper);
        string string_to_print;
        string opt_par = "";

        if(isoper) opt_par = "(";

        string_to_print = string(num_of_tabs, '\t') + opt_par + node->oper + "\n";
        cout << string_to_print;

        if(isoper) num_of_tabs++;

        structurePrint(node->left_child, num_of_tabs);
        structurePrint(node->right_child, num_of_tabs);

        if(isoper) {
            num_of_tabs--;
            cout << string(num_of_tabs, '\t') << ")" << endl;
        }
    }
}

#endif //RPN_RPN_H
