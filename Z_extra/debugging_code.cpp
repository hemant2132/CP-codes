// ref: tourist's submissions

string to_string(char s)
{
    string res="'''";
    res[1]=s;
    return res;
}

string to_string(string s)
{
    return '"'+s+'"';
}

string to_string(const char* s)
{
    return to_string((string)s);
}

string to_string(bool b)
{
    return (b?"true":"false");
}

template<typename A, typename B>
string to_string(pair<A, B> p)
{
    return "("+to_string(p.F)+", "+to_string(p.S)+")";
}

template<typename A>
string to_string(A v)
{
    bool first=true;
    string res="{";
    for(const auto &x:v)
    {
        if(!first)
            res+=", ";
        first=false;
        res+=to_string(x);
    }
    res+="}";

    return res;
}

void debug_out() { cout<<"\n"; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cout<<" "<<to_string(H);
    debug_out(T...);
}

#define dbug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
