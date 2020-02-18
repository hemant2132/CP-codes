//Returns the no. of inversions in the range [l, r) in arr

int merge_sort(vector<int> arr,int l=0,int r=n)
{
    if(l>r)
        return 0;

    int mid=(l+r)/2;
    int res=0;

    res+=merge_sort(arr,l,mid);
    res+=merge_sort(arr,mid,r);

    vector<int> sorted;

    int i=l,j=mid;

    while(i<mid)
    {
        while(j<r && arr[j]<arr[i])
        {
            sorted.push_back(arr[j++]);
        }

        res+=j-mid;
        sorted.push_back(arr[i++]);
    }

    while(j<r)
        sorted.push_back(arr[j++]);

    for(int i=l;i<r;++i)
        arr[i]=sorted[i-l];

    return res;
}
