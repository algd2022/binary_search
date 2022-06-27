#include <stdio.h>

int n;
int k;
int A[100000];

int p(int a, int b){
  if(a <= b) return 1;
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = n;
  int lb_tmp,ub_tmp;
  for(int j = 0; j < k; j++){
    lb_tmp = lb;
    ub_tmp = ub;
    int sum_left = 0;
    int sum_right = 0;
    while (ub_tmp - lb_tmp > 1){
      int mid = (lb_tmp + ub_tmp) / 2;
      for(i = lb; i <= mid; i++) sum_left += A[i];
      for(i = mid + 1; i < ub; i++) sum_right += A[i];
      if(p(sum_left,sum_right)) lb_tmp = mid;
      else ub_tmp = mid;
    }
    if(p(sum_left,sum_right)) lb = lb_tmp;
    else ub = ub_tmp;
  }
  /*result*/
  printf("%d\n", A[ub]);
  return 0;
  return 0;
}
