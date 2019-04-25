//
//  bf2italien.c
//  bfi
//
//  Created by Sascha Jecklin on 25.04.19.
//  Copyright © 2019 Sascha Jecklin. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* translate(char* text, char* out)
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        switch(text[i])
        {
            case '.':
                strcat(out, "bu ");
                break;
            case '<':
                strcat(out, "ba ");
                break;
            case '>':
                strcat(out, "bupi ");
                break;
            case '-':
                strcat(out, "di ");
                break;
            case '+':
                strcat(out, "pe ");
                break;
            case '[':
                strcat(out, "bupedi ");
                break;
            case ']':
                strcat(out, "bapudei ");
                break;
            case ',':
                strcat(out, "bapedi ");
                break;
            default:
                break;
        }
    }
    return out;
    
}

int main()
{
    char bf[] = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    char out[400];
    translate(bf, out);
    printf("%s\n", out);
    return 0;
}
