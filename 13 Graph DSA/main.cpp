#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

class Graph {
    int V; // vertices / nodes
    list<int> *l; // pointer of interger list

    public:
    Graph(int data){
        this->V = data;
        l = new list<int>[V];
    }
    void addEdge(int source, int destination){
        l[source].push_back(destination);
        l[destination].push_back(source);
    }
    void Breadth_First_Search(){
        queue<int> q;
        vector<bool> visited(V, false);

        q.push(0);
        visited[0] = true;

        while (q.size() > 0)
        {
            int source = q.front(); // this is the source of queue;
            q.pop();
            cout<< source<< " "<<endl;

            for (int destination : l[source])
            {
                if (!visited[destination])
                {
                    visited[destination] = true;
                    q.push(destination);
                }
                
            }
        }
        cout<<endl;
    }

    void Deapth_First_Search_Helper(int source, vector<bool> &visited){
        cout<<source<<" "<<endl;
        visited[source] = true;
        for(int destination : l[source]){
            if (!visited[destination])
            {
                Deapth_First_Search_Helper(destination, visited);
            }
            
        }
    }
    void Deapth_First_Search(){
        int source = 0;
        vector<bool> visited(V, false);
        Deapth_First_Search_Helper(source, visited);
    }
};

int main(){
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(1,2);
    G.addEdge(1,3);
    G.addEdge(2,3);
    G.addEdge(2,4);

    // G.Breadth_First_Search();
    // G.Deapth_First_Search();
    return 0;
}