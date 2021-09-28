#include<stdio.h>
#include <stdlib.h>

int n;
int at[1001], bt[1001], et[1001], wt[1001], tat[1001], rem[1001];
int ttat = 0, twt = 0;

int Find(int tmr){
    int mn = 11111111, index = -1;
    for(int i = 1; i <= n; i++){
        if(tmr >= at[i] && rem[i] > 0){
            if(bt[i] < mn){
                mn = bt[i];
                index = i;
            }
        }
    }
    return index;
}

int main(){

    printf("Enter number of process:\n");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter arrival time and burst time of %d process ", i);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }

    int completed = 0, tmr = 0;
    while(completed < n){
        int index = Find(tmr);
        if(index != -1){
            rem[index] --;
            if(rem[index] == 0){
                et[index] = tmr + 1;
                completed ++;
            }
        }
        tmr ++;
    }
    for(int i = 1; i <= n; i++){
        tat[i] = et[i] - at[i];
        wt[i] = tat[i] - bt[i];
        ttat += tat[i];
        twt += wt[i];
        printf("P[%d]:Waiting time %d, Turn around time %d, Completion time %d\n", i, wt[i], tat[i], et[i]);
    }
    printf("Average total around time: %f\n", ttat * 1.0 / n);
    printf("Average waiting time: %f\n", twt * 1.0 / n);
    return 0;
}