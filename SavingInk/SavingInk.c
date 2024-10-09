#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define INF 999999

struct Edge{
    float x, y;
};

float calcEdge(struct Edge* edge, int i, int j) {
    return sqrt(pow((edge[j].x-edge[i].x), 2) + pow((edge[j].y - edge[i].y), 2));
}

float Prim(struct Edge* edge, int n) {
    float sum = 0.0;
    float distance[n];
    int isVisit[n];

    for(int i = 0; i < n; i++) {
        distance[i] = INF;
        isVisit[i] = 0;
    }

    distance[0] = 0.0;
    for(int i = 0; i < n; i++) {
        float min = INF;
        int visit = -1;
        for(int j = 0; j < n; j++) {
            if(!isVisit[j] && distance[j] < min) {
                min = distance[j];
                visit = j;
            }
        }
        isVisit[visit] = 1;
        sum += distance[visit];

        for(int j = 0; j < n; j++) {
            if(!isVisit[j]) {
                float dist = calcEdge(edge, visit, j);
                if(dist < distance[j])
                    distance[j] = dist;
            }
        }
    }
    return sum;
}

int main() {
    int n;
    scanf("%d", &n);
    struct Edge edge[n];

    for(int i = 0; i < n; i++) {
        scanf("%f %f", &edge[i].x, &edge[i].y);
    }

    float sum = Prim(edge, n);
    printf("%.2f", sum);
}
