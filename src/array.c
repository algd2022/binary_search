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

  lb = -1; // a[0] >= k を満たす a[] がありうる:n=3,a=[0,1,2],k=0のときx=0
  ub = n; // a[n-1] >= k を満たさない a[] がありうる:n=3,a=[0,1,2],k=3のときx=n
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if (A[mid] >= k){
      ub = mid;
    } else {
      lb = mid;
    }
  }

  printf("%d\n", ub);
  return 0;
}