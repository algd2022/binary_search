#include <stdio.h>

int n;
int k;
int A[100000];

int create(int mid){
  int i, count = 0;
  for(i = 0; i < n; i++){
    count += A[i] / mid;
  }
  if(count >= k){
    return 1;
  } 
  else{
    return 0;
  }
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 0;
  for(i = 0; i < n; i++){
    ub += A[i];
  }
  ub /= n;
  
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(create(mid)) lb = mid;
    else ub = mid;
  }
  printf("%d\n", lb);

  return 0;
}
