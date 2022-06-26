#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  //A[-1]=0(or-∞),A[n]=+∞と考える
  //初期値をそれぞれ定めるlb,ubをそれぞれ+1,-1するとA[mid] >= kが常に不成立、成立しなくなる
  lb = -1;
  ub = n;
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(A[mid] >= k) {
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}
