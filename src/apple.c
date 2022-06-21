#include <stdio.h>

int n;
int k;
int A[100000];

#define PRINT_DEBUG 0
#if PRINT_DEBUG
  #define PRINT printf
#else
  #define PRINT 1 ? (void) 0: printf
#endif

int p(int x, int k){ //xが持ち帰れる値なら1
  int sum=0;
  PRINT("bags= ");
  for (int i=0;i<n;i++){
    int need_bags = (A[i]%x==0)? A[i]/x : A[i]/x + 1;
    PRINT("%d ",need_bags);
    sum += need_bags;
  }
  PRINT("\n");
  if(sum<=k) return 1;
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  //////edit///////
  lb = 0; // x=0の時絶対に持ち帰れない。(絶対にp(lb)==0。)逆に全員一個しか収穫しなくてバッグがn個ある場合にx=1で十分持ち帰れてしまう。
  ub = 1e9; // x=1e9の時絶対に持ち帰れる。(絶対にp(ub)==1。)逆に全員が1e9個収穫してバックがn個しかない場合x=1e9-1では持ち帰れない。
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    PRINT("lb=%d, mid=%d, ub=%d ", lb, mid, ub);
    if(p(mid,k)==1){
      ub = mid;
    }
    else{
      lb = mid;
    }
  }
  printf("%d\n", ub);
  //////edit end//////
  return 0;
}








/* オリジナル。
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


  return 0;
}
*/
