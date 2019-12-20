#include <iostream> //console io
#include <string.h> //string handling
#include <algorithm> //transform
using namespace std;
struct to_upper {
int operator() (int ch)
{
return toupper(ch);
}
};
void encrypt_vigenere(const string& plaintext, const string& key, string& ciphertext){
int i, j, ch;
for(i = 0, j = 0; i < plaintext.length(); ++i, j++) {
if(j >= key.length())
j = 0;
if(plaintext[i] >= 'A' && plaintext[i] <= 'Z')
ch = ((plaintext[i] - 'A') + (key[j] - 'A')) % 26;
else
ch = plaintext[i] - 'A'; //only encrypt A-Z
ciphertext.append(string(1, (char)(ch + 'A')));
}
}
void decrypt_vigenere(const string& ciphertext, const string& key, string& plaintext){
int i, j, ch;
for(i = 0, j = 0; i < ciphertext.length(); ++i, j++) {
if(j >= key.length())
j = 0;
if(ciphertext[i] >= 'A' && ciphertext[i] <= 'Z')
ch = ((ciphertext[i] - 'A') + 26 - (key[j] - 'A')) % 26;
else
ch = ciphertext[i] - 'A'; //only decrypt A-Z
plaintext.append(string(1, (char)(ch + 'A')));
}
}
int main(int argc, char* argv[])
{
cout << "Enter plaintext to encrypt:\n";
char plaintext[256] = {0};
char key[256] = {0};
cin.getline (plaintext,256);
cout << "Text to encrypt: " << plaintext << endl;
cin.clear(); //clears any cin errors
cout << "Enter key (can be any string):";
cin.getline (key, 256);
//uppercase KEY
transform(key, key+strlen(key), key, to_upper());
cout << "key chosen: " << key << endl;
string cipher;
//uppercase plaintext
transform(plaintext, plaintext+strlen(plaintext), plaintext, to_upper());
encrypt_vigenere(plaintext, key, cipher);
string decrypted;
decrypt_vigenere(cipher, key, decrypted);
cout << "Vigenere encrypted text: " << cipher << "\n decrypted: " << decrypted << endl;
return 0;
}
