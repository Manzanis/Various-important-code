#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include "ConexionesComputadora.h"
#include "Entry.h"
#include "graph.h"

using namespace std;

map<string, Graph<string>> createGraph1(set<string> dates, string ips,
map<string, ConnectPc> pcCon, map<string, int> &connect_x_day, bool (*compare)(Connection c))
{
    map<string, Graph<string>> graph_per_day;
    for (auto x = dates.begin(); x != dates.end(); x++)
    {
        connect_x_day[*x] = 0;
        Graph<string> today;
        for (auto i = pcCon.begin(); i != pcCon.end(); i++)
        {
            today.add_node(i -> first);
        }

        for (auto i = pcCon.begin(); i != pcCon.end(); i++)
        {
            string Tip = i-> first;
            ConnectPc TPc = i-> second;
            vector<Connection> ConexionesEntrantes = TPc.getConexionEntrante();
            vector<Connection> ConexionesSaliente = TPc.getConexionSaliente();
            for(size_t j=0; j < ConexionesEntrantes.size(); j++)
            {
                string ipEntr = ConexionesEntrantes[j].ip;
                string daten = ConexionesEntrantes[j].date;
                if (*x == daten && compare(ConexionesEntrantes[j]))
                {
                    today.add_edges(ipEntr, Tip);
                    if (Tip == ips)
                    {
                        connect_x_day[*x]++;//agregar linea desde ip hasta Tip 
                    }
                }
                
            }
            for(size_t j = 0; j < ConexionesSaliente.size(); j++)
            {
                string ipDes = ConexionesSaliente[j].ip;
                string daten = ConexionesSaliente[j].date;
                if (*x == daten && compare(ConexionesSaliente[j]))
                {
                    today.add_edges(Tip, ipDes);
                    if (ipDes == ips)
                    {
                        connect_x_day[*x]++;//agregar linea desde ip hasta Tip 
                    }
                }   
            }
        }
        graph_per_day[*x] = today; 
    }
    return graph_per_day;
}

bool isWeb(Connection c)
{
    
    return c.port == "465", c.port == "993", c.port == "443";
}

map<string, int> connecPerDay(string date, vector<Entry> data)
{
    map<string, int> domain;
    for (size_t i = 0; i < data.size(); i++)
    {
        if (date = data[i].date && data[i].getDesthost() != "-")
        {
            string chain = data[i].getDesthost();
            int count = chain.find_first_of(".\\");
            string name = chain.substr(count, chain.size());
            if (name != ".reto.com")
            {
                if (domain.find(chain) == domain.end())
                {
                    domain.insert(make_pair(chain, 1));
                }
                else
                {
                    domain[chain]++;
                }
                
            }
        }
    }
    return domain;
}

bool intIp(Connection c)
{
    string start = c.ip;
    string ipSrc = "192.168.173";
    for (int i = 0; i < ipSrc.size(); i++)
    {
        if (ipSrc[i] != start[i])
        {
            return false;
        }
    }
    return true;
}

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

    map<string, ConnectPc> pcCon;
    for (size_t i = 0; i < trial.size(); i++)
    {
        if (pcCon.find(trial[i].getStartip()) == pcCon.end())
        {
            ConnectPc pc(trial[i].getStartip(), trial[i].getStarthost());
            pcCon[trial[i].getStartip()] = pc;
        }
         if(pcCon.find(trial[i].getDestip()) == pcCon.end())
         {
            ConnectPc pc(trial[i].getDestip(), trial[i].getDesthost());
            pcCon[trial[i].getDestip()] = pc;
        }
    }
    for(size_t i=0; i<trial.size(); i++)
    {
        string StIp = trial[i].getStartip();
        string DestIp = trial[i].getDestip();
        string StPort = trial[i].getStartport();
        string DestPort = trial[i].getDestport();
        string days = trial[i].getDate();
        pcCon[StIp].insertarConexionSaliente(days, DestIp, StPort);
        pcCon[DestIp].insertarConexionEntrante(days, StIp, DestPort);
    }


    set<string> Source;
    set<string> Destiny;
    set<string> Dates;
    set<string> Allips;
    map<string,int> Con_Per_Day; 

    int i = 0;
    while (i < trial.size())
    {
        if(trial[i].getDate() != "" && Dates.find(trial[i].getDate()) == Dates.end())
        {
            Dates.insert(trial[i].getDate());
        }
        i++;
    }

    string A = "92.168.173.135";
    string B = "6.133.208.47";
    string C = "204.112.53.96";

    //1.

    map<string,Graph<string> > graph_x_day = createGraph1(Dates, A, pcCon,Con_Per_Day, intIp);
    for(auto i = graph_x_day.begin(); i != graph_x_day.end(); i++)
    {
        string it_date = i -> first;
        Graph<string> it_graph=i->second;
        cout << "Date: " << it_date << endl;

        int MaxAdjacent = 0;
        string ipMax="None";

        for (auto j = pcCon.begin(); j != pcCon.end(); j++){
            if(it_graph.vecinos(j -> first) > MaxAdjacent){
                MaxAdjacent = it_graph.vecinos(j -> first);
                ipMax = j -> first;
            }
        }
        cout << "The ip with the most adjacent nodes is: " << ipMax << endl;
        cout << "A had " << it_graph.vecinos(A) << " adjacent nodes"<<endl;
        cout << endl;

    }

    //2.

    cout << "A's connections per day" << endl;

    for(auto i=Con_Per_Day.begin(); i != Con_Per_Day.end(); i++)
    {
    
        cout << i->first << " : " << i->second << endl;
    }
    cout<<endl;

    //3.

    map<string,Graph<string>> Web_graphs = createGraph1(Dates, B, pcCon, Con_Per_Day, isWeb);
    cout << "B's daily connections" << endl;
    for(auto i = Con_Per_Day.begin(); i != Con_Per_Day.end(); i++){
    
        cout << i -> first << " : " << i -> second << endl;
    }
    cout<<endl;

    //4. 

    map<string,Graph<string>> C_graph = createGraph1(Dates, C, pcCon, Con_Per_Day, isWeb);
    cout << "C's daily connections" << endl;
    for(auto i = Con_Per_Day.begin(); i != Con_Per_Day.end(); i++){
        cout << i -> first << " : " << i -> second << endl;
    }
    cout<<endl;
}