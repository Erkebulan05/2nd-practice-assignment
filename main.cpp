#include <iostream>
#include <string>

using namespace std;

string vigenere_cipher(string message, string key) {
  int key_index = 0;
  string ciphertext;

  for (char c : message) {
    // Find the corresponding character in the key
    char key_char = key[key_index];

    // Encrypt the character using the key character
    int shift = key_char - 'a';
    char encrypted_char = (c - 'a' + shift) % 26 + 'a';

    // Append the encrypted character to the ciphertext
    ciphertext += encrypted_char;

    // Increment the key index
    key_index++;

    // If the key index is greater than or equal to the length of the key, reset it to 0
    if (key_index >= key.length()) {
      key_index = 0;
    }
  }

  return ciphertext;
}

string vigenere_decrypt(string ciphertext, string key) {
  int key_index = 0;
  string plaintext;

  for (char c : ciphertext) {
    // Find the corresponding character in the key
    char key_char = key[key_index];

    // Decrypt the character using the key character
    int shift = 26 - (key_char - 'a');
    char decrypted_char = (c - 'a' + shift) % 26 + 'a';

    // Append the decrypted character to the plaintext
    plaintext += decrypted_char;

    // Increment the key index
    key_index++;

    // If the key index is greater than or equal to the length of the key, reset it to 0
    if (key_index >= key.length()) {
      key_index = 0;
    }
  }

  return plaintext;
}

int main() {
  string message;
  string key;

  // Input the message and key from the user
  cout << "Enter the message: ";
  getline(cin, message);

  cout << "Enter the key: ";
  getline(cin, key);

  // Encrypt the message
  string ciphertext = vigenere_cipher(message, key);
  cout << "Ciphertext: " << ciphertext << endl;

  // Decrypt the ciphertext
  string plaintext = vigenere_decrypt(ciphertext, key);
  cout << "Plaintext: " << plaintext << endl;

  return 0;
}
