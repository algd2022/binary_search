#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
  int s=0;      /*仕事量の総和*/
   int j = 1;    /*A配列をj個に分割する*/
  for( int i=0;i<n;i++){
      if(A[i] > x){        /*A[i]がxより大きいとき、0を返す*/
          return 0;
        }
      else if (s + A[i] <= x){    /*総和とA[i]の和がx以下の時A[i]を総和に追加*/
          s += A[i];
        }
     else {     /*s+A[i]がxより大きいとき、配列を分割する*/
         s = 0;
         s += A[i];
         j++;     
      } 
    }
      return j <= k;
    } 
      
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
   lb = 0 ;    /*0<xより*/
  ub = n*10000+1;  /*1<=A[i]<=10^4より*/
  while(ub - lb>1){
  int mid = (lb + ub) / 2;
  if (p(mid)){
      ub = mid;
    }
    else {
        lb = mid;
    }
  }
  printf("%d\n", ub);
  
  return 0;
}
