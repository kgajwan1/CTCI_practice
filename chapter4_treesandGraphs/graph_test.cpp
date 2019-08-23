#include <bits/stdc++.h>

struct edge{
    int src,dest;
};

typedef std::pair<int,int> Pair;

class weighted_edge{
    public:
    int src,dest,weight;
};
//non weighted
class Graph
{
    public:
    std::vector<std::vector<int>> adjlist; 
    Graph(std::vector<edge> const &edges, int n)
    {
        adjlist.resize(n);
        for (auto &edge:edges)
        {
            adjlist[edge.src].push_back(edge.dest);
           // adjlist[edge.dest].push_back(edge.src);
        }
    } 
};

class weightedGraph{
    public:
    std::vector<std::vector<Pair>> adjlist; 
    weightedGraph(std::vector<weighted_edge> const &edges, int n)
    {
        adjlist.resize(n);
        for (auto &edge:edges)
        {
            adjlist[edge.src].push_back(std::make_pair(edge.dest,edge.weight));
        }
    } 
};
void printGraph(Graph const& graph, int n)
{
    for (int i = 0; i< n;i++)
    {
        std::cout << i << "-->"; 
         for (int v:graph.adjlist[i])
         std::cout << v<<'\n';
    }
   
}

void printweighted_Graph(weightedGraph const& graph, int n)
{
    for (int i = 0; i< n;i++)
    {
       
         for (Pair v : graph.adjlist[i])
            std::cout <<"("<< i <<"," <<v.first<<","<<v.second<<")"<<'\n';
    }
   
}
int main()
{
    std::vector <edge> edges  ={
        {0,1},{1,2},{2,0},{2,1},{3,2},{4,5},{5,4}
    };
    std::vector <weighted_edge> edges2  ={
        {0,1,6},{1,2,7},{2,0,5},{2,1,4},{3,2,10},{4,5,1},{5,4,3}
    };
    int n = 6;
    Graph graph(edges,n);
    printGraph(graph,n);
    weightedGraph graph2(edges2,n);
    printweighted_Graph(graph2,n);
}