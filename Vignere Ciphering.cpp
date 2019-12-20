#include<iostream>
#include<string.h>

#define MAX 50
using namespace std;
int h=0,y=1;
char g[MAX];
void hill(char []);
int main()
{
char m[MAX],l[3];
for(int i=0;i<MAX;i++)
{
m[i]=NULL;
g[i]=NULL;
}
cout<<"Enter the message: ";
cin>>m;
for(int i=0;i<MAX;i++)
{
if(m[i]==NULL)
h=0;
else
y++;
}
y=y/3;
for(int i=0;i<y;i++)
{
l[0]=m[h];
l[1]=m[h+1];
l[2]=m[h+2];
hill(l);
}
cout<<"----------------------------------------------------------------------\n";
cout<<"The Plain Text is: ";
for(int i=0;i<MAX;i++)
cout<<m[i];
cout<<"\nThe Cipher Text is: ";
for(int i=0;i<MAX;i++)
cout<<g[i];
cout<<"\n----------------------------------------------------------------------\n";
return 0;
}
void hill(char m[])
{
int key[3][3]={{6,24,1},{13,16,10},{20,17,15}},keyt[3][3],det[3][3],mod26[3][3],c[3];
char s[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int i,j,k=0;
cout<<"The Plain Text Matrix is: ";
for(i=0;i<3;i++)
{
for(j=0;j<25;j++)
{
if(m[i]==s[j])
{
c[k]=j;
cout<<c[k]<<"\n\t\t\t ";
k++;
break;
}
}
}
k--;
int o[3][1],p=0,temp=0;
cout<<"\nThe Key is: ";
for(i=0;i<3;i++)
{p=0;
temp=0;
for(j=0;j<3;j++)
{ temp+=key[i][p]*c[j];
p++;
cout<<key[i][j]<<"\t";
}
o[i][0]=temp;
cout<<"\n\t ";
}
//for(int z=0;z<3;z++)
//cout<<o[z][0]<<endl;
cout<<"\nThe Encrypted Matrix is: ";
for(int z=0;z<3;z++)
{
o[z][0]=o[z][0]%26;
cout<<o[z][0]<<"\n\t\t\t ";
}
cout<<"\nThe Encrypted Message is: ";
for(i=0;i<3;i++)
{
for(j=0;j<26;j++)
{
if(o[i][0]==j)
{cout<<s[j];
g[h]=s[j];
h++;}
}
}
cout<<"\n";
//cout<<"The transpose is: "<<endl;
for(int i=0;i<3;i++)
{
// cout<<"\n";
for(int j=0;j<3;j++)
{
keyt[i][j]=key[j][i];
// cout<<keyt[i][j]<<"\t";
}
}
p=0;
int q=0;
int r=1,temp1,temp2;
cout<<"\nThe Inverse of the Key is: ";
det[0][0]=(keyt[1][1]*keyt[2][2])-(keyt[1][2]*keyt[2][1]);
det[0][1]=(keyt[1][0]*keyt[2][2])-(keyt[1][2]*keyt[2][0]);
det[0][2]=(keyt[1][0]*keyt[2][1])-(keyt[1][1]*keyt[2][0]);
det[1][0]=(keyt[0][1]*keyt[2][2])-(keyt[0][2]*keyt[2][1]);
det[1][1]=(keyt[0][0]*keyt[2][2])-(keyt[0][2]*keyt[2][0]);
det[1][2]=(keyt[0][0]*keyt[2][1])-(keyt[0][1]*keyt[2][0]);
det[2][0]=(keyt[0][1]*keyt[1][2])-(keyt[0][2]*keyt[1][1]);
det[2][1]=(keyt[0][0]*keyt[1][2])-(keyt[0][2]*keyt[1][0]);
det[2][2]=(keyt[0][0]*keyt[1][1])-(keyt[0][1]*keyt[1][0]);
int f=0;
for(int i=0;i<3;i++)
{//cout<<"\n";
for(int j=0;j<3;j++)
{ if(f==0)
{ det[i][j]=det[i][j];
f=1;
}
else
{
det[i][j]=-det[i][j];
f=0;
}
// cout<<det[i][j]<<"\t";
}
}
//cout<<"The mod 26 matrix is: ";
int m23=0;
for(int i=0;i<3;i++)
{
for(int j=0;j<3;j++)
{
if(det[i][j]<0)
{int temp3=-det[i][j];
while(m23<temp3)
m23=m23+26;
m23=m23-26;
mod26[i][j]=temp3-m23;
m23=0;
}
else
{while (m23<det[i][j])
m23=m23+26;
mod26[i][j]=m23-det[i][j];
m23=0;
}
cout<<mod26[i][j]<<"\t";
}
cout<<"\n\t\t\t ";
}
int o1[3][1];
for (i=0;i<3;i++)
{ p=0;
//cout<<"\n";
int temp22=0;
for(j=0;j<3;j++)
{ temp22+=mod26[i][p]*o[j][0];
p++;
}
o1[i][0]=temp22;
// cout<<o1[i][0]<<"\t";
}
cout<<"\nThe Decrypted Matrix is: ";
for(int z=0;z<3;z++)
{
o1[z][0]=o1[z][0]%26;
cout<<o1[z][0]<<"\n\t\t\t ";
}
cout<<"\nThe Decrypted Message is: ";
for(i=0;i<3;i++)
{
for(j=0;j<26;j++)
{
if(o1[i][0]==j)
cout<<s[j];
}
}
cout<<"\n";
}
