/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    *returnSize = 2;
    int* ptr = (int*) malloc(2* sizeof(int));

    int i = 0;
    int j = 0;

    for (i=0 ; i< numsSize-1 ; i++)
    {
        for (j = i+1 ; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                ptr[0] = i;
                ptr[1] = j;
                return ptr;
            }
        }
    }
    return NULL;
}

int main ()
{

    int* nums = (int*) malloc (4*sizeof(int));
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;
    int* returnSize = (int*) malloc(sizeof(int));
    int* result     = twoSum( nums, 4, 9, returnSize);

    // Free aloocated memory
    free(nums);
    free(returnSize);
    free(result);

    return 0;
}