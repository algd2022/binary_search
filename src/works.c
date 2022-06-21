#include <stdio.h>

int n;
int k;
int A[100000];

int p(int mid) {
  int s = A[0];
  int x = 0;
  if (s > mid) {
    return 1;
  }
  for (int i = 1; i < n; i++) {
    if (A[i] > mid) {
      return 1;
    }
    if (A[i] == mid) {
      if (s == 0) {
        x = x + 1;
      } else {
        s = 0;
        x = x + 2;
      }
    } else {
      if (s > mid) {
        s = A[i - 1] + A[i];
        x = x + 1;
      } else if (s == mid) {
        s = A[i];
        x = x + 1;
      } else {
        s = s + A[i];
      }
    }
  }
  if (s > mid) {
    return x + 2 > k;
  } else if (s == 0) {
    return x > k;
  } else {
    return x + 1 > k;
  }
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 0;
  for (i =0; i < n; i++) {
    ub = ub + A[i];
  }
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
