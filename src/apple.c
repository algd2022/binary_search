#include <stdio.h>

int n;
int k;
int A[100000];

int div_ceil(int p, int q){
  return (p + q - 1) / q;
}

int canHave(x){
  int num_bag = 0;
  for(int i = 0; i < n; i++){
    num_bag += div_ceil(A[i], x);
  }
  return num_bag <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000000;
  //n is number of human
  //k is number of bag
  //search size of bag
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(canHave(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
