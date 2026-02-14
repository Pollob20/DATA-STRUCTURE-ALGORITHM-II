#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int tree[4 * MAX];
int arr[MAX];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;
    int p1 = query(2 * node, start, mid, l, r);
    int p2 = query(2 * node + 1, mid + 1, end, l, r);

    return p1 + p2;
}

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

int main() {
    int n = 8;

    int input[] = {5, 8, 6, 3, 2, 7, 2, 6};
    for (int i = 0; i < n; i++)
        arr[i] = input[i];

    build(1, 0, n - 1);

    printf("Sum of range (2, 5): %d\n", query(1, 0, n - 1, 2, 5));

    update(1, 0, n - 1, 3, 10);

    printf("After update: Sum of range (2, 5): %d\n", query(1, 0, n - 1, 2, 5));

    return 0;
}
