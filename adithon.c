 #include <stdio.h>

int main() {
    int choice;
    int a, b, result;

    printf("Simple Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch(choice) {
        case 1:
            result = a + b;
            printf("Result = %d\n", result);
            break;
        case 2:
            result = a - b;
            printf("Result = %d\n", result);
            break;
        case 3:
            result = a * b;
            printf("Result = %d\n", result);
            break;
        case 4:
            if(b != 0) {
                result = a / b;
                printf("Result = %d\n", result);
            } else {
                printf("Error: Division by zero!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
      