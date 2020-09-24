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
        
        void separateDate(string d, string day, string month, string year)
        {
            stringstream ss (d);
            string valor;
            char delim = '-';
            int nd = 0;

            while(getline(ss, valor, delim))
            {
                if(nd == 0)
                {
                    day = valor;
                }
                if(nd == 1)
                {
                    month = valor;
                }
                if(nd == 2)
                {
                    year = valor;
                }
            }

        }

        int convertYear(string year)
        {
            int año = (year == "2020") ? 20 : 0;
            return año;
        }
        
        int datetoNum(string cal)
        {
            string day, month, year;
            separateDate(cal, day, month, year);
            int año = convertYear(year);
            int dia = stoi(day);
            int mes = stoi(month);

            return año + dia + (mes * 100);
        }

        Entry(string date, string hour, string sIp, string sPort, string hostF, string dIp, string dPort, string hostD)
        {
            this -> date = date;
            dateNum = datetoNum(date);
            this -> hour = hour;
            this -> sIp = sIp;
            this -> sPort = sPort;
            this -> hostF = hostF;
            this -> dIp = dIp;
            this -> dPort = dPort;
            this -> hostD = hostD;
        }
};