Problem Statement Break Down :

1. we have an integer array citations where the citations[i] is the value of i-th paper citations
2. we have to return the h-index 
3. the h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
4. in simple language we have to find the value of h such that if the value of h is 3 then there will be 3 papers atleast having 3 or more citations 

Solution :

// Brute force 

#include<bits/stdc++.h>
using namespace std;

int get_H(vector<int> &citations){
    
    sort(citations.begin(),citations.end(),greater<int>());
    
    int h = 1;
    int max_h = 0;
    
    while(h<=citations[0]){
        
        int cnt = 0;
        for(int i=0;i<citations.size();i++){
            
            if(h <= citations[i]){
                cnt++;
            }
        }
        
        if(cnt >= h){
            
            max_h = max(max_h,h);
            
        }
        else{
            break;
        }
        h++;
    }
    
    return max_h;
}
int main(){
    
    int n;
    cin>>n;
    
    vector<int> citations;
    
    for(int i=0;i<n;i++){
        
        int val;
        cin>>val;
        
        citations.push_back(val);
    }
    
    cout<<get_H(citations);
    
}

Time complexity : O(nlogn)+O(citations[0]*n)
Space complexity : O(1)

// Optimised approach

#include<bits/stdc++.h>
using namespace std;

int get_H(vector<int> &citations){
    
    sort(citations.begin(),citations.end(),greater<int> ());

    int h = 0;

    while(h < citations.size() && citations[h] > h){
        h++;
    }      

    return h;

}
int main(){
    
    int n;
    cin>>n;
    
    vector<int> citations;
    
    for(int i=0;i<n;i++){
        
        int val;
        cin>>val;
        
        citations.push_back(val);
    }
    
    cout<<get_H(citations);
    
}

Time complexity : O(nlogn)
Space complexity : O(1)
