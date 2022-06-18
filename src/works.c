#include <stdio.h>

int n;
int k;
int A[100000];

int isOK(int key){
  int tem = 0, num = 1; // work time, required worker's num

  for (int i = 0; i < n; i++){
    if (tem + A[i] > key){
      if (A[i] > key){//max A > key (cant finish job)
        return 0;
      }
      num += 1;
      tem = A[i];
    }
    else{
      tem += A[i];
    }
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
  ub = 100000000; // ok (10**9)

  while (ub - lb > 1){
    int mid = (ub + lb) / 2;
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
