#include <stdio.h>

int n;
int k;
int A[100000];

int main(){
  int i, lb, ub, now_index;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = n;
  while(ub - lb > 1){
    now_index = (lb + ub) / 2;
    if(A[now_index] > k){
      ub = now_index;
    }else{
      lb = now_index;
    }
  }
  printf("%d\n", ub);



  return 0;
}
