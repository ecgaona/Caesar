/* Caesar.c by Eduardo F. Carr-Gaona
This program will encipher any text
using Caesar's cipher by prompting 
the user at the command line for the
key. */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])

{
    if (argc != 2)
        {
            printf("Invalid number of arguments!\n");
            return 1; 
        }
    int k = atoi(argv[1]);
    if (k < 0)
        {
            printf("Key must be a non-negative integer!\n");
            return 2; 
        }
    string p = GetString();
    if (p != NULL)
        {
            for (int i = 0, n = strlen(p); i < n; i++)
                {
                    if (isalpha(p[i]))  /* ensures only the letters in the Latin alphabet are enciphered */
                        {
                            if (islower(p[i]))  /* maintains the integrity of the letter case the user entered */
                                {   
                                    int c = (((p[i] - 97) + k) % 26) + 97;  /* caesar cipher = (plaintext + key) % 26 */
                                    printf("%c",c);                         /* adding/subtracting 97 & 65 converts ascii */ 
                                }                                           /* index to alphabetical index and vice versa */
                            if (isupper(p[i]))                              /* caesar cipher only works w/ alphabetical index */
                                {
                                    int c = (((p[i] - 65) + k) % 26) + 65;
                                    printf("%c",c);
                                }
                        }
                    else 
                        {              
                            int c = p[i];   /* prints any non-alpha characters the user entered with their plaintext */
                            printf("%c",c);
                        }
                }  
        }
    printf("\n");
    return 0;       
}
