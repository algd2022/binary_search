#include <stdio.h>

int n;
int k;
int A[100000];

// num個のサイズのバッグでりんごを持ち帰れるかチェックする関数
int takeout_check(int num);

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
    if(takeout_check(mid) == 1) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);

  return 0;
}

int takeout_check(int num){
  int needed_bag, i;
  needed_bag = 0; 
  for(i = 0; i < n; i++){
    needed_bag += (A[i] + num - 1) / num;
  }
  if(needed_bag <= k) return 1;
  else return 0;
}