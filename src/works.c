#include <stdio.h>

int n;
int k;
int A[100000];

// 最大仕事量をxとし、仕事量がx超過にならない最大値になるように分割していく。
// 分割数がk以下になる最小のxを求めれば良い。

int p(int x){
  int sum = 1;
  int h = x;
  for(int i = 0; i < n; i++){
    if(h >= A[i]){
      h -= A[i];
    }
    else if(A[i] > x) return 0;
    else{
      sum++;
      h = x - A[i];
    }
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
  ub = n * 10000;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d", ub);
  return 0;
}