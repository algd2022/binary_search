#include <stdio.h>

int n;
int k;
int A[100000];

int work(x){
  int ammount = 0;
  int human = 0;
  for(int i = 0; i < n; i++){
    if(ammount + A[i] <= x){
      ammount += A[i];
    }else{
      human++;
      ammount = A[i];
    }
    if(human >= k || x < A[i]){
      return 0;
    }
  }
  return 1;
}

int main(){
  int i, lb, ub;
  lb = 0;
  ub = 1000000000;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(work(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
