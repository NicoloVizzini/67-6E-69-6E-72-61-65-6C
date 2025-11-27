#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int check_flags (int argc, char **argv, int *i){
    //printf("inside check flags\n");
    while(*i<argc){ //I read about get ops but if I used it you would make me implement it
        if (strcmp(argv[*i], "-n") == 0) {
            (*i)++; //yes before fixing I did *i++, yes I discovered the precedence of ++
            break;
        }
        else
            return 0;
            
            
        
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    int no_new_line = 0;
    if(argc > 1 && argv[1][0] == '-')
        no_new_line = check_flags(argc,argv, &i);
    //printf("debug i %d\n",i);
    for(i; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    if(!no_new_line)
        printf("\n");

}
