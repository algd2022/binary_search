#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  return (long long int)A[m] >= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = -1;
  ub = n + 1;
  if(A[n-1] < k){
    printf("%d\n",n);
  }else{
    while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(p(mid)){
        ub = mid ;
      }else{
        lb = mid;
      }
    }
    printf("%d\n",ub);
  }


  return 0;
}
