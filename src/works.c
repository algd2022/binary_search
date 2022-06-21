#include <stdio.h>

int n;
int k;
int A[100000];

int p(int a[], int x) {
    int i, j = 0, sum = 0, num = 1;
    for (i = 0; i < n; i++) {
        if (x < a[i]) {
            j = 1;
            break;
        }
        sum += a[i];
        if (sum > x) {
            num++;
            sum = a[i];
        }
    }
    if (j == 1 || num > k) return 0;
    else return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ub = n * 10000;
  lb = 0;
  while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (p(A, mid) == 1) {
          ub = mid;
      }
      else {
          lb = mid;
      }
  }
  printf("%d\n", ub);

  return 0;
}
