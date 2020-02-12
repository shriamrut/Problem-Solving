void topologicalsort(int s,stack<int>&st)
{
  vis[s]=1;
  for(auto v:adj[s])
  {
    if(!vis[v])
      topologicalsort(v,st);
  }
  st.push(s);
}
