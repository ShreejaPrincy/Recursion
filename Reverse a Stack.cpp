// Time Complexity: O(n^2)
// Space Complexity: O(n) due to recursion stack
class Solution {
  public:
    void insertatbottom(stack<int>&st,int num){
        if(st.empty()){
            st.push(num);
            return;
        }
        int tope=st.top();
        st.pop();
        insertatbottom(st,num);
        st.push(tope);
    }
    void solve(stack<int>&st){
        if(st.empty())  return;
        int tope=st.top();
        st.pop();
        solve(st);
        insertatbottom(st,tope);
    }
    void reverseStack(stack<int> &st) {
        return solve(st);
    }
};
