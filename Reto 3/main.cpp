#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "ConexionesComputadora.h"
#include "Entry.h"

using namespace std;

int main()
{
    ifstream bitacora_csv("nuevo12.csv");
    stringstream ss;
    vector<Entry> trial;
    string date, hour, sIp, sPort, hostF, dIp, dPort, hostD;
    char delim = ',';
    string linea, valor;
    int nd;

    while(getline(bitacora_csv, linea))
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
    }

    stack<string> pila, idek;
    queue<string> fila;
    vector<string> anom;
    set<string> normal;
    map<string, ConnectPc> dix;

    string Hostf, Hostd, huh, res, name, ip;
    int count, num;
    int counter = 0;

    for (size_t i = 0; i < trial.size(); i++)
    {
      Hostf = trial[i].getStarthost();
      Hostd = trial[i].getDesthost();

      count = Hostf.find_first_of(".\\");
      huh = Hostf.substr(count, Hostf.size());

      if (trial[i].getDesthost() != "-")
      {
        num = Hostd.find_first_of(".\\");
        res = Hostd.substr(num, Hostd.size());

        if (res != ".reto.com")
        {
          normal.insert(Hostd);
        }
        if (dix.find(Hostf) == dix.end())
        {
          ip = trial[i].getStartip();
          for (size_t j = 0; j < trial.size(); i++)
          {
            if (ip == trial[j].getStartip())
            {
              pila.push(trial[i].getDestip());
              name = trial[j].getStarthost();
            }
            if (ip == trial[j].getDestip())
            {
              fila.push(trial[j].getStartip());
            }
          }
          ConnectPc connect(ip, name, pila, fila);
          dix.insert(make_pair(Hostf, connect));
        }
      }

      if (huh != ".reto.com")
      {
        normal.insert(Hostf);
      }
    }

    cout << "Normal data" << endl;
    for (auto it = normal.begin(); it != normal.end(); ++it)
    {
      cout << " " << *it << "\n" << endl;
    }

    cout << "Dictionary" << endl;
    map<string, ConnectPc>::iterator in = dix.begin();
    while (in != dix.end())
    {
      cout << in -> first << " " << in -> second.getStack().size() << endl;
      in ++;
    }

    //1.
    cout << "Hay algún nombre de dominio que sea anómalo? \nSi, en nuestro caso se puede encontrar el dominio 'scgifuytklyuh951zztp.net' como uno anómalo." << endl;

    //2.
    cout << "Se puede encontrar el ip del dominio se puede hacer uso del siguiente programa: " << endl;
    for (size_t i = 0; i < trial.size(); i++)
    {
        if (trial[i].getDesthost() == "scgifuytklyuh951zztp.net")
        {
            anom.push_back(trial[i].getDestip());
            cout << "El ip de este dominio es: " << trial[i].getDestip() << endl;
        }
    }
    cout<<endl;

    //3.
    int cant = 0;

    for (auto in = dix.begin(); in != dix.end(); in++)
    {
        string i = in -> first;
        int d = i.find_first_of(".\\");
        string k = i.substr(d, i.size() - 1);
        if (k == ".reto.com")
        {
            if (in -> second.getStack().size() > 0)
            {
                cant ++;
            }
        }
    }
    cout << "La cantidad de ips con una conexión entrante (mínimo) son: " << cant << endl;
    cout<<endl;

    //4.
    set<string> ipes;

    for (auto in = dix.begin(); in != dix.end(); in++)
    {
        idek = in -> second.getStack();
        while(idek.empty() == false)
        {
            if (idek.top() != "-")
            {
                ipes.insert(idek.top());
            }
            idek.pop();
        }
    }

    cout << "Las ips de las conexiones entrantes serían: " << endl;
    for (auto it = ipes.begin(); it != ipes.end(); ++it)
    {
        cout << *it << endl;
    }

    //6
    for (auto it = ipes.begin(); it != ipes.end(); ++it)
    {
        if (*it == "6.133.208.47,965")
        {
            counter ++;
        }
    }
    if (counter > 0)
    {
        cout << "Los datos si se han comunicado con los anomalos" << endl;
    }
    else
    {
        cout << "No hubo conexión entre datos" << endl;
    }
    
}