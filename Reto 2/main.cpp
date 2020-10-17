#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <queue>
#include "ConexionesComputadora.h"
#include "Entry.h"

using namespace std;

int main()
{
    ifstream bitacora_txt("equipo12.txt");
    stringstream ss;
    vector<Entry> trial;
    string date, hour, sIp, sPort, hostF, dIp, dPort, hostD;
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
    }

    stack<string> pila;
    queue<string> fila;

    //4.
    int i = 0;
    string searchip = "-";
    
    while(searchip == "-")
    {
        searchip = trial[i].getStartip();
        i++;
    }

    int j = searchip.find_last_of(".\\");
    string resIp = searchip.substr(0, j);
    string Createip;
    cout << "Insert a number between 1 and 150 to generate an IP: " << endl;
    cin >> Createip;
    cout << endl;

    string sum = resIp + "." + Createip; //Se suma lo encontrado en el resultado del Ip y lo generado por el numero dado por el usuario para así devolver una ip generada.

    cout << "Your generated IP is: " << sum << endl;
    cout << endl;

    int idk = 0;
    string name;
    while (idk != trial.size())
    {
        if (sum == trial[idk].getStartip())
        {
            fila.push(trial[idk].getDestip());
            name = trial[idk].getStartport(); //Dependiendo de que se encuentre en el vector se devuelven los valores de la ip inicial, final, puerto inicial o final
        }
        if (sum == trial[idk].getDestip())
        {
            pila.push(trial[idk].getStartip());
        }

        idk ++;
    }

    cout << "----------------------------------------\n" << endl;

    //7.1
    ConnectPc connect(sum, name, pila, fila);
    connect.print();

    int idek = connect.getStack().top().find_last_of(".\\");
    string resip = connect.getStack().top();

    //7.2
    cout << "The last known IP is: "  << resip << endl;
    string resipt = connect.getStack().top().substr(0, idek); //Se busca en el primer valor de la pila con respecto a lo encontrado en el ultimo valor de la pila

    if(resipt == resIp)
    {
        cout << "Previous connection is internal. \n" << endl;
    }
    else
    {
        cout << "Previous connection is external." << endl;
    }

    //7.3
    cout << "There are " << pila.size()<< " incoming connections. \n" << endl;

    //7.4
    cout << "There are " << fila.size()<< " outgoing connections. \n" << endl;

    //7.5 (EXTRA)
    while(connect.getStack().empty() == false)
    {
       string idefk = connect.getStack().top();
       connect.getStack().pop();
       string ffs = connect.getStack().top();

       if(idefk == ffs)
       {
           connect.getStack().pop();
           string huh = connect.getStack().top();
           if (huh == ffs)
           {
               cout << "This pc does have 3 connections in a row to the same website. \n" << endl;
               break;
           }
       }
       else
       {
           break;
       }
       
    } 


    return 0;
}