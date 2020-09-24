#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

  while(getline(bitacora_txt, linea))
  {
    stringstream ss(linea);
    nd = 0;

    while(getline(ss, valor, delim))
    {
      if(nd == 0)
      {
        date = valor;
      }
      if(nd == 1)
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

    Entry prueba(date, hour, sIp, sPort, hostF, dIp, dPort, hostD);
    trial.push_back(prueba);
  }
}