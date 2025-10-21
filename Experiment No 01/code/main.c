#include <stdio.h>

void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertElement(int arr[], int size, int element, int position) {
    if (size >= 100) {
        printf("Array is full. Insertion failed.\n");
        return size;
    }
    
    if (position < 1 || position > size + 1) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", size + 1);
        return size;
    }

    int index = position - 1;

    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;
    printf("Successfully inserted %d at position %d.\n", element, position);

    return size + 1;
}

int deleteElement(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty. Deletion failed.\n");
        return size;
    }

    if (position < 1 || position > size) {
        printf("Invalid position. Please enter a position between 1 and %d.\n", size);
        return size;
    }

 
    int index = position - 1;
    int deletedElement = arr[index];

   
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    printf("Successfully deleted %d from position %d.\n", deletedElement, position);

    
    return size - 1;
}


int main() {
    int arr[100] = {10, 20, 30, 40, 50}; 
    int size = 5; 
    int choice, element, position;

    printf("Initial Array:\n");
    displayArray(arr, size);
    printf("--------------------------\n");

    while (1) {
        printf("\n---MENU---\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position (1 to %d): ", size + 1);
                scanf("%d", &position);
                size = insertElement(arr, size, element, position);
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter the position to delete (1 to %d): ", size);
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                displayArray(arr, size);
                break;
            case 3:
                displayArray(arr, size);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
