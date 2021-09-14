#include <stdio.h>
#include <unistd.h>

int main(){
    /*
	    Calling fork() returns the PID of the child process to the parent, and 0 to the child
	    getpid() function will return the PID of the process in its call
	    The PID increases by 1 for each new process
	 */
    int x = fork();
    int n = getpid();
    if(x != 0)
        printf("Hello from parent[PID - %d]\n", n);
    else
        printf("Hello from child[PID - %d]\n", n);
}