#include<stdio.h>

void flip(int p[], int lv, int top) {
    while (lv < top) {
        int tmp = p[lv];
        p[lv] = p[top];
        p[top] = tmp;
        lv++;
        top--;
    }
}

int Max(int p[], int lv, int i) {
    int max = 0;
    int maxlv = lv;
    for(int j = lv; j < i; j++) {
        if(p[j] > max) {
            max = p[j];
            maxlv = j;
        }
    }
    return maxlv;
}

int flippedPoint(int point, int i) {
    return i - point;
}

int main() {
    int pancakes[30];
    int diameter;
    int i = 0;
    int flipPoint[57]; // for worst case (<= 2n-3, n = number of pancakes)
    int flipped= 0;

    while(scanf("%d", &diameter) != EOF) pancakes[i++] = diameter;

    for(int j = 0; j < i; j++) {
        printf("%d ", pancakes[j]);
    }

    for(int size = i; size > 1; size--) {
        int flipPan = Max(pancakes, 0, size);
        if(flipPan != size - 1) {
            if(flipPan > 0) {
                flip(pancakes, 0, flipPan);
                flipPoint[flipped++] = flippedPoint(flipPan, i);
            }
            flip(pancakes, 0, size-1);
            flipPoint[flipped++] = flippedPoint(size, i) + 1;
        }
    }

    printf("(");
    for(int j = 0; j < i; j++) {
        if(j == i-1) printf("%d", pancakes[j]);
        else printf("%d ", pancakes[j]);
    }
    printf(")\n");
    
    for(int j = 0; j < flipped; j++) {
        printf("%d ", flipPoint[j]);
    }
    printf("0\n");

    return 0;

}