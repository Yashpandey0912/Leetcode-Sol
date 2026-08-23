class Solution {
public:
const int intmin=INT_MIN;
const int intmax=INT_MAX;
    int helper(int i,string s,long long num,int sign){
        if(i>s.size()||!isdigit(s[i])){
            return int(num*sign);
        }
        num=num*10+(s[i]-'0');
        if(sign*num<=intmin)return intmin;
        if(sign*num>=intmax)return intmax;
        return helper(i+1,s,num,sign);
        

    }
    int myAtoi(string s,int i=0) {
        while(i<s.size()&&s[i]==' ')i++;
        int sign=1;
        if(i<s.size()&&s[i]=='+'||s[i]=='-'    ){
            sign=(s[i]=='-')?-1:1;
            i++;    
        }
        return helper(i,s,0,sign);


        
    }
};