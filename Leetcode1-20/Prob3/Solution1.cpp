#include <unordered_set>
#include <vector>
#include <unordered_map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=findLength2(s);
        return result;
    }

private:
    /// using an unordered_map to record both the element in the string, and the corresponding index
    /// keep record the first and last element of current string
    /// complexity O(n)
    int findLength2(string& s){
        int result=0;
        if(s.size()==0) return result;
         
        // use map to store the char and its index
        unordered_map<char,int> subStrMap; 
        
        // record the begin and end index of current substring
        vector<int> subStrRange={0,0};        
        
        for(int strIdx=0;strIdx<s.size();strIdx++){
            // update the end of current substring
            subStrRange[1]=strIdx;
            
            // if no repeat char
            if(subStrMap.find(s[strIdx]) ==subStrMap.end()){ 
                subStrMap.insert( pair<char,int>(s[strIdx], strIdx) );
            }
            
            // find repeat char
            else
            {
                handleRepeat(subStrMap,  s,  subStrRange);
                continue;
            }   
            
            result=result>subStrMap.size()? result : subStrMap.size();        
        }
        return result;

    }	    
    /// when find repeated char, 
    /// delete the chars before repeated char in the map
    /// update the index of the repeated char in the map 
    /// update the begin of current substring
    void handleRepeat(unordered_map<char, int>& subStrMap, string& s, vector<int>& subStrRange){
        int repeatCharIdx=subStrRange[1];
        char repeatChar=s[repeatCharIdx];
        
        //delete chars before repeated char in the map  
        int begin=subStrRange[0];
        int end=subStrMap.find(repeatChar)->second;        
        for(int i=begin;i<end;i++)
            subStrMap.erase(s[i]);
        
        // update the index of this repeated char in map
        subStrMap[repeatChar]=repeatCharIdx;
        
        // update the begin index of current substring 
        subStrRange[0]=end+1;       
    
    }
    /// using an unordered_map to speed up the search
    /// complexity O(n*n)
    int findLength1(string& s){
        int result=0;
        if(s.size()==0) return result;
        
        for(int headIdx=0;headIdx<s.size();headIdx++){
            unordered_set<char> subStrSet;
            for(int tailIdx=headIdx; tailIdx<s.size();tailIdx++){
                if(subStrSet.find(s[tailIdx]) ==subStrSet.end()){ 
                    subStrSet.insert(s[tailIdx]);
                }
                // find repeat, break to count the length of this substring
                else
                {
                    break;
                }                
            }
            result=result>subStrSet.size()? result: subStrSet.size();        
        }
        return result;
    }	
};
