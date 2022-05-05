# README
Student Name: Andrew Eeckman
Student ID: 914834317
Date: 10/17/2021

## NOTE: rpn.cpp must be updated to run test cases, inputs are hard-coded.

## Compilation Instructions:
To compile rpn.cpp and rpn.h using Terminal (MacOS) or on any CSIF computers, use the following console command: "g++ rpn.cpp rph.h" (excluding the quotes)

## Run Instructions:
To run the compiled code, type the following into console: "./a.out" (excluding the quotes)

## Input and "-l" Instructions:
In rpn.cpp, all inputs are hard-coded. In order to change the operands and operators input array, one should modify the variable "string input[]". To update the given size of the input array, one should modify "int n". Finally, to view the structure of the RPN calculation, one should either set "bool dash_l" to true or false. If set to true, the program will display the calculation's structure; if set to false, only the calculation's result will be printed. Again, to clarify all inputs are manually declared in the rpn.cpp file; the program will not accept command line or user inputs. 

## Assumptions:
The following input assumptions were made in the creation of this program:
1. All operands entered will be valid ones. No alphabetic or special characters will be entered in the input array. Operators, however, may be invalid.
2. The given size of the input array (int n) is always correct. It will never be entered as less than or more than the actual size of the input array.

## Error Handling:
The following inputs will be treated as errors causing an "exit(-1)" instruction to be run, terminating the program (Note: even if -l is true, error-containing input will not have its structure displayed):
1. Too few or too many operands and operators present in the input array.
2. Any input array not already given in Reverse Polish Notation.
3. 0 raised to 0 as the result is technically undefined.
3. -1 raised to 0.5 as the result is the imaginary number i, which is not supported.
4. 0 raised to any negative number as the result would be undefined.
5. Division by 0 as the result would also be undefined.

## Test Cases:
The following test cases were tried and run successfully given the submitted code:
1. string input[] = {"2", "12", "6", "-", "/", "5", "3", "+", "*"}, result = 2.67
2. string input[] = {"2", "12", "6", "-", "/", "5", "3", "+", "*", ">"}, result = 3.00
3. string input[] = {"2", "3", "**"}, result = 8.00
4. string input[] = {"6", "9", "+", "4", "2", "*", "4", "2", "**", "+", "+"}, result = 39.00
5. string input[] = {"2", "20", "*", "2", "/", "3", "4", "+", "3", "2", "**", "*", "+", "6", "-", "15", "+"}, result = 92.00
6. string input[] = {"3", "=", "5"}, result = "Error: Invalid Operator"
7. string input[] = {"0", "0", "**"}, result = "Error: 0 to the Power of 0 is Undefined"
8. string input[] = {"4", "0", "/"}, result = "Error: Division By Zero"
9. string input[] = {"-1", "0.5", "**"}, result = "Error: -1 to the Power of 0.5 yields imaginary number i"
10. string input[] = {"0", "-2", "**"}, result = "Error: 0 to the Power of a Negative Number is Undefined"
11. string input[] = {"3", "+"}, result = "Error: Incorrect Number of Operands"
12. string input[] = {"3", "4", ">"}, result = "Error: Too Many Operands Given For Listed Operators"

## References:
1. https://www.geeksforgeeks.org/expression-tree/
2. https://www.cplusplus.com/reference/stack/stack/
3. https://www.cplusplus.com/doc/tutorial/exceptions/
4. https://en.wikipedia.org/wiki/Reverse_Polish_notation
5. https://www.free-online-calculator-use.com/postfix-evaluator.html#calculator-start
