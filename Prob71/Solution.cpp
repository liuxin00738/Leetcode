class Solution {
public:
    string simplifyPath(string path) {
        vector<string> resultVec;
        stringstream input(path);
        string temp;
        string result("");
        
        while(getline(input, temp, '/')){
            cout<<temp<<endl;
            if(temp=="." || temp=="") continue;
            if(temp==".." && !resultVec.empty()) resultVec.pop_back(); 
            else if(temp!="..") resultVec.push_back(temp);
        }
        
        for(int i=0;i<resultVec.size();i++)
            result+='/'+resultVec[i];
        
        if(result.empty()) result+='/';
        return result;
    }
};