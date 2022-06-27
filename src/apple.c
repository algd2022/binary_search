#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int n;
int k;
int A[100000];

bool enough(int x){
  int sum = 0;
  for(int j = 0; j < n; j++){
    sum += ceil((double)A[j]/(double)x);
  }
  if(sum <= k){
    return true;
  }else{
    return false;
  }
}

int main(){
  int i, lb=0, ub=pow(10, 9), mid;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while(ub - lb > 1){
    mid = (ub + lb) / 2;
    if(enough(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);

  return 0;
}
