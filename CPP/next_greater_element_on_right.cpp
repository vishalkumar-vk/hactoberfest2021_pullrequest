/*

Given an array arr[ ] of size N having distinct elements, the task is to find the next greater element for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. For example, next greater of the last element is always -1.

*/
class Solution{
 public:
vector<long long> nextLargerElement(vector<long long> arr, int n){
  stack<long long>s;
       s.push(arr[n-1]);
       vector<long long>ans;
       ans.push_back(-1);
       for(int i=n-2;i>=0;i--){
           while(!s.empty() && s.top()<=arr[i])
           s.pop();
           if(s.empty())  ans.push_back(-1);
           else ans.push_back(s.top());
           s.push(arr[i]);
       }
       reverse(ans.begin(),ans.end());
      return ans;
}
};
