/* Find the factorial of any number */
#include<stdio.h>
main( )
{
	int n,value;
	printf( "Enter the number : ");
	scanf( "%d", &n );
	if ( n < 0 )
		printf( "No factorial of negative number\n");
	else
		if ( n==0 )
			printf( "Factorial of zero is 1\n" );
		else
		{
			value = factorial( n ); /* Function for factorial of number */
			printf( "Factorial of %d = %d\n", n, value );
		}
}/*End of main()*/
factorial( int k )
{
	int fact =1;
	if ( k > 1 )
		fact = k * factorial( k-1 );  /* Recursive function call */
	return ( fact );
}
