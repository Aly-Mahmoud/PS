#include <stdio.h>

typedef struct 
{
    int ID;
    char *str ;
    int salary;
} employee;

int main ()
{
    employee e1;

    employee *ptr = &e1;

    e1.ID=1000;
    e1.str = "Aly Mahmoud Taha";
    e1.salary = 30000;

    ptr->ID = 2000;
    ptr->str = "Ahmed Mohamed";
    ptr->salary = 25000;
}