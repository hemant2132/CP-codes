/*
    -> Trie (for strings)
    -> ref: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/tutorial/
*/

struct TrieNode {
    TrieNode *ch[28];
    int cnt;
    TrieNode() {
        for (int i = 0; i < 28; ++i) ch[i] = nullptr;
        cnt = 0;
    }
};

TrieNode *root = nullptr;

void insertString(string s) {
    TrieNode *cur = root;
    int len = sz(s);
    int c;
    for (int i = 0; i < len; ++i) {
        c = s[i] - 'A';
        if (!cur->ch[c]) cur->ch[c] = new TrieNode();
        cur = cur->ch[c];
        cur->cnt++;
    }
}

void resetNodes(TrieNode *cur) {
    for (int i = 0; i < 28; ++i) {
        if (cur->ch[i] != nullptr) {
            cur->ch[i]->cnt = 0;
            resetNodes(cur->ch[i]);
        }
    }
}