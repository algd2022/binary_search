#include <stdio.h>

int n;
int k;
int A[100000];


int p(int m){
  int i;
  int j = 0;
  for(i = 0; i < n; i++){
    j = j + A[i] / m;
  }
  if(j >= k){
    return 0;
  }
  else {
    return 1;
  }
}


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }


  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", lb);


  return 0;
}