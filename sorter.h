#ifndef sorter_h
#define sorter_h

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Sorter
{
    public:
        Sorter() {};
        ~Sorter() {};

        void Swap(int i, int j, vector<T> &arr)
        {
            T aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }

        virtual void sort(vector<T> &arr) {};
};

template <typename T>
class SelectionSort : Sorter<T>
{
    public:
        SelectionSort() {};
        ~SelectionSort() {};

        void Sort(vector<T> &arr)
        {
            for (size_t i = 0; i < arr.size() - 1; i++)
            {
                size_t min = i;
                for (size_t j = i+1; j < arr.size(); j++)
                {
                    if(arr[j] < arr[min])
                    {
                        min = j;
                    }
                }
                Sorter<T>::Swap(i, min, arr);
                
            }
            
        }
};

/*template <typename T>
class BubbleSort : Sorter<T>
{
    public:
        BubbleSort() {};
        ~BubbleSort() {};

        void Sort_B(vector<T> &arr)
        {
            
        }
};*/

#endif