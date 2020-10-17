#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <iostream>

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

        string getStartip()
        {
            return sIp;
        }

        string getStartport()
        {
            return sPort;
        }


        string getDestip()
        {
            return dIp;
        }

        string getDestport()
        {
            return dPort;
        }
};

#endif