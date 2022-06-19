#include <stdio.h>

int n;
int k;
int A[100000];

int is_enough_size(int size_of_bag) {
    int number_of_bag_needed = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] % size_of_bag == 0) {
            number_of_bag_needed += A[i] / size_of_bag;
        } else {
            number_of_bag_needed += A[i] / size_of_bag + 1;
        }
    }

	return number_of_bag_needed <= k;
}

int main() {
    int i, lb, ub;
    int max_number_of_apple = 0;

    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > max_number_of_apple) {
            max_number_of_apple = A[i];
        }
    }

    lb = 0;
    ub = max_number_of_apple + 1;

    while (ub - lb > 1) {
        int mid = (lb + ub) / 2;
        if (is_enough_size(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    printf("%d\n", ub);
    return 0;
}
