#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INF 0x3f3f3f3f

int MatrixChain(int p[], int n, int **s);
void  TraceBack(int **s, int i, int j);

int main() {
	int i, n, ans;
	scanf("%d", &n);

	int *p = (int *)malloc(sizeof(int) * (n + 1));
	for (i = 0; i <= n; i++)
		scanf("%d", &p[i]);

	int **s = (int **)malloc(sizeof(int *) * (n + 1));
	for (i = 0; i <= n; i++)
		s[i] = (int *)malloc(sizeof(int) * (n + 1));
	memset(s, 0, sizeof(s));

	if(n == 1) {
        printf("0\n(A1)\n");
	}
	else {
        ans = MatrixChain(p, n, s);
        printf("%d\n", ans);
        TraceBack(s, 1, n);
        printf("\n");
	}

	return 0;
}


int MatrixChain(int p[], int n, int **s) {
	int i, j, k, l;
	int q = 0;

	int **m = (int **)malloc(sizeof(int *) * (n + 1));
	for (i = 0; i <= n; i++)
		m[i] = (int *)malloc(sizeof(int) * (n + 1));
	for (i = 1; i <= n; i++)
		m[i][i] = 0;

	for (l = 2; l <= n; l++)
		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = INF;
			for (k = i; k < j; k++) {
				q = (m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]);
				if (m[i][j] > q) {
					s[i][j] = k;
					m[i][j] = q;
				}
			}
		}

	return m[1][n];
}

void TraceBack(int **s, int i, int j) {
	if (i == j)
		printf("A%d", i);
	else {
		printf("(");
		TraceBack(s, i, s[i][j]);
		TraceBack(s, s[i][j] + 1, j);
		printf(")");
	}
}