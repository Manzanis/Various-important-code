#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "sorter.h"
#include "mytimer.h"

using namespace std;

template <typename T>
void print_vector(vector<T> arr, int N)
{
    for (size_t i = 0; i < arr.size() && i < N; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

template <typename T>
void compare_vectors(vector<T> a, vector<T> b, string message = "")
{
    cout << message << " ";
    // check if equal
    if (a == b)
        cout << "CONGRATS, your implementation is correct!" << endl;
    else
        cout << "Ops, sorry cowboy (cowgirl), it seems that something is still missing in your implementation" << endl;
}

int main()
{
    //generate a random float number array 
    vector<int> arr_f;
    int count = 10;

    for (size_t i = 0; i < count; i++)
    {
        arr_f.push_back((int)rand() % 256);
    }

    vector<int> arr_1(arr_f);
    vector<int> arr_2(arr_f);
    vector<int> arr_3(arr_f);
    vector<int> arr_4(arr_f);

    cout << "Unsorted: " << endl;
    print_vector(arr_f, 10);

    DECLARE_TIMING(t);
    START_TIMING(t);
    std::sort(arr_f.begin(), arr_f.end());
    STOP_TIMING(t);
    SHOW_TIMING(t, "std::sort");

    //Create SelectionSort instance
    DECLARE_TIMING(t1);
    START_TIMING(t1);
    SelectionSort<int> selsort;
    selsort.Sort(arr_1);
    STOP_TIMING(t1);
    compare_vectors(arr_f, arr_1, "Selection sort");
    SHOW_TIMING(t1, "Selection Sort: ");

    DECLARE_TIMING(t2);
    START_TIMING(t2);
    BubbleSort<int> bubsort;
    bubsort.Sort_B(arr_2);
    STOP_TIMING(t2);
    compare_vectors(arr_f, arr_2, "Bubble Sort");
    SHOW_TIMING(t2, "Bubble Sort: ");

    DECLARE_TIMING(t3);
    START_TIMING(t3);
    InsertSort<int> inssort;
    inssort.Sort_Ins(arr_3);
    STOP_TIMING(t3);
    compare_vectors(arr_f, arr_3, "Insertion sort");
    SHOW_TIMING(t3, "Insertion Sort: ");

    DECLARE_TIMING(t4);
    START_TIMING(t4);
    MergeSort<int> mergesort;
    mergesort.Sort_Merge(arr_4, 0, arr_4.size() - 1);
    STOP_TIMING(t4);
    compare_vectors(arr_f, arr_4, "Merge Sort");
    SHOW_TIMING(t4, "Merge Sort: ");

    return 0;
}
