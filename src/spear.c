#include <stdio.h>

int n;
int k;
int A[100000];

// appleのときのbagとほぼ同じ
int spear(int length){
  int sum = 0;
  for (int i = 0; i < n; i++){
    sum += A[i] / length;
  }
  if (sum < k){
    return 0;
  }
  return 1;
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
    if(spear(mid)) lb = mid;
    else ub = mid;
  }

  printf("%d\n", lb);




  return 0;
}
