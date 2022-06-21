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

int p(x, k){ //全員がx時間までの仕事量で全ての仕事をこなし切ったら1。
  int workers_rest = k;
  int worker_sum = 0;
  PRINT("worker_time = ");
  for(int i=0;i<n;i++){
    worker_sum+=A[i];
    if(worker_sum>x){ //過剰労働になったら残機を減らして次に託す。
      PRINT("%d ", worker_sum-A[i]);
      workers_rest--;
      worker_sum = 0;
      i--;
    }
    if(workers_rest==0){ //残機がなくなったら失敗。
      return 0;
    }
  }
  PRINT("%d ", worker_sum);
  return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  ////////edit////////////
  lb = 0; //lb=0で絶対にp(lb)==0となる。逆にlb=1でもn人で仕事量1の仕事n個を処理できるためp(lb)==1となる。
  ub = 1e4*n; //lb=1e4*nで絶対にp(lb)==1となる。逆にlb=(1e4*n)-1でも、1人で仕事量1e4の仕事n個を処理できないp(lb)==0となる。
  while(ub-lb>1){
    int mid = (ub+lb)/2;
    PRINT("lb=%d mid=%d ub=%d ", lb, mid, ub);
    if(p(mid, k)==1){
      ub = mid;
    }
    else{
      lb = mid;
    }
    PRINT("\n");
  }
  printf("%d\n", ub);
  ///////edit end/////////
  return 0;
}
