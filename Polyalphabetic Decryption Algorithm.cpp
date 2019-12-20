#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char plaintext[100];
char ciphertext[100];
int length;
int key=7;
int m=key;
cout<<"enter the cipher message\n\n";
cin.getline(ciphertext,99,'\n');
cout<<"----------\n";
cout<<"the plain message\n\n";
length=strlen(ciphertext);
int i = 0;
for(i=0;i<length;i++)
{
if(ciphertext[i]==' ')
{
plaintext[i]=' ';
cout<<plaintext[i];
continue;
}
int y=(int)ciphertext[i];
if (y>96)
{
	y=y-32;
ciphertext[i]=(char)y;
}
int x = ((((int)ciphertext[i]-65)-(key=key+1))%26 );
x=(x<0)?(x+26):x;
plaintext[i]=(char)x + 65;
cout<<plaintext[i];
}
cout<<"\n\n";
return(0);
}
