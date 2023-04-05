#include <stdio.h>
#include <conio.h>
#include <string.h>
void main() {
int i,j,keylen,msglen;
char input[100], key[30],temp[30],quot[100],rem[30],key1[30];
printf("Enter Data: ");
gets(input); //input message
printf("Enter Key: ");
gets(key); //input divisor
keylen=strlen(key); //length of divisor
msglen=strlen(input); //length of original message
strcpy(key1,key);
for (i=0;i<keylen-1;i++) {
input[msglen+i]='0';
}
for (i=0;i<keylen;i++)
temp[i]=input[i];
for (i=0;i<msglen;i++) { //performing binary division
quot[i]=temp[0];
if(quot[i]=='0')
for (j=0;j<keylen;j++)
key[j]='0'; else
for (j=0;j<keylen;j++)
key[j]=key1[j];
for (j=keylen-1;j>0;j--) {
if(temp[j]==key[j])
rem[j-1]='0'; else
rem[j-1]='1';
}
rem[keylen-1]=input[i+keylen];
strcpy(temp,rem);
}
strcpy(rem,temp);
printf("\nQuotient is ");
for (i=0;i<msglen;i++)
printf("%c",quot[i]);
printf("\nRemainder is ");
for (i=0;i<keylen-1;i++)
printf("%c",rem[i]);
printf("\nFinal data is: "); //printing final message after
// appending with checksum
for (i=0;i<msglen;i++)
printf("%c",input[i]);
for (i=0;i<keylen-1;i++)
printf("%c",rem[i]);
char temp1[20];
printf("\n\nEnter received data: "); //input received data
scanf("%s",temp1);
for (i=0;i<keylen;i++)
temp[i]=temp1[i];
for (i=0;i<msglen;i++) //division with same divisor
{
quot[i]=temp[0]; //to check remainder is 0 or not
if(quot[i]=='0')
for (j=0;j<keylen;j++)
key[j]='0'; else
for (j=0;j<keylen;j++)
key[j]=key1[j];
for (j=keylen-1;j>0;j--) {
if(temp[j]==key[j])
rem[j-1]='0'; else
rem[j-1]='1';
}
rem[keylen-1]=temp1[i+keylen];
strcpy(temp,rem);
}
strcpy(rem,temp);
printf("\nQuotient is ");
for (i=0;i<msglen;i++)
printf("%c",quot[i]);
printf("\nRemainder is ");
for (i=0;i<keylen-1;i++)
printf("%c",rem[i]);
int flag=0; //initializing flag=0
for(i=0;i<keylen-1;i++)
{
if(rem[i]=='1') //if remainder contains 1 at any bit
{
flag=1; //flag value changes to 1
break;
}
}
if(flag==0) //the channel did not corrupt the message
{
printf("\nNo Error");
}
else //else the message is corrupted
{
printf("\n Error");
}
}
