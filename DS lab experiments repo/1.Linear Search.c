//Linear search
#include <stdio.h>
int main() {
    int size, i, element;
    int arr[100];

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter %d elements:\n", size);
    for(i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &element);

    for(i = 0; i < size; i++) {
        if(arr[i] == element) {
            printf("Element found at position %d\n", i + 1);
            return 0;
        }
    }

    printf("Element not found in the array.\n");

    return 0;
}