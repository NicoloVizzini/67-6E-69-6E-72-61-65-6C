#include <stdio.h>

int main()
{
    int c = 0;
    int space = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            space += 1;        
        }
        else 
            space = 0;
        if (space == 0)
            putchar(c);
        if (space == 1)
            putchar('\n');
        
    }
}