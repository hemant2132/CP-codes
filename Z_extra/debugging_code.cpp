/* 
    -> Debugging template
    -> ref:
        1. https://codeforces.com/blog/entry/68809 
        2. tourist's submission - https://codeforces.com/contest/1110/submission/49588803
*/

string to_string(char s)
{   string res="'''"; res[1] = s; return res; }

string to_string(string s)
{   return '"' + s + '"'; }

string to_string(const char* s)
{   return to_string((string)s); }

string to_string(bool b)
{   return (b ? "true" : "false"); }

template<typename A, typename B>
string to_string(pair<A, B> p)
{   return "(" + to_string(p.F) + ", " + to_string(p.S) + ")"; }

template<typename A>
string to_string(A v) {
    bool first = 1; string res = "{";
    for (const auto &x : v) {
        if (!first)  res += ", ";
        first = 0;
        res += to_string(x);
    }

    res += "}";
    return res;
}

void debug() { cout << "\n"; }
template<typename Head, typename... Tail>
void debug(Head H, Tail... T) {
    cout << " " << to_string(H);
    debug(T...);
}

#define show(...) cout << "[" << #__VA_ARGS__ << "]:", debug(__VA_ARGS__)