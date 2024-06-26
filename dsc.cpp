#include<stdio.h>

void findWaitingTime(int n, int bt[], int wt[], int at[]) {
    int i, j;
    int rt[n];
    for (i = 0; i < n; i++)
    rt[i] = bt[i];

    int complete = 0, t = 0, minm = 9999999;
    int shortest = 0, finish_time;
    int flag = 0;

    while (complete != n) {
            for (j = 0; j < n; j++) {
                    if ((at[j] <= t) && (rt[j] < minm) && rt[j] > 0) {
                            minm = rt[j];
                            shortest = j;
                            flag = 1;
                    }
            }

            if (flag == 0) {
                    t++;
                    continue;
            }

            rt[shortest]--;
            minm = rt[shortest];
            if (minm == 0)
            minm = 9999999;

            if (rt[shortest] == 0) {
                    complete++;
                    flag = 0;
                    finish_time = t + 1;
                    wt[shortest] = finish_time - bt[shortest] - at[shortest];
                    if (wt[shortest] < 0)
                    wt[shortest] = 0;
            }
            t++;
    }
}

void findTurnAroundTime(int n, int bt[], int wt[], int tat[]) {
    int i;
    for (i = 0; i < n; i++)
    tat[i] = bt[i] + wt[i];
}

void findavgTime(int n, int bt[], int at[]) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0, i;

    findWaitingTime(n, bt, wt, at);

    findTurnAroundTime(n, bt, wt, tat);



    for (i = 0; i < n; i++) {
            total_wt = total_wt + wt[i];
            total_tat = total_tat + tat[i];

    }



    printf("%.2f", (float) total_wt / (float) n);
printf("\n%.2f\n", (float) total_tat / (float) n);
}

int main() {
    int n, i;

    scanf("%d", &n);

    int burst_time[n], arrival_time[n];


    for (i = 0; i < n; i++) {

            scanf("%d", &arrival_time[i]);
    }


    for (i = 0; i < n; i++) {

            scanf("%d", &burst_time[i]);
    }

    findavgTime(n, burst_time, arrival_time);
    return 0;
}