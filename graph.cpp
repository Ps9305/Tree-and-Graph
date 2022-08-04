#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int> >adj;
    
    void addEdge(int u,int v,bool direction){
        adj[u].push_back(v);
        if(direction==0){
            adj[v].push_back(u);
        }
    }

    void printlist(){
        for(auto i: adj)
        {
             cout<<i.first<<"->";

             for(auto j: i.second){
                cout<<j<<",";
             }
             cout << endl; 
        }
       
    }
    
};

int main(){
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the nuber of edge"<<endl;

    graph g;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);
    }
    g.printlist();

    return 0;
}
