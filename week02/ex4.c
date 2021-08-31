#include <stdio.h>

//swap function
void swap(int *first, int *second) {
    int *temp = *first;
    *first = *second;
    *second = temp;
}


int main() {
    int a, b;
    printf("Enter two integers:\n");
    //read a and b
    scanf("%d%d", &a, &b);

    // call swap function
    swap(&a, &b);

    // print a and b
    printf("After swap function:\n");
    printf("%d %d", a, b);
}