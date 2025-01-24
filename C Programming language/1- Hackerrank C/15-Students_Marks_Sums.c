#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) 
{
    int sum = 0;
    if (number_of_students == 0)
    {
        return sum;
    }
    else
    {
        int i = 0;

    if ( gender == 'g')
    {
        if (number_of_students == 1)
        {
            return 0;
        }

        for (i = 1 ; i<number_of_students ; i+=2)
        {
            sum += marks[i];
        }
    }
    if ( gender == 'b')
    {
        for (i = 0 ; i<number_of_students ; i+=2)
        {
            sum += marks[i];
        }
    }
    }
    return sum;
}

int main() 
{
    int number_of_students;
    char gender;
    int sum;
  
    printf("Put the number of students you bastered\n");
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
    

    for (int student = 0; student < number_of_students; student++) 
    {
        printf("Enter degree for student %d: ", student);
        scanf("%d", (marks + student));
    }
    
    printf("PUT g for girls sum of degrees, PUT b for Boys sum of degress:");
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    getchar();
    getchar();

    return 0;
}