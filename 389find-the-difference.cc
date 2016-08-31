class Solution {
public:
    char findTheDifference(string s, string t) {
        int i, diff = 0;
        for(i = 0; i < t.size(); i++)
            diff += t[i];
        for(i = 0; i < s.size(); i++)
            diff -= s[i];
        return diff;
    }
};
