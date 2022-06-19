#include <stdio.h>

int n;
int k;
int A[100000];

int is_able_to_done_all_works(int work_quantity) {
    int number_of_workers_used = 1;
    int target_worker_work_quantity_left = work_quantity;

    for (int i = 0; i < n; i++) {
        // この方法が使えるのは、「それぞれの人は連続した何時間かを働き」という一文から
        if (A[i] <= target_worker_work_quantity_left) {
            target_worker_work_quantity_left -= A[i];
        } else {
            number_of_workers_used++;
            target_worker_work_quantity_left = work_quantity - A[i];
        }
    }
    return number_of_workers_used <= k;
}

int main() {
    int max_size_of_work_quantity = 0;
    int sum_of_work_quantity = 0;

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        if (A[i] > max_size_of_work_quantity) {
            max_size_of_work_quantity = A[i];
        }
        sum_of_work_quantity += A[i];
    }

    int ng = max_size_of_work_quantity -1;
    int ok = sum_of_work_quantity + 1;

    while ((ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (is_able_to_done_all_works(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }

    printf("%d\n", ok);
    return 0;
}
