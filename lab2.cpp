#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char plaintext[100];
char ciphertext[100];
int length;
int key;
 cout<<"enter the plain message\n\n";
 cin.getline(plaintext,99,'\n');
cout<<"enter the key :";
cin>>key;
cout<<"----------\n";
cout<<"the cipher message\n\n";
length=strlen(plaintext);
int i = 0;
for(i=0;i<length;i++)
{
if(plaintext[i]==' ')
{
 ciphertext[i]=' ';
 cout<<ciphertext[i];
 continue;
}
 int y=(int)plaintext[i];
 if (y>96)
{
 y=y-32;
 plaintext[i]=(char)y;
}
int x =((((int)plaintext[i]-65)+key)%26)+65;
ciphertext[i]=(char)x;
cout<<ciphertext[i];
}
cout<<"\n\n";
return(0);
}

