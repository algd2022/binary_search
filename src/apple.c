#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int p(int x){
  int i, bagnum;
  bagnum = 0;
  for(i = 0;i < n;i++){
    bagnum += (A[i] + x - 1)  / x ;
    //mod x > 0で+1, mod x = 0で+0
  }
  if(bagnum <= k){
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
  ub = 1000000000;
  while(ub - lb > 1){
    int mid = (ub + lb) / 2;
    if (p(mid) == 0){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }
  printf("%d\n" , ub);
  return 0;
}
