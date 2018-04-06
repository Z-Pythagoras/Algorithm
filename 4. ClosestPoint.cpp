#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

typedef struct {
	int p;
	double x, y;
}Point;

int CmpX(const void * a, const void * b) {
	Point* c = (Point*)a;
	Point* d = (Point*)b;
	if (c->x > d->x)
		return 1;
	else if (c->x == d->x)
		return 0;
	else
		return -1;
}

int CmpY(const void * a, const void * b) {
	Point* c = (Point*)a;
	Point* d = (Point*)b;
	if (c->y > d->y)
		return 1;
	else if (c->y == d->y)
		return 0;
	else
		return -1;
}

double Dis(Point a, Point b) {
	double dx = a.x - b.x, dy = a.y - b.y;

	return sqrt(dx*dx + dy * dy);
}

void Merge(Point c[], Point d[], int l, int m, int r) {
	int i = l, j = m + 1, k = l;

	while ((i <= m) && (j <= r)) {
		if (c[i].y <= c[j].y) d[k++] = c[i++];
		else d[k++] = c[j++];
	}
	while (i <= m) d[k++] = c[i++];
	while (j <= r) d[k++] = c[j++];
}

double Closest(Point X[], Point Y[], Point Z[], int l, int r) {
	double d1, d2, d3, dr = 0, dp = 0, d = 0;
	int f, g, k, m;

	if (r - l == 1) return Dis(X[l], X[r]);
	if (r - l == 2) {  
		d1 = Dis(X[l], X[l + 1]);
		d2 = Dis(X[l + 1], X[r]);
		d3 = Dis(X[l], X[r]);
		if (d1 <= d2 && d1 <= d3) return d1;
		else if (d2 <= d3) return d2;
		else return d3;
	}

	m = (l + r) / 2;
	f = l, g = m + 1;
	for (int i = l; i <= r; ++i) {
		if (Y[i].p > m) Z[g++] = Y[i];
		else Z[f++] = Y[i];
	}
	d = Closest(X, Z, Y, l, m);
	dr = Closest(X, Z, Y, m + 1, r);
	if (dr < d) d = dr;
	Merge(Z, Y, l, m, r);

	k = l;
	for (int i = l; i <= r; ++i)
		if (fabs(Y[m].x - Y[i].x) < d) Z[k++] = Y[i];

	for (int i = l; i < k; ++i)
		for (int j = i + 1; j < k && Z[j].y - Z[i].y < d; ++j) {
			dp = Dis(Z[i], Z[j]);
			if (dp < d) d = dp;
		}

	return d;
}

Point X[N], Y[N], Z[N];

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n;
	double  d = 0.0;
	while (scanf("%d", &n) == 1) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) 
			scanf("%lf%lf", &X[i].x, &X[i].y);
		qsort(X, n, sizeof(Point), CmpX);

		for (int i = 0; i < n; ++i) {
			Y[i].p = i;
			Y[i] = X[i];
		}

		qsort(Y, n, sizeof(Point), CmpY);

		d = Closest(X, Y, Z, 0, n - 1);
		printf("%.2f\n", d / 2.0);
	}

	return 0;
}