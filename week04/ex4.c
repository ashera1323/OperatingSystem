#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
    char command[1000];
    while(strcmp(command, "exit\n"))
    {
        fgets(command, 1000, stdin);
        if (fork() == 0) {
            system(command);
            break;
        }
    }
    return 0;
}
