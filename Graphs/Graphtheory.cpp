#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<map>
#include<unordered_map>
#include<climits>
#include<string>
#include<set>
#define pb push_back
#define mp make_pair
#define w(x) int x; cin>>x; while(x--)
#define setbits(x) __builtin_popcount(x)
#define inf INT_MAX

/*
class Graph
{
    int v;
    vector<list<int>> l;
    public :
    Graph(int v)
    {
        this->v = v;
    }
    void AddEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printGraph()
    {
        for(int i = 0; i<l.size(); i++)
        {
            cout<<i<<"->"<<" ";
            for(auto c : l[i])
                cout<<c<<",";
            
            cout<<endl;
        }
    }
    
};
class Graph2
{
    int v;
    unordered_map<string,list<pair<string,int>>> m;
    public :
    void AddEdge(string source, string destination, int weight, bool isbidirectional)
    {
        m[source].push_back(make_pair(destination,weight));
        if(isbidirectional)
            m[destination].push_back(make_pair(source,weight));
    }
    void showgraph()
    {
        for(auto it : m)
        {
            cout<<"Source : -> "<<it.first<<" ";
            for(auto c : it.second)
            {
                cout<<c.first<<" "<<c.second<<",";
            }
            cout<<endl;
        }
    }
};
*/
// Graph Traversals
// The standard breadth first search and depth first search
//
class Graph
{
    // A bfs is similar to a level order traversal of a queue and it shall be done in the following manner;
    // What are the neighbours of 0 and once you put it in the queue you mark it as visited;
    int v;
    public :
    unordered_map<int,list<int>> l; // This shall be used, an adjacency list to store all the elements of the graph;
    public :
    Graph(int v)
    {
        this->v = v;
    }
    Graph()
    {
        
    }
    void Addedge(int s, int d)
    {
        l[s].pb(d);
        l[d].pb(s);
    }
    void bfs(int s)
    {
        vector<bool> visited(v+1,false); // this shall be done using this.
        // We can also make a boolean map
        //unordered_map<int,bool> visited;
        // this map can be used to store if there are certain values in the node class pair.
        queue<int> q;
        q.push(s);
        visited[s] = true;
        while(!q.empty())
        {
            
            int cn = q.front();
            q.pop();
            for(auto it : l[cn])
            {
                 if(!visited[it])
                 {
                     q.push(it);
                 }
            }
        }
        return;
    }
    void depthfirstsearch(int sv, map<int,bool> &visited)
    {
        // Base cases
        // Dont need a base case for the recursion.
        
        cout<<sv<<" ";
        visited[sv] = true;
        list<int> adjacentnodes = l[sv];
        for(auto neighbour : adjacentnodes)
        {
             if(!visited[neighbour])
             {
                 depthfirstsearch(neighbour,visited); // Call the recurusive depth first search algorithm on the neighbours;
             }
        }
        return;
    }
    void dfs(int sv)
    {
        // Recursive algorithm;
        // Base case;
        map<int,bool> visited;
        for(auto it : l)
            visited[it.first] = false;
      
        depthfirstsearch(sv,visited);
        return;
    }
    int shortestpath(int sv, int dv)
    {
        //map<int,bool> visited;
        // Otherwise you can take a map to store the distances;
        map<int,int> distance;
        queue<int> q;
        q.push(sv);
        distance[sv] = 0;
        for(auto it : l)
        {
            distance[it.first] = inf;
        }
        distance[sv] = 0;
        while(!q.empty())
        {
            int currentnode = q.front();
            q.pop();
            list<int> adjacentnodes = l[currentnode];
            for(auto children : adjacentnodes)
            {
                if(distance[children]==inf)
                {
                    q.push(children);
                    distance[children] = distance[currentnode] + 1; // Unweighted graph;
                }
            }
        }
        return distance[dv];
    }
    // How to find the no of connected components using a depth first search
    int NoofconnectedComponents()
    {
        int components = 0;
        map<int,bool> visited;
        for(auto it : l)
            visited[it.first] = false;
        int sv = 0;
        // Finding out first source vertex;
        bool allvisited = false;
        while(!allvisited)
        {
        for(auto it = visited.begin(); it !=visited.end(); it++)
        {
             if(it->second == false)
             {
                 sv = it->first;
                 break;
             }
            if(it==visited.end())
            {
            allvisited = true;
            }
        }
            components+=1;
            depthfirstsearch(sv,visited);
        }
        return components;
    }
   void getmecomponents(int sv, map<int,bool> &visited,int &res)
    {
        visited[sv] = true;
        res+=1;
        for(auto adjacentnodes : l[sv])
        {
            if(!visited[adjacentnodes])
            {
            getmecomponents(adjacentnodes,visited,res);
            }
        }
    }
   bool doescycleexist(int sv, map<int,bool> &visited, map<int,int> &parent)
    {
        
        visited[sv] = true;
        // Fill the parent map;
        for(auto adjacentnode : l[sv]) // for all the adjacent nodes.
        {
            parent[adjacentnode] = sv; // Declare the parent;
        }
        // DFS recursive calls.
        for(auto adjacentnode : l[sv])
        {
            if(!visited[adjacentnode])
            {
            bool containscycle = doescycleexist(adjacentnode,visited,parent);
            if(containscycle)
                return true;
            }
            else if(parent[adjacentnode] != sv)
                return true;
        }
        return false;
    }
    // To check if a graph is a bipartite graph or not
    /*
     A bipartitie graph is a graph that can be divided in 2 sets such that all the nodes with no adjacent edge are in the same set.
     Set s1 and set s2 and then all the edges are only between nodes from s1 to s2 or s2 to s1 and never from s1 to s1 or s2 to s2.
     A tree can also be considered as a bipartite graph with alternate levels in the same set.
     The Chromatic number of a bipartite graph is 2.
     */
   bool Detectcycle(int sv)
    {
        
        map<int,bool> visited;
        map<int,int> parent;
        parent[sv] = -1; // Just initialise that there is no parent for this starting vertex.
        // Initialisation of the visited map for the particular graph.
        for(auto m : l)
        {
            visited[m.first] = false;
            for(auto nbr : m.second)
            {
                visited[nbr]  = false;
            }
        }
        return doescycleexist(sv,visited,parent);
    }
    
};
