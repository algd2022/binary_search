#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ///////edit/////////
  lb = -1; //A[-1]は存在しない（気持ち的には-∞）なので絶対にk<=A[n]を満たさない。
  ub = n; //A[n]=1e9なのでk<=A[n]を絶対に満たす。
  A[n] = 1e9; 
  while(ub-lb>1){
    int mid = (ub+lb)/2;
    // printf("lb=%d, mid=%d, ub=%d\n", lb, mid, ub);
    if(k<=A[mid]){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  //////edit end//////
  return 0;
}
