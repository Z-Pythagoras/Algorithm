#include <stdio.h>
#define N 10005

int main() {
    int n, s, c, y, minn = 99999;
    long long ans = 0;
    scanf("%d%d", &n, &s);
    while(n--) {
        scanf("%d%d", &c, &y);
        minn = (minn + s) < c ? (minn + s) : c;
        ans += minn * y;
    }
    printf("%lld\n", ans);

    return 0;
}