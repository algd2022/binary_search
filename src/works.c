#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int n;
int k;
int A[100000];

bool can(int x){
  int need = 1, sum = 0;
  for(int j=0; j < n; j++){
    if(A[j] > x){
      return false;
    }else if(sum + A[j] > x){
      need++;
      sum = 0;
    }
    sum += A[j];
  }

  if(need <= k){
    return true;
  }else{
    return false;
  }
}

int main(){
  int i, lb=0, ub=pow(10,4), mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
    mid = (ub + lb) / 2;
    if(can(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
