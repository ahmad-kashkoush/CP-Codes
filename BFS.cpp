//والله يابني مانا عارف ادينا بنهبد
//كود بلا هدف, تكبييييير
#include"macros.h"
typedef vector<vector<int>> Graph;
/* * [BFS]
 1. Level By Level
 2. Using Queue
    2.1 adding children, removing parents
 3. A shortest path Algorithm iff weight equal 1
 4. 1-m always, iff he gives it m-1, think in reverse
  */


 Graph BuildGraph(){
    int n, m; cin>>n>>m;
    Graph adj(n+1);
    while(m--){
        int u, v; cin>>u>>v;
        adj[u].emplace_back(v);
    }
    return adj;

}

void BFSPrintNodesLevelByLevel(int FirstNode,  Graph &gh){
    queue<int> nodes;
    gh[0].emplace_back(FirstNode);
    nodes.push(0);

    int Level=0;
    while(!nodes.empty()){
        int sz=nodes.size();
        queue<int> levelNodes;
        while(sz--) {
            auto k = nodes.front();
            nodes.pop();
            for (auto child: gh[k]) {
                nodes.push(child);
                levelNodes.push(child);
            }
        }
        cout<<el;

        if(!levelNodes.empty())
            cout<<"Level #"<<Level<<": ";
        while(!levelNodes.empty()){
            cout<<levelNodes.front()<<" ";
            levelNodes.pop();
        }

        sz=nodes.size(), Level++;
    }

/*
!input
12 11
1 2
1 3
1 4
2 5
2 6
5 10
5 9
4 7
4 8
7 11
7 12
!output
1
2 3 4
5 6 7 8
10 9 11 12
 */
}
vector<int> BFSVectorOfDepth(int FirstNode, Graph &gh){
     vector<int> len((gh.size()), INT_MAX);
     queue<int> nodes;
     nodes.push(FirstNode);
     len[FirstNode]=0;
     int depth=1;
     while(!nodes.empty()){
         int sz=nodes.size();
         while(sz--){
             int k=nodes.front();nodes.pop();
             for(auto child:gh[k]){
                 nodes.push(child);
                 if(len[child]==INT_MAX)
                     len[child]=depth;
             }
         }

         depth++;
     }
     return len;
 }
 vector<int> BFSPath(int s, int d, Graph &gh){
     /*!What I've done
      1.use Bfs as usual
      2. create a parent for each node
      3. from d node go back to root by par[d]
     */
     vector<int> len((gh.size()), INT_MAX);
     vector<int> par((gh.size()), -1);
     queue<int> nodes;
     nodes.push(s);
     len[s]=0;
     int depth=1;
     bool ok=true;
     while(!nodes.empty() and ok){
         int sz=nodes.size();
         while(sz--){
             int k=nodes.front();nodes.pop();
             for(auto child:gh[k]){
                 nodes.push(child);
                 if(len[child]==INT_MAX) {
                     len[child] = depth;
                     par[child]=k;
                     if(child==d){
                         ok=false;
                         break;
                     }
                 }
             }
         }
         depth++;
     }
     vector<int> path;
     while(d!=-1){
         path.emplace_back(d);
         d=par[d];
     }
     reverse(all(path));
     return path;

 }
void solve() {
        Graph k=BuildGraph();
//        BFSPrintNodesLevelByLevel(1, k);
//       vector<int> Depth=BFSVectorOfDepth(1, k);
//        vector<int> path=BFSPath(1, 7, k);
        for(auto i:path)
            cout<<i<<" ";
}

int main() {
    judge();
    int tc=1;
    //cin>>tc;
    while(tc--) {
        solve();
//        cout<<"Hello";
        cout<<el;
    }
    return 0;
}
