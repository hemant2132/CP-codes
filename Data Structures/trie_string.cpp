struct node
{
    node* ch[28];
    int cnt;
    node()
    {
        for(int i=0;i<28;++i)
            ch[i]=NULL;

        cnt=0;
    }
};

node* root=NULL;

void insrt(string s)
{
    node* cur=root;
    int len=s.length();
    int x;
    for(int i=0;i<len;++i)
    {
        x=s[i]-'A';

        if(!cur->ch[x])
            cur->ch[x]=new node();
        cur=cur->ch[x];
        cur->cnt++;
    }
}

void rem(node* cur)
{
    for(int i=0;i<28;++i)
    {
        if(cur->ch[i]!=NULL)
        {
            cur->ch[i]->cnt=0;
            rem(cur->ch[i]);
        }
    }
}
