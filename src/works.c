#include <stdio.h>

int n;
int k;
int A[100000];

int p(unsigned int x) {
  int num_people = 1;
  int workload = 0;
  for (int i = 0; i < n; i++) {
    if (A[i] > x) return 0;
    if (workload + A[i] <= x) {
      workload += A[i];
    } else {
      num_people += 1;
      workload = A[i];
    }
  }
  return num_people <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1) {
    int mid = (ub + lb) / 2;
    if (p(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
