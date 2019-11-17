#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char strOriginalIput[100], strPass[35], strENCR[100], outpass[100];
int istrLen = 0;
int iArray[20] =
{
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
};
cout << "\n Enter String(without space) : ";
cin >> strOriginalIput;
istrLen = strlen(strOriginalIput);
strOriginalIput[istrLen + 1] = '\0';
cout << "\n Enter Crypt Pass: ";
cin >> strPass;
int iLen = strlen(strPass);
strPass[iLen + 1] = '\0';
strcpy(outpass, strPass);
outpass[iLen + 1] = '\0';
int cnt = 0;
//cout << strOriginalIput << "\n";
for (int i = 0; i < iLen - 1; i++)
{
for (int j = 0; j < iLen - 1 - i; j++)
if (strPass[j + 1] < strPass[j])
{
/* compare the two neighbors */
char tmp = strPass[j]; /* swap a[j] and a[j+1] */
strPass[j] = strPass[j + 1];
strPass[j + 1] = tmp;
int t = iArray[j];
iArray[j] = iArray[j + 1];
iArray[j + 1] = t;
}
}
cnt = 0;
for (int z = 0; z < iLen; z++)
{
for (int x = 0; x <= iLen; x++)
{
if ((iArray[z] + iLen * x) <= istrLen)
{
strENCR[cnt++] = strOriginalIput[(iArray[z] + iLen * x) - 1];
}
}
}
strENCR[istrLen] = '\0';
//cout << strENCR << "\n\n" ;
/************************************************************************/
/* Out put */
/************************************************************************/
int nl = 1;
for (int i = 0; i < iLen; i++)
cout << outpass[i] << " ";
cout << "\n-------------------------------";
cout << "\n";
for (int i = 0; i < istrLen; i++)
{
if (i == iLen * nl)
{
cout << "\n" << strOriginalIput[i] << " ";
nl++;
}
else
cout << strOriginalIput[i] << " ";
}
cout << "\n\n" << "Encrypted String : " << strENCR;
/************************************************************************/
/* Encryption is over, now going for decryption */
/************************************************************************/
cout << "\n";
char strtmp[100];
cnt = 0;
for (int z = 0; z < iLen; z++)
{
for (int x = 0; x <= iLen; x++)
{
if ((iArray[z] + iLen * x) <= (istrLen))
strtmp[iArray[z] + (iLen * x) - 1] = strENCR[cnt++];
}
}
strtmp[istrLen] = '\0';
cout << "Decrypted String :" << strtmp << "\n\n";
return(0);}
