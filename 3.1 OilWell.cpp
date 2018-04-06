//又TLE了

#include <iostream>
#include <algorithm>
using namespace std;

int y[2000005], n;

int Partition(int a[], int l, int r, int pivot) {   
	int i = l;
	int j = r;
	while (true) {
		while (a[i] <= pivot && i < r)
			++i;   
		while (a[j] > pivot)
			--j;   
		if (i >= j) break;
		swap(a[i], a[j]);
	}
	a[l] = a[j];
	a[j] = pivot;
	return j;
}

int S_sort(int a[], int low, int high, int k) {
	int i, j, x, q, n;
	n = high - low;
	if (n < 5) {
		sort(a + low, a + high);
		return a[low + k - 1];
	}
	for (i = 0; i < n / 5; i++) {
		sort(a + low + i * 5, a + low + i * 5 + 5);
		swap(a[low + i], a[low + i * 5 + 2]);
	}
	x = S_sort(a, low, low + n / 5, n / 10 + 1);
	j = Partition(a, low, high, x);
	q = j - low + 1;
	if (q == k)
		return x;
	else if (q > k)
		return S_sort(a, low, j + 1, k);
	else
		return S_sort(a, j + 1, high, k - q);
}

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	n = 0;
	while (~scanf("%d,%d", &y[n], &y[n])) n++;
	cout << S_sort(y, 0, n, (n + 1) / 2) << endl;

	return 0;
}