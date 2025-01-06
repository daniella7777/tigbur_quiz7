#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    unsigned long address_decimal; // Decimal representation
    void *address_hex;             // Hexadecimal representation
} Variable;

void visualizeMemory(Variable variables[], int count) {
    // Sort the variables by decimal address
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (variables[j].address_decimal > variables[j + 1].address_decimal) {
                Variable temp = variables[j];
                variables[j] = variables[j + 1];
                variables[j + 1] = temp;
            }
        }
    }

    printf("\nMemory Layout:\n");
    printf("=================\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %lu (0x%p)\n", variables[i].name, variables[i].address_decimal, variables[i].address_hex);
    }

    printf("\nVisual Memory Representation (Bottom-to-Top):\n");
    printf("=============================================\n");
    for (int i = count - 1; i >= 0; i--) { // Reverse order for bottom-to-top display
        printf("[%-20s] Decimal: %lu, Hex: 0x%p\n", 
               variables[i].name, variables[i].address_decimal, variables[i].address_hex);
    }
}





int global_var = 42; // Global variable

void function2(int param2, Variable variables[], int *count) {
    variables[(*count)++] = (Variable){"param2 (function2)", (unsigned long)&param2, &param2};
}

void function1(int param1, Variable variables[], int *count) {

    static int static_var = 99; // Static variable
    int local_var;             // Local variable
    int *dynamic_var = malloc(sizeof(int)); // Dynamically allocated variable

    variables[(*count)++] = (Variable){"global_var", (unsigned long)&global_var, &global_var};
    variables[(*count)++] = (Variable){"static_var", (unsigned long)&static_var, &static_var};
    variables[(*count)++] = (Variable){"dynamic_var (heap)", (unsigned long)dynamic_var, dynamic_var};
    variables[(*count)++] = (Variable){"local_var (stack)", (unsigned long)&local_var, &local_var};
    variables[(*count)++] = (Variable){"param1 (function1)", (unsigned long)&param1, &param1};

    function2(5, variables, count);

    free(dynamic_var); // Free allocated memory
}

int main() {

    Variable variables[20]; // Array to store variable names and addresses
    int count = 0;

    int main_var = 0; // Variable in main function
    variables[count++] = (Variable){"main_var", (unsigned long)&main_var, &main_var};

    function1(10, variables, &count);

    visualizeMemory(variables, count);
    return 0;
}
