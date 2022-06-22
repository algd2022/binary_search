#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  unsigned int i, totalwork, worker;
  totalwork = 0;
  worker = 1;/*最初の一人目から数え始める*/
  for(i = 1; i <=n; i++){
    if(A[i - 1] > m){
      return 0; /*一つの仕事が多すぎるので最高値をもっと下げる*/
    }
    else if(totalwork + A[i - 1] > m){
      /*printf("m%d\n", m);
      printf("totalwork%d\n", totalwork);*/
      totalwork = A[i - 1];
      worker = worker + 1;  /*合計の一人当たりの仕事が多すぎるので、次の人に仕事を回す*/
      /*printf("worker%d\n", worker);*/
    }
    else{
      totalwork = totalwork + A[i - 1]; /*まだ仕事する*/
    }
  }

  return worker <= k; /*仕事した人がk以下か*/

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
    int mid = (lb + ub) / 2;
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
