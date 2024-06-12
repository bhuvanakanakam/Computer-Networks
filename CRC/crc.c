// Shreeya Saaye Nallaboina
// SE21UCSE202

#include <stdio.h>
#include <string.h>

char data[28];
char check_value[28];
char gen_poly[10];
int data_length, gen_length, i, j; 

void XOR() {
    for (j = 1; j < gen_length; j++) {
        if (check_value[j] == gen_poly[j])
            check_value[j] = '0';
        else
            check_value[j] = '1';
    }
        
}

void crc() {
    for (i = 0; i < gen_length; i++) 
        check_value[i] = data[i];
    do {
        if (check_value[0] == '1')
            XOR();
        for (j = 0; j < gen_length - 1; j++) 
            check_value[j] = check_value[j + 1];
        check_value[j] = data[i++];
    } while (i <= data_length + gen_length - 1); 
}

void receiver() {
    printf("Input: Enter the received data: ");
    scanf("%s", data);

    crc();

    for (i = 0; (i < gen_length - 1) && (check_value[i] != '1'); i++); 

    if (i < gen_length - 1)
        printf("Output: Errors detected\n");
    else
        printf("Output: No errors detected\n");
}

int main() {
    printf("Input: Enter the number of bits in input data: ");
    scanf("%d", &data_length);

    printf("Input: Enter the number of bits in the polynomial generator (divisor): ");
    scanf("%d", &gen_length); 

    printf("Input: Enter the data: ");
    scanf("%s", data);

    printf("Input: Enter the divisor: ");
    scanf("%s", gen_poly);

    data_length = strlen(data);

    for (i = data_length; i < data_length + gen_length - 1; i++) 
        data[i] = '0';

    crc();

    printf("CRC value: %s\n", check_value);

    for (i = data_length; i < data_length + gen_length - 1; i++) 
        data[i] = check_value[i - data_length];

    printf("Transmitted Data: %s\n", data);

    receiver();

    return 0;
}