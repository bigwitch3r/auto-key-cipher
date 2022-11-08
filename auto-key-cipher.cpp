/*
* Защита информации - Лабораторная работа №1
* Вариант №5 - Шифр с автоключом
*/

#include <iostream>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    string message = "", alphabet = "", primary_key = "", autokey = "";

    cout << "Please, enter the text to encrypt:" << endl;
    cin >> message;

    cout << "Please, enter the alphabet:" << endl;
    cin >> alphabet;

    cout << "Please, enter the key to encrypt the text:" << endl;
    cin >> primary_key;

    // Составление автоключа
    autokey = primary_key + message;
    autokey = autokey.substr(0, autokey.length() - primary_key.length());

    string encrypted_message = "";
    string decrypted_message = "";

    // В этом цикле происходит шифрование
    for (int i = 0; i < message.length(); i++)
    {
        int first = alphabet.find(message.at(i));
        int second = alphabet.find(autokey.at(i));
        int total = (first + second) % ((int)alphabet.length());

        encrypted_message += alphabet.at(total);
    }

    cout << "Autokey is " << autokey << endl;
    cout << "Encrypted message is " << encrypted_message << endl;

    // Начало дешифрования
    string current_key = primary_key;
    
    for (int i = 0; i < encrypted_message.length(); i++)
    {
        int get1 = alphabet.find(encrypted_message.at(i));
        int get2 = alphabet.find(current_key.at(i));
        int total = (get1 - get2) % ((int)alphabet.length());

        total = (total < 0) ? total + alphabet.length() : total;

        decrypted_message += alphabet.at(total);
        current_key += alphabet.at(total);
    }

    cout << "Decrypted message is " << decrypted_message << endl;
}

// АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ
// ABCDEFGHIJKLMNOPQRSTUVWXYZ