#include <stdio.h>

int n;
int k;
int A[100000];

int possible(int x){
  long int nes = 0;
  for(int i = 0; i < n; i++) nes += (A[i] + x - 1) / x;
  return nes <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = (int)1e9;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if(possible(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",ub);

  return 0;
}

