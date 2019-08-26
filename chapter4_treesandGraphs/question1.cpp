//path between 2 nodes of a graph
//check if it exists or not

#include<bits/stdc++.h>

class edge{
    public:
    int src,dest;
};

class graph{
    public:
    std::vector<std::vector<int>> adjList;

    graph(std::vector<edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge :edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    } 
};
void printGraph(graph const& g, int n)
{
    for (int i = 0; i< n;i++)
    {
       std::cout << i << "-->"; 
         for (int v:g.adjList[i])
         std::cout << v<<'\n';
    }   
}

bool isReachable(const graph &g, int src,int dest,std::vector<bool>  &discovered )
{
    std::queue<int> q;
    discovered [src] = true;
    //push src in queue
    q.push(src);

    while(!q.empty())
    {
        int v = q.front();
        q.pop();
         //if dest is found;
        
        if (v == dest)
        {
            return true;
        }
        for (int u : g.adjList[v])
        {
            if (!discovered[u])
            {
                discovered[u] = true;
                q.push(u);
            }
        } 
    }
    return false;
}  

int main()
{
    //std::merge edges, do count unique to count edges of nodes
    //wont work, visit all and make a counter
    std::vector<edge> edges =  {
       {0, 3}, {1, 0}, {1, 2}, {1, 4}, {2, 7}, {3, 4},
		{3, 5}, {4, 3}, {4, 6}, {5, 6}, {6, 7}
    };
    //nodes
    int N = 8;

	// create a graph from given edges
	graph g(edges, N);

	// stores vertex is discovered or not
	std::vector<bool> discovered(N);

	// source and destination vertex
	int src = 0, dest = 1;

	// perform DFS traversal from the source vertex to check the connectivity
	// and store path from the source vertex to the destination vertex
	if (isReachable(g, src, dest, discovered))
	{
		std::cout << "Path exists from vertex " << src << " to vertex " << dest;
		
	}
	else {
		std::cout << "No path exists between vertices " << src << " and " << dest;
	}
}

