#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include "bst.h"
#include "ConexionesComputadora.h"
#include "Entry.h"

using namespace std;

map<string, int> conexionesPorDia(string date, vector<Entry> arr)
{
    map<string, int> domXdate;
    int d = 0;

    while (d < arr.size())
    {
        if (date == arr[d].getDate())
        {
            if (arr[d].getDesthost() != "-")
            {
                string conn = arr[d].getDesthost();
                int f = conn.find_first_of(".\\");
                string newHost = conn.substr(f, conn.size());

                if (newHost != ".reto.com")
                {
                    if (domXdate.find(conn) == domXdate.end())
                    {
                        domXdate.insert(make_pair(conn, 1));
                    }
                    if (domXdate.find(conn) != domXdate.end())
                    {
                        domXdate[conn] ++;
                    }
                }
            }
        }
    }
    d ++;
    return domXdate;
}

bool compares(const pair<string, int> &primElem, const pair<string, int> &secElem)
{
    return primElem.second > secElem.second;
}

void top(int n, string date, map<string, int> domXdate)
{
    BinarySearchTree<pair<string, int>> tree;
    map<string, int>::iterator huh = domXdate.begin();
    vector<pair<string, int>> idk;

    while (huh != domXdate.end())
    {
        tree.insert_node_recursive(make_pair(huh -> first, huh -> second));
        idk.push_back(make_pair(huh -> first, huh -> second));
        huh ++;
    }
    for (size_t i = 0; i < n && i < idk.size(); i++)
    {
        cout << idk[i].first << ": " << idk[i].second << endl;
    } 
    cout<<endl;
}

int main()
{
    //Tocó cambiarlo porque solo servía con archivos .txt se obtuvo el error: terminate called after throwing an instance of 'std::out_of_range'
                                                                              //what():  basic_string::substr: __pos (which is 18446744073709551615) > this->size() (which is 2)
                                                                              //Aborted (core dumped)

                                                                              //Al hacer uso de este metodo
    /*ifstream bitacora_txt("nuevo12.txt");
    stringstream ss;
    char delim = ',';
    string linea, valor;
    int nd;

    //Lectura de archivo y guardado de datos en un vector.
    while(getline(bitacora_txt, linea))
    {
        stringstream ss(linea);
        nd = 0;

        while(getline(ss, valor, delim))
        {
            if (nd == 0)
            {
                date = valor;
            }
            if (nd == 1)
            {
                hour = valor;
            }
            if(nd == 2)
            {
                sIp = valor;
            }
            if(nd == 3)
            {
                sPort = valor;
            }
            if(nd == 4)
            {
                hostF = valor;
            }
            if(nd == 5)
            {
                dIp = valor;
            }
            if(nd == 6)
            {
                dPort = valor;
            }
            if(nd == 7)
            {
                hostD = valor;
            }
            nd ++;
        }
        Entry holder(date, hour, sIp, sPort, hostF, dIp, dPort, hostD);
        trial.push_back(holder);
    }*/

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
    
    int i = 0;
    set<string> fecha;

    while (i < trial.size())
    {
        fecha.insert(trial[i].getDate());
        i ++;
    }

    set<string>::iterator it = fecha.begin();
    while (it != fecha.end())
    {
        map<string, int> domXdate = conexionesPorDia(*it, trial);
        top(5, *it, domXdate);
        it ++;
    }
}