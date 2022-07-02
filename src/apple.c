#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int bag = 0;
  for(int i = 0; i < n; i++){
    bag += 1 + (A[i] - 1)/x;
  }
  return bag;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub + 1) / 2;
    if(mid < 1) break; 
    else if(p(mid) <= k) {
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
