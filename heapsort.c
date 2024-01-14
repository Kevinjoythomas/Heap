#include<stdio.h>
#include<stdlib.h>

// Global array to store heap elements
int arr[20] = {20, 10, 50, 60, 100, 200, 500, 7, 2, 1000, 75, 2000, 8000, 1, 300, 275, 90, 350, 10000, 8};

// Function to perform min-heapify operation on a node
void minHeapify(int node, int n) {
    int left = (2 * node) + 1;
    int right = (2 * node) + 2;
    int min = node;

    if (left < n && arr[left] < arr[min]) {
        min = left;
    }
    if (right < n && arr[right] < arr[min]) {
        min = right;
    }

    if (node != min) {
        int temp = arr[min];
        arr[min] = arr[node];
        arr[node] = temp;
        minHeapify(min, n);
    }
    return;
}

// Function to perform max-heapify operation on a node
void maxHeapify(int node, int n) {
    int left = (2 * node) + 1;
    int right = (2 * node) + 2;
    int max = node;

    if (left < n && arr[left] > arr[max]) {
        max = left;
    }
    if (right < n && arr[right] > arr[max]) {
        max = right;
    }

    if (max != node) {
        int temp = arr[max];
        arr[max] = arr[node];
        arr[node] = temp;
        maxHeapify(max, n);
    }
    return;
}

// Function to print the elements of the array
void printTree(int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

// Function to perform heap sort
void heapsort(int n) {
    if (n == 0) {
        return;
    }

    int t = arr[n - 1];
    arr[n - 1] = arr[0];
    arr[0] = t;
    maxHeapify(0, n - 1);
    heapsort(n - 1);
}

int main() {
    int n = 20;
    int lastnl = (n / 2) - 1;

    // Build max heap
    for (int i = lastnl; i >= 0; i--) {
        maxHeapify(i, n);
    }

    // Print original array
    printf("Original array:\n");
    printTree(20);

    // Perform heap sort
    heapsort(20);

    // Print sorted array
    printf("\nSorted array:\n");
    printTree(20);

    return 0;
}
