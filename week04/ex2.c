#include <stdio.h>
#include <unistd.h>

int main(){
    for (int i=1; i<=3; i++){
        fork();
    }
    sleep(5);
    return 0;
}
/* explanation:
 Root process starts new child process recursively while fork() functions exist.
 Each process will be divided by 2, so the total number of processes will be 2^N
 3 forks -> 8 process
 5 forks -> 32 process
 */