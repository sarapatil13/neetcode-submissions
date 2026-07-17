class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())
        return false;

        vector<int> s1count(26,0);
        vector<int> window(26,0);

        for(int i=0;i<s1.size();i++)
        {
         s1count[s1[i]-'a']++;
         window[s2[i]-'a']++;
        }

        if(s1count==window)
        return true;
         
      for(int i=s1.size(); i<s2.size();i++)
      {
         window[s2[i]-'a']++;
         window[s2[i-s1.size()]-'a']--;
         
         if(s1count==window)
         return true;
      }
      return false;
    }
};
