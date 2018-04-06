#include <stdio.h>

int main() {
    long long num[16] = {1, 3};
    int n;

    for(int i = 2; i <= 15; i++)
        num[i] = 4 * num[i - 1] - num[i - 2];
    while(~scanf("%d", &n) && n !=-1) {
        if(n % 2) printf("0\n");
        else printf("%lld\n", num[n / 2]);
    }

    return 0;
}