#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Escapes for -e
    \\     backslash
    \a     alert (BEL)
    \b     backspace
    \c     produce no further output
    \e     escape
    \f     form feed
    \n     new line
    \r     carriage return
    \t     horizontal tab
    \v     vertical tab
    \0NNN  byte with octal val
*/

enum Flags {flag_n, flag_e};
int check_flags (int argc, char **argv, int *i, int *flags){
    //printf("inside check flags\n");
    while(*i < argc){ //I read about get ops but if I used it you would make me implement it
        if (strcmp(argv[*i], "-n") == 0) {
            (*i)++; //yes before fixing I did *i++, yes I discovered the precedence of ++
            flags[flag_n] = 1;
            break;
        }
        if (strcmp(argv[*i], "-e") == 0) {
            (*i)++; 
            flags[flag_e] = 1;
            break;
        }
        else
            return 0;
            
            
        
    }
}
void parse_escapes(int argc, char** argv,int i){
    char c;
    while(i < argc){
       // printf("debug i %d",i);
        for(int j = 0; j< strlen(argv[i]);){
            int increment = 1;
            //printf("debug j%d\n",j);
            c = argv[i][j];
            if (c == '\\') {
                if (j + 1 >= strlen(argv[i])){
                    printf("\\");
                    break;
                }
                char escape = argv[i][++j];
                //printf("here before the switch");
                switch(escape){
                    case '\\': 
                    case 'a':   
                        printf("\a");
                        break;
                    case 'b':   
                        printf("\b");
                        break;
                    case 'c':  
                        exit(0);
                    case 'e':   
                        printf("\e");
                        break;
                    case 'f': 
                        printf("\f");
                        break;
                    case 'n':   
                        //printf("ca");
                        printf("\n");
                        break;
                    case 'r':   
                        printf("\r");
                        break;
                    case 't':   
                        printf("\t");
                        break;
                    case 'v':   
                        printf("\v");
                        break;
                    case '0':   {
                        int count = 0;
                        int val = 0;
                        for (count = 0; count < 3 && j+1+count < strlen(argv[i]); count++) {
                            char o = argv[i][j+1+count];
                            if (o >= '0' && o <= '7') {
                                val = val * 8 + (o - '0');
                            } else {
                                break;  
                            }
                        }
                            printf("%c", val);
                            increment += count;  
                            break;
                    }
                    case 'x':  {
                        //printf("here exa");
                        int count = 0;
                        int val = 0;
                    for (count = 0; count < 2 && j+1+count < strlen(argv[i]); count++) {
                            char x = argv[i][j+1+count];

                            if (x >= '0' && x <= '9') {
                                val = val*16 + (x - '0');
                            } 
                            else if (x >= 'a' && x <= 'f') {
                                val = val*16 + (x - 'a' + 10);
                            } 
                            else if (x >= 'A' && x <= 'F') {
                                val = val*16 + (x - 'A' + 10);
                            } 
                            else {
                                break; 
                            }
                        }

                    printf("%c", val);
                    increment += count; 
                    break;
                    }
               
                default:

                    printf("\\%c",argv[i][j]);
           
                }
           
            //printf("here now j is %d",j);
            j += increment;
            //printf("here after increment now j is %d",j);

            }  
            else{
                printf("%c",argv[i][j]); 
                j++;
                
            }
                }   
                i++;
                    }

                        }

int main(int argc, char **argv)
{
    int i = 1;
    int flags[2] = {0};
    if(argc > 1 && argv[1][0] == '-')
        check_flags(argc, argv, &i, flags);
    //printf("debug i %d\n",i);
    if(!flags[flag_e])
        for(i; i < argc; i++) {
            printf("%s", argv[i]);
        }
    else 
        parse_escapes(argc, argv, i);

    if(flags[flag_n] == 0)
        printf("\n");

}
