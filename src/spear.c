#include <stdio.h>

int n;
int k;
int A[100000];

int p(m){
  int num = 0,i;
  for(i = 0; i < n; i++){
    num = num + A[i]/m;
  }
  return num < k;
}

int main(){
  int i, lb, ub,max;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  max = A[0];
  for(i = 0;i < n;i++){
    if(max < A[i]){
      max = A[i];
    }
  }
  lb = 0;
  ub = max + 1 ;
  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(mid)){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n",lb);


  return 0;
}
