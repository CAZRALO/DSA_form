struct Node {
    Node* child[26];
    bool wordEnd;
    Node() {
        for (int i=0; i<26; i++) child[i]=NULL;
        wordEnd=false;
    }
};

struct Trie{
    Node *root;
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        Node* p = root;
        for (char &ch:s) {
            int c=ch-'a';
            if (!p->child[c]) p->child[c] = new Node();
            p=p->child[c];
        }
        p->wordEnd=true;
    }

    bool find(string s) {
        Node* p = root;
        for (char &ch:s) {
            int c=ch-'a';
            if (!p->child[c]) return false;
            p=p->child[c];
        }
        return p->wordEnd;
    }
};
