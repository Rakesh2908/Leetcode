class AllOne {
public:
    unordered_map<string,int>m;
    set<pair<int,string>>s;

    AllOne() 
    {

    }
    
    void inc(string key) 
    {
        int cnt = m[key];
        s.erase({cnt,key});

        m[key]++;

        s.insert({m[key],key});
    }
    
    void dec(string key) 
    {
        int cnt = m[key];
        s.erase({cnt,key});

        m[key]--;

        if(m[key]==0)   m.erase(key);
        else    s.insert({m[key],key});
    }
    
    string getMaxKey() 
    {
        if(s.size())    return s.rbegin()->second;
        return "";
    }
    
    string getMinKey() 
    {
        if(s.size())    return s.begin()->second;
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */