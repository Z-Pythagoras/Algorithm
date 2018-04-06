#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool tree[1505][1505];
int cnt[1505];

int main() {
	int n, st, cn, ed, ans, nn, i, j, k;

	while (~scanf("%d", &n)) {
		memset(tree, false, sizeof(tree));
		memset(cnt, 0, sizeof(cnt));
		for (i = 0; i < n; i++) {
			scanf("%d:(%d)", &st, &cn);
			for (j = 0; j < cn; j++) {
				scanf("%d", &ed);
				tree[st][ed] = tree[ed][st] = true;
				cnt[st]++; cnt[ed]++;
			}
		}

		ans = 0; nn = n;
		while (nn) {
			for (j = 0; j < n; j++)
				if (cnt[j] == 1) {
					cnt[j]--; nn--;
					for (k = 0; k < n; k++)
						if (tree[j][k]) {
							tree[j][k] = tree[k][j] = false;
							cnt[k] = 0; ans++; nn--;
							break;
						}
					for (i = 0; i < n; i++)
						if (tree[k][i]) {
							if (cnt[i] == 1) {
								tree[k][i] = tree[i][k] = false;
								nn--; cnt[i] = 0;
							}
							else {
								tree[k][i] = tree[i][k] = false;
								cnt[i]--;
							}
						}
				}
		}
		printf("%d\n", ans);
	}

	return 0;
}