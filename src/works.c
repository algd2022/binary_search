#include <stdio.h>

int n;
int k;
int A[100000];


int func(int x){
  int task = 0, ers = 0, i =0;
  while((ers < k) && (i < n)){
    task += A[i];
    if (task <= x){
      i++;
    }
    else{
      ers++;
      task = 0;
    }
  }
  if (i == n){
    return 1;
  }
  else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;
  ub = 1000000000;
  while(ub - lb >1){
    int mid = (ub + lb) / 2;
    if (func(mid)){
      ub = mid; //全員の仕事量をmidで抑えられるのでmidを小さくする
    }
    else lb = mid; //人数がkを超過するためmidを大きくする
  }
  printf("%d\n", ub);
  return 0;
}