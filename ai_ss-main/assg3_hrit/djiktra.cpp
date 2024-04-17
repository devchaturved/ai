#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
#define INF INT_MAX
#define pii pair<int ,int>

vector<int> dijkstra(int source,vector<vector<pii>>&graph,int v){
    vector<int>dist(v,INF);
    vector<bool>vis(v,false);
    priority_queue<pii,vector<pii>,greater<pii>>pq;//pair{weight,vertex}
    pq.push({0,source});
    dist[source]=0;
    while(!pq.empty()){
        int weight=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=true;
        for(auto child:graph[u]){//graph pair{vertex,weight}
            int x=child.first;
            int wt=child.second;
            if(!vis[x]&&dist[u]+wt<dist[x]){
                dist[x]=dist[u]+wt;
                pq.push({dist[x],x});
            }
        }
    }
    return dist;
}

int main(){
    int v,e;cin>>v>>e;
    vector<vector<pair<int,int>>>vec(v);
    for(int i=0;i<e;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        src--,dest--;
        vec[src].push_back({dest,weight});
        vec[dest].push_back({dest,weight});
    }
    vector<int>a(v);
    // cout<<"Enter the source you want to start with: ";
    // int x;cin>>x;
    a=dijkstra(0,vec,v);
    int ans=INT_MIN;
    for(int i=0;i<v;i++){
        // ans=max(ans,a[i]);
        cout<<a[i]<<" ";
    }
    // cout<<ans<<endl;
    // cout<<a[2]<<" "<<a[1];
}