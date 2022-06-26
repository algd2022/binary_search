#include <stdio.h>

int n;
int k;
int A[100000];

int p(int w_max){
  int k_need = 1;
  int w_sum = 0;
  for(int i = 0; i < n; i++){
    if(A[i] > w_max){
      return 0;
    }else if(w_sum + A[i] <= w_max){
      w_sum = w_sum + A[i];
    }else{
      k_need++;
      w_sum = A[i];
    }
  }
  return k_need <= k;
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
    int mid = (ub + lb) / 2;
    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }

  printf("%d", ub);
  
  return 0;
}
