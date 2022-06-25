#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    s += (A[i] - 1) / x + 1;
  }
  return s <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000001;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
