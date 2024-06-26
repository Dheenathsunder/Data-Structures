#include <stdio.h>

void insertionsort(int arr[], int n) {
    int i, j, curr, temp;
    for (i = 1; i <= n - 1; i++) {
        curr = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > curr) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    insertionsort(arr, n);
    printf("Sorted array is :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
