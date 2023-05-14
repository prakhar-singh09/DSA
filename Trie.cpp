class Trie {
public:
    Trie* trie[26];
    bool stop;
    Trie() {    
        stop = false;
        memset(trie,0,sizeof(trie));
    }
    
    void insert(string word) {
       Trie* temp = this;
       for(auto ch:word){
         if(temp->trie[ch-'a'] == NULL)
           temp->trie[ch-'a'] = new Trie();
        temp = temp->trie[ch-'a'];
       }
 temp->stop = true;
    }
    
    bool search(string word) {
          Trie* temp = this;
       for(auto ch:word){
         if(temp->trie[ch-'a'] == NULL)
          return false;
        temp = temp->trie[ch-'a'];
       }
 return temp->stop;
    }
    
    bool startsWith(string prefix) {
          Trie* temp = this;
       for(auto ch:prefix){
         if(temp->trie[ch-'a'] == NULL)
          return false;
        temp = temp->trie[ch-'a'];
       }
           return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
