#include<stdio.h>
#include<stdlib.h>
#define ROWMAX 10
#define COLUMNMAX 100
int matrix[COLUMNMAX][ROWMAX];
int DP[COLUMNMAX][ROWMAX];

void makeTable(int m, int n) {

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            DP[i][j] = 999;
        }
    } // to exclude unnecessary value for movement

    DP[0][0] = matrix[0][0];
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < m; i++) {
            int smallSum = DP[(i-1+m)%m][j-1];
            if(DP[i][j-1] < smallSum) smallSum = DP[i][j-1];
            if(DP[(i+1)%m][j-1] < smallSum) smallSum = DP[(i+1)%m][j-1];
            DP[i][j] = smallSum + matrix[i][j];
        }
    }
}

int* findPath(int m, int n) {
    int* path = (int*)malloc(n * sizeof(int));

    int i = m - 1;

    path[0] = matrix[i][n-1];
    int pathnum = 1;

    for(int j = n-1; j > 0; j--) {
        if(DP[(i-1+m)%m][j-1] == DP[i][j] - matrix[i][j]) i = (i-1+m)%m;
        else if(DP[i][j-1] == DP[i][j] - matrix[i][j]);
        else i = (i+1)%m;
        path[pathnum++] = matrix[i][j-1];
    }

    return path;
}

int main() {
    int buffer[100][10] = {0};
    int sum[100] = {0};
    int rownum[100] = {0};
    int testcase = 0;
    int EOFcheck;

    while(1) {
        int n, m;
        if(scanf("%d %d", &m, &n) == EOF) break;
        // m = columns n = rows
        rownum[testcase] = n;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        makeTable(m, n);

        int* path = findPath(m, n);
        int num = 0;

        for(int i = n - 1; i >= 0; i--) {
            buffer[testcase][num++] = path[i];
            sum[testcase] += path[i];
        }

        free(path);
        testcase++;
    }

    for(int i = 0; i < testcase; i++) {
        for(int j = 0; j < rownum[i]; j++) {
            printf("%d ", buffer[i][j]);
        }
        printf("\n%d\n", sum[i]);
    }

    return 0;
}
