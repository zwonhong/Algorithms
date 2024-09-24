#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 1000

struct Box {
    int dollar;
    int size;
};

int* findMin(struct Box *box, int n) {
    float value1 = (float)box[0].dollar / (float)box[0].size;
    float value2 = (float)box[1].dollar / (float)box[1].size;
    int count1 = -999, count2 = -999;

    if (value1 < value2) {
        int cases = n / box[0].size;
        while (cases >= 0) {
            if ((n - box[0].size * cases) % box[1].size == 0) {
                count1 = cases;
                count2 = (n - box[0].size * cases) / box[1].size;
                break;
            }
            cases--;
        }
    } else {
        int cases = n / box[1].size;
        while (cases >= 0) {
            if ((n - box[1].size * cases) % box[0].size == 0) {
                count2 = cases;
                count1 = (n - box[1].size * cases) / box[0].size;
                break;
            }
            cases--;
        }
    }

    int *val = (int *)malloc(2 * sizeof(int));
    val[0] = count1;
    val[1] = count2;

    return val;
}

int main() {
    int n;
    int ans[MAXSIZE][2];
    int num = 0;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        struct Box box[2];
        for (int i = 0; i < 2; i++) {
            scanf("%d %d", &box[i].dollar, &box[i].size);
        }
        int *val = findMin(box, n);
        ans[num][0] = val[0];
        ans[num][1] = val[1];
        num++;
        free(val);
    }

    for (int i = 0; i < num; i++) {
        if (ans[i][0] < 0)
            printf("failed\n");
        else
            printf("%d %d\n", ans[i][0], ans[i][1]);
    }

    return 0;
}
