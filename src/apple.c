#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int cnt = 0;
  for(int i = 0; i < n; i++){
    cnt += (A[i] - 1)/x + 1;
  }
  if(cnt <= k) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9;

  while(ub - lb > 1){
    int mid = lb + (ub - lb)/2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);
  return 0;
}
