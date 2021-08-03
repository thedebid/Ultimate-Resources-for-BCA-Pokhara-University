#include<stdio.h>
#include<string.h>
main()
{
	char text[25],pattern[80];
	int position;

	printf("Enter the text : ");
	gets(text);
	printf("Enter the pattern for matching : ");
	scanf("%s",pattern);
	position=pmatch(text,pattern);
	if(position==0)
		printf("%s does not exist in %s \n",pattern,text);
	else
		printf("%s starts at %d\n",pattern,position);
}/*End of main()*/

int pmatch(char text[],char pattern[])
{
	int matched,i,j,k=0;
	if( strlen(pattern) > strlen(text) )
		return 0;
	for(i=0;i<=strlen(text);i++)
	{
		k=0;
		for(j=i;k<strlen(pattern);j++,k++)
		{
			if(pattern[k]!=text[j])
			{
				matched=0;
				break;
			}
			else
				matched=1;
		}/*End of for */
		if(matched==1)
			return(i+1);
	}/*End of for */
	return 0;
}/*End of pmatch() */





