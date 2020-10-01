class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> v;
        while(getline(ss, token, '/'))
            v.push_back(token);
        stack<string> s;
        for(string str : v)
        {
            if(str != "")
            {
                if(str == ".." && s.size() > 0)
                    s.pop();
                else if(str != "." && str!= "..")
                    s.push(str);
            }
        }
        if(s.empty())
            return "/";
        string ans = "";
        while(!s.empty())
        {
            string t = s.top();
            ans = "/" + t + ans;
            s.pop();
        }
        return ans;
    }
};