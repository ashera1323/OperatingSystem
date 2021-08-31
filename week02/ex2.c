#include <stdio.h>
#include <string.h>

int main() {
    printf("Enter the string:\n");
    char s[256];

    //read string
    scanf("%s", &s);
    int sz = strlen(s); // size of the string

    //swap first and last characters to reverse the string
    for (int i = 0; i < sz/2; i++) {
        char temp = s[i];
        s[i] = s[sz - 1 - i];
        s[sz - 1 - i] = temp;
    }

    printf("Reverse of string is %s", s);
}