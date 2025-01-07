#include <stdio.h>
#include <stdlib.h>

//Compile with -fno-pic -no-pie
//Run with setarch -R ./part1.c
typedef struct {
    char *name;
    void *address; 
} var_t;

void visualizeMemory(var_t vars[], int count) {

    // Sort the variables by address 
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if ((unsigned long)vars[j].address > (unsigned long)vars[j + 1].address) {
                var_t temp = vars[j];
                vars[j] = vars[j + 1];
                vars[j + 1] = temp;
            }
        }
    }

    printf("\nMemory Layout:\n");
    printf("=================\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %lu (0x%p)\n", vars[i].name, (unsigned long)vars[i].address, vars[i].address);
    }

    printf("\nVisual Memory Representation (Bottom-to-Top):\n");
    printf("=============================================\n");
    for (int i = count - 1; i >= 0; i--) { // Reverse order for bottom-to-top display
        printf("[%-20s] Decimal: %lu, Hex: 0x%p\n", 
               vars[i].name, (unsigned long)vars[i].address, vars[i].address);
    }
}



int global_var = 42; // Global variable

void function2(int param2, var_t variables[], int *count) {
    variables[(*count)++] = (var_t){"param2 (function2)", &param2};
}

void function1(int param1, var_t variables[], int *count) {

    static int static_var = 99; // Static variable
    int local_var;             // Local variable
    int *dynamic_var = malloc(sizeof(int)); // Dynamically allocated variable

    variables[(*count)++] = (var_t){"global_var", &global_var};
    variables[(*count)++] = (var_t){"static_var", &static_var};
    variables[(*count)++] = (var_t){"dynamic_var (heap)", dynamic_var};
    variables[(*count)++] = (var_t){"local_var (stack)", &local_var};
    variables[(*count)++] = (var_t){"param1 (function1)", &param1};

    function2(5, variables, count);

    free(dynamic_var); 
}

int main() {
    var_t vars[20]; // Array to store variable names and addresses
    int count = 0;

    function1(10, vars, &count);

    visualizeMemory(vars, count);

    return 0;
}
