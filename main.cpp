#include <iostream>
#include <string>
using namespace std;
    string encryptVigenere(const string& plaintext, const string& keyword) {
    string ciphertext;
    int keywordLength = keyword.length();
    int plaintextLength = plaintext.length();

    for (int i = 0; i < plaintextLength; ++i) {
        char plainChar = plaintext[i];
        char keywordChar = keyword[i % keywordLength]; // повторяем ключевое слово

        // Преобразование символов в верхний регистр
        plainChar = toupper(plainChar);
        keywordChar = toupper(keywordChar);

        if (isalpha(plainChar)) {
            // Приводим символы к значениям от 0 до 25 (A=0, B=1, и т.д.)
            plainChar -= 'A';
            keywordChar -= 'A';

            // Шифрование символа
            char encryptedChar = (plainChar + keywordChar) % 26;

            // Преобразование обратно в символы ASCII
            encryptedChar += 'A';

            ciphertext += encryptedChar;
        } else {
            // Если символ не является буквой, просто добавляем его к зашифрованному тексту без изменений
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext;
    string keyword;

    cout << "Введите текст для шифрования: ";
    getline(cin, plaintext);

    cout << "Введите ключевое слово: ";
    getline(cin, keyword);

    string ciphertext = encryptVigenere(plaintext, keyword);

    cout << "Зашифрованный текст: " << ciphertext << std::endl;

    return 0;
}
