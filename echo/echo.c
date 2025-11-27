#include <stdlib.h>
#include <stdio.h>
#include <string.h>
enum Flags {flag_n, flag_e};
int check_flags (int argc, char **argv, int *i, int *flags){
    //printf("inside check flags\n");
    while(*i<argc){ //I read about get ops but if I used it you would make me implement it
        if (strcmp(argv[*i], "-n") == 0) {
            (*i)++; //yes before fixing I did *i++, yes I discovered the precedence of ++
            flags[flag_n] = 1;
            break;
        }
        else
            return 0;
            
            
        
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    int flags[2] = {0};
    if(argc > 1 && argv[1][0] == '-')
        check_flags(argc,argv, &i,flags);
    //printf("debug i %d\n",i);
    for(i; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    if(flags[flag_n] == 0)
        printf("\n");

}
