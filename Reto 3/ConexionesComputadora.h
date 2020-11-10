#ifndef _CONEXION_COMPU_H_
#define _CONEXION_COMPU_H_

#include <stddef.h>
#include <queue>
#include <stack>
#include <iostream>

using namespace std;

class ConnectPc
{
    private:
        string Ip, Nombre;
        stack<string> ConexionesEntrantes;
        queue<string> ConexionesSalientes;
    
    public:
        ConnectPc() = default;

        ConnectPc(string ip, string name, stack<string> recieveConect, queue<string> throwConect)
        {
            Ip = ip;
            Nombre = name;
            ConexionesEntrantes = recieveConect;
            ConexionesSalientes = throwConect;
        }

        string getIp()
        {
            return Ip;
        }

        stack<string> getStack()
        {
            return ConexionesEntrantes;
        }

        queue<string> getQueue()
        {
            return ConexionesSalientes;
        }

        /*void print()
        {
            cout << "The user's IP is: " << Ip << endl;
            cout << "\nThe user's hostname is: " << Nombre << endl;
            cout << endl;
        }*/
};


#endif