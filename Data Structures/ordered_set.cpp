/*
    -> Ordered Set
    -> ref: https://codeforces.com/blog/entry/11080
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>

ordered_set os;

// order_of_key(val) -> returns the no. of elements strictly less than 'val' 
// *find_by_order(index) -> returns the value at 'index' (0-based indexing)
// use pair<T, int> for multiset
// you can use a custom comparator instead of less<T>
