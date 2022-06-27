#include <stdio.h>

int n;
int k;
int A[100000];


unsigned int binary_search(int A[], int x, int n){
  int lb = 0;
  int ub = 10e8;
  while(ub - lb > 1){
    int bag = 0;
    int mid = (lb + ub) / 2;
    for(int i = 0; i < n; i++){
      bag += (A[i]+mid-1)/mid; // bag = sum of all bags
    }
    if(bag <= x) ub = mid;
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
