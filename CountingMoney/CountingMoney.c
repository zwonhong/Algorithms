#include<stdio.h>

int main() {
    float bills[11] = {100.0, 50.0, 10.0, 5.0, 2.0, 1.0, 0.5, 0.25, 0.10, 0.05, 0.01};
    float times[11][2] = {{0}, {0}};
    for(int i = 0; i < 11; i++) {
        times[i][0] = bills[i];
    }
    float n;

    scanf("%f", &n);
    for (int i = 0; i < 11 && n > 0; i++) {
        while (n >= bills[i]) {
            n -= bills[i];
            times[i][1]++;
            n = ((int)(n * 100 + 0.5)) / 100.0;
        }
    }

    for(int i = 0; i < 11; i++) {
        if (times[i][1] != 0) {
            if(times[i][0] >= 1.0)
                printf("%d of %d dollars\n", (int)(times[i][1]), (int)(times[i][0]));
            else
                printf("%d of %d cents\n", (int)(times[i][1]), (int)(times[i][0] * 100));
        }
    }

    return 0;
}