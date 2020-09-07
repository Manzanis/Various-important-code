#ifndef sorter_h
#define sorter_h

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Sorter
{
    public:
        Sorter() = default;

        void Swap(int i, int j, vector<T> &arr)
        {
            T aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }

        virtual void Sort(vector<T> &arr) {};
};

template <typename T>
class SelectionSort : Sorter<T>
{
    public:
        SelectionSort() = default;

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

template <typename T>
class BubbleSort : Sorter<T>
{
    public:
        BubbleSort() = default;

        void Sort_B(vector<T> &arr)
        {
            for (size_t i = 0; i < arr.size(); i++)
            {
                bool no_swap = true;
                for (size_t j = 0; j < arr.size() - i-1; j++)
                {
                    if (arr[j] > arr[j+1])
                    {
                        Sorter<T>::Swap(j, j+1, arr);
                        no_swap = false;
                    }
                }
                if (no_swap)
                {
                    break;
                }
            }
            
        }
};

template <typename T>
class InsertSort : Sorter<T>
{
    public:
        InsertSort() = default;

        void Sort_Ins(vector<T> &arr)
        {
            T key;
            for (size_t i = 1; i < arr.size(); i++)
            {
                key = arr[i];
                int j = i - 1;

                while (j >= 0 && arr[j] > key)
                {
                    arr[j+1] = arr[j];
                    j--;
                }
                arr[j+1] = key;
            }
            
        }

};

template <typename T>
class MergeSort : Sorter<T>
{
    public:
        MergeSort() = default;

        void Sort(vector<T> &arr)
        {
            Sort_Merge(arr, 0, arr.size() - 1);
        }

        void Sort_Merge(vector<T> &arr, int l, int r)
        {
            if (l < r)
            {
                int m = l + (r-l) / 2;

                Sort_Merge(arr, l, m);
                Sort_Merge(arr, m+1, r);

                Merge(arr, l, m, r);
            }
        }
        void Merge(vector<T> &arr, int l, int m, int r)
        {
            int arr1 = m - l + 1; 
            int arr2 = r - m;
            
            int O[arr1], S[arr2]; 

            for (size_t i = 0; i < arr1; i++)
            {
                O[i] = arr[l + i]; 
                for (size_t j = 0; j < arr2; j++)
                {
                    S[j] = arr[m + 1 + j]; 
                }

            } 

            int a = 0; 
            int b = 0; 
            int c = l; 

            while (a < arr1 && b < arr2) 
            {  
                if (O[a] <= S[b]) 
                { 
                    arr[c] = O[a]; 
                    a++; 
                } 
                else 
                { 
                    arr[c] = S[b]; 
                    b++; 
                } 
                c++; 
            } 
    
            while (a < arr1) 
            { 
                arr[c] = O[a]; 
                a++; 
                c++; 
            } 
    

            while (b < arr2)
            { 
                arr[c] = S[b]; 
                b++; 
                c++;
            } 
        }
};

#endif