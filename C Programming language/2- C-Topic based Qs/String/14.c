#include <stdio.h>

int main() {
    char str[80], search[20]; // Declare character arrays for the main string and the substring to search
    int str_size = 0, search_size = 0, i, j, flg; // Declare variables for counting, iteration, and flag for substring check

    printf("\n\nCheck whether a given substring is present in the given string :\n"); // Display information about the task
    printf("-------------------------------------------------------------------\n");

    printf("Input the string : ");
    fgets(str, sizeof str, stdin); // Read a string from the standard input (keyboard)

    printf("Input the substring to be searched : ");
    fgets(search, sizeof search, stdin); // Read the substring to be searched

    // Calculate the length of the main string
    while (str[str_size] != '\0') 
    {
        str_size++;
    }
    str_size--;

    // Calculate the length of the substring
    while (search[search_size] != '\0') 
    {
        search_size++;
    }
    search_size--;

    // Check if the substring exists in the main string
    for (i = 0; i <= (str_size - search_size) ; i++) 
    {
        for (j = 0; j < search_size; j++) 
        {
            flg = 1; // Initialize the flag for matching substring
            if (str[i] != search[j]) 
            {
                flg = 0; // Set the flag to zero if characters don't match
                break;
            }
        }
        if (flg == 1) 
        {
            break; // Break the loop if substring is found
        }
    }

    if (flg == 1) 
    {
        printf("The substring exists in the string.\n\n"); // Display message if the substring is found
    } 
    else 
    {
        printf("The substring does not exist in the string.\n\n"); // Display message if the substring is not found
		
		return 0; // Return 0 to indicate successful execution of the program
    }
    getchar();
    getchar();
}
