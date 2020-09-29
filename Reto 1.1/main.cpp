#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Entry.h"

using namespace std;

template <typename T>
void print_vector(vector<T> arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
    cout << endl;
}


int main()
{
  ifstream bitacora_txt("equipo12.txt");
  stringstream ss;
  vector<Entry> trial;
  string date, hour, sIp, hostF, dIp, hostD;
  int sPort, dPort;
  char delim = ',';
  string linea, valor, everthng;
  int nd;

  while(getline(bitacora_txt, linea))
  {
    Entry e;
    stringstream ss(linea);
    nd = 0;

    while(getline(ss, valor, delim))
    {
      if(nd == 0)
      {
        e.date = valor;
      }
      if(nd == 1)
      {
        e.hour = valor;
      }
      if(nd == 2)
      {
        e.sIp = valor;
      }
      if(nd == 3)
      {
        e.sPort = valor;
      }
      if(nd == 4)
      {
        e.hostF = valor;
      }
      if(nd == 5)
      {
        e.dIp = valor;
      }
      if(nd == 6)
      {
        e.dPort = valor;
      }
      if(nd == 7)
      {
        e.hostD = valor;
      }

      nd ++;
    }

    trial.push_back(e);
  }

  //1. 
  cout << endl;
  cout << "There are " << trial.size() << " data." << endl;
  cout << endl;

  //2.
  Search<Entry> idk;
  cout << "There are " << idk.dateSeqSearch(trial, "11-8-2020") << " instances in the second date.\n" << endl;

  //3.
  cout<<"Jeffrey's PC: " << idk.nameSeqSearch(trial, "jeffrey.reto.com") << endl;
  cout<<"Betty's PC: " << idk.nameSeqSearch(trial, "betty.reto.com") << endl;
  cout<<"Katherine's PC: " << idk.nameSeqSearch(trial, "katherine.reto.com") << endl;
  cout<<"Scott's PC: " << idk.nameSeqSearch(trial, "scott.reto.com") << endl;
  cout<<"Benjamin's PC: " << idk.nameSeqSearch(trial, "benjamin.reto.com") << endl;
  cout<<"Samuel's PC: " <<  idk.nameSeqSearch(trial, "samuel.reto.com") << endl;
  cout<<"Raymond's PC: " << idk.nameSeqSearch(trial, "raymond.reto.com") << endl;
  cout << endl;

  //4.

  idk.sipSeqSearch(trial, "-");

  //5.

  cout << "Server computer: " << idk.nameSeqSearch(trial, "server.reto.com") << endl;
  cout << endl;

  //6.

  cout << "The mail service is called: freemailserver.com" << endl;
  cout << endl;

  //7.
  vector<string> destiny2;
  string n;
  for (size_t i = 0; i < trial.size(); i++)
  {
    n = trial[i].dPort;
    destiny2.push_back(n);
  }
  
  vector<int> chikito;
  for (size_t i = 0; i < destiny2.size(); i++)
  {
    string g = comp_Dip(destiny2[i], "1000");
    
    if (g != "-")
    { 
      int k = stoi(g);
      chikito.push_back(k);
    }
    i++;
  }
  
  Quicksort<int> idfk;

  idfk.quicksort(chikito, 0, chikito.size());
  cout << "Destiny ports that are less than 1000: " << endl;
  print_vector(chikito);
}