class Solution {
public:
   vector<vector<string>>ans;
 vector<string>ds;
   bool isPalindrome(string &temp ){
         int l = 0;
int r = temp.size() - 1;

while(l < r) {
    if(temp[l] != temp[r])
        return false;
    l++;
    r--;
}
return true;
}

 void solver(int index,string&s){
    //base case
    if(index==s.size()){
        ans.push_back(ds);
        return;
    }


    for (int i =index;i<s.size();i++){
        string temp=s.substr(index,i-index+1);
        if(isPalindrome(temp)){
    ds.push_back(temp);
    solver(i+1,s);
    ds.pop_back();
}
    }
   


   
   
}
vector<vector<string>> partition(string s) {
        solver(0, s);
        return ans;
    }
};