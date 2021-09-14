#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char command[1000];
    while(strcmp(command, "exit"))
    {
        printf("> ");
        scanf("%1000s", command);
        system(command);
    }
    return 0;
}