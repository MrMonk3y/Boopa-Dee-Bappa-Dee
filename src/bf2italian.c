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
                strcat(out, "boo ");
                break;
            case '<':
                strcat(out, "bappa ");
                break;
            case '>':
                strcat(out, "boopa ");
                break;
            case '-':
                strcat(out, "dee ");
                break;
            case '+':
                strcat(out, "pe ");
                break;
            case '[':
                strcat(out, "boopadee ");
                break;
            case ']':
                strcat(out, "bappadee ");
                break;
            case ',':
                strcat(out, "boopabappa");
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
    char out[500];
    translate(bf, out);
    printf("%s\n", out);
    return 0;
}
