#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) 
        	return false; 
        if( x < 10) 
        	return true; 
        int result = 0; 
        int buf = x; 
        while(buf != 0)
        { 
        	result = result * 10 + buf % 10; 
        	buf /= 10;
        } 
        return result == x;
    }
};