#include <stdio.h>

int n;
int k;
int A[100000];

int main() {
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  if (A[n - 1] < k) {
    printf("%d\n", n);
    return 0;
  }
  if (A[0] >= k) {
    printf("0\n");
    return 0;
  }

  lb = 0;
  ub = n - 1;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (A[mid] >= k) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
