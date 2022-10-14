// C++ Program to print Bottom View of Binary Tree
#include <bits/stdc++.h>
#include <map>
using namespace std;

// Tree node class
struct Node
{
	// data of the node
	int data;
	
	// horizontal distance of the node
	int hd;
	
	//left and right references
	Node * left, * right;
	
	// Constructor of tree node
	Node(int key)
	{
		data = key;
		hd = INT_MAX;
		left = right = NULL;
	}
};

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m)
{
	// Base case
	if (root == NULL)
		return;
	
	// If node for a particular
	// horizontal distance is not
	// present, add to the map.
	if (m.find(hd) == m.end())
	{
		m[hd] = make_pair(root -> data, curr);
	}
	// Compare height for already
	// present node at similar horizontal
	// distance
	else
	{
		pair < int, int > p = m[hd];
		if (p.second <= curr)
		{
			m[hd].second = curr;
			m[hd].first = root -> data;
		}
	}
	
	// Recur for left subtree
	printBottomViewUtil(root -> left, curr + 1, hd - 1, m);
	
	// Recur for right subtree
	printBottomViewUtil(root -> right, curr + 1, hd + 1, m);
}

void printBottomView(Node * root)
{
	
	// Map to store Horizontal Distance,
	// Height and Data.
	map < int, pair < int, int > > m;
	
	printBottomViewUtil(root, 0, 0, m);
	
	// Prints the values stored by printBottomViewUtil()
	map < int, pair < int, int > > ::iterator it;
	for (it = m.begin(); it != m.end(); ++it)
	{
		pair < int, int > p = it -> second;
		cout << p.first << " ";
	}
}
vector<int> findSpiral(Node *root)
{
    vector<int> res;
    if(root == NULL) return res;
    
	int num = 0;
	queue<Node*> q;
	vector<vector<int>> v(100);
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		Node* temp = q.front();
		q.pop();
		if(q.empty()){
			num++;
			break;
		}
		// cout<<"hi"<<endl;
		if(temp == NULL){
			// cout<<"hi1"<<endl;
			
			q.push(NULL);
			num++;
			continue;
		}
		int x = temp->data;
		// cout<<x<<endl;
		// cout<<x<<endl;
		v[num].push_back(x);
		// cout<<"temp"<<endl;
		if(temp->left){
			// cout<<"hi2"<<endl;
			q.push(temp->left);
		}
		if(temp->right){
			// cout<<"hi3"<<endl;
			q.push(temp->right);
		}
		// cout<<"hi4"<<endl;
	}
	// cout<<v[1].size()<<endl;
	res.push_back(v[0][0]);
	// cout<<v[0][0]<<" ";
	for(int i = 1;i<num;i++){
		// cout<<"inside";
		if(i%2 !=0){
			for(int j = 0;j<v[i].size();j++){
				// cout<<v[i][j]<<" ";
				res.push_back(v[i][j]);
			}
		}
		else{
			for(int j = v[i].size()-1;j>=0;j--){
				// cout<<v[i][j]<<" ";
				res.push_back(v[i][j]);
			}
		}
	}
	return res;
}
int main()
{
	Node * root = new Node(1);
	root -> left = new Node(2);
	root -> right = new Node(3);
	// root -> left -> left = new Node(5);
	// root -> left -> right = new Node(3);
	// root -> right -> left = new Node(4);
	// root -> right -> right = new Node(25);
	// root -> left -> right -> left = new Node(10);
	// root -> left -> right -> right = new Node(14);
	// cout << "Bottom view of the given binary tree :\n";
	// printBottomView(root);
	vector<int> v = findSpiral(root);
	for(int i = 0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
