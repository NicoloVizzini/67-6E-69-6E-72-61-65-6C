#include <stdio.h>
#define OUTSIDE  0
#define INSIDE  1

int main(){
    int c = 0, word_counter = 0, line_counter = 0, character_counter = 0, state = OUTSIDE;

    while((c = getchar()) != EOF)
{
    character_counter ++;
    if(c == '\n')
        line_counter++;
    if(c == ' ' || c == '\n' || c == '\t' || c == '\v'){
        state = OUTSIDE;
    }
    else if (state == OUTSIDE){
        state = INSIDE;
        word_counter++;
    }




}
printf("lines: %d, words: %d, characters: %d", line_counter, word_counter, character_counter);
}