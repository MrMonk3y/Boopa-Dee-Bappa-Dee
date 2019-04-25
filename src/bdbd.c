#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// initialize the tape with 30,000 zeroes
unsigned char tape[30000] = {0};

// set the pointer to point at the left-most cell of the tape
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
    int i = 0;
    pch = strtok (input," ,.-");
    while (pch != NULL)
    {
       // printf ("%s\n",pch);
        strcpy(words_array[i], pch);
        pch = strtok (NULL, " ,.-");
        i++;
    }
}

int main()
{
    //char str[] ="boopabappa boopadee boo boopadee dee bappadee boopabappa bappadee";
    char str[] ="pe pe pe pe pe pe pe pe boopadee boopa pe pe pe pe boopadee boopa pe pe boopa pe pe pe boopa pe pe pe boopa pe bappa bappa bappa bappa dee bappadee boopa pe boopa pe boopa dee boopa boopa pe boopadee bappa bappadee bappa dee bappadee boopa boopa boo boopa dee dee dee boo pe pe pe pe pe pe pe boo boo pe pe pe boo boopa boopa boo bappa dee boo bappa boo pe pe pe boo dee dee dee dee dee dee boo dee dee dee dee dee dee dee dee boo boopa boopa pe boo boopa pe pe boo ";
    char words[400][10] = {{0}};
    string2words(words, str);
    interpret(words);
    //interpret(",[.[-],]");  // cat input
    return 0;
}
