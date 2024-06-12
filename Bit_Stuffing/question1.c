#include <stdio.h>
#define MAX_SIZE 100

void bitStuffing(int arr[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        printf("%d", arr[i]);
        
        if (arr[i] == 1)
            count++;
        else
            count = 0;
        
        if (count == 5 && i != N - 1) {
            printf("0"); 
            count = 0;
        }
    }
    printf("\n");
}

int main() {
    char choice;
    printf("SE21UCSE035 - Bit Stuffing Code\n");
    
    do {
        int N;
        printf("Enter the size of the array: ");
        scanf("%d", &N);
        
        int arr[MAX_SIZE];
        printf("Enter the array elements (0s and 1s only, separated by spaces): ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        
        printf("Output: ");
        bitStuffing(arr, N);
        
        printf("Do you want to go again? (y/n): ");
        scanf(" %c", &choice);
        
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}


