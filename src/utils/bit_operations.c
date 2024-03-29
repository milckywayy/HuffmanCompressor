#include "bit_operations.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Converts byte(char) to binary string
char *byte_to_binary(unsigned char byte) {
	char* binary;
	
	binary = (char*) malloc(9 * sizeof(char)); // 8 bits + '\0'
	if (binary == NULL) {
		// Memory alloc error
		return NULL;
	}

	for (int i = 7; i >= 0; i--) {
		binary[7 - i] = (byte & (1 << i)) ? '1' : '0';
	}

	binary[8] = '\0';

	return binary;
}

unsigned char binary_to_byte(char *binary) {
    unsigned char byte = 0;

    size_t len = strlen(binary);
    for (size_t i = 0; i < len; i++) {
        if (binary[len - 1 - i] == '1') {
            byte |= (1 << i);
        }
    }
    return byte;
}