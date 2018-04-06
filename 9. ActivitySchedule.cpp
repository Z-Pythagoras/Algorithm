#include <cstdio>
#include <algorithm>
using namespace std;

int st[1000005], ed[1000005];

int main() {
    int n, i, j, cnt;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d%d", &st[i], &ed[i]);
    sort(st, st + n);
    sort(ed, ed + n);
    for(i = 0, j = 0, cnt = 0; i < n; i++) {
        if(st[i] < ed[j]) cnt++;
        else j++;
    }
    printf("%d\n", cnt);

    return 0;
}