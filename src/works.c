#include <stdio.h>

int n;
int k;
int A[100000];
int p(int x){
  int i, sum, worker, worked;
  worked = 0;
  worker = 1;
  for (i = 0; i < n; i++){
    worked += A[i];
    if (A[i] > x){
      return 0;
    }
    else if (worked > x){
      worker += 1;
      worked = 0;
      i--;
    }
  }
  return (worker <= k);
  
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9;
  while (ub-lb>1)
  {
    int mid = (ub+lb)/2;
    if (p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n",ub);
  return 0;
}
