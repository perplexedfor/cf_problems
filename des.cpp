#include <iostream>
#include <bitset>
#include <string>

using namespace std;

// Constants for DES Algorithm
const int INITIAL_PERMUTATION[64] = {
    58, 50, 42, 34, 26, 18, 10, 2,
    60, 52, 44, 36, 28, 20, 12, 4,
    62, 54, 46, 38, 30, 22, 14, 6,
    64, 56, 48, 40, 32, 24, 16, 8,
    57, 49, 41, 33, 25, 17, 9, 1,
    59, 51, 43, 35, 27, 19, 11, 3,
    61, 53, 45, 37, 29, 21, 13, 5,
    63, 55, 47, 39, 31, 23, 15, 7
};

const int FINAL_PERMUTATION[64] = {
    40, 8, 48, 16, 56, 24, 64, 32,
    39, 7, 47, 15, 55, 23, 63, 31,
    38, 6, 46, 14, 54, 22, 62, 30,
    37, 5, 45, 13, 53, 21, 61, 29,
    36, 4, 44, 12, 52, 20, 60, 28,
    35, 3, 43, 11, 51, 19, 59, 27,
    34, 2, 42, 10, 50, 18, 58, 26,
    33, 1, 41, 9, 49, 17, 57, 25
};

// Dummy 64-bit key and data
bitset<64> key(0x133457799BBCDFF1); // Example 64-bit key
bitset<64> plaintext(0x0123456789ABCDEF); // Example 64-bit data

// Function to apply a permutation on a 64-bit input
bitset<64> applyPermutation(const bitset<64>& input, const int* permutation) {
    bitset<64> permuted;
    for (int i = 0; i < 64; i++) {
        permuted[63 - i] = input[64 - permutation[i]];
    }
    return permuted;
}

// Function to simulate the core DES function (substitution, expansion, etc.)
bitset<32> DESFunction(bitset<32> right, bitset<48> roundKey) {
    // Convert the 48-bit roundKey to a 32-bit subset before XOR
    bitset<32> truncatedKey(roundKey.to_ulong() & 0xFFFFFFFF);
    return right ^ truncatedKey;
}

// Key schedule generation (dummy for now)
bitset<48> generateRoundKey(int round) {
    // For simplicity, just return the first 48 bits of the key in this example
    return bitset<48>(key.to_ullong() >> 16);
}

// Function to perform DES encryption on a 64-bit block
bitset<64> encryptBlock(bitset<64> block) {
    block = applyPermutation(block, INITIAL_PERMUTATION);

    // Split block into two halves
    bitset<32> left = bitset<32>((block >> 32).to_ulong());
    bitset<32> right = bitset<32>(block.to_ulong());

    // Perform 16 rounds of encryption
    for (int round = 0; round < 16; ++round) {
        bitset<32> temp = right;
        right = left ^ DESFunction(right, generateRoundKey(round));
        left = temp;
    }

    // Combine left and right halves
    bitset<64> combined((left.to_ullong() << 32) | right.to_ullong());

    // Apply final permutation
    return applyPermutation(combined, FINAL_PERMUTATION);
}

// Function to perform DES decryption on a 64-bit block
bitset<64> decryptBlock(bitset<64> block) {
    block = applyPermutation(block, INITIAL_PERMUTATION);

    // Split block into two halves
    bitset<32> left = bitset<32>((block >> 32).to_ulong());
    bitset<32> right = bitset<32>(block.to_ulong());

    // Perform 16 rounds of decryption (reverse order of keys)
    for (int round = 15; round >= 0; --round) {
        bitset<32> temp = left;
        left = right ^ DESFunction(left, generateRoundKey(round));
        right = temp;
    }

    // Combine left and right halves
    bitset<64> combined((left.to_ullong() << 32) | right.to_ullong());

    // Apply final permutation
    return applyPermutation(combined, FINAL_PERMUTATION);
}

int main() {
    cout << "Plaintext: " << plaintext << endl;

    bitset<64> ciphertext = encryptBlock(plaintext);
    cout << "Ciphertext: " << ciphertext << endl;

    bitset<64> decryptedText = decryptBlock(ciphertext);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}