#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

typedef struct {
    int u, v, w;
} GRAPH;

GRAPH cow[20005];
int dis[20005];

int BellmanFord(int node, int edge) {
    int i, j;
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    for(i = 1; i <= node - 1; i++)
        for(j = 1; j <= edge; j++)
            if(dis[cow[j].v] > dis[cow[j].u] + cow[j].w)
                dis[cow[j].v] = dis[cow[j].u] + cow[j].w;
    for(j = 1; j <= edge; j++)
            if(dis[cow[j].v] > dis[cow[j].u] + cow[j].w)
                return -1;
    if(dis[node] == INF)
        return -2;
    return dis[node];
}

int main() {
    int n, ml, md, u, v, w, i, cnt;
    scanf("%d%d%d", &n, &ml, &md);
    cnt = 1;
    for(i = 0; i < ml; i++, cnt++) {
        scanf("%d%d%d", &u, &v, &w);
        cow[cnt].u = u; cow[cnt].v = v; cow[cnt].w = w;
    }
    for(i = 0; i < md; i++, cnt++) {
        scanf("%d%d%d", &u, &v, &w);
        cow[cnt].u = v; cow[cnt].v = u; cow[cnt].w = -w;
    }
    cnt--;

    int ans = BellmanFord(n, cnt);
    printf("%d\n", ans);

    return 0;
}