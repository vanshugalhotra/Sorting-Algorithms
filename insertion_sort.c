// Insertion Sort Algorithm

/*

Time complexity:  O(n^2)

Adaptive( Means if array is already sorted does it take O(n^2) time or less):

Yes it is adaptive, If array is sorted it will take O(n) time

Stable(order of similar elements doesn't change in input array and sorted one): yes

Inplace sorting algorithm:
Means it doesn't take any extra space for sorting
sorting is done in original array
_______________________________________________________________________________________________
Working:.....

Lets say we have an array like...

    |   |   |   |   |   |    
    | 1 | 5 | 2 | 4 | 7 |
    |   |   |   |   |   |

Now on first pass We will sort first 2 elements

    1   |5 , here key = 5 means element which will change its place if condition is true
    so the condition is if 1>5 then change there places which is not so we are done with our first pass

Now on second pass we will sort first 3 elements,

    1 5 |2, here key = 2 
    so the condition says is 5>2 yeahh so lets shift 5, "1  emp  5", note that 2 is not on its place it will after 2nd pass
    now condition says is 1>2 nope. so second pass is complete. lets put 2 on its place.

Now on third pass we will sort first 4 elements,

    1 2 5|4, here key = 4
    so the condition says is 5>4 yes!! so lets shift 5, "1 2 emp 5", as you know the real array is something like "1 2 5 5" but 5 on index 2 will be overwritten
    now condition says is 2>4 no!. so third pass ends. lets put 4(i.e key) on its place. After putting 4 on its place our 5 on index 2 is overwritten

Now on fourth pass we will sort all the five elements,

    1 2 4 5|7, here key = 7
    so the condition says is 5>7 which is false, so our fourth pass ends.
    and our array is sorted.

It took us (n-1) passes to sort the array!!!!

(note): this algorithm is adaptive cuz if the array is already sorted , we need to make just
n-1 comparisons.

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

void insertion_sort(int *array, int size)
{
    int key, j; // "i" is used for key and "j" for all the elements left of the key
    for (int i = 1; i < size; i++) // 1,2,.....n-1 (loop for each pass)
    {
        key = array[i];
        j = i-1;
        while (j>=0 && array[j] > key)
        {
            array[j+1] = array[j]; // 
            j--;
        }
        array[j+1] = key;
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

    insertion_sort(array, n);
    printf("\nAfter sorting.......\n");
    display(array, n);

    return 0;
}