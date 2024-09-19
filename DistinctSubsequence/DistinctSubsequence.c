#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
int DP[10000][100];

int DPTable(char *s, char *t, int snum, int tnum) {
    DP[0][0] = 1;
    for (int i = 1; i <= snum; i++) {
        DP[i][0] = 1;
    }
    for (int j = 1; j <= tnum; j++) {
        DP[0][j] = 0;
    }


    for (int i = 1; i <= snum; i++) {
        for (int j = 1; j <= tnum; j++) {
            if (s[i-1] == t[j-1]) {
                DP[i][j] = DP[i-1][j-1] + DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j];
            }
        }
    }

    return DP[snum][tnum];
}

int main() {
    int n;
    scanf("%d", &n);
    int *buffer = (int *)malloc(n * sizeof(int));
    getchar();

    for (int i = 0; i < n; i++) {
        char s[10000] = {0};
        char t[100] = {0};
        
        fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0;

        fgets(t, sizeof(t), stdin);
        t[strcspn(t, "\n")] = 0;

        int snum = strlen(s);
        int tnum = strlen(t);

        buffer[i] = DPTable(s, t, snum, tnum);
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", buffer[i]);
    }

    return 0;
}
