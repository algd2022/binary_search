#include <stdio.h>

int n;
int k;
int A[100000];


int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  int min,max,mid;
  min=-1;
  max=n;
  while(max-min>1){ //bsearch
    mid=(min+max)/2;
    if(A[mid]>=k){
      max=mid;
    } else {
      min=mid;
    }
  }
  printf("%d\n",max);
  return 0;
}
