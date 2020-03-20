struct node
{
    node* ch[2];
    int cnt;
    node()
    {
        ch[0]=ch[1]=NULL;
        cnt=0;
    }
};

node* root=NULL;

void insert(int n)
{
    node* cur=root;
    int x;
    for(int i=30;i>=0;--i)
    {
        x=((1<<i)&n)>0;

        if(!cur->ch[x])
            cur->ch[x]=new node();
        cur=cur->ch[x];
        cur->cnt++;
    }
}

void remove(int n)
{
    node* cur=root;
    int x;
    for(int i=30;i>=0;--i)
    {
        x=((1<<i)&n)>0;
        cur=cur->ch[x];
        cur->cnt--;
    }
}

int maxxor(int n)
{
    node* cur=root;
    int x,ans=0;
    for(int i=30;i>=0;--i)
    {
        x=((1<<i)&n)>0;

        if(cur->ch[!x] && cur->ch[!x]->cnt)
        {
            ans+=(1<<i);
            cur=cur->ch[!x];
        }
        else
            cur=cur->ch[x];
    }

    return ans;
}
