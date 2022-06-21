//
//  main.c
//  taco2
//
//  Created by 吉田晃太朗 on 2022/06/21.
//

#include <stdio.h>
unsigned int binary_search(int a[], int x, int n){
    int lb=-1;
    int ub=n;
    
    while(ub - lb > 1){
        int mid = (ub + lb) / 2;
        if(a[mid] >= x) ub = mid;
        else lb = mid;
    }
    return ub;
}
int main(int argc, const char * argv[]) {
    int n,k,i;
    int a[100000];
    
    scanf("%d",&n);
    scanf("%d",&k);
    for(i=0;i<n;i++){
        printf("Input a%d",i);
        scanf("%d",&a[i]);
    }
    
    printf("%d",binary_search(a,k,n));
    
    return 0;
}
