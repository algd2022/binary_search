#include <stdio.h>

int n;
int k;
int A[100000];

int p(int n_alt, int array[], int mid_alt, int k_alt) {
	int bag_number = 0;
	for (int i = 0; i < n; i++) {
		bag_number += (array[i] + mid_alt - 1) / mid_alt;
	}
	if (bag_number <= k)return 1;
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