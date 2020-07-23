
void util(int n, vector<string> &res, unordered_map<int,string> &map)
{
    // Base case;
    if(n == 0)
        return; // If nothing remains then return.
    
    int x = n%10;
    int rem = n/10;
    util(rem,res,map);
    string s = map[x];
    res.insert(res.end(),s);
    return;
}
vector<string> TwoZeroFourEight(int n)
{
    vector<string> res;
    unordered_map<int,string> m;
    m[0] = "zero";
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    util(n,res,m);
    return res;
}
