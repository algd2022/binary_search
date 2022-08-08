#include <stdio.h>

int n;
int k;
int A[100000];

int spear(int A[], int n, int k, int x){
  int i, count = 0, nokori;
  for(i=0; i<n; i++){
    nokori = A[i];
    while(nokori - x >= 0){
      nokori-=x;
      count++;
    }
  }
  if(count >= k) return 0;
  return 1;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  lb = 0;
  ub = 1000000001;
  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(spear(A, n, k, mid)){
    ub = mid;
    }
    else{
    lb = mid;
    }
  }

  printf("%u", lb);

  return 0;
}
