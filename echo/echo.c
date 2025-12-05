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

//enum Flags {flag_n, flag_e}; //This was a one liner 


typedef struct {
    bool e;
    bool n;
} Flags;

int check_flags (int argc, char **argv, int *i, Flags *flags){
    //printf("inside check flags\n");
    while(*i < argc){ //I read about get ops but if I used it you would make me implement it
        if (strcmp(argv[*i], "-n") == 0) {
            (*i)++; //yes before fixing I did *i++, yes I discovered the precedence of ++
            flags -> n = true;
            break;
        }
        if (strcmp(argv[*i], "-e") == 0) {
            (*i)++; 
            flags -> e = true;
            break;
        }
        else
            return 0;
            
            
        
    }
}
void parse_escapes(int argc, char** argv,int i){
    char c;
    const char *p = argv[i];
    while(c = *p++){
            char escape = *p;
            if (c == '\\') {
                if (escape == '\0'){
                    printf("\\");
                    break;
                }
                //printf("here before the switch");
                switch(escape){
                    case '\\':
                        putchar('\\');
                        p++;
                        break;
                    case 'a':   
                        putchar('\a');
                        p++;
                        break;
                    case 'b':   
                        putchar('\b');
                        p++;
                        break;
                    case 'c':  
                        exit(0);
                    case 'e':   
                        putchar('\e');
                        p++;
                        break;
                    case 'f': 
                        putchar('\f');
                        p++;
                        break;
                    case 'n':   
                        putchar('\n');
                        p++;
                        break;
                    case 'r':   
                        putchar('\r');
                        p++;
                        break;
                    case 't':   
                        putchar('\t');
                        p++;
                        break;
                    case 'v':   
                        putchar('\v');
                        p++;
                        break;
                    case '0':   {
                        int count = 0;
                        int val = 0;
                        const char *next = p;
                        next ++;

                        for (;count < 3  && *next >= '0' && *next <= '7';count++) {
    
                                val = val * 8 + (*next - '0');
                                next++;
                                p++;
                            }
                       // printf("%d",count);
                        if(count > 0){
                            printf("%c", val);
                            p++;
                        }
                        break;

                        
                    }
                    case 'x':  {
                        //printf("here exa");
                        int count = 0;
                        int val = 0;
                        const char *next = p;
                        next ++;
                    for (;count < 2;count++ ) {

                            if (*next >= '0' && *next<= '9') {
                                val = val*16 + (*next - '0');
                                next ++;
                                p ++;
                            } 
                            else if (*next >= 'a' && *next <= 'f') {
                                val = val*16 + (*next - 'a' + 10);
                                next ++;
                                p ++;
                            }
                            else if (*next>= 'A' && *next <= 'F') {
                                val = val*16 + (*next - 'A' + 10);
                                next ++;
                                p ++;
                            } 
                            else {
                                break; 
                            }
                        }

                    if(count > 0){
                        printf("%c", val);
                        p++;
                    break;
                    }
                }
               
                default:
                    printf("\\%c",c);
           
                }
           
        

            }  
            else{
                printf("%c",c) ;
               
                
            }
                }   
                    }


int main(int argc, char **argv)
{
    int i = 1;
    Flags f = { false, false };
    if(argc > 1 && argv[1][0] == '-')
        check_flags(argc, argv, &i, &f);
    //printf("debug i %d\n",i);
    if(!f.e)
        for(i; i < argc; i++) {
            printf("%s", argv[i]);
        }
    else 
        parse_escapes(argc, argv, i);

    if(!f.n )
        printf("\n");

}
