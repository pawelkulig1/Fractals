/*
	Pawel Kulig 2015
*/

#include <stdio.h>
#include "gfx.h"
#include "rotation.h"

#define PI 3.14159265

int text_length = 0; //length of given text
int word_length = 6; // 6 OR 8
int iter_count = 0; //number of iteration

// ------------------------------------PLANE CALCULATIONS
//

void draw_plane_square(int plane[][word_length*iter_count]);
/*
	rotates plane 4 times to make symetric fractal and
	draws plane with gfx library int proper position then shows result on screen
	
*/

void display_plane(int plane[][word_length*iter_count]);
/*
	Display plane in the terminal avoid using with big arrays because it may
	take a while 
*/
void initialize_plane(int plane[][word_length*iter_count], int *converted_numbers); 
/*
	initilialize plane with 0 in middle and all borders are set to numbers from 
	array with numbers. Numbers are rotated every second 6 or 8 rows and columns
*/

void adding_inside_plane(int plane[][word_length*iter_count]); 
/*
Goes through all array fields and adds values to new one
	1 1  ===\  1 1
	1	 ===/  1 2
*/


//
// ------------------------------------PLANE CALCULATIONS


void reduce(int *tab, int x); // x is 6 OR 8 // reduce number of ints to 6 or 8


// ------------------------------------DRAWING
//

void draw_pixel(int x, int y, int R, int G, int B); 
/*
	draws pixel in x, y cords an witch given R, G, B color variables
*/
void show_drawing(); //shows drawing on display and waits

//
// ------------------------------------DRAWING

// ------------------------------------CONVERSIONS
//

int length(char *tab); 
/*
	gets generate new line character on the end of line so the function delete
	this sign, moves '\0' one point earlier and return length of array
*/

void char_tab_int_tab(char *text, int *tab); 
/* 	| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
	| a | b | c | d | e | f | g | h | i |
	| j | k | l | m | n | o | p | r | s |
	| t | u | w | y | z |
	   
	converting char array in int array with algorythm shown above
*/
	   

int char_to_int(char c); // converts single char to int
void match_colors(int number, int *RGB); 
/*
	get number and return RGB array witch predefined color this function may be
	changed to create more colorfull fractals
*/

//
// ------------------------------------CONVERSIONS


void square(); //draws square
void triangle();


int main()
{
	square();
	return 0;
}


void square()
{
	char text[100];
	printf("Prosze podac ciag znakow: ");
	fgets(text, sizeof(text), stdin);

	printf("Prosze podac liczbe (6 lub 8): ");
	scanf("%i", &word_length);
	
	printf("Prosze podac ilosc iteracji: ");
	scanf("%i", &iter_count);
	


	text_length = length(text);
	int int_text[text_length];
	
	char_tab_int_tab(text, int_text);
	reduce(int_text, word_length); 
	
	int converted_numbers[word_length];
	
	int i=0;
	
	for(i=0; i<word_length;i++)
	{
		converted_numbers[i] = int_text[i];
		printf("%d ", converted_numbers[i]);
	}
	printf("\n");
	
	int plane_size = word_length*iter_count;
	
	printf("Plane size: %d x %d \n", plane_size, plane_size);
	
	int plane_for_addition[plane_size][plane_size];
	initialize_plane(plane_for_addition, converted_numbers);
	
	adding_inside_plane(plane_for_addition);
	
	draw_plane_square(plane_for_addition);
}

void triangle()
{
	int tab[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15, 16};
	gfx_open(1200,900 ,"Fractal graphic test");
	
	int x = 40;
	int y = 0;
	
	draw_pixel(100,100, 100,100,100);
	draw_pixel(x+100, -y+100, 255, 255, 255);
	int i=0;
	for(i=0;i<180;i++)
	{
		rotate_pixel(&x, &y,0,0, i);
		draw_pixel(x+100, -y+100, 200, 200, 200);
	}
	//printf("%d, %d\n", x, y);
	//show_drawing();
	

	


	double a =30;
	double B = 90-a;
	//int i=0;
	int j=0;
	//int x=0;
	//int y=0;
	
	x=0;
	y=0;
	int x_r=0;
	int y_r=0;
	int plane_size=4;
	
	//int tab[4][4] = {0,1,2,3,4,5,6,7,8, 9, 10, 11, 12, 13, 14, 15};
	
	if(a==90)
	{	//printf("1\n");
		
		//square()
		
	}	
	
	
	else
	{
		//rotate_square_array_right(plane_size, tab);
		int RGB[3] ={255,255,255};
		a = 2*tan((B)*PI/180); //if we get 30* here we should divide by 2 to make peace 15*
		//printf("%f\n", a);
		for(i=0;i<plane_size;i++)
		{
			printf("\n");
			for(j=0;j<plane_size;j++)
			{
				//printf("%d, %d, %d", i, j, tab[i][j]);
				if(a*(plane_size - 1 -i)<=(plane_size - 1 - j))
				{
					/*x=300+plane_size - 1- i;
					y= 300 +plane_size - 1 - j;
					x_r=x;
					y_r=-y;
					
					//rotate_pixel(&x, &y, 30);
					//match_colors(tab[plane_size - 1- i][plane_size - 1 - j], RGB); 
					
					
					draw_pixel(x, y, RGB[0], RGB[1], RGB[2]);
					rotate_pixel(&x_r, &y_r,-175,650, 30);
					draw_pixel(x_r, y_r, RGB[0], RGB[1], RGB[2]);
					x+=2*i;
					x_r=x;
					y_r=-y;
					draw_pixel(x, y, RGB[0], RGB[1], RGB[2]);
					rotate_pixel(&x_r, &y_r, -175,650, 30);
					draw_pixel(x_r, y_r, RGB[0], RGB[1], RGB[2]);
					*/
					
					
					
					printf("x: %d, y:  %d, %d\n",plane_size - 1- i ,plane_size - 1 - j , tab[plane_size - 1- i][plane_size - 1 - j]); 
				}
			}
		}
	}
	show_drawing();
}

void draw_plane_square(int plane[][word_length*iter_count])
{
	gfx_open(1200,900 ,"Fractal graphic test");
	int i=0; //iterator
	int j=0; //iterator
	int RGB[3] = {}; //colors RGB
	int ratio = 4; // how many times is bigger 1 pixel 4 means 4x4 = 16
	for(i=0;i<3;i++)
	{
		printf("%d ", ratio);
		if((word_length*iter_count*ratio*2) > 900)
			ratio--;
		else break;
	}
	
	int z=0; //iterator to draw scaled pixels
	int x_pocz=1200/2, y_pocz=900/2; //center of the screen
	int k = 0; // iterator to rotate array and draw it in another place
	
	for(k=0;k<4;k++)
	{
		for(i=0;i<word_length*iter_count;i++)
		{
			for(j=0;j<word_length*iter_count;j++)
			{
				match_colors(plane[i][j], RGB);
			
				for(z=0;z<ratio;z++)
				{
					draw_pixel(x_pocz + z+(i*ratio), y_pocz + j*ratio,  RGB[0], RGB[1], RGB[2]);
					draw_pixel(x_pocz + z+(i*ratio), y_pocz + j*ratio+1,  RGB[0], RGB[1], RGB[2]);
					draw_pixel(x_pocz + z+(i*ratio), y_pocz + j*ratio+2,  RGB[0], RGB[1], RGB[2]);
					draw_pixel(x_pocz + z+(i*ratio), y_pocz + j*ratio+3,  RGB[0], RGB[1], RGB[2]);
				}
			}
		}
	
		rotate_square_array_right(word_length*iter_count, plane);
	
		switch(k) //set drawing position after rotating array
		{
			case 0:
			{
				x_pocz -= (word_length*iter_count*ratio);
				break;
			}
			
			case 1:
			{
				y_pocz -= (word_length*iter_count*ratio);
				break;
			}
			
			case 2:
			{
				x_pocz += (word_length*iter_count*ratio);
				break;
			}
		}
	}
	show_drawing();
}


void adding_inside_plane(int plane[][word_length*iter_count])
{
	int x=1;
	int y=1;
	int i=1; //we should leave [0] row and [0] column
	int j=1;
	while(1)
	{
		i=x;
		j=y;
		while(1)
		{
			plane[i][j] = add(plane[i-1][j], plane[i][j-1]);
			
			if(i==1 || j == (word_length*iter_count)-1) break;
			i--;
			j++;
		}
		
		if(!(x==((word_length*iter_count)-1)))
			x++;
		else
			y++;

		if((y==((word_length*iter_count)-1)))
			break;
	}
	
	plane[(word_length*iter_count)-1][(word_length*iter_count)-1] = add(plane[(word_length*iter_count)-2][(word_length*iter_count)-1], plane[(word_length*iter_count)-1][(word_length*iter_count)-2]);
	/* Last array field must be calculated manually because algorithm avoid 
	doing that, fix needed!
	*/
}


void initialize_plane(int plane[][word_length*iter_count], int *converted_numbers)
{
	int i=0, j=0;
	for(i=0;i<word_length*iter_count;i++)
	{
		for(j=0; j<word_length*iter_count;j++)
		{
			plane[i][j] = 0;
		}
		//printf("\n");
	}
	
	int iter_2 = iter_count/2;
	if(iter_count%2 == 1) iter_2 +=1;
	//printf("iter_2: %d \n", iter_2);
	
	for(i=0; i<word_length; i++) //write 8 or 6 characters
	{
		for(j=0;j<(iter_2);j++) //change position over 6 or 8 signs
		{
			plane[i + (2*j*word_length)][0] = converted_numbers[i]; 
			plane[0][i + (2*j*word_length)] = converted_numbers[i];
			
			if(j==(iter_2-1) && iter_count%2!=0) break; 
			/* if there is no even numbers of iterations last two lines must be
			 avoided in order not to overflow array*/
			
			plane[word_length + i + (2*j*word_length)][0] = converted_numbers[word_length - (i+1)];
			plane[0][word_length + i + (2*j*word_length)] = converted_numbers[word_length - (i+1)];
			
		}
	}
	
	/*
	converted_numbers = array of 6 or 8 numbers from text given
	plane = whole plane of numbers to generate fractals
	word_length = 6 or 8
	iter_count = number of iterations
	
	This is complicated it fills plane borders with numbers alternately every word_length rows and columns
	for world length = 6 and iter_number it goes:
	1 2 3 4 5 6 6 5 4 3 2 1...
	2
	3
	4
	5
	6
	6
	5
	4
	3
	2
	1
	.
	.
	.
	
	*/
}

void display_plane(int plane[][word_length*iter_count])
{
	int i=0, j=0;
	for(i=0;i<word_length*iter_count;i++)
	{
		for(j=0; j<word_length*iter_count;j++)
		{
			printf("%d ", plane[i][j]);
		}
		printf("\n");
	}
}

void char_tab_int_tab(char *text, int *tab)
{
	int i=0;
	for(i;i<text_length;i++)
	{
		tab[i] = char_to_int(text[i]);
	}
}

int length(char *text)
{
	int i=0;
	while(text[i]!='\0')
	{
		i++;
	}
	text[i-1] = '\0';

	text[i] = '0';
	return i-1; 
}

int char_to_int(char c)
{
	/* | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
	   | a | b | c | d | e | f | g | h | i |
	   | j | k | l | m | n | o | p | r | s |
	   | t | u | w | y | z |*/

	if(c == 'a' || c == 'j' || c=='t')
		return 1;
	if(c == 'b' || c == 'k' || c=='u')
		return 2;
	if(c == 'c' || c == 'l' || c=='w')
		return 3;
	if(c == 'd' || c == 'm' || c=='y')
		return 4;
	if(c == 'e' || c == 'n' || c=='z')
		return 5;
	if(c == 'f' || c == 'o')
		return 6;
	if(c == 'g' || c == 'p')
		return 7;
	if(c == 'h' || c == 'r')
		return 8;
	if(c == 'i' || c == 's')
		return 9;

	return 0;
}

void match_colors(int number, int *RGB)
{
	/*
	 51,204,255 - BLUE #1
	 51,102,255 - BLUE #2
	102, 51,255 - BLUE #3
	 51,255,204 - CYAN
	  0,184,245 - BLUE #4
	  0,138,184 - BLUE #5
	 51,255,102 - GREEN #1
	102,255, 51 - GREEN #2
	 61,245,  0 - GREEN #3
	 46,184,  0 - GREEN #4
	*/
	
	switch(number)
	{
		case 0:
		{
			RGB[0] = 51;
			RGB[1] = 204;
			RGB[2] = 255;
			break;
		}
		
		case 1:
		{
			RGB[0] = 51;
			RGB[1] = 102;
			RGB[2] = 255;
			break;
		}
		case 2:
		{
			RGB[0] = 102;
			RGB[1] = 51;
			RGB[2] = 255;
			break;
		}
		case 3:
		{
			RGB[0] = 51;
			RGB[1] = 255;
			RGB[2] = 204;
			break;
		}
		case 4:
		{
			RGB[0] = 0;
			RGB[1] = 184;
			RGB[2] = 245;
			break;
		}
		case 5:
		{
			RGB[0] = 0;
			RGB[1] = 138;
			RGB[2] = 184;
			break;
		}
		case 6:
		{
			RGB[0] = 51;
			RGB[1] = 255;
			RGB[2] = 102;
			break;
		}
		case 7:
		{
			RGB[0] = 102;
			RGB[1] = 255;
			RGB[2] = 51;
			break;
		}
		case 8:
		{
			RGB[0] = 61;
			RGB[1] = 245;
			RGB[2] = 0;
			break;
		}
		case 9:
		{
			RGB[0] = 46;
			RGB[1] = 184;
			RGB[2] = 0;
			break;
		}
	}
	
	/*
	 51,204,255 - BLUE #1
	 51,102,255 - BLUE #2
	102, 51,255 - BLUE #3
	 51,255,204 - CYAN
	  0,184,245 - BLUE #4
	  0,138,184 - BLUE #5
	 51,255,102 - GREEN #1
	102,255, 51 - GREEN #2
	 61,245,  0 - GREEN #3
	 46,184,  0 - GREEN #4
	*/
	
	//RGB[0] = 51 + number*20;
	//RGB[1] = 51 + number*20;
	//RGB[2] = 255 - number*20;
	
	
}

void reduce(int *tab, int x) // x is 6 OR 8
{
	int i=0, j=1;
	for(j=1; (text_length-j)>(x-1); j++)
	{
	
		for(i=0; i<text_length-j;i++)
		{
			//printf("%d, %d => ", tab[i], tab[i+1]); 
			tab[i] = add(tab[i], tab[i+1]);
			//printf("%d \n", tab[i]);
			//i++;
		}
		//printf("--------------------------- \n");
	tab[i] = -1;
	}
}

void draw_pixel(int x, int y, int R, int G, int B)
{
	gfx_color(R,G,B);
	gfx_point(x, y);
}

void show_drawing()
{
	char c;

	while(1) {
		// Wait for the user to press a character.
		c = gfx_wait();

		// Quit if it is the letter q.
		if(c=='q') break;
	}
}

/*
	Pawel Kulig 2015
*/
