void euler(int start)
{
    stack<int> stk;

    stk.push(start);

    int x;
    while(!stk.empty())
    {
        x=stk.top();

        if(v[x].size())
        {
            stk.push(v[x].back());
            v[x].pop_back();
        }
        else
            stk.pop();
    }
}
