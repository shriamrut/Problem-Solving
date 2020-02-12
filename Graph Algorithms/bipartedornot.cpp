bool isbiparted(int s)
{
  queue<int>q;
  q.push(s);
  vector<char>color(this->nodes+1,'d');
  vis[s]=1;
  color[s]='a';
  while(!q.empty())
  {
    int u=q.front();
    q.pop();
    for(auto v:adj[u])
    {
      if(!vis[v] && color[v]=='d' )
      {
        if(color[u]=='a')
          color[v]='b';
        else if(color[u]=='b')
          color[v]='a';
        else if(color[u]==color[v])
        {
          return 1;
        }
        q.push(v);
        vis[v]=1;
      }
      else if(color[u]==color[v])
        return 1;
    }
  }
  return 0;
}
