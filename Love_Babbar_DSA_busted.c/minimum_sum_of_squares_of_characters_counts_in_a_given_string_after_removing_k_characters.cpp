#include <bits/stdc++.h>
using namespace std;
// Question: Given a string s of lowercase alphabets and a number k, the task is to print the minimum value of the string after removal of 'k' characters.
// The value of a strinng is defined as the sum of squares of thhe count of each distinct character.

//Approach: 
// 1. Initialize empty priority queue
// 2. Count frequency of each character and store into temp array. 
// 3. remove k characters which have highest frequency from queue.
// 4. finally count sum of square of each element and return it.  


// timecomplxity: O(l+mx*log(l)+ k*log(l)+ mx*log(l)): O(k*logn)
// time complexity: O(k*log(n)) where n: size of the string or we could say l both are same 
// space complexity: O(1)
int minValue(string str, int k)
{
    int l = str.size();
    int mx = 26;
    int freq[26];
    int sum =0;
    priority_queue<int> q;
    memset(freq, 0, sizeof(freq)); // it is used to initialize all the elements of an array to zero . 
    for (int i = 0; i < l; i++)
    {
        freq[str[i] - 'a']++;
    }

    for (int i = 0; i < mx; i++)
    {
        q.push(freq[i]);
    }

    for (int i = 0; i < k; i++)
    {
        int temp = q.top();
        q.pop();
        temp--;
        q.push(temp);
    }

    for(int i=0;i<mx;i++){
        int temp = q.top();
        sum += (temp*temp);
        q.pop();
    }
    return sum;
}
int main()
{
    string str = "aaab";
    int k = 2;
    cout<<minValue(str, k)<<endl;
    return 0;
}