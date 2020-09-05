/*
 * Chef        : preetam rane
 * Chef-Id     : pvr2114
 * Dish        : Partition Labels
 * Created on  : Saturday, 5th September 2020 8:31:46 am
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        map <char, int> cnt;
        for(int i = 0; i < s.size(); i++)cnt[s[i]] = i;
        int j = 0, start = 0;
        int i = 0;
        int n = s.size();
        vector <int> ans;
        while(i < n){
            j = max(j, cnt[s[i]]);
            if( i == j){
                ans.push_back(i-start+ 1);
                start = i + 1;
            }
            i++;
        }
        return ans;
    }
};

void print_vector(vector<int> v){
    cout << "[";
    for(int i = 0; i<v.size(); i++){
        if(i==v.size()-1)
            cout << v[i];
        else
            cout << v[i] << ",";
    }
   cout << "]"<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Solution ob;
    print_vector(ob.partitionLabels("ababcbacadefegdehijhklij"));
    return 0;
}
