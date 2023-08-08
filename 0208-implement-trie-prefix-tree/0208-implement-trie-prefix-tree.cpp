class Trie {
public:
    set<string> s;
    set<string> prefs;
    Trie() {
        
    }
    
    void insert(string word) {
        s.insert(word);
        string pref = "";
        for(auto x: word){
            pref += x;
            prefs.insert(pref);
        }
    }
    
    bool search(string word) {
        return s.count(word);
    }
    
    bool startsWith(string prefix) {
        return prefs.count(prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */