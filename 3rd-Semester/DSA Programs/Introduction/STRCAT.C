#include<stdio.h>
main()
{
	char str1[30],str2[30];
	printf("Enter the first string : ");
	gets(str1);
	printf("Enter the second string : ");
	gets(str2);
	Concat(str1,str2);
	printf("Now the first string is %s\n",str1);
}/*End of main()*/
Concat(char *str1, char *str2)
{
	while(*str1!='\0')
		str1++;
	while(*str2!='\0')
	{
		*str1=*str2;
		str1++;
		str2++;
	}
	*str1='\0';
}/*End of Concat()*/