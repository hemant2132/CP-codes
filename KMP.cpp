void getLPS(string pat,int lps[])
{
    int m=pat.length();

    lps[0]=0;
    for(int i=1,j;i<m;++i)
    {
        for(j=lps[i-1];j>0 && pat[i]!=pat[j];j=lps[j-1]);

        if(pat[i]==pat[j])
            ++j;

        lps[i]=j;
    }
}

int getOccurrences(string str,string pat)
{
    int n=str.length();
    int m=pat.length();

    int ans=0;
    for(int i=0,j=0;i<n;)
    {
        if(pat[j]==str[i])
        {
            ++i;
            ++j;
        }

        if(j==m)
        {
            ++ans;
            j=lps[j-1];
        }
        else if(i<n && pat[j]!=str[i])
        {
            if(j)
                j=lps[j-1];
            else
                ++i;
        }
    }

    return ans;
}
