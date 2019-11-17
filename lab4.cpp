#define freq 5 
#include <iostream> 
#include <string.h>
using namespace std; 
int main() { 
char ip[90],c[90]={0},p[90]={0}; 
int i,l;
cout<<"Enter input:";
cin.getline(ip,89,'\n');
l = strlen(ip);
 cout<<"Cipher Text:";
 for(i=0;i<l;i++) {
 	if(ip[i]==' '){
 	
 	c[i]=' ';
 	cout<<c[i];}
 else{
 
 c[i] = ( (ip[i]-97+freq)%26 )+97;
 cout<<c[i];}}
cout<<"\nPlain Text:";
   for(i=0;i<l;i++) {
   	if(c[i]==' '){
   		p[i]=' ';
   		cout<<p[i];
   	}
   
   else if( (c[i]-97-freq) < 0) {
   
   p[i] = c[i]-freq+26;
   cout<<p[i]; }
   else{
   
    p[i] = ((c[i]-97-freq)%26)+97; 
	cout<<p[i]; //getch(); return 1;
	}
}
}
