//Binary Search
#include <stdio.h>
int main() {
    int size, i, element;
    int low = 0, high, mid;
    int arr[100];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d sorted elements (ascending order):\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    high = size - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == element) {
            printf("Element found at position %d\n", mid + 1);
            return 0;
        }
        else if(arr[mid] < element) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("Element not found in the array.\n");

    return 0;
} 