#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#pragma once
using namespace std;

class Entry
{
    protected:
        string date, hour, sIp, sPort, hostF, dIp, dPort, hostD;
        int dateNum;

    public:
        Entry() {};
        ~Entry() {};

        Entry(string date, string hour, string sIp, string sPort, string hostF, string dIp, string dPort, string hostD)
        {
            this -> date = date;
            this -> hour = hour;
            this -> sIp = sIp;
            this -> sPort = sPort;
            this -> hostF = hostF;
            this -> dIp = dIp;
            this -> dPort = dPort;
            this -> hostD = hostD;
        }    

        string getHostName(Entry &a)
        {
            if (a.dIp == "192.168.173.178")
            {
                return a.hostD;
            }
            else
            {
                return "Not found";
            }
            
        } 
};

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
class Quicksort : public Sorter<T>
{
    public:
    Quicksort() = default;

    void sort(std::vector<T> &arr)
    {
        quicksort(arr, 0, arr.size() - 1);
    }

    void quicksort(std::vector<T> &arr, int low, int high)
    {
        if (low < high)  
        {  
            int pi = partition(arr, low, high);  
    
            quicksort(arr, low, pi - 1);  
            quicksort(arr, pi + 1, high);  
        }  
    }

    int partition (std::vector<T> &arr, int low, int high)
    {  
        T pivot = arr[high]; 
        int i = (low - 1);   
      
        for (int j = low; j <= high - 1; j++)  
        {  
            if (arr[j] < pivot)  
            {  
                i++;
                Sorter<T>::Swap(i, j, arr);
            }  
        }  
        Sorter<T>::Swap(i+1, high, arr);
        return (i + 1);  
    }
};

string intUrl(string sIp)
{
    int huh;
    huh = sIp.find_last_of(".\\");
    string totalip = sIp.substr(0, huh);
    string zero = ".0";
    string tip = totalip + zero;
    cout << "Internal company ip: " << tip << endl;
    cout << endl;
    return tip;
}

string comp_Dip(string a, string b)
{
    if (a < b)
    {
        return "-";
    }
    else
    {
        return a;
    }
    
}

template <typename T>
class Search : Entry
{
    protected:
        bool compDate(Entry &a, string date)
        {
            return a.date == date;
        }

        bool compName(Entry &a, string name)
        {
            return a.hostF == name;
        }

        bool compDip(Entry &a, string ip)
        {
            return a.dIp = ip;
        }

        bool compSip(Entry &a, string starter)
        {
            string m = intUrl(a.sIp)
            return m == starter;
        }
    
    public:
        Search() = default;

        int dateSeqSearch(vector<T> arr, string a)
        {
            int counter = 0;
            for (size_t i = 0; i < arr.size(); i++)
            {
                bool rito = compDate(arr[i], a);
                if (rito == true)
                {
                    counter ++;
                }
            }
            
        }

        string nameSeqSearch(vector<T> arr, string a)
        {
            string idfk;
            for (size_t i = 0; i < arr.size(); i++)
            {
                bool rito = compName(arr[i], a)
                if (rito == true)
                {
                    idfk = "Found";
                    return idfk;
                }
                
            }
            idfk = "Not found";
            return idfk; 
        }

        void dipSeqSearch(vector<T> arr, string a)
        {
            int counter;
            for (size_t i = 0; i < arr.size(); i++)
            {
                bool rito = compDip(arr[i], a);
                if (rito == true)
                {
                    counter ++;
                }
            }
            cout << "How many destiny ip are: " << counter << endl;
        }

        void sipSeqSearch(vector<T> arr, string a)
        {
            int counter;
            bool rito = compSip(arr[2], a);

            if (rito == true)
            {
                cout << "No line" << endl;
            }
            
        }
};

#endif