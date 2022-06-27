#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int binary_search(int A[], int k,int n){
  int lb = 0;
  int ub = 1000;
  if(n%k==0){
    ub=ub*n/k;
  }
  else{
    ub=ub*(n/k+1);
  }
  int i,j,rem;
  int x;
  while(ub - lb > 1){
    x=0;
    int mid = (lb + ub) / 2;
    rem=mid;
    j=1;
    for(i=0; i<n;i++){
      if(rem>=A[i]){
        rem=rem-A[i];
      }
      else if(mid<A[i]){ 
        j=j+k;
        break;
      }
      else{
        rem=mid-A[i];
        j=j+1;
      }
    }
    if(j > k) {
      lb = mid;
    }
    else {
      ub = mid;
    }
  }
  return ub;
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
