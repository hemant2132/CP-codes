int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int x,int y)
{
    return (x>=0 && x<n && y>=0 && y<m && s[x][y]!='#' && dist[x][y]==inf);
}

int bfs2d(int sx,int sy)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            dist[i][j]=inf;
    }

    dist[sx][sy]=0;
    q.push({sx,sy});

    int res=0,x,y;
    pii p;

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        res=max(res,dist[p.F][p.S]);

        for(int i=0;i<4;++i)
        {
            x=p.F+dx[i];
            y=p.S+dy[i];

            if(valid(x,y))
            {
                dist[x][y]=dist[p.F][p.S]+1;
                q.push({x,y});
            }
        }
    }

    return res;
}
