#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

int DPTable[MAXSIZE][MAXSIZE];
int Windex[MAXSIZE];
int Sindex[MAXSIZE];
int final[100];

int Min(int arr[], int now, int n) {
    int min = arr[now];
    int minIndex = now;
    for(int i = now; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int Max(int arr[], int now, int n) {
    int max = arr[now];
    int maxIndex = now;
    for(int i = now; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            maxIndex = i;
        }
    }
    return maxIndex;
}

void AscendingSort(int arr[], int n) {
    int tmp, minIndex;
    int Matching[MAXSIZE][2];
    for (int i = 0; i < n; i++) {
        Matching[i][0] = i;
        Matching[i][1] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        minIndex = Min(arr, i, n);
        if(i != minIndex) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;

            tmp = Matching[i][1];
            Matching[i][1] = Matching[minIndex][1];
            Matching[minIndex][1] = tmp;
            tmp = Matching[i][0];
            Matching[i][0] = Matching[minIndex][0];
            Matching[minIndex][0] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        Windex[i] = Matching[i][0] + 1;
    }
}

void DescendingSort(int arr[], int n) {
    int tmp, maxIndex;
    int Matching[MAXSIZE][2];
    for (int i = 0; i < n; i++) {
        Matching[i][0] = i;
        Matching[i][1] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        maxIndex = Max(arr, i, n);
        if(i != maxIndex) {
            tmp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = tmp;

            tmp = Matching[i][1];
            Matching[i][1] = Matching[maxIndex][1];
            Matching[maxIndex][1] = tmp;
            tmp = Matching[i][0];
            Matching[i][0] = Matching[maxIndex][0];
            Matching[maxIndex][0] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        Sindex[i] = Matching[i][0] + 1;
    }
}

void makeTable(int n) {
    DPTable[0][0] = 0;
    for(int i = 1; i < n+1; i++) {
        DPTable[0][i] = Windex[i-1];
        DPTable[i][0] = Sindex[i-1];
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if(i-1 != 0) DPTable[i][j] = DPTable[i-1][j];
            for (int k = j; k < n + 1; k++) {
                if (k-1 != 0 && DPTable[i][k] < DPTable[i][k-1])
                    DPTable[i][k] = DPTable[i][k-1];
            }
            if (DPTable[0][j] == DPTable[i][0]) DPTable[i][j]++;
        }
    }
}

void findPath(int n, int size) {
    int i = size;
    int j = size;
    int count = 0;

    while (i > 0 && j > 0) {
        if (DPTable[i][j] == n) {
            final[count] = DPTable[i][0];
            count++;
            n--;
        }
        if (i > 1 && DPTable[i][j] == DPTable[i-1][j]) 
            i--;
        else if (j > 1 && DPTable[i][j] == DPTable[i][j-1])
            j--;
        else {
            i--;
            j--;
        }
    }
}

int main() {
    int W[MAXSIZE];
    int S[MAXSIZE];
    int num = 0;
    int n = 4;
    
    while(scanf("%d %d", &W[num], &S[num]) != EOF) num++;
    AscendingSort(W, num);
    DescendingSort(S, num);
    makeTable(num);
    
    scanf("%d", &n);
    findPath(n, num);

    for(int i = 0; i <= num; i++) {
        for(int j = 0; j <= num; j++) {
            printf("%d ", DPTable[i][j]);
        }
        printf("\n");
    }
    for(int i = n-1; i >= 0; i--) {
        printf("%d\n", final[i]);
    }

    return 0;
}