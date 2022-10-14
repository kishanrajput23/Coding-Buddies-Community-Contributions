#include <bits/stdc++.h>
using namespace std;

// for a single query time complexity: is : O(1)
class LRUcache
{
    list<int> dll;
    unordered_map<int, list<int>::iterator> m;

public:
    int csize;
    LRUcache(int n);
    void reference(int x);
    void display();
};

LRUcache::LRUcache(int n)
{
    csize = n;
}

// time complexity: O(1)
void LRUcache::reference(int x)
{
    //NOt present in the map
    if (m.find(x) == m.end())
    {
        if (dll.size() == csize)
        {
            int l = dll.back();
            dll.pop_back();
            m.erase(l);
            dll.push_front(x);
            m[x] = dll.begin();
        }
        else
        {
            dll.push_front(x);
            m[x] = dll.begin();
        }
    }
    else
    {
        dll.remove(x);
        dll.push_front(x);
    }
}

void LRUcache::display()
{
    for (list<int>::iterator it = dll.begin(); it != dll.end(); it++)
    {
        cout << *it << " ";
    }
}
int main()
{
    LRUcache cache(4);
    cache.reference(1);
    cache.reference(2);
    cache.reference(3);
    cache.reference(1);
    cache.reference(4);
    cache.reference(5);
    cache.display();
    return 0;
}