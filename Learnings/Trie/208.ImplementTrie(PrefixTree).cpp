/*
https://leetcode.com/problems/implement-trie-prefix-tree/description/
This is the basic Trie data structure:
Put words : apple,apps,apxl,bac,bat in the Trie
Questions: 
    -Is so n so prefix present in this trie ? 
    -Insert this word in your trie.
    -Is this word present ? 
---------------------------------------------------------------------------------------------------
Implementation:
Trie: 
--------------------------------------------------------
|   Node *root                                         |
|------------------------------------------------------|
|   Trie()              //to make a root               |
|   insert(word)        //to insert a string           |
|   search(word)        //is this word present?        |
|   startsWith(prefix)  //is this prefix present?      |
--------------------------------------------------------

Node used in a Trie:
------------------------------------------------------------------------------------------------
|   Node * links[26]                                                                           |
|   flag                //marks the ending of a node                                           |
-----------------------------------------------------------------------------------------------|
|   containsKey(ch)     //does this node has a pointer to ch ?                                 | 
|   put(ch,Node *node)  //for the node with this ch, "node" is the reference node n1(ch) -> n2 |
|   get (ch)            //I am at a node, tell me if i have a reference to this ch             |
------------------------------------------------------------------------------------------------


*/

class Node{
    public:
        Node *links[26];
        bool flag = false;

        bool containsKey(char ch){
            //does this Node contains the character "ch" ? 
            return links[ch-'a']!=NULL;
        }

        void put(char ch, Node *node){
            //for character ch, "node" is the reference node
            links[ch-'a'] = node; 
        }

        Node *get(char ch){
            return links[ch-'a'];
        }


};

class Trie {
    private:
        Node *root;


    public:
        
        Trie() {
            root=new Node();
        }
        
        void insert(string word) {
            Node *node = root; 
            for(char ch:word){
               if(!node->containsKey(ch)){
                  node->put(ch,new Node());
               }
               node= node->get(ch);
            }
            node->flag=true;
        }
        
        bool search(string word) {
            Node *node = root;
            for(char ch:word){
                if(!node->containsKey(ch)) return false;
                node = node->get(ch);
            }
            return node->flag;
          
        }
        
        bool startsWith(string prefix) {
            Node *node = root;
            for(char ch:prefix){
                if(!node->containsKey(ch)) return false;
                node=node->get(ch);
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