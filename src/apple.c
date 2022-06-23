#include <stdio.h>

int n;
int k;
int A[100000];

int canGetApple(int x){
    int bag_sum = 0;
    for(int i=0; i<n; i++){
        bag_sum += (A[i]+x-1)/x;
    }
    if(bag_sum<=k) return 1;
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

    while(ub-lb>1){
        int mid = (lb+ub)/2;
        if(canGetApple(mid)==1){
            ub = mid;
        }
        else{
            lb = mid;
        }
    }
    printf("%d\n", ub);

  return 0;
}
