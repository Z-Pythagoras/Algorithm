#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
using namespace std;

int RandomPartition(int nn) {
	int par = 0;
	time_t t;

	srand((unsigned)time(&t));

	if (nn <= 30000)
		par = rand() % (nn - 1);
	else {
		while (nn > 30000) {
			par += rand() % 30000;
			nn -= 30000;
		}
		par += rand() % (nn - 1);
	}
	return par;
}

int s1[2000005], s3[2000005];

int Select(int* S, int k, int num) {
	int mid, n1, n2, n3;

	if (num < 75) {
		sort(S, S + num);
		return S[k - 1];
	}
	else {
		mid = S[RandomPartition(num)];
		n1 = n2 = n3 = 0;
		for (int i = 0; i < num; i++) {
			if (S[i] < mid) s1[n1++] = S[i];
			else if (S[i] == mid) n2++;
			else s3[n3++] = S[i];
		}
		if (n1 >= k) return Select(s1, k, n1);
		else if (n1 + n2 >= k) return mid;
		else return Select(s3, k - n1 - n2, n3);
	}
}

int y[2000005], x, n;

int main() {
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while (~scanf("%d,%d", &x, &y[n])) n++;

	printf("%d\n", Select(y, (n + 1) / 2, n));

	return 0;
}