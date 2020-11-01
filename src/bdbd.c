#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// initialize the tape with 30,000 zeroes
unsigned char tape[30000] = {0};
unsigned char* ptr = tape;

void interpret(char input[10][10])
{
    char current_char[10];
    size_t i;
    size_t loop;
    
    for (i = 0; input[i] != 0; i++)
    {
        strcpy(current_char, input[i]);
        if (!strcmp(current_char, "\0"))
        {
            break;
        }
        else if (!strcmp(current_char, "boopa")) // >
        {
            ++ptr;
        }
        else if (!strcmp(current_char, "bappa")) // <
        {
            --ptr;
        }
        else if (!strcmp(current_char, "pe")) // +
        {
            ++*ptr;
        }
        else if (!strcmp(current_char, "dee")) // -
        {
            --*ptr;
        }
        else if (!strcmp(current_char, "boo")) // .
        {
            putchar(*ptr);
        }
        else if (!strcmp(current_char, "boopabappa")) // ,
        {
            *ptr = getchar();
        }
        else if (!strcmp(current_char, "boopadee")) // [
        {
            continue;
        }
        else if (!strcmp(current_char, "bappadee") && *ptr) // ]
        {
            loop = 1;
            while (loop > 0)
            {
                strcpy(current_char, input[--i]);
                if (!strcmp(current_char, "boopadee")) // [
                {
                    loop--;
                }
                else if (!strcmp(current_char, "bappadee")) // ]
                {
                    loop++;
                }
            }
        }
    }
}

void string2words(char words_array[400][10], char* input)
{
    char * pch;
    size_t i = 0;
    pch = strtok (input," ,.-");
    while (pch != NULL)
    {
        strcpy(words_array[i], pch);
        pch = strtok (NULL, " ,.-");
        i++;
    }
}

int main(int argc, char* argv[])
{
    if(1 == argc)
    {
        printf("Need input file");
    }
    else
    {
        char * buffer = 0;
        long length;
        FILE * f = fopen (argv[1], "r");
        
        if (f)
        {
            fseek (f, 0, SEEK_END);
            length = ftell (f);
            fseek (f, 0, SEEK_SET);
            buffer = calloc (length, sizeof(char));
            if (buffer)
            {
                fread (buffer, 1, length, f);
            }
            fclose (f);
        }
        
        if (buffer)
        {
            char words[400][10] = {{0}};
            string2words(words, buffer);
            interpret(words);
        }
    }
    
    return 0;
}
