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
        Entry() = default;

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

        string getSecondDate()
        {
            if (date == "11-8-2020")
            {
                return date;
            }
        }

        string getPcName()
        {
            if (hostF == "jeffrey.reto.com" || hostF == "betty.reto.com"  || hostF == "katherine.reto.com" || hostF == "scott.reto.com" || hostF == "benjamin.reto.com" ||
                hostF == "samuel.reto.com" || hostF == "raymond.reto.com")
                {
                    return hostF;
                }
        }

        string getCompanyServer()
        {
            if (sIp == "192.168.173.44")
            {
                return sIp;
            }
        }

        string getServerIp()
        {
            if (hostF == "server.reto.com")
            {
                return hostF;
            }
        }

        string getDestinyPort()
        {
            int value = stoi(dPort);
            if(value < 1000)
            {
                return dPort;
            }
        }

        string getHostDirection()
        {
            return hostD;
        }

        template <typename T>
        void seqSearch(string value, vector <T> arr, bool (*compare)(T &a, string &value))
        {
            int count = 0;
            for(size_t i = 0; i < arr.size(); i++)
            {
                if(arr[i].getSecondDate() > value)
                {
                    break;
                }
                if(arr[i].getDestinyPort() == value)
                {
                    cout << "At a port below 1000, " << arr[i].getDestinyPort() << ", at position " << i << " you can find the site entered: " << arr[i].getHostDirection() << endl;
                    break;
                }   
                if((*compare)(arr[i], value))
                {
                    count++;
                }
            }
            return count;
        }
};