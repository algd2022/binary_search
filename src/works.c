#include <stdio.h>

int n;
int k;
int A[100000];


int p(int x){
  int a = 0;
  int b = 1;
    for(int i=0;i<n;i++){
      if(A[i]>x){
        return 0;
      }
    else if(a+A[i]>x){
      a = A[i];
      b++;
    }
    else{
      a += A[i];
    }
  }
  return b <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000 ;
    while ( ub - lb > 1) {
      int mid = ( lb + ub ) / 2;
        if( p ( mid )){
          ub = mid ;
        }
        else {
          lb = mid ;
        }
   }
printf ("%d\n" , ub );


  return 0;
}
