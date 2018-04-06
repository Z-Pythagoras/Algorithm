#include <cstdio>
#include <algorithm>
using namespace std;

int a[10005];

int main() {
	int n, k, maxnum, ans, cnt;
	int low, high, mid;
	double len;

	while (~scanf("%d%d", &n, &k)) {
		maxnum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &len);
			a[i] = (int)((len + 0.005) * 100);
			maxnum = max(maxnum, a[i]);
		}
		
		low = 1; high = maxnum; ans = 0;
		while (low <= high) { //for(int k = 0; k < 10000; k++)
			mid = (low + high) / 2; 
			cnt = 0;
			for (int i = 0; i < n; i++)
				cnt += a[i] / mid;
			if (cnt >= k) {
				ans = max(ans, mid); 
				low = mid + 1;
			}
			else
				high = mid - 1;
		}
		printf("%.2f\n", ans / 100.0);
	}

	return 0;
}