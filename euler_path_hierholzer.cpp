// euler path - a path that uses every edge of the graph exactly once

void euler(int start)
{
    stack<int> stk;

    stk.push(start);

    int x;
    bool fl;
    while(!stk.empty())
    {
        x=stk.top();

        fl=0;
        for(int i=0;i<N;++i)
        {
            if(mat[x][i])
            {
                fl=1;
                stk.push(i);
                mat[x][i]=0;
                break;
            }
        }

        if(!fl)
        {
            // euler_path.pb(x);

            stk.pop();
        }
    }
}
