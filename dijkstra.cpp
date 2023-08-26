#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

const int BN=1e3+5;
vector<pii> v[BN];
int dis[BN];
bool vis[BN];

void dijkstra(int s)
{
priority_queue<pii, vector<pii>, greater<pii>> pq;
pq.push({0,s});
dis[s]=0;
while (!pq.empty())
{
    pii parent = pq.top();
    pq.pop();
    int parentNode= parent.second;
    if(vis[parentNode]) continue;

    vis[parentNode]=true;
    int parent_cost= parent.second;
    for (size_t i = 0; i < v[parentNode].size(); i++)
    {
        pii child = v[parentNode][i];
        int childnode = child.first;
        int childcost = child.second;
        if(parent_cost + childcost < dis[childnode])
        {
            dis[childnode] = parent_cost+childcost;
            pq.push({dis[childnode], childnode});

        }
    }
    

}


}


int main(){
    int n,e;
    cin>>n>>e;
    while (e--)
    {
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    }

    for (size_t i = 1; i <=n ; i++)
    {
        dis[i]=INT_MAX;
    }
    
    dijkstra(1);
    for (int     i = 1; i <=n; i++)
    {
        cout<<dis[i]<<endl;
    }
    
    return 0;
}