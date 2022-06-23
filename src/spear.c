#include <stdio.h>

int n;
int k;
int A[100000];

int canGetSpear(int x){
    int spear_sum = 0;
    for(int i=0; i<n; i++){
        spear_sum += A[i]/x;
    }
    if(spear_sum>=k) return 1;
    else return 0;
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

    lb = 0;
    ub = 1000000000+1;

    // lb:canGetSpear==1, ub:canGetSpear==0
    while(ub-lb>1){
        int mid = (lb+ub)/2;
        if(canGetSpear(mid)==1){
            lb = mid;
        }
        else{
            ub = mid;
        }
    }
    printf("%d\n", lb);


  return 0;
}
