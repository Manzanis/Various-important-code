#ifndef _CONEXION_COMPU_H_
#define _CONEXION_COMPU_H_

#include <stddef.h>
#include <queue>
#include <stack>
#include <iostream>
#include <vector>

using namespace std;

class Connection
{
    public:
        string date, ip, port;

        Connection(string fecha, string _ip, string puerto)
        {
            date = fecha;
            ip = _ip;
            port = puerto;
        }
};

class ConnectPc
{
    private:
        string Ip, Nombre;
        vector<Connection> ConexionesEntrantes;
        vector<Connection> ConexionesSalientes;
    
    public:
        ConnectPc() = default;

        ConnectPc(string _ip, string _name)
        {
            Ip =  _ip;
            Nombre = _name;
        }
        
        ConnectPc(string ip, string name, vector<Connection> recieveConect, vector<Connection> throwConect)
        {
            Ip = ip;
            Nombre = name;
            ConexionesEntrantes = recieveConect;
            ConexionesSalientes = throwConect;
        }

        vector<Connection> getConexionEntrante()
        {
            return ConexionesEntrantes;
        }

        vector<Connection> getConexionSaliente()
        {
            return ConexionesSalientes;
        }

        string getIp()
        {
            return Ip;
        }

        string getName()
        {
            return Nombre;
        }

        void insertarConexionSaliente(string ip, string fecha, string puerto)
        {
            Connection c(ip, fecha, puerto);
            ConexionesSalientes.push_back(c);
        }

        void insertarConexionEntrante(string ip, string fecha, string puerto)
        {
            Connection c(ip, fecha, puerto);
            ConexionesEntrantes.push_back(c);
        }
};


#endif