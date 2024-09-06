#include<stdio.h>

struct Nap {
    int StartHH;
    int StartMM;
    int EndHH;
    int EndMM;
    int startTime;
    int endTime;
} Nap[];

int main() {
    int Day = 1; //for check text case
    int num;
    int LongestNap = 0;
    int newNap, NapStart;
    char buffer[100];

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d:%d %d:%d", &Nap[i].StartHH, &Nap[i].StartMM, &Nap[i].EndHH, &Nap[i].EndMM);
        fgets(buffer, sizeof(buffer), stdin);
        Nap[i].startTime = Nap[i].StartHH * 60 + Nap[i].StartMM;
        Nap[i].endTime = Nap[i].EndHH * 60 + Nap[i].EndMM;
        if (i > 0) {
            newNap = Nap[i].startTime - Nap[i-1].endTime; 
        }
        else newNap = 0;

        if (LongestNap < newNap) {
            LongestNap = newNap;
            NapStart = Nap[i-1].endTime;
        }
    }

    if (LongestNap < 60) {
        printf("Day #%d: the longest nap starts at %d:%02d and will last for %d minutes", Day, NapStart/60, NapStart%60, LongestNap);
    }
    else {
        printf("Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes", Day, NapStart/60, NapStart%60, LongestNap/60, LongestNap%60);
    }

    return 0;
}