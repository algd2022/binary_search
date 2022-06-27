#include <stdio.h>

int n;
int k;
int A[100000];

/*仕事量が一番多い人の仕事量をmとしてその時人数k人いないにおさまることを考える*/
int p(int m){
  int i;
  int sum = 0;
  int people = 1;
  for (i = 0; i < n; i++){
    if(A[i] > m)
      return 0;
    if(sum + A[i] > m){
      sum = A[i];
      people = people + 1;
    }
    else{
    sum = sum + A[i];
    }
  }
  return people <=k;
}
int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0; //仕事は1以上
  ub = 1000000000; /*最大で100000時間働き、その中ですべての仕事量が10000であった時の最大の仕事量は1000000000であるため*/
  while(ub - lb > 1) {
    int mid = (lb + ub) / 2;
    if(p(mid)){
      ub = mid;
    }
    else {
      lb = mid;
    }
  }
  printf("%d\n", ub);
  return 0;
}


