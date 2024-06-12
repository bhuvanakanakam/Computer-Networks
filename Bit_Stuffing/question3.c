#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

// Function to perform CRC calculation
void crcGenerator(char data[], char divisor[], int dataBits, int divisorBits, char crc[]) {
    int i, j;
    char temp[MAX_SIZE], quotient[MAX_SIZE], remainder[MAX_SIZE];
    strcpy(temp, data);

    for (i = 0; i < divisorBits - 1; i++) {
        strcat(temp, "0");
    }

    for (i = 0; i < dataBits; i++) {
        quotient[i] = temp[i];
    }

    for (i = 0; i < dataBits; i++) {
        if (quotient[i] == '1') {
            for (j = 0; j < divisorBits; j++) {
                if (quotient[i + j] == divisor[j])
                    quotient[i + j] = '0';
                else
                    quotient[i + j] = '1';
            }
        }
    }

    for (i = 0; i < dataBits; i++) {
        remainder[i] = quotient[i + dataBits];
    }

    strcpy(crc, remainder); // Copy CRC value to the provided string
}

int main() {
    char choice;

    do {
        int dataBits, divisorBits;
        char data[MAX_SIZE], divisor[MAX_SIZE], transmittedData[MAX_SIZE], receivedData[MAX_SIZE], crc[MAX_SIZE];

        printf("Input: Enter the number of bits in input data: ");
        scanf("%d", &dataBits);
        
        printf("Input: Enter the number of bits in the polynomial generator (divisor): ");
        scanf("%d", &divisorBits);

        printf("Input: Enter the data: ");
        scanf("%s", data);

        printf("Input: Enter the divisor: ");
        scanf("%s", divisor);

        crcGenerator(data, divisor, dataBits, divisorBits, crc); // Call crcGenerator function to get CRC value

        printf("CRC value: %s\n", crc);

        printf("Output: Transmitted data: %s", data);
        strcpy(transmittedData, data);
        for (int i = 0; i < strlen(divisor) - 1; i++)
            strcat(transmittedData, "0");
        strcat(transmittedData, crc); // Concatenate CRC value to transmitted data
        printf("%s\n", transmittedData);

        printf("Input: Enter the received data: ");
        scanf("%s", receivedData);

        int error = 0;
        for (int i = 0; i < strlen(receivedData) - divisorBits + 1; i++) {
            if (receivedData[i] == '1') {
                for (int j = 0; j < divisorBits; j++) {
                    if (receivedData[i + j] != divisor[j]) {
                        error = 1;
                        break;
                    }
                }
            }
            if (error == 1)
                break;
        }

        if (error == 0)
            printf("Output: No errors detected\n");
        else
            printf("Output: Errors detected\n");

        printf("Do you want to go again? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any leading whitespace

    } while (choice == 'y' || choice == 'Y');

    return 0;
}


