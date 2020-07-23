int stoiutil(string s,unordered_map<char,int> &m)
{
    if(s.size()==0)
        return 0;
    if(s.size()==1)
        return m[s[0]];
    
    string subs = s.substr(1);
    int res = m[s[0]];
    int p = 10;
    p = pow(10,(int)s.size());
    res*=p;
    return res + stoiutil(subs,m);
}
int STOI(string s)
{
    unordered_map<char,int> m;
    for(int i = 0; i<10; i++)
    {
        m['i'] = i;
    }
    return stoiutil(s,m);
}
