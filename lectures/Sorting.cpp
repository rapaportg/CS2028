/*

    Quick Sort - another divide and conquer algorithm

        Process:
            1. pick a random pivot x.
            2. Partition the data into 3 subsets <x, ==x, >x
            3. Repeat steps 1 and 2 with the < and > subsets

        Performance:
            - Average case/Best case -  O(nlog(n))

            - Worst case - O(n^2)

        Limitations:
            - Performs very poorly for bad pivot selections

        Optimization:
            - grab the first, last, and middle value and use the one that is in the middle of those 3.







    Heap Sort - an in-place sorting algorithm. It divides the input into sorted and unsorted regions.

        Process:
            1. Make the array follow valid head rules. This is the unsorted section
            2. Swap the last node in the remaining unsorted portion of the list with the first node and reheap down
                - each time this happens, n shrinks by 1.

            To heapify, start with the last spot in memory. If it is larger, we swap.

            Then we move left 1 spot and repeat until only the first node remain

        Performance: O(nlog(n))

        Note: this is not a stable sort. what that means is if you have 2 items with the same value, the order of those 2 items may change.




    Counting Sort - an algorithm for sorting items when they are small(ish) integers (at least the sort key)
                        not an in-place sort. the Output is a new array


        Process:
            1. Step through all the items and count how mant occurances there are of each key
            2. Set the values in the count such that they include the previous values. Running sum
            3. Start at the beginning and populate the new array witht the counts array showing where they go. The new array is sorted

        Note:   To use this you need to know the maximum value. (and minimum if not 0). Not stable

        This is only efficent when that range of values is small

        Performance: O(n) - really is O(n) + O(m) + O(n)





    Radix Sort - a non-comparative sorting algorithm that typically sorts integers but can also sort strings

        Process:
            1. Use counting sort to sort base on least significant digit. ignore all other digits, this requires a modification to counting sort to be stable.
            2. Repeat step 1 for each digit from least Significant to most significant


        *Note: pad keys appropriately


        Performance: O(wn) where w is the number of digits. -> O(n)

*/