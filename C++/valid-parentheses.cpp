class Solution {
public:
    bool isValid(string s) {
        if (s.length() % 2 != 0) return false;
        
        stack<char> order;
        unordered_map<char, char> umap;
        umap['('] = ')';
        umap['{'] = '}';
        umap['['] = ']';
        
        for (int i = 0; i < s.length(); i++) {
            if (umap.count(s[i])) order.push(umap[s[i]]);
            else if (!order.empty() && s[i] == order.top()) order.pop();
            else return false;
        }
        
        if (!order.empty()) return false;
        return true;
    }
};