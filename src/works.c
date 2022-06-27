#include <stdio.h>

int n;
int k;
int A[100000];

int p(int l1,int l2,int l3, int X[]){
    int i1 = 0;
    int i2 = 0;
    int sum = 0;
    while(i2<l1){
        sum += X[i2];
        if(sum + X[i2 + 1] < l3){
            i2++;
        }    
        else if(sum < l3 && sum + A[i2 + 1] > l3){
            sum = 0;
            i1++;
            i2++;
        }
        else return 0;
    }
    return i1 <= l2; 
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int u = 0;
  for(int i = 0;i<n;i++){
      u += A[i];
  }
  lb = 1;
  ub = 1000000000;
  while(ub - lb >1){
    int mid = ( lb + ub ) / 2;
    if(p(n,k,mid,A)) ub = mid;
    else lb = mid;
  }
  printf("%d\n", lb);
  return 0;
}
