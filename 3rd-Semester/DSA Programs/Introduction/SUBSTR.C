#include<stdio.h>
main()
{
	char string[30];
	int n,s;
	printf("Enter the string : ");
	gets(string);
	printf("Enter the position from where substring starts : ");
	scanf("%d",&s);
	printf("Enter number of characters in the substring : ");
	scanf("%d",&n);
	substr(string,s,n);
	printf("\n");
}/*End of main()*/
substr(char *string, int s,int n)
{
	int i;
	for(i=0;i<s-1;i++)
	{
		string++;
		if(*string=='\0')
		{
			printf("There are less than %d characters in string\n",s);
			exit(1);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%c",*string);
		string++;
	}
}/*End of sustr()*/