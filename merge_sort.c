// Merge Sort

/*

Time complexity:

Adaptive:

Stable:

Inplace: No

_____________________________________________________________________________________________
Working.......................(our goal is to merge 2 sorted arrays into 1)

To understand its working first we need to understand what is merging process:

Merging process means merging 2 sorted arrays to 1 sorted array.
something like 1 3 5 merged with 7 4 , sorted array becomes 1 2 4 5 7

________________________________________Merging Process:

Consider 2 sorted arrays:

Array 1:    1 3 5 17 18
Array 2:    4 9 10 23 55 99

So we will say "i" = 0 , j="0" and k="0"

we will traverse "i" in array 1 and "j" in array 2
we will compare array1[i] and array2[j]
if (array1[i] < array2[j]), then we will insert array1[i] in array3[k] and increment "i" and "k"
we incremented "i" to check next element in array 1 and "k" to insert next element in array 3
If the condition stands false then we will insert array2[j] and increment "j" and "k"
Thats pretty simple we are inserting smaller elements from both arrays to one array

Now if "i" or "j" reaches its end then it means that every other elements are bigger
so we will copy them as it is.

So taking above arrays we get i=0, j=0
on first comparison we got 1<4 so we will insert 1 in array3 and do i++ and k++
on second comparison we got 3<4 so we will insert 3 in array3 and do i++ and k++
on third comparison we got 5>4 so we will insert 4 in array3 and do j++ and k++.....
doing it untill we reach at a position where i<size or j<size here we got i=4 and j=3
now as we reached a position where i<size so we will copy down array2's elements as it is to array3
cuz now they all are greater than our array1's elements.

___________________________________________________Merging Process in a single array:

Now we know what is an mergin process.
we can also use the same process with little modification to do merging in a single array.

consider the following array..

1 5 19 4 7 9 17

here elements left to the 4 are sorted and right to the 4 are also sorted;
so we will say,
i=low=0, j=high=size-1, and our mid is= 2(index at which 4 exists - 1)

So now our 2 sorted arrays are
Array 1: from low to mid
Array 2: from mid + 1 to high

now we will do our mergin process on these 2 arrays to get a sorted one.
we will merge them to a  array say "sorted_Array"

Note:(sorted_Array will we now copied down to the orignal one from where we got our 2 arrays.)

__________________________________________________Working of Merge Sort______

Merge sort works recursively..

Lets say we have an array like this (unsorted)

1 78 34 2 34 87 45

we will say low = 0, high = size - 1 , and mid = (low+high)/2

and we will call merge sort again on
these 2 arrays
Array 1: from low to mid
Array 2: from mid + 1 to high

We will do it unitll (low<high)
this condition says thats we can't split our array further into parts cuz we got just 1 element

now we will follow our mergin procedure on the array, which is splitted into atleast 2 elements

Lets dry this on our array.

Here low = 0 , high = 6, mid = 3
Now our array is splitted as follows

    Array1:     1 78 34 2
    Array2:     34 87 45

    Now  Array 1 will we spillted as follows(low = 0, high = 3, mid = 1)

        Array1.1:   1 78
        Array1.2:   34 2

        Now our Array1.1 will be splited as follows, (low = 0, high = 1, mid = 0)

            Array1.1.1:     1
            Array1.1.2:     78

            Now it cant be further splitted so this will be merged
            becoming    1 78

            Array1.2 will also do the same and
            become   2 34

        Now our Array 1: will be merged and
        become      1 2 34 78

Meanwhile the same thing will be done with our Array 2: and array will
become      34 45 87

Now at last our array 1 and array 2 will be merged and
become      1 2 34 34 45 78 87

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

void merge(int *array, int low, int mid, int high) // this function will follow the merging process in a single array
{
    int *merged_array = (int *)malloc((high - low + 1) * sizeof(int));
    // int merged_array[high + 1];
    int i, j, k; // "i" to traverse in array 1, and "j"  in array 2
    i = low;     // array 1 starts from low and ends at mid
    j = mid + 1; //  array 2 starts from mid + 1, thats why j = mid + 1
    k = low;

    // array1's end is mid and array2's end is high
    while (i <= mid && j <= high) // this condition checks if any one array's traversing variable(i or j) reaches its end
    {
        if (array[i] < array[j]) // if array1's element is smaller than array2's element
        {
            merged_array[k] = array[i]; // then push the smaller one into new_array
            i++;                        // switching to next element to compare
            k++;
        }

        else // if array2's element is smaller
        {
            merged_array[k] = array[j];
            j++;
            k++;
        }
    }
    // Now we are here cuz while loop is exited
    // Now it exited cuz either "i" reached end or "j"
    // So we will copy the remaining elements to the new array
    // only one of the following loop will be executed
    while (i <= mid) // if "j" reached end then we will copy array1's elements
    {
        merged_array[k] = array[i];
        i++;
        k++;
    }
    while (j <= high) // if "i" reached end then we will copy array2's elements
    {
        merged_array[k] = array[j];
        j++;
        k++;
    }
    // Now we got our sorted array in our new array
    // but we need to copy it back in original array
    for (i = low; i <= high; i++)
    {
        array[i] = merged_array[i]; // copying elements
    }
}

void merge_sort(int *array, int low, int high)
{
    int mid;
    if (low < high) // condition that checks can array be further splitted?
    {
        mid = (low + high) / 2;
        merge_sort(array, low, mid);      // calling it for splitted array1 (from low to mid)
        merge_sort(array, mid + 1, high); // calling it for splitted array2 (from mid + 1 to high)

        // Note this merge will be executed at end when splitting process result in a very
        // smaller array of size 2

        // as we need to merge it from a single array so we need to pass mid also which will split the single arrays to 2 arrays
        merge(array, low, mid, high); // now finally merging the splitest array
        // array like 1 and 78 which is splitted down to just 2 elements from n elements
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

    merge_sort(array, 0, n - 1);
    printf("\nAfter sorting.......\n");
    display(array, n);

    return 0;
}