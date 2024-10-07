#include <stdio.h>
#include <stdlib.h>

// Complete the following function.
int find_nth_term(int n, int a, int b, int c) 
{
    // Base case: when n is 1, 2, or 3, return the corresponding initial term.
    if (n == 1)
        return a;
    if (n == 2)
        return b;
    if (n == 3)
        return c;

    // Recursive case: return the sum of the previous three terms
    return find_nth_term(n - 1, a, b, c) + find_nth_term(n - 2, a, b, c) + find_nth_term(n - 3, a, b, c);
}

int main() 
{
    int n, a, b, c;
  
    // Sample input for testing purposes
    n = 5; a = 1; b = 2; c = 3;

    int ans = find_nth_term(n, a, b, c);
    printf("%d", ans); 

    return 0;
}
