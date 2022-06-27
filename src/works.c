#include <stdio.h>
int n;
int k;
int A[100000];

int p(int n_alt, int array[], int mid_alt, int k_alt) {
	int workers = 0;
	int works = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] > mid_alt)return 0;
		works += array[i];
		if (works == mid_alt) {
			workers++;
			works = 0;
		}
		else if (works > mid_alt) {
			workers++;
			works = array[i];
		}
	}
	if (works > 0)workers++;
	if (workers <= k)return 1;
	return 0;
}

int main() {
	int i, lb, ub;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	lb = 0;
	ub = 1000000000;
	while (ub - lb > 1) {
		int mid = (lb + ub) / 2;
		if (p(n, A, mid, k)) ub = mid;
		else lb = mid;
	}

	printf("%d\n", ub);
	return 0;
}
