// Time Complexity: Exponential
// Space Complexity: O(n)
//(TLE) ->recursion
class Solution {
public:
    bool match(string word,string s,int i){
        if(i + word.size() > s.size())
            return false;
        for(int j=0;j<word.size();j++){
            if(s[i+j]!=word[j])    return false;
        }
        return true;
    }
    bool is_segmented(string s, vector<string>& wordDict,int i){
        int n = wordDict.size();
        if(i==s.size())    return true;
        for(int k=0;k<n;k++){
            if(match(wordDict[k],s,i)){
                int c=wordDict[k].size();
                if(is_segmented(s,wordDict,i+c))
                    return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       return is_segmented(s,wordDict,0);
    }
};
