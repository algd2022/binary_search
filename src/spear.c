#include <stdio.h>

int n;
int k;
int A[100000];

int isOK(int key){
  int num = 0; // number of wood bar
  for (int i = 0; i < n; i++){
    num += A[i] / key;
  }
  if (num >= k){
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

  lb = 0; // ok
  ub = 1000000001; // ng (10**9 + 1)

  while ((ub - lb) > 1){
    int mid = (ub + lb) / 2;
    if (isOK(mid)){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }

  printf("%d\n", lb);

  return 0;
}
