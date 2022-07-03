#include <stdio.h>

int n;
int k;
int A[100000];

int worktimesum(int A[], int n){
  int i, sum=0;
  for(i=0; i<n; i++) sum+=A[i];
  return sum;
}

int work(int A[], int n, int k, int x){
  int i=0, count=0, timesum=0;
  while(i<n){
    if(A[i] > x) return 0;
    else{
      if(x - timesum >= A[i]){
	timesum+=A[i];
        i++;
      }
      else{
	timesum = 0;
	count++;
      }
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
  ub = worktimesum(A, n);
  while(ub - lb > 1){
    int mid = (lb + ub)/2;
    if(work(A, n, k, mid)){
    ub = mid;
    }
    else{
    lb = mid;
    }
  }

  printf("%u", ub);

  return 0;
}
