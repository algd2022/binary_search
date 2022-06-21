#include <stdio.h>

int n;
int k;
int A[100000];

#define PRINT_DEBUG 0
#if PRINT_DEBUG
  #define PRINT printf
#else
  #define PRINT 1?(void) 0: printf
#endif

int p(int x,int k){ //各木から作れる槍の本数の合計が必要値ｋを満たしていたら1が返る。
  int sum = 0;
  if(x==0) return 1;
  PRINT("makeable_spears= ");
  for (int i=0;i<n;i++){
    int makeable_spears = A[i]/x;
    PRINT("%d ", makeable_spears);
    sum += makeable_spears;
  }
  PRINT("\n");
  if(sum>=k) return 1;
  return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ////////edit///////////
  lb = 0; // lb=0の時絶対にp(lb)==1となる。逆に木の本数が1本、長さが1、必要な本数が1e5だった場合lb=1では満たさない。
  ub = 1e9+1; // lb=1e9+1の時絶対にp(lb)==0となる。逆に全ての木の長さが1e9で、必要な本数が1本だった場合はx=1e9で十分満たしてしまう。
  while(ub-lb>1){
    int mid = (ub+lb)/2;
    PRINT("lb=%d mid=%d ub=%d ", lb, mid, ub);
    if(p(mid, k)==1){
      lb = mid;
    }
    else{
      ub = mid;
    }
  }
  printf("%d\n", lb);
  ///////edit end////////
  return 0;
}