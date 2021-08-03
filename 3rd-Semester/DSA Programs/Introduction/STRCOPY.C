#include<stdio.h>
main()
{
	char str1[30],str2[30];
	int i=0;
	printf("Enter the first string : ");
	gets(str1);

	printf("Enter the second string : ");
	gets(str2);

	CopyString(str1,str2);
	printf("Now the first string is same as the second string \n");
	printf("First string is %s \n",str1);
	printf("Second string is %s \n",str2);

}/*End of main() */

CopyString(char *str1,char *str2)
{
	while(*str2!='\0')
	{
	      *str1= *str2;
	      str1++;
	      str2++;
	}
	*str1='\0';
}/*End of CopyString*/