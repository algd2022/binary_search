#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int time = 0;
  for(int i = 0; i<k;i++){
    int work_sum = 0;
    while(time < n && work_sum + A[time] <= m){
      work_sum += A[time++];
    }
  }
  return time == n;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  lb = 0;
  ub = 1000000000;
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(p(mid))ub = mid;
    else lb = mid;
  }
  printf("%d\n",ub);
  return 0;

}
