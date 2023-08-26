#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int BN=1e3+5;
vector<pii> adj[BN];
bool visited[BN];

void bfs(int s){
    queue<pii> q;
    q.push({s, 0});
    visited[s]=true;

    while (!q.empty())
    {
        int u=q.front().first;
        q.pop();
        //
        for(auto v:adj[u])
        {
            q.push({v.first, v.second});
            visited[v.first]=true;
            cout<<v.first<<v.second<<endl;
        }
    }
    

}


int main(){
    int n,e;
    cin>>n>>e;
    for (size_t i = 0; i < e; i++)
    {

        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        // adj[b].push_back({a,c });
    }


    bfs(3);
    // for (size_t i = 1; i <= n; i++)
    // {
    //     for(auto v:adj[i])
    //     {
    //         cout<<"node route"<<i <<v.first<<" weight "<<v.second<<" "<<endl;
    //     }
    // }
    

    
    return 0;
}