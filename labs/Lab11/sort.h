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
        T       *merge();

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
void    Sort<T>::mergeSort()
{

}

template<class T>
T      *Sort<T>::merge()
{

}