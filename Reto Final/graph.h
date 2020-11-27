#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <list>
#include <limits>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

template <class T>
class GraphVertex
{
    private:
        T val;
        vector<int> adj;
    
    public:
        GraphVertex() = default;

        GraphVertex(T _val) {val = _val;} 

        T get_val() {return val;}
        void set_val(T _val) {val = _val;}

        vector<int> get_adj() {return adj;}
        void add_to_adj(int idx) {adj.push_back(idx);}
        friend bool operator == (GraphVertex<T> a, GraphVertex<T> b)
        {
            return a.get_val()==b.get_val();
        }
};

template <class T>
class Graph
{
    private:
        vector<GraphVertex<T>> nodes;
        bool is_directed;
    
    public:
        ~Graph() {};
        Graph() {is_directed = false;}

        void add_node(T val)
        {
            GraphVertex<T> node(val);
            nodes.push_back(node);
        }

        void add_edges(int src, int dst)
        {
            nodes[src].add_to_adj(dst);
            if (!is_directed)
            {
                nodes[dst].add_to_adj(src);
            }
        }

        void add_edges(T src, T dst)
        {
            GraphVertex<T> src_vertex(src);
            GraphVertex<T> dst_vertex(dst);
            auto s=find(nodes.begin(), nodes.end(), src_vertex);
            auto d=find(nodes.begin(), nodes.end(), dst_vertex);
            if(s != nodes.end() && d != nodes.end())
            {
                int src_index=s-nodes.begin();
                int dst_index=d-nodes.begin();
                add_edges(src_index, dst_index);
            }
        }

        int vecinos(T v)
        {
            GraphVertex<T> v_vertex(v);
            auto s=find(nodes.begin(), nodes.end(), v_vertex);
            if(s != nodes.end())
            {
                int index=s-nodes.begin();
                return nodes[index].get_adj().size();
            }
            return 0;
        }

        void BFS(int start_vertex)
        {
            vector<bool> visitados(nodes.size(), false);
            queue<int> queue;

            visitados[start_vertex] = true;
            queue.push(start_vertex);

            while (!queue.empty())
            {
                int s = queue.front();
                cout << nodes[s].get_val() << " ";

                queue.pop();
                for (vector<int>::iterator i = nodes[s].get_adj().begin(); i != nodes[s].get_adj().end(); i++)
                {
                    if (!visitados[*i])
                    {
                        queue.push(*i);
                        visitados[*i] = true;
                    }
                }
            }
            cout<<endl;
        }

        void DFS(int start_vertex)
        {
            vector<bool> visitados(nodes.size(), false);
            stack<int> stack;
            stack.push(start_vertex);

            while (!stack.empty())
            {
                int s = stack.top();
                stack.pop();
                if (!visitados[s])
                {
                    visitados[s] = true;
                    cout << nodes[s].get_val() << " ";

                    for (vector<int>::iterator i = nodes[s].get_adj().begin(); i != nodes[s].get_adj().end(); i++)
                    {
                        if (!visitados[*i])
                        {
                            stack.push(*i);
                        }
                    }
                }
            }
            cout<<endl;
        }
};

template <class T>
class GraphVertexWeighted
{
private:
    T val;
    std::vector<std::pair<int, float> > adj;
public: 
    ~GraphVertexWeighted() {};
    GraphVertexWeighted() {};
    GraphVertexWeighted(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<std::pair<int, float>> get_adj() {return adj;};
    void add_to_adj(int idx, float weight) {adj.push_back(std::make_pair(idx, weight));};
};


template <class T>
class GraphWeighted
{
    private:
        vector<GraphVertexWeighted<T> > nodes;
        bool is_directed;

    public:
        ~GraphWeighted() {};
        GraphWeighted() {is_directed=false;};

        void add_node(T val)
        {
            GraphVertexWeighted<T> node(val);
            nodes.push_back(node);
        }

        void add_edge(int src, int dst, float weight)
        {
            nodes[src].add_to_adj(dst, weight);
            if (!is_directed)
                nodes[dst].add_to_adj(src, weight);
        }

        T get_node_val(int i)
        {
            return nodes[i].get_val();
        }

    vector<float> shortest_path(int s)
    {
        vector<bool> sure;
        vector<float> distances;
        bool unsure_nodes=true;
        int u=0;
        float min=numeric_limits<float>::infinity();
        for(int i=0;i<nodes.size(); i++)
        {
            sure.push_back(false);
            distances.push_back(numeric_limits<float>::infinity());
        }

        distances[s]=0;

        while (unsure_nodes)
        {
            u = 0;
            min = numeric_limits<float>::infinity();
            for (int i = 0; i < nodes.size(); i++)
            {
                if (sure[i]==false)
                {
                    if (distances[i]<min)
                    {
                        min=distances[i];
                        u=i;
                        
                    }
                }
            vector<pair< int,float > > vecinos;
            vecinos=nodes[u].get_adj();

            for (int v = 0; v < nodes[u].get_adj().size(); v++)
            {
                float dist=0;
                dist=std::min(distances[v],distances[u]+vecinos[v].second);
                distances[vecinos[v].first]=dist;
            }
            sure[u]=true;


            unsure_nodes=false;

            for (int  j = 0; j < sure.size(); j++)
            {
                if (sure[j]==false)
                {
                    unsure_nodes=true;
                }
                
            }
                
            }    

        }
        return distances;
    }        
};

#endif