#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  //k人がm時間以内にできるなら1それ以外0
  int idx = 0;
  int sum = 0;
  int ret = 1;
  for(int i = 0;i < n;++i){
      sum += A[i];
      if(sum > m){
        ++idx;
        sum = A[i];
        if(idx >= k || sum > m){
          ret = 0;
          break;
        }
      }
  }
  return ret;
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
    int mid = (ub - lb)/2 + lb;
    if(p(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
}
