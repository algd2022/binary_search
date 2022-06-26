#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i;
  int a;
  int count = 1;
  int sum = 0;
  for(i = 0; i < n ; i ++){
    a = A[i];
    if(A[i] > m){
      return 0;
    }
    if(sum + A[i] > m){
     sum = 0;
     count = count + 1;
    }
    sum = sum + A[i];
  }
  return count <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1e9;

  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(p(mid)){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }

  printf("%d\n", ub);

  return 0;
}
