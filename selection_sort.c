// Selection sort
/*

Time complexity:  O(n^2)

Adaptive( Means if array is already sorted does it take O(n^2) time or less):

No it is not adaptive, If array is sorted it will take O(n^2) time

Stable(order of similar elements doesn't change in input array and sorted one): NO

Total nmber of passes are also (n-1)
Total number of possible swaps are (n-1)
Total number of comparisons are 1+2+3.....n-1

Advantage of this algorithm is that we can sort array using minimum number of swaps
_______________________________________________________________________________________________
Working:.....

Lets say we have an array like...  (Our goal is to place smallest element on first place)

    |   |   |   |   |   |
    | 1 | 5 | 2 | 4 | 7 |
    |   |   |   |   |   |

Now on first pass, we will take say first element in our "minimum" so we will compare it with
every other element, where ever we found an element smaller than our "minimum" we will say
"min" = that element, and then we will continue this till we found our smallest element in whole array

So in first pass, "min" = 1, then while comparing it will not found any smaller element so our
first pass ends.

Now on second pass, we will say second element is "min", so will do the same procedure
So "min"= 5 and by comparing, we got at end , "min" = 2, so we will swap 5 and 2

It will cost us n-1 passes to sort the array.

Inplace sorting algorithm:
Means it doesn't take any extra space for sorting
sorting is done in original array

Note: if the array is already sorted , no. of comparisons wont be affected hence
our algorithm is not adaptive,

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

void selection_sort(int *array, int size)
{
    int indexofMin, temp;
    for (int i = 0; i < size - 1; i++)
    {
        indexofMin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[indexofMin])
            {
                indexofMin = j;
            }
        }
        // swapping the i th element with the smalles element in array
        temp = array[i];
        array[i] = array[indexofMin];
        array[indexofMin] = temp;
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

    selection_sort(array, n);
    printf("\nAfter sorting.......\n");
    display(array, n);

    return 0;
}