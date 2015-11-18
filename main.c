#include <stdio.h>
#include "gfx.h"

//#define text_length 11
int text_length = 0;
int word_length = 6; // 6 OR 8
int iter_count = 0;

int length(char *tab); // gives length of string
void char_tab_int_tab(char *text, int *tab); // converts tab of char to tab of int
int char_to_int(char c); // converts csingle char to int
void reduce(int *tab, int x); // x is 6 OR 8 // reduce number of ints to 6 or 8
void draw_pixel(int x, int y, int R, int G, int B); // draws pixel in cords of given colour
void show_drawing(); //shows drawing on display and waits
int add(int x, int y); // adds 2 numbers not allowing them to be bigger than 9

int main()
{
    char text[100];
    
    /*gfx_open(800, 600,"Fractal graphic test");
    draw_pixel(10,10, 100,100,100);
    draw_pixel(100,100, 100,100,100);
    show_drawing();*/

    
    
    printf("Prosze podac ciag znakow: ");
    fgets(text, sizeof(text), stdin);

    printf("Prosze podac liczbe (6 lub 8): ");
    scanf("%i", &word_length);
    
    printf("Prosze podac ilosc iteracji: ");
    scanf("%i", &iter_count);
    
    text_length = length(text);
    int tab[text_length];
    char_tab_int_tab(text, tab); 
    reduce(tab, word_length); 
    
    

    return 0;
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
    //text_length = i-1;
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

int add(int x, int y)
{
    if(x+y>=10) return x+y-10;
    else return x+y;
}
