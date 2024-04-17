#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
#define pii pair<int ,int>

int MST(vector<vector<pii>> &graph,int v){
    vector<int> dist(v,INF);
    vector<int> parent(v,-1);
    vector<bool> vis(v,false);
    priority_queue<pii,vector<pii>,greater<pii>>pq;//pair(weight,vertex)
    pq.push({0,0});
    dist[0]=0;
    int mincost=0;
    while(!pq.empty()){
        int u=pq.top().second;
        if(vis[u]==true){
            pq.pop();
            continue;
        }
        vis[u]=true;
        int weight=pq.top().first;
        pq.pop();
        mincost+=weight;
        for(auto child:graph[u]){//graph=pair(VERTEX,WEIGHT)
            int v=child.first;//vertex
            int edge_weight=child.second;//weight
            if(!vis[v]&&edge_weight<dist[v]){
                dist[v]=edge_weight;
                pq.push({dist[v],v});
                parent[v]=u;
            }
        }
    }
    for(int i=1;i<v;i++){
        cout<<parent[i]<<"-"<<i<<endl;
    }
    return mincost;
}

int main(){
    // cout<<"Enter number of edges and vertex: ";
    int e,v;cin>>e>>v;
    vector<vector<pii>> graph(v);
    for(int i=0;i<e;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        
        graph[src].push_back({dest,weight});
        graph[dest].push_back({src,weight});
    }
    cout<<MST(graph,v);
}