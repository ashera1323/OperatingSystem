#include<stdio.h>

int main(){
    int n, q;
    int at[1001], bt[1001], et[1001], wt[1001], tat[1001], rem[1001];
    int ttat = 0, twt = 0;
    printf("Enter number of process: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        printf("Enter arrival time and burst time of %d process ", i);
        scanf("%d%d", &at[i], &bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter quantum number ");
    scanf("%d", &q);
    int completed = 0, tmr = 0;

    while(completed < n){
        int ch = 0;
        for(int i = 1; i <= n; i++){
            if(at[i] <= tmr && rem[i] > 0){
                ch = 1;
                if(rem[i] > q){
                    rem[i] -= q;
                    tmr += q;
                }
                else{
                    tmr += rem[i];
                    rem[i] = 0;
                    et[i] = tmr;
                    completed ++;
                }
            }
        }
        if(!ch) tmr++;
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