class Solution {
public:

//TC: O(n), MC: O(n)   n = size of string

    bool isValid(string s) {
stack<char>st;

    // char c='(';
    // char c1 =')';
    // cout<<(int)c<<" "<<(int)c1<<endl;


        for(auto x : s){
            if(x=='(' || x=='{' || x=='[') st.push(x);
            else {
                if(st.size()==0) return 0;
                char topSign = st.top();
                int in = (int)topSign;
                int out = (int)x;
                int diff = abs(out-in);
                if(diff==1 || diff==2) st.pop();     //two bracked diff =1 (), diff=2 {},[]
                else return 0;
               }
        }   




        if(st.size()==0) return 1;
        else return 0;


    }
};