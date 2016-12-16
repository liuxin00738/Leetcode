#include <iostream>
#include <vector>
#include <unordered_map>
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
            if(hashTable.find(target-nums[i]) != hashTable.end()){
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
    int target=9;
    vector<int> result;
    
    result=solution.twoSum(nums, target);
    if(result.size()>1)
        cout<<result[0]<<" "<<result[1]<<endl;

}
int main(int argc, char* argv[]){
    simpleTest();

    return 0;
}
