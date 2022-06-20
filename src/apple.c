#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int n, int k, int mid) {
  int bag_n = 0;
  for (int i = 0; i < n; i++) {
    bag_n += (A[i] + mid - 1) / mid;
  }
  if (bag_n <= k) {
    return 1;
  }
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  int mid;
  lb = 0;
  ub = 1000000000;
  while (ub - lb > 1){
    mid = (lb + ub) / 2;
    if (p(A, n, k, mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);

  return 0;
}
