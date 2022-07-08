#include <stdio.h>
int hanbetsu(int l,int r,int k,int a[],int n){
    int i,j,ans,sum;
    ans = 0;
    for (i=r;i>=l;i--){
        sum = 0;
        if (ans>0){
            break;
        }
        for (j=0;j<n;j++){
            if (a[n-1-j]/i>=1){
                sum += a[n-1-j]/i;
                if (sum>=k){
                    ans = i;
                    break;
                }
            }
            else
                break;
        }
    }
    return ans;
}

int main(){
    int n,k,A[100000],i,j,tmp,ans,sum,T,add;
    scanf("%d %d",&n,&k);
    for (i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    for (i=0; i<n; ++i) {
        for (j=i+1; j<n; ++j) {
            if (A[i] > A[j]) {
                tmp =  A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
    
    T=-1;
    for (i=n-1;i>=0;i--){
        sum = 0;
        if (T<0){
            for (j=n-1;j>=0;j--){
                if (A[j]/A[i]>=1){
                    sum += A[j]/A[i];
                    if (sum>=k){
                        T=i;
                        break;
                    }
                }
                else
                    break;
            }
        }
        else
            break;
    }
    add = 0;
    for (i=0;i<n;i++){
        add += A[i];
    }
    if (add<k){
        ans = 0;
    }
    else if (k==1){
        ans = A[n-1];
    }
    else if (T==-1){
        ans = hanbetsu(1,A[0],k,A,n);
    }
    else {
        ans = hanbetsu(A[T],A[T+1],k,A,n);
    }
    printf("%d",ans);

}