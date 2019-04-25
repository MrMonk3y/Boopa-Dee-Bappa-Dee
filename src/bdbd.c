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
        else if (!strcmp(current_char, "bupi")) // >
        {
            ++ptr;
        }
        else if (!strcmp(current_char, "ba")) // <
        {
            --ptr;
        }
        else if (!strcmp(current_char, "pe")) // +
        {
            ++*ptr;
        }
        else if (!strcmp(current_char, "di")) // -
        {
            --*ptr;
        }
        else if (!strcmp(current_char, "bu")) // .
        {
            putchar(*ptr);
        }
        else if (!strcmp(current_char, "bapedi")) // ,
        {
            *ptr = getchar();
        }
        else if (!strcmp(current_char, "bupedi")) // [
        {
            continue;
        }
        else if (!strcmp(current_char, "bapudei") && *ptr) // ]
        {
            loop = 1;
            while (loop > 0)
            {
                strcpy(current_char, input[--i]);
                if (!strcmp(current_char, "bupedi")) // [
                {
                    loop--;
                }
                else if (!strcmp(current_char, "bapudei")) // ]
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
    //char str[] ="bapedi bupedi bu bupedi di bapudei bapedi bapudei";
    char str[] ="pe pe pe pe pe pe pe pe bupedi bupi pe pe pe pe bupedi bupi pe pe bupi pe pe pe bupi pe pe pe bupi pe ba ba ba ba di bapudei bupi pe bupi pe bupi di bupi bupi pe bupedi ba bapudei ba di bapudei bupi bupi bu bupi di di di bu pe pe pe pe pe pe pe bu bu pe pe pe bu bupi bupi bu ba di bu ba bu pe pe pe bu di di di di di di bu di di di di di di di di bu bupi bupi pe bu bupi pe pe bu";
    char words[400][10] = {{0}};
    string2words(words, str);
    interpret(words);
    //interpret(",[.[-],]");  // outputs input
    printf("done");
    return 0;
}
