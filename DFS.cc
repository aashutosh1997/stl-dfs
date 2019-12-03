#include<iostream>
#include<vector>
#include<list>
#include<stack>
#include<map>
#include<algorithm>
#include<iterator>
#include<utility>
using namespace std;

int main()
{
	int n,c,v1,v2,R,P;
	cout<<"Enter the number of nodes: ";
	cin>>n;
	vector<list<int> > adjList(n+1);
	map<int,int> check;
	do
	{
		cout<<"Enter an edge (vertex1 vertex2)"<<endl;
		cin>>v1>>v2;
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
		cout<<"Do you wish to add one more edge?(0/1): ";
		cin>>(c);
	}while(c==1);
	cout<<"Enter the root vertex of this tree: ";
	cin>>R;
	P=R;
	cout<<"\nThe Depth First Traversal is: ";
	std::stack<int> S;
	S.push(R);
	check.insert(make_pair(R,R));
	cout<<R;
	list<int>::iterator itr;
	while(!S.empty())
	{
		P=S.top();
		itr=adjList[P].begin();
		while(itr!=adjList[P].end())
		{
			if (check.find(*itr)==check.end())
			{
				cout<<*itr;
				check.insert(make_pair(*itr,*itr));
				S.push(*itr);
				P=S.top();
				itr=adjList[P].begin();
				continue;
			}
			itr++;
		}	
		S.pop();
	}
	return 1;
}
