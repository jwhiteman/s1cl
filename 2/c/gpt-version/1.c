#include <stdio.h>
#include <string.h>

/*
 * COOL THINGS:
 * - const char *
 * - size_t
 * - void functions that take a length & a buffer and write to them
 * - iterating through an array & writing to a double length buffer
 * - iterating through an array & writing to a half length buffer
 * - explicit null termination using '\0'
 * QUESTIONS:
 * - ++i vs i++
 * BAD THINGS (?):
 * - multiple for loops
 * - not dynamic w/ respect to various inputs and keys (?)
*/

// Function to convert a single hex char to a byte
unsigned char hexCharToByte(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return 0; // Not a valid hex char
}

// Function to convert a hex string to a byte array
void hexStringToByteArray(const char *hexStr, unsigned char *byteArray) {
    for (size_t i = 0; i < strlen(hexStr) / 2; ++i) {
        byteArray[i] = hexCharToByte(hexStr[2*i]) << 4 | hexCharToByte(hexStr[2*i + 1]);
    }
}

// Function to XOR two byte arrays
void fixedXOR(const unsigned char *input1, const unsigned char *input2, unsigned char *output, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        output[i] = input1[i] ^ input2[i];
    }
}

// Function to convert a byte array back to a hex string
void byteArrayToHexString(const unsigned char *byteArray, char *hexStr, size_t length) {
    for (size_t i = 0; i < length; ++i) {
        sprintf(&hexStr[i*2], "%02x", byteArray[i]);
    }
}

int main() {
    const char *inputStr1 = "1c0111001f010100061a024b53535009181c";
    const char *inputStr2 = "686974207468652062756c6c277320657965";
    size_t length = strlen(inputStr1) / 2;

    unsigned char input1[length];
    unsigned char input2[length];
    unsigned char output[length];
    char outputStr[length * 2 + 1]; // Each byte becomes two hex characters, plus null terminator

    hexStringToByteArray(inputStr1, input1);
    hexStringToByteArray(inputStr2, input2);

    fixedXOR(input1, input2, output, length);

    byteArrayToHexString(output, outputStr, length);
    outputStr[length * 2] = '\0'; // Ensure null termination

    printf("Result: %s\n", outputStr);

    return 0;
}

