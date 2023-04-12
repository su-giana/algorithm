#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) 
    {
        int n = path.size();
        vector<vector<char> > directories(n);
        vector<string>  pathlist;
        string ans;

        int temp = 0;
        bool slash = false;
        for(int i = 1 ; i<n ; i++)
        {
            if(path[i] != '/')
            {
                if(slash)   {temp++; slash = false;}
                directories[temp].push_back(path[i]);
            }
            else
            {
                slash = true;
            }
        }

        for(int i = 0 ; i<directories.size() ; i++)
        {
            string directory(directories[i].begin(), directories[i].end());
            if(directory=="")       continue;
            if(directory == ".")    continue;
            else if(directory == "..")
            {
                if(!pathlist.empty())
                    pathlist.pop_back();
            }
            else
            {
                pathlist.push_back(directory);
            }
        }

        for(int i = 0 ; i<pathlist.size() ; i++)
        {
            ans += "/";
            ans += pathlist[i];
        }
        if(ans=="")     return "/";
        return ans;
    }
};