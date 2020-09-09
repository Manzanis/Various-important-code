#include <iostream>
#include <vector>
#include "busqueda.h"
#include "sorter.h"

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

int main()
{
    // Ask user for n
    int size;
    cout << "Enter the size of the array you want: ";
    cin >> size;

    vector<int> arr_d;

    for (size_t i = 0; i < size; i++)
    {
        arr_d.push_back((int)rand() % (size * 2));
    }
    
    // Ask user for the number(s) to find
    int qnum;
    cout << "How many numbers do you want to find?: ";
    cin >> qnum;

    vector<int> arr_num;
    for (size_t i = 0; i < qnum; i++)
    {
        int num;
        cout << "Enter the number(s): ";
        cin >> num;
        arr_num.push_back(num);
    }

    // Start with finding and sorting code
    int selec;
    cout << "Please select the sorting option:";
    cout << "\n1.Insertion Sort." << "\n2. Bubble Sort." << "\n3. Quick Sort" << endl;
    cin >> selec;

    if (selec > 3 || selec < 1)
    {
        throw "Illegal number";
    }

    if (selec == 1)
    {
        Finder<int> v1;
        print_vector(arr_d, size);
        for (size_t i = 0; i < qnum; i++)
        {
            v1.seq_Find(arr_d, size, arr_num[i]);
        }
        
        InsertSort<int> inssort;
        inssort.Sort_Ins(arr_d);
        print_vector(arr_d, size);
        for (size_t j = 0; j < qnum; j++)
        {
            cout << "Your number is in: " << v1.Binary(arr_d, 0, arr_d.size(), arr_num[j]) << endl;
        }
        

    }
    if (selec == 2)
    {
        Finder<int> v2;
        print_vector(arr_d, size);
        for (size_t i = 0; i < qnum; i++)
        {
            v2.seq_Find(arr_d, size, arr_num[i]);
        }

        BubbleSort<int> bubsort;
        bubsort.Sort_B(arr_d);
        print_vector(arr_d, size);
        for (size_t j = 0; j < qnum; j++)
        {
            cout << "Your number is in: " << v2.Binary(arr_d, 0, arr_d.size(), arr_num[j]) << endl;
        }
    }
    if (selec == 3)
    {
        Finder<int> v3;
        print_vector(arr_d, size);
        for (size_t i = 0; i < qnum; i++)
        {
            v3.seq_Find(arr_d, size, arr_num[i]);
        }

        Quicksort<int> qsort;
        qsort.quicksort(arr_d, 0, arr_d.size());
        print_vector(arr_d, size);
        for (size_t j = 0; j < qnum; j++)
        {
            cout << "Your number is in: " << v3.Binary(arr_d, 0, arr_d.size(), arr_num[j]) << endl;
        }
    }

    return 0;
}