#ifndef SORT_H
#define SORT_H
#include <iostream>

using namespace std;

template <class T>
class Sort
{
    private:
        T       *data; // needs to be an array
        int     length;
        void    swap(int x, int y); // swaps x and y in array
        void    mergeSort(int l, int r);
        T       *merge(int l, int mid, int r);

    public:
        //Sort();
        Sort(T *inData);
        void    bubbleSort();       // DONE
        void    insertionSort();    // DONE
        void    mergeSort();
        void    quickSort();
        void    heapSort();
        void    countingSort();
        void    radixSort();
        void    print();
        void    setData(T *inData);
        T       getData();
        int     getLength();

};

#endif

template<class T>
Sort<T>::Sort(T *inData)
{
    data = inData;
    length = sizeof(inData) + 1;
}

template<class T>
void    Sort<T>::setData(T *arr)
{
    data = arr;
}

template<class T>
int     Sort<T>::getLength()
{
    return length;
}

template<class T>
void    Sort<T>::print()
{
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        cout << data[i] << ", ";
    }
    cout << "]" <<  endl;
}

template<class T>
void    Sort<T>::swap(int x, int y)
{
    T   tmp;

    tmp = data[x];
    data[x] = data[y];
    data[y] = tmp;
}

template<class T>
void    Sort<T>::bubbleSort()
{
    bool    good;
    int     x;
    T       tmp;

    good = true;
    while (good)
    {
        x = 0;
        for (int i = 0; i < length; i++)
        {
            if (i < length - 1 && data[i] > data[i+1])
            {
                tmp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = tmp;
            }
            else
            {
                x++;
            }

        }
        if (x == length)
        {
            good = false;
        }
    }
}

template<class T>
void    Sort<T>::insertionSort()
{
    int     i = 1;
    int     j;

    while (i < length)
    {
        j = i;
        while (j > 0 && data[j - 1] > data[j])
        {
            swap(j, j - 1);
            j--;
        }
        i++;
    }
}

template<class T>
void    Sort<T>::mergeSort(int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);

        merge(left, mid, right);
    }
}

template<class T>
void    Sort<T>::mergeSort()
{
    mergeSort(0,length);
}

template<class T>
T      *Sort<T>::merge(int l, int mid, int r)
{
    int i, j, k;
    int L = mid - l + 1;
    int R = r - mid;
    int left[L];
    int right[R];

    for (i = 0; i < L; i++)
    {
        left[i] = data[l + i];
    }
    for (j = 0; j < R; j++)
    {
        right[j] = data[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < L && j < R)
    {
        if (left[i] <= right[j])
        {
            data[k] = left[i];
            i++;
        }
        else
        {
            data[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < L)
    {
        data[k] = left[i];
        i++;
        k++;
    }
    while (j < R)
    {
        data[k] = right[j];
        j++;
        k++;
    }
}