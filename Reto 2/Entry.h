#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Entry
{
    private:
        string date, hour, sIp, sPort, hostF, dIp, dPort, hostD;
    
    public:
        Entry() = default;

        Entry(string daten, string hourn, string sIpn, string sPortn, string hostFn, string dIpn, string dPortn, string hostDn)
        {
            date = daten;
            hour = hourn;
            sIp = sIpn;
            sPort = sPortn;
            hostF = hostFn;
            dIp = dIpn;
            dPort = dPortn;
            hostD = hostDn;
        }

        string getDate()
        {
            return date;
        }

        string getStartport()
        {
            return sPort;
        }
};

#endif