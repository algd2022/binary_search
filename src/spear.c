#include <stdio.h>

int n;
int k;
int A[100000];

// 長さlengthの槍をk本作れるかどうか判定する関数
int make_check(int length);

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1e9 + 1;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(make_check(mid) == 1) lb = mid;
    else ub = mid;
  }

  printf("%d\n", lb);

  return 0;
}

int make_check(int length){
  int sum_spear, i;
  sum_spear = 0;
  for(i = 0; i < n; i++){
    sum_spear += A[i] / length;
  }
  if(sum_spear >= k) return 1;
  else return 0;
}