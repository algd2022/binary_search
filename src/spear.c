#include <stdio.h>

int n;
int k;
int A[100000];

// i番目の木から作れる槍の本数は A[i] / x
// その和がk以上になる最大のxを求めれば良い。
int p(int x){
  int sum = 0;
  for(int i = 0; i < n; i++){
    sum += A[i] / x;
  }
  return sum >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000 + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d", lb);
  return 0;
}