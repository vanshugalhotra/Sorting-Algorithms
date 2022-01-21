// Count sort

/*

Time complexity: O(m+n) 

where n=number of elements, m = max element in array
But, when n is very large... m will be negligible,
so time complexity = O(n)

Adaptive: No

Stable: 

Inplace: No (extra space is used) O(m)

_____________________________________________________________________________________
Working........(our goal is to count the occurenece of a particular element in unsorted array)

Lets say we have an array like this

    1 8 3 5 7 1 3

we need to find the maximum element in the array.

so here max = 8;

now we will create an another array with size = max + 1, like "int count[max+1]" = {0};
initializing every element to 0

Now while traversing in our array we will
increment the value of elements in our count array at index = element of our array

For example,,,

our count array will look like this, 0 0 0 0 0 0 0 0 0
while traversing in our array,
we got first element, 1 so we will increment the value of count array's element at index = 1;

so now our count array look like this, 0 1 0 0 0 0 0 0 0
so doing this,, we will got our count array at the end like

    0 2 0 2 0 1 0 1 1

Now we will traverse in our count array.. if the value is 0 then skip
if its non zero then do...following till it becomes zero

insert the index of the value at which it is non-zero in our array, and decrement it

So here, at index 0 value is 0 so it will be skipped
at index 1 value is 2 so
    1 will be inserted in our array at first index. now at index 1 value is 1(2 is decremented)
    so 1 will be inserted in our array at second index. now at index 1 value is 0 so lets skip it

Now at index 2 value is 0, so it will be skipped
so by doing this we will got our sorted array,,

    1 1 3 3 5 7 8


*/
#include <stdio.h>
#include <stdlib.h>

void display(int *array, int size)
{
    printf("Elements are:\t");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    printf("\n");
}

void count_sort(int *array, int size)
{
    int max = array[0];
    for (int i = 0; i < size; i++) // finding the max element
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    int *count = (int *)calloc(max + 1, sizeof(int)); // using calloc to initialize every element to 0
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++; // incrementing count array's elements
    }
    int k = 0, i = 0;

    while (i <= max) // it will create our sorted array using our count array
    {
        if (count[i] > 0)
        {
            array[k] = i; // index of count array
            count[i]--;
            k++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n, *array;

    printf("Enter the number of elements in array:\n");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    printf("\nBefore sorting.....\n");
    display(array, n);

    count_sort(array, n);
    printf("\nAfter sorting.......\n");
    display(array, n);

    return 0;
}