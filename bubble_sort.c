// Bubble sort algorithm

/*

Time complexity:  O(n^2)

Adaptive( Means if array is already sorted does it take O(n^2) time or less):

By default it is not adaptive but can be modified to be adaptive and can do it in O(n) time is
array is already sorted

Stable(order of similar elements doesn't change in input array and sorted one): yes

Total nmber of passes are also (n-1)
Total number of possible swaps are 1+2+3.....n-1
Total number of comparisons are 1+2+3.....n-1

Q: How do we make it adaptive;

So we will check if the array is sorted or not if it is then we will break the loop;
To check if it is sorted or not we have one technique;
We will declare a variable say, num_swaps; we will increment it everytime we swap 2 elements;
As we know if the array is not sorted we have to swap elements to sort it, so after one pass if
num_swaps is still 0 means no swapping occured hence the array was already sorted;

Inplace sorting algorithm:
Means it doesn't take any extra space for sorting
sorting is done in original array
_______________________________________________________________________________________________
Working:.....

Lets say we have an array like... (our goal is to place the greatest element on the last index)

    |   |   |   |   |   |
    | 1 | 5 | 2 | 4 | 7 |
    |   |   |   |   |   |
    
Now on first pass, we will compare, (2 consecutive elements) our first and second element if(first > second) we need to swap them
similarily first pass  will continue till n-1 and nth element,

Now we got our greatest element on the last index,

So on second pass, we will do the same but, we need to make 1 less comparison cuz our 1 element is on its place 
and there is no need to compare that element

So this will continue, and array will be sorted in (n-1) passes, doing 1+2....n-1 possible comparisons and swaps.

(Note) this algorithm is not adaptive by default but can be maked.

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

void bubble_sort(int *array, int size)
{
    int temp, number_of_swaps;
    ;
    for (int i = 0; i < size - 1; i++) // outer loop for every pass (total passes = n-1)
    {
        printf("Working on Pass Number:%d\n", i + 1);
        number_of_swaps = 0;
        for (int j = 0; j < size - 1 - i; j++) // for comparison in each pass (each time we decrease number of comparisons by "i" cause after every pass 1 element is at its place i.e the greatest one)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                number_of_swaps++; // doing this to check whether the array is passed is sorted or not
            }
        }
        if (number_of_swaps < 1) // if number_of_swaps are 0 then our array is sorted so lets break the loop there is no need to continue the loop
        {
            break;
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

    bubble_sort(array, n);
    printf("\nAfter sorting.......\n");
    display(array, n);

    return 0;
}