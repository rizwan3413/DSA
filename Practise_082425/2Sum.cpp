#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//2sum equal to target 
vector<int> twoSum(vector<int> &nums, int target){
    unordered_map<int, int> numbersMap;
    vector<int> answer;
    
    for(int i = 0; i < nums.size();i++){
        
        int first = nums[i];
        int second = target - first;
        
        if(numbersMap.find(second) != numbersMap.end()){
            answer.push_back(i);
            answer.push_back(numbersMap[second]);
            break;
        }
        
        numbersMap[nums[i]] = i;
    }
    return answer;
}


int main()
{
    std::vector<int> refVector = { 2, 5, 7, -1, 10, 13};
    auto vec = twoSum(refVector, 15);
    std::cout<<"Vector indexes are: " << vec[0] << "," << vec[1] << std::endl;

    return 0;
}