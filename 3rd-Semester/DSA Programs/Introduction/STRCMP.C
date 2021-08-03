#include<stdio.h>
main()
{
	char str1[30],str2[30];
	int s;
	printf("Enter the first string : ");
	gets(str1);

	printf("Enter the second string : ");
	gets(str2);

	s=Compare(str1,str2);

	if(s==0)
		printf("Strings are same\n");
	else
	    if(s>0)
		printf("String 1 is greater than string 2\n");
	    else
		printf("String 2 is greater than string 1\n");
}/*End of main() */

int Compare(char *str1,char *str2)
{
	while(*str1!='\0'|| *str2!='\0')
	{
		if( *str1 == *str2 )
		{
			  str1++;
			  str2++;
		}
		else
			return( *str1 - *str2 );
	}
	return 0;
}/*End of Compare()*/


