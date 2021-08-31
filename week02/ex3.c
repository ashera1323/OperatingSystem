#include <stdio.h>

// func print trinagle with n height and 2n-1 wedth
void f(int n) {
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        for(int j = 1; j <= n-i; j++){
            printf(" ");
        }

        while(cnt != 2*i-1){
            printf("*");
            cnt++;
        }
        printf("\n");
    }
}

//main function
int main(int argc, char* argv[]) {
    if (argc <= 1) {
        return 0;
    }

    int n;
    // read height n
    sscanf(argv[1], "%d", &n);

    f(n);
}
