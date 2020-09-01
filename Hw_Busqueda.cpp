#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
#include "sorter.h"
#include "busqueda.h"

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
    srand((unsigned)time(0));

    vector<int> arr;
    int count = 100000;

    int min = 999, max = -1;  // Randomizer gracias a Stack overflow
    for (size_t i = 0; i < count; i++)
    {
        int val = (rand()%500)-200;
        if( val < min ) min = val;
        if( val > max ) max = val;   

        arr.push_back(val);
    }   

    int num;
    cout << "Type the number you want to find: ";
    cin >> num;

    Finder<int> busqueda;

    cout << "\nSequential search: " << endl;
    busqueda.seq_Find(arr, count, num);

    SelectionSort<int> sort; // Ordenamos el array
    sort.Sort(arr);

    int first = arr[0];
    int last = arr[count];

    cout << "\nSequential search O1: " << endl;
    busqueda.seq_O1(arr, count, num);

    cout << "\nSequential search O2: " << endl;
    busqueda.seq_O2(arr, count, num);

    cout << "\nBinary search: " << endl; //Por tiempo no pude resolver el bug con esta implementación
    busqueda.Binary(arr, first, last, num);

    return 0;
}