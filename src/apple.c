#include <stdio.h>

int n;
int k;
int A[100000];

// i番目の人が使うかごの個数は A[i] / x 以上の最小の整数 = (A[i] + x - 1) / x
// その和がk以下になる最小のxを求めれば良い。
int p(int x){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += (A[i] + x - 1) / x;
  }
  return sum <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d", ub);
  return 0;
}