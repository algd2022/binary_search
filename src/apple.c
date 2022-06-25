#include <stdio.h>

int n;
int k;
int A[100000];

int bagcalc(int maxnum){
  int i, count=0;
  for(i=0; i<n; i++){
    count+=(A[i]+maxnum-1)/maxnum;
  }
  if(count<=k){
    return 1;
  }else{
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
  ub = A[0];
  for(i = 0; i < n; i++){
    if(ub < A[i]) ub = A[i];
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(bagcalc(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
