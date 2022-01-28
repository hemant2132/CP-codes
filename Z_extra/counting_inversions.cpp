// Returns the no. of inversions in the range [l, r] in 'arr'

vector<int> temp_arr;

int countInversions(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;

    int mid = (l + r) / 2;
    int res = 0;
    res += countInversions(arr, l, mid);
    res += countInversions(arr, mid + 1, r);

    int i = l, j = mid + 1;
    int k = l;
    while (i <= mid) {
        while (j <= r && arr[j] < arr[i])
            temp_arr[k++] = arr[j++];

        res += j - (mid + 1);
        temp_arr[k++] = arr[i++];
    }

    while (j <= r)
        temp_arr[k++] = arr[j++];

    for (int i = l; i <= r; ++i)
        arr[i] = temp_arr[i];

    return res;
}