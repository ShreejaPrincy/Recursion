// Time Complexity: O(n^2)
// Space Complexity: O(n)
class Solution {
  public:
    void insertatpos(stack<int>&st,int num){
        if(st.empty() || st.top()<=num){
            st.push(num);
            return;
        }

        int tope=st.top();
        st.pop();
        insertatpos(st,num);

        st.push(tope);
    }
    void sorted(stack<int>&st){
        if(st.empty())  return;
        
        int tope=st.top();
        st.pop();
        sorted(st);
        insertatpos(st,tope);
    }
    void sortStack(stack<int> &st) {
        return sorted(st);
    }
};
