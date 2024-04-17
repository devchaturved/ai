// Implementation of Kruskals algorithm using DSU (Disjoint Set Union)
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int parent[N];
int size[N];

void make(int v){
    parent[v]=v;
    size[v]=1;
}

int find(int v){
    if(parent[v]==v) return v;
    //Path compression
    return parent[v]=find(parent[v]);
}

void Union(int a,int b){
    a=find(a);
    b=find(b);
    // Union by Size/Rank
    if(a!=b && size[a]<size[b]){
        swap(a,b);
    }
    parent[b]=a;
    size[b]+=size[a];
}

int main(){
    int v,e;cin>>v>>e;
    vector<pair<int ,pair<int,int> > >vec;
    for(int i=0;i<e;i++){
        int src,dest,weight;
        cin>>src>>dest>>weight;
        vec.push_back({weight,{src,dest}});
    }
    sort(vec.begin(),vec.end());
    for(int i=1;i<=v;i++){
        make(i);
    }
    int total_cost=0;
    for(auto edge:vec){
        int wt=edge.first;
        int x=edge.second.first;
        int y=edge.second.second;
        if(find(x)==find(y)){
            continue;
        }
        total_cost+=wt;
        Union(x,y);
        cout<<x<<" "<<y<<endl;
    }
    cout<<"Cost of minimum spanning tree is: ";
    cout<<total_cost<<endl;
}