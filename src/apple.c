#include <stdio.h>

int n;
int k;
int A[100000];

int isOK(int key){
  int num = 0;
  for (int i = 0; i < n; i++){
    num += (A[i] + key - 1) / key; // round up
  }
  if (num <= k){
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

  lb = 0; // ng
  ub = 1000000000; // ok (10**9)

  while (ub - lb > 1){
    int mid = (lb + ub) / 2;

    if (isOK(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
