#include <stdio.h>

int n;
int k;
int A[100000];

int work(int timelimits, int people){
    int workingtime = 0;
    int humans = 1;
    for(int i = 0; i < n; i++){
        if(A[i] > timelimits)return 0;


        workingtime += A[i];

        if(workingtime > timelimits){
            humans += 1;
            workingtime = A[i];
        }
    }
    if(people >= humans) return 1;
    else return 0;
}

int main(){
  int i;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int lb = 0;
  int ub = 1000000000;
  while (ub - lb > 1){
  int mid = (lb + ub ) / 2;

  if (work(mid,k)) ub = mid ;
  else lb = mid ;
}
    printf("%d", ub);
  return 0;
}
