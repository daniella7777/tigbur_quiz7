#include <stdio.h>
#include <stdlib.h>

//Compile with -fno-pic -no-pie
//Run with setarch -R ./part1.c

// Global uninitialized array 
int global_array[10];

// Function for the function pointer
void some_function() {}

/*
Create a function called identify that:
1. prints the input pointers addresses
2. identifys and prints which pointer is the function pointer, which is the global array pointer, and which is the pointer to the heap memory*/


int main() {
    // Create void pointer to the function

    //Create void pointer for dynamic memory

    //Create void pointer for the global array

    //Create a local veriable and a void pointer to it
   

    //char* s = "bla";

    // Call the identify function

    // Free the dynamically allocated memory

    return 0;
}
