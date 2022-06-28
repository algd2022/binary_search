#include <stdio.h>

int n;
int k;
int A[100000];

int wr(int x){
  int worker = 1;
  int work = 0;
  for(int i = 0; i < n; i++ ){   
    if(work + A[i] <= x){
      work = work + A[i];  
    }
    else if(A[i] <= x){
      work=A[i];
      worker++;
    }
    else{
      return 0;
    }
  }
  return worker <= k;  
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = -1;
  ub = 1e9;
  while(ub - lb > 1){
    int mid = (lb + ub) / 2;
    if(wr((mid))) ub = mid;
    else lb = mid;
  }

  printf("%d\n", ub);
  return 0;
}
