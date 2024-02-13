#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char operator;
    double result, operand;
    double num1, num2;

    printf("Masukan angka serta penjumlahan: ");
    
    // Read the first number separately to initialize the result
    if (scanf("%lf", &result) != 1) {
        printf("Error: Invalid input\n");
        return 1;
    }
    
    // Read the operator and numbers in a loop
    while (scanf(" %c %lf", &operator, &operand) == 2) {
        if (operator == '%') {
            // Read the next number as an operand
            if (scanf("%lf", &num2) != 1) {
                printf("Error: Invalid input\n");
                return 1;
            }
            // Perform the modulus operation
            if (operand != 0) {
                result = fmod(result, operand);
            } else {
                printf("Error: Modulus by zero\n");
                return 1;
            }
            // Set operand to num2 for the next iteration
            operand = num2;
        }
        switch (operator) {
            case '+':
                result += operand;
                break;
            case '-':
                result -= operand;
                break;
            case '*':
                result *= operand;
                break;
            case '/':
                if (operand != 0) {
                    result /= operand;
                } else {
                    printf("Error: Division by zero\n");
                    return 1;
                }
                break;
            case 'r':
            case 'R':
                if (result >= 0) {
                    result = sqrt(result);
                } else {
                    printf("Error: Square root of a negative number\n");
                    return 1;
                }
                break;
            default:
                printf("Error: Invalid operator\n");
                return 1;
        }
        printf("Hasil: %.2lf\n", result);
    }


    return 0;
}
