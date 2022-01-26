/*
    -> Trie (for bits)
    -> ref: https://threadsiiithyderabad.quora.com/Tutorial-on-Trie-and-example-problems
*/

struct TrieNode {
    TrieNode *ch[2];
    int cnt;
    TrieNode() {
        for (int i = 0; i < 2; ++i) ch[i] = nullptr;
        cnt = 0;
    }
};

TrieNode *root = nullptr;

void insertNumber(int n) {
    TrieNode *cur = root;
    int bit;
    for (int i = 30; i >= 0; --i) {
        bit = ((1 << i) & n) > 0;
        if (!cur->ch[bit]) cur->ch[bit] = new TrieNode();
        cur = cur->ch[bit];
        cur->cnt++;
    }
}

void removeNumber(int n) {
    TrieNode *cur = root;
    int bit;
    for (int i = 30; i >= 0; --i) {
        bit = ((1 << i) & n) > 0;
        cur = cur->ch[bit];
        cur->cnt--;
    }
}

int maxXor(int n) {
    TrieNode *cur = root;
    int bit, ans = 0;
    for (int i = 30; i >= 0; --i) {
        bit = ((1 << i) & n) > 0;
        if (cur->ch[!bit] && cur->ch[!bit]->cnt) {
            ans += (1 << i);
            cur = cur->ch[!bit];
        } else {
            cur = cur->ch[bit];
        }
    }

    return ans;
}