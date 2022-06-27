#include <stdio.h>

int n;
int k;
int A[100000];

int check(int A[], int mid, int n, int k){
  int times = 0;
  int workers = 1;

  for(int i = 0; i < n; i++){
    if(A[i] > mid){ // fail to complete the job
      return 0;
    }
    else if(times+A[i] <= mid){
      times += A[i];
    }
    else if(A[i] <= mid){
      times += A[i];
      workers++;
    }
  }

  if(workers <= k) return 1;
  else return 0;
}

unsigned int binary_search(int A[], int x, int n){
  int lb = 0;
  int ub = 10e8;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(check(A, mid, n, k)) ub = mid;
    else lb = mid;
  }
  return ub;
}

int main(){
  int i, lb, ub;
  int ans;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ans = binary_search(A, k, n);
  printf("%d\n", ans);

  return 0;
}