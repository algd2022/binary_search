
#include <stdio.h>

int n;
int k;
int A[100000];

int check(int x){
    int tmp=0, count=1;
    for(int t=0;t<n;t++){
        tmp+=A[t];
        if(tmp > x){
            t--;
            tmp=0;
            count++;
        }
        if(count > k)return 0;
    }
    return 1;
}

unsigned int binary_search (int lb, int ub, int k){
    while (ub - lb > 1){
        int mid = (lb + ub ) / 2;
        if (check(mid)) ub = mid ;
        else lb = mid ;
            
}
    return ub ;
}


int main(){
    int i, ub, lb;
    scanf("%d%d", &n, &k);
    for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
    }
    
    
    lb=0;
    ub=1000000000;

    
    int res=0;
    res = binary_search(lb, ub, k);
    printf("%d\n", res);


    return 0;
}
