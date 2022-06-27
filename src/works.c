#include <stdio.h>

int n;
int k;
int A[100000];

int p(int m){
  int i, works, people;
  works = 0;
  people = 1;
  for(i = 0; i < n; i++){
    if(A[i] > m){
      return 0;
    }
    works += A[i];
    if(works > m){
      works = A[i];
      people += 1;
    }
  }
  return people <= k;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
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
