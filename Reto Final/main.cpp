#include <iostream>
#include <vector>
#include <fstream>
#include "Entry.h"
#include "graph.h"

using namespace std;

int main()
{
    vector<Entry> trial;
    ifstream equipo12;
    equipo12.open("nuevo12.csv");
    string date, hour, sIp, sPort, hostF, dIp, dPort, hostD;
    while (equipo12.good())
    {
        getline(equipo12, date, ',');
        getline(equipo12, hour, ',');
        getline(equipo12, sIp, ',');
        getline(equipo12, sPort, ',');
        getline(equipo12, hostF, ',');
        getline(equipo12, dIp, ',');
        getline(equipo12, dPort, ',');
        getline(equipo12, hostD, '\n');
        Entry holder(date, hour, sIp, sPort, hostF, dIp, dPort, hostD); 
        trial.push_back(holder);
    }
    equipo12.close();

    
}