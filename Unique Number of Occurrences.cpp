class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int>m;
        for (auto x : arr) {
            m[x]++;
        }
        int uniq = m.size();
        set<int>st;
        for (auto x : m) {
            st.insert(x.second);
        }
        if (st.size() == uniq) return true;
        else return false;
    }
};