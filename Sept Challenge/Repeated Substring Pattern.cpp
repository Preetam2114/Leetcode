/*
 * Chef        : preetam rane
 * Chef-Id     : pvr2114
 * Dish        : Repeated Substring Pattern
 * Created on  : Friday, 4th September 2020 11:35:18 am
 */


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void printVector(vector <int> v){
        for(int i = 0; i < v.size(); i++)cout << v[i] << " ";
        cout << endl;
    }
    
    bool repeatedSubstringPattern(string s) {
      int n = s.size();
      vector <int> dp(n);
      int i = 1;
      int j = 0;
      while(i < n){
         if(s[i] == s[j]){
            dp[i] = j+1;
            i++;
            j++;
         } else {
            if(j > 0){
               j = dp[j-1];
            } else {
               dp[i] = 0;
               i++;
            }
         }
      }
      return dp[n - 1] && n % (n - dp[n-1]) == 0;
   }
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution sn;
    string s = "abab";
    cout<<sn.repeatedSubstringPattern(s)<<endl;
    return 0;
}
