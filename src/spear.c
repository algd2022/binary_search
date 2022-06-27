#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int binary_search(int A[], int k,int n){
  int lb = 0;
  int ub = 1000000001;
  int i;
  int y;
  while(ub - lb > 1){
    y=0;
    int mid = (lb + ub) / 2;
    for(i=0; i<n;i++){
      y+=A[i]/mid;
    }
    if(y < k) {
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  return lb;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  unsigned int ans = binary_search(A,k,n);
  printf("%d\n",ans);

  return 0;
}
