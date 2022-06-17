#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int s = 0;
  int i = 0;
  for(i = 0; i<n; i++){
    s += (A[i] + m - 1)/m ; /*袋の数は、収穫したリンゴの数を袋に入るリンゴの数で割って切り上げたものである*/
  }
  return s <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
      
    lb = 0;         /*袋に入るリンゴが0の時、入力制約から常にp(A,0)=0*/
    ub = 1e9;/*最悪の場合、n=k,任意のiでA[i]=1e9であるから、xは高々1e9である。*/
      
    while(ub - lb > 1){
      int mid =(lb + ub)/2;

      if(p(mid)){
        ub = mid;
      }

      else{
        lb = mid;
      }
    }
      
    printf("%d\n" , ub);


  return 0;
}
