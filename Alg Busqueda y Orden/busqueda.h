#ifndef busqueda_h
#define busqueda_h

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

template <typename T>
class Finder
{
    public:
        Finder() = default;

        int seq_Find(vector<T> &arr, int n, int K)
        {
            int fail, indice;

            fail = -1;
            for (indice = 0; indice < n; indice ++)
            {
                if (K == arr[indice])
                {
                    fail = indice;
                    break;
                }
            }
            cout << "Your number is in (If -1: Not found): " << fail << endl;    
        }

        int seq_O1(vector<T> &arr, int n, int K)
        {
            int fail, indice;

            fail = -1;
            for (indice = 0; indice < n; indice ++)
            {
                if (arr[indice] > K)
                {
                    break;
                }
                
                if (K == arr[indice])
                {
                    fail = indice;
                    break;
                }
            }
            cout << "Your number is in(If -1: Not found): " << fail << endl;
        }

        int seq_O2(vector<T> &arr, int n, int K)
        {
            int fail, indice;

            fail = -1;
            for (indice = 0; indice < n; indice += 2)
            {
                if (arr[indice] > K) 
                {
                    if (arr[indice - 1] == K)
                    {
                        fail = (indice - 1);
                        break;
                    }
                    else
                    {
                        break;
                    }
                    
                }

                if (K == arr[indice])
                {
                    fail = indice;
                    break;
                }
            }
            cout << "Your number is in(If -1: Not found): " << fail << endl;
        }
        
        int Binary(vector<T> &arr, int first, int last, int K)
        {
            int fail = -1;

            if(last > first) 
            {
                int mid = first + (last - first) / 2;

                if(K == arr[mid])
                {
                    return mid;
                }
                if (K < arr[mid])
                {
                    return Binary(arr, first, mid-1, K);
                }
                else
                {
                    return Binary(arr, mid+1, last, K);  
                }
            }
            return fail;
        }
};

#endif