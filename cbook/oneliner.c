#include <stdio.h>

int main()
{
    int c;
    int space = 0, first_word = 0, first_character = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            putchar(c);
            first_character = 0;
            first_word = 0;
            continue;
        }
        if (c == ' ')
        {
            space = 1;
        }

        else
        {

            if (space == 1)
            {
                if (first_word++)
                    putchar('\n');
                space = 0;
            }
            else if (space == 0 && first_character == 0)
            {
                first_word = 1;
            }

            putchar(c);
        }
    }
}