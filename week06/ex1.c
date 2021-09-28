#include <stdio.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))

// swap function
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}



int main() {
    int n, ttat = 0, twt = 0, tmr = 0;
    int bt[1001], at[1001], wt[1001], tat[1001], ct[1001];

    printf("Enter number of process:\n");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++){
        printf("Enter arrival time and burst time of %d process ", i);
        scanf("%d%d", &at[i], &bt[i]);
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n-i; j++)
            if (at[j] > at[j+1]){
                swap(&at[j], &at[j+1]);
                swap(&bt[j], &bt[j+1]);
            }

    for(int i = 1; i<= n; i++){
        wt[i] = max(0, tmr - at[i]);
        tat[i] = wt[i] + bt[i];
        tmr = max(tmr + bt[i], at[i] + bt[i]);
        ct[i] = tmr;
        ttat += tat[i];
        twt += wt[i];
        printf("P[%d]: Completion time %d, Waiting time %d, Turn around time %d\n", i, ct[i], wt[i], tat[i]);
    }
    printf("Average total around time: %f\n", ttat * 1.0 / n);
    printf("Average waiting time: %f\n", twt * 1.0 / n);
    return 0;
}
