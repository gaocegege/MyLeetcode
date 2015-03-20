class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
    if(strs.size() == 0) return "";
        string prefix = strs[0], temp;
        for(int i=1; i< strs.size(); ++i){
               prefix = findCommon(prefix, strs[i]);
        }
        return prefix;
    }
private:
    string findCommon(string s1, string s2){
        int len = min(s1.size(), s2.size()), i;
        for(i=0; i<len; ++i){
            if(s1[i] != s2[i])
                break;
        }
        return  s1.substr(0,i);
    }
};