#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int n, k;

class Trie {
    private:
    map<string, Trie*> next;
    public:
    void insert(vector<string>& v, int idx) {
        if(idx == v.size())
            return;

        if(next.find(v[idx]) == next.end()) {
            Trie* trie = new Trie;
            next.insert({v[idx], trie});
        }

        next[v[idx]]->insert(v, idx + 1);
    }

    void dfs(int d) {
        for(pair<string, Trie*> i : next) {                         //i의 선언 부분은 auto& 로 치환가능.
            for(int j = 0; j < d; j++) {
                cout << "--";
            }
            cout << i.first << "\n";
            i.second->dfs(d + 1);
            delete i.second;
        }
    }
};

int main() {
    cin >> n;

    Trie* root = new Trie();

    for(int i = 0; i < n; i++) {
        cin >> k;
        vector<string> tmp(k);
        for(int j = 0; j < k; j++) {
            cin >> tmp[j];
        }
        root->insert(tmp, 0);
    }

    root->dfs(0);
    delete root;

    return 0;
}