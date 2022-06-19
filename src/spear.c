#include <stdio.h>

int n;
int k;
int A[100000];

int is_get_spear(int length_of_spear) {
    int number_of_spear_can_be_made = 0;
    for (int i = 0; i < n; i++) {
        number_of_spear_can_be_made += A[i] / length_of_spear;
    }
    
    return number_of_spear_can_be_made >= k;
}

int main() {

    int max_length_of_spear = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if(A[i] > max_length_of_spear) {
            max_length_of_spear = A[i];
        }
    }

    int ok = 0;
    int ng = max_length_of_spear + 1;

    while(ng - ok > 1) {
        int mid = (ng + ok) / 2;
        if(is_get_spear(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    printf("%d\n", ok);
    return 0;
}
