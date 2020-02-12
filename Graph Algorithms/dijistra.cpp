 //Add it to graph class
 void dijistra(int s)
  {
    vector<int>dis(nodes+1,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push(mp(0,s));
    dis[s]=0;
    vis[s]=1;
    while(!pq.empty())
    {
      pair<int,int> p=pq.top();
      pq.pop();
      int u=p.ss;
      for(pair<int,int>pv :adj[u])
      {
        int v=pv.ff;
        int wt=pv.ss;
        if(dis[u]+wt<dis[v] && !vis[v])
        {
          dis[v]=dis[u]+wt;
          pq.push(mp(dis[v],v));
        }
      }
    }
    for(int i=1;i<=nodes;i++)
      cout<<dis[i]<<" ";
  }
