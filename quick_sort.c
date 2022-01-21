// Quick Sort

/*

Time complexity:  O(n^2)

worst case: O(n^2)
average case: O(n logn)
best case: O(n logn)

Adaptive( Means if array is already sorted does it take O(n^2) time or less):

NO it is not adaptive, infact its worst case is when array is already sorted

Stable(order of similar elements doesn't change in input array and sorted one): 
By default it is not stable

Inplace sorting algorithm:
Means it doesn't take any extra space for sorting
sorting is done in original array

_______________________________________________________________________________________________
Working:..... (It will work recursively)

Lets say we have an array like...

(our goal is to place the "i"th element or the first element on its place)
(placing criteria is, that we should place the ith element or "pivot" element to a place
such that it has greater elements to its right and smaller to its left..)

    |   |   |   |   |   |
    | 1 | 5 | 2 | 4 | 7 |
    |   |   |   |   |   |

    Partioning procedure.... (pivot  = 0)
    1. take i = low (0)
    2. take j = high (last element i.e n-1)
    3. increment i untill we found greater element to our pivot (untill array[i] > pivot)
    4. decrement j unitll we found smaller or equal element to our pivot (untill array[j] <= pivot)
    5. when we found our "i" and "j" we will swap(array[i], array[j]);
    6 also when our j<=i we will swap(pivot, array[j]);

    So following above procedure...

    Our pivot element is 1
    "i" starts from zero and moves untill it found element greater than pivot so it found 5
    so our i's value is 1(index at which he found 5) meanwhile our "j" starts from (n-1 th index)
    means from last element and kept decreasing untill he found element smaller than pivot so
    it come all the way to the front cuz there wasn't any element, so j=0 so our condition j<=i (0<=1)
    statisfied and we swap(pivot, array[j]), and gets array

    1 5 2 4 7 which is not changes as you can see, but it makes sense cuz see element right to our
    pivot are greater than it...

    So now our new pivot is 5,
    "i" starts from 1(pivot's location) and increases untill he found greater element and go all the
    way down to element 7(index 4) so our "i" is 4 meanwhile our "j" starts from (n-1 th index)
    and kept decreasing untill he found smaller element and come to element 4(index 3) so now
    i = 4 and j = 3 our condition (j<=i) satisfied so lets swap(pivot, array[j]); and we get.

    1 4 2 5 7, now as you can see pivot element (5) has smaller element to its left and greater to its right
    now we need to follow the same procedure on array(left to the pivot 5) i.e 1 4 2 and array(right to it)
    which is just one element.

    Note: If the condition(j<=i) not satisfies we need to swap elements on jth and ith indices
    swap(array[j], array[i]);


    Note: we will do it recursively

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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int createPartition(int *array, int low, int high)
{
    int pivot = array[low];
    int i = low + 1, j = high;

    do
    {
        while (array[i] <= pivot) // doing this till we found greater element than our pivot
        {
            i++;
        }

        while (array[j] > pivot) // doing this till we found smaller or equal element to our pivot
        {
            j--;
        }

        if (i < j)
        {
            swap(&array[i], &array[j]); // swapping ith and jth element
        }
        
    } while (i < j); // this condition says that when our j<=i exit the loop and swap 

    swap(&array[j], &array[low]); // array[low] is pivot we used array[low] to reflect the change in original array

    return j;
}

void quick_sort(int *array, int low, int high)
{
    int partitionIndex; // index of pivot after partition

    if (low < high) // condition
    {
        partitionIndex = createPartition(array, low, high);
        // create partition function will place pivot element to its place and will returns its index
        // to such place where it has smaller elements to its left and larger to right

        // Now we got our partition index, means new location of our pivot element..
        // so now we got 2 new sub arrays to sort,
        // 1: left to the pivot element
        // 2: right to the pivot element
        quick_sort(array, low, partitionIndex - 1);  // left sub array to the pivot
        quick_sort(array, partitionIndex + 1, high); // right sub array to the pivot
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

    quick_sort(array, 0, n - 1);
    printf("\nAfter sorting.......\n");
    display(array, n);

    return 0;
}