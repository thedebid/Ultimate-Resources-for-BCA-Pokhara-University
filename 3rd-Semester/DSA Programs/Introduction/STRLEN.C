#include<stdio.h>
main()
{
	char str[25];
	int length;
	printf("Enter the string : ");
	gets(str);
	length=Length(str);
	printf("Length of string is %d\n",length);
}/*End of main()*/

Length(char *str)
{
     int len=0;
     while(*str!='\0')
     {
	len++;
	str++;
     }
     return(len);
}/*End of Length()*/