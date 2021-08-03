/* Program to find out the path matrix by powers of adjacency matrix */
#include<stdio.h>
#define MAX 20

int n;
main()
{

	int w_adj[MAX][MAX],adj[MAX][MAX],adjp[MAX][MAX];
	int x[MAX][MAX],path[20][20],i,j,p;

	printf("Input number of vertices : ");
	scanf("%d",&n);

	printf("Enter the weighted adjacent matrix :\n");
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
		scanf("%d",&w_adj[i][j]);
	printf("The weighted adjacency matrix is :\n");
	display(w_adj);

	/* Converts weighted adjacency matrix to boolean matrix */
	to_boolean(w_adj,adj);

	printf("The boolean adjacency matrix is :\n");
	display(adj);

	while(1)
	{
		printf("Enter the path length to be searched (0 to quit) : ");
		scanf("%d",&p);
		if(p==0)
			break;
		/* Matrix adjp is equal to adj raised to power p */
		pow_matrix(adj,p,adjp);
		printf("The path matrix for lengths equal to %d is : \n",p);
		display(adjp);
	}/*End of while */

	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		x[i][j]=0;
	/*All the powers of adj will be added to matrix x */
	for(p=1;p<=n;p++)
	{
		pow_matrix(adj,p,adjp);
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			x[i][j]=x[i][j]+adjp[i][j];
	}

	printf("The matrix x is :\n");
	display(x);

	to_boolean(x,path);

	printf("The path matrix is :\n");
	display(path);
}/*End of main() */

/*This function computes the pth power of matrix adj and stores result in adjp */
pow_matrix(int adj[MAX][MAX],int p,int adjp[MAX][MAX] )
{

	int i,j,k,tmp[MAX][MAX];

	/*Initially adjp is equal to adj */
	for(i=0;i<n;i++)
	  for(j=0;j<n;j++)
	   adjp[i][j]=adj[i][j];

	for(k=1;k<p;k++)
	{
		/*Multiply adjp with adj and store result in tmp */
		multiply(adjp,adj,tmp);

		for(i=0;i<n;i++)
		  for(j=0;j<n;j++)
		     adjp[i][j]=tmp[i][j]; /* New adjp is equal to tmp */
	}
}/*End of pow_matrix()*/

/*This function multiplies mat1 and mat2 and stores the result in mat3 */
multiply(int mat1[MAX][MAX],int mat2[MAX][MAX],int mat3[MAX][MAX])
{
     int i,j,k;

	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	   {
		mat3[i][j]=0;
		for(k=0;k<n;k++)
		   mat3[i][j] = mat3[i][j]+ mat1[i][k] * mat2[k][j];
	   }
}/*End of multiply()*/

/*This fn converts matrix mat into boolean matrix and stores result in boolmat */
to_boolean( int mat[MAX][MAX], int boolmat[MAX][MAX] )
{
	int i,j;
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	   if (mat[i][j] == 0 )
		boolmat[i][j]=0;
	   else
		boolmat[i][j]=1;
}/*End of to_boolean()*/

display(int matrix[MAX][MAX])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",matrix[i][j]);
		printf("\n");
	}
}/*End of display()*/
