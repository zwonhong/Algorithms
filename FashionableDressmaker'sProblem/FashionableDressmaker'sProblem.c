#include<stdio.h>
#include<stdlib.h>

struct JOBS {
    int time;
    int penalty;
    float unit;
};

int Max(struct JOBS* jobs, int now, int n) {
    int MaxIndex = now;
    float max = jobs[now].unit;

    for(int i = now + 1; i < n; i++) {
        if(max < jobs[i].unit) {
            max = jobs[i].unit;
            MaxIndex = i;
        }
    }

    return MaxIndex;
}

int* Sort(struct JOBS* jobs, int n) {
    int tmp;
    float temp;

    int* result = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        result[i] = i;
    }

    for(int i = 0; i < n; i++) {
        int max = Max(jobs, i, n);
        if(i != max) {
            tmp = jobs[i].time;
            jobs[i].time = jobs[max].time;
            jobs[max].time = tmp;

            tmp = jobs[i].penalty;
            jobs[i].penalty = jobs[max].penalty;
            jobs[max].penalty = tmp;

            temp = jobs[i].unit;
            jobs[i].unit = jobs[max].unit;
            jobs[max].unit = temp;

            tmp = result[i];
            result[i] = result[max];
            result[max] = tmp;
        }
    }

    return result;
}

int main() {
    int testcase;
    int times = 0;
    while(times < 3) {
        scanf("%d", &testcase);
        printf("\n");
        int n;
        scanf("%d", &n);

        struct JOBS jobs[n];
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &jobs[i].time, &jobs[i].penalty);
            jobs[i].unit = (float)(jobs[i].penalty) / (float)(jobs[i].time);  // unit 값 계산
        }

        int* result = Sort(jobs, n);
        printf("Test %d : ", testcase);
        for(int i = 0; i < n; i++) {
            printf("%d ", result[i]+1);
        }
        printf("\n");

        free(result);
        times++;
    }
    return 0;
}
