#include <algorithm>
#include <cassert>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
public:
    /// create a hash table, where key is element, and value is the index
    /// for each element, search if target-element is in the hash table
    /// complexity is o(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hashTable;
        
        /// boarder case gard
        if(nums.size()==0)
            return result;
        ///create the hash table
        for(int i=0;i<nums.size();i++)
            hashTable.insert( std::make_pair<int, int>( int(nums[i]), int(i) ));       
        
        // search the hash table for solution
        for(int i=0;i<nums.size();i++){
            if(hashTable.find(target-nums[i]) != hashTable.end() && i!= hashTable[target-nums[i]]){
                result.push_back(i);
                result.push_back(hashTable[target-nums[i]]);
                break;
            }           
        }
        return result;        
    }
    
};

void simpleTest(){
    Solution solution;
    vector<int> nums={2, 7, 11, 15};
    vector<int> answer={0,1};
    int target=9;
    vector<int> result;
    
    result=solution.twoSum(nums, target);    
    if(result.size()<2){ 
        cout<<"no solution"<<endl;
        return;
    }
    
    cout<<result[0]<<" "<<result[1]<<endl;    
    sort(result.begin(), result.end());
    assert(result[0]==answer[0]);
    assert(result[1]==answer[1]);

}
int main(int argc, char* argv[]){
    simpleTest();

    return 0;
}
