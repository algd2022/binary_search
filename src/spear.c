#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s = s + A[i] / mid;
  }
  return s < k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = A[0] + 1;
  for (i = 0; i < n; i++) {
    if (A[i] + 1 > ub) ub = A[i] + 1;
  }
  while (ub - lb > 1) {
    int mid = (lb + ub + 1) / 2;
    if (p(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", lb);
  return 0;
}
