//https://www.geeksforgeeks.org/problems/unique-binary-tree-requirements/1


#include<iostream>
using namespace std;


  bool isPossible(int a, int b) {
        // code here
        if(a == b)return false;
        if((a == 1 && b == 3)||(a == 3 && b ==1))return false;
        return true;
        
    }

int main(){
    
    cout<<isPossible(1,3);

}