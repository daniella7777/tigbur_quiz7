#include <stdio.h>

double calc(int a){
    return a/2;
}

//double g = calc(3);

void count(){
    static int counter = 0;
    printf("counter: %d\n",counter++);
}

int main(){
    double l = calc(5);
    printf("%g\n", l);

    count();
    count();
    count();



    return 0;
}