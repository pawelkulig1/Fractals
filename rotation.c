#include "rotation.h"

int add(int x, int y)
{
    if(x+y>=10) return x+y-10;
    else return x+y;
}

void rotate_square_array_right(int n, int array[][n])
{
	//MAKES COPY OF ARRAY TO ROTATE

	int temp[n][n];
	int i=0, j=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			temp[i][j] = array[i][j];
		}
	}
	//---------------------------
	
	//printf("%d ", array[0][n-1]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			array[i][j]= temp[j][n-i-1]; //rotates array right
			//array[0][0] = temp[0][n-1];
			
		}
	}
}


void rotate_pixel(int *x, int *y, int x_pocz, int y_pocz, double angle)
{
	double x_2 = *x, y_2 = *y;

	x_2 = ((*x)*cos(angle*(PI/180)) - (*y)*sin(angle*(PI/180)));
	y_2 = ((*x)*sin(angle*(PI/180)) + (*y)*cos(angle*(PI/180)));
	
	x_2 +=x_pocz;
	y_2 +=y_pocz;
	x_2 = round(x_2);
	y_2 = round(y_2);
	
	*x = x_2;
	*y = y_2;
	
}

