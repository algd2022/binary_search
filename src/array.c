#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  return (x >= k);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  //n is length of list
  //k is border
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;
  ub = n;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(A[mid])){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
