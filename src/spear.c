
#include <stdio.h>

int n;
int k;
int A[100000];

unsigned int number_of_spear(int x){
    int res = 0;
    for (int t=0;t<n;t++){
        res+=A[t]/x;
    }
    return  res;
}

unsigned int binary_search (int lb, int ub, int k){
    while (ub - lb > 1){
        int mid = (lb + ub ) / 2;
        if (number_of_spear(mid) >= k) lb = mid ;
        else ub = mid ;
        }
    return lb ; // 少し変更
}


int main(){
    int i, ub, lb;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    }
    
    
    lb=-1;
    ub=1000000001;

    
    int res=0;
    res = binary_search(lb, ub, k);
    printf("%d\n", res);


    return 0;
}
