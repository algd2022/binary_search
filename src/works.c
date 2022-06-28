#include <stdio.h>

int n;
int k;
int A[100000];

int p(int A[], int n, int k, int mid) {
  int hrs = 0;
  int wkrs = 1;
  for (int i = 0; i < n; i++) {
    if (A[i] > mid) {
      return 0;
    }
    if (hrs + A[i] > mid) {
      hrs = 0;
      wkrs++;
    }

    hrs += A[i];

  }
  if (wkrs <= k) {
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

lb = 0;
ub = 1000000000;
while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (p(A, n, k, mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
} 