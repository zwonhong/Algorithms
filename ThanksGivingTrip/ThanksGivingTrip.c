#include<stdio.h>

int main() {
    int n = -1;
    int time = 0;
    int spentSum[10];
    while (n != 0) {
        int money[10];
        int sum = 0;
        int avg = 0, spent = 0;
        spentSum[time] = 0;

        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            scanf("%d", &money[i]);
            sum += money[i];
        }
        avg = sum/n;
        for (int j = 0; j < n; j++) {
            if (money[j] < avg) {
                spent = avg - money[j];
                spentSum[time] += spent;
            }
        }
        time++;
    }

    for (int i = 0; i < time; i++) {
        printf("%d won\n", spentSum[i]);
    }
}