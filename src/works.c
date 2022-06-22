#include <stdio.h>

int n;
int k;
int A[100000];


int can_assign(unsigned int x){
  int i, load = 0, workers = 1;
  for(i = 0; i < n; i++){
    if(A[i] > x) return 0;
    if(load + A[i] <= x){
      load += A[i];
    }else{
      workers++;
      load = A[i];
    }
  }
  return workers <= k;
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
    int mid = (lb + ub) / 2;
    if(can_assign(mid)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", ub);
  return 0;
}
