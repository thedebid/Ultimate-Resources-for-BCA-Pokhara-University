/*Program to generate fibonacci series upto some limit*/
#include<stdio.h>
main( )
{
	int F1=0, F2=1, F3, limit;
	printf( " Series up to: " );
	scanf( "%d", &limit );
	if( limit >= 2 )
	{
		printf( "Fibonacci series is:\n" );
		printf( "%d, %d ", F1, F2 );
		F3 = F1 + F2;
		while( F3 <= limit )
		{
			printf( ", %d", F3 );
			F1 = F2;
			F2 = F3;
			F3 = F1 + F2;
		}/* End of while */
	}/* End of if */
}/* End of main( ) */
