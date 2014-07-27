#include<stdio.h>
#include<algorithm>
using namespace std;

int level(int n)
{
	int i=1;
	while(n>>=1 > 0)
	{
		i++;
	}
	return i;

}

struct node{
	int count;
	int max;
	node()
	{
		count=0;
		max=0;
	}
}tree[1<<20];

void add(int treeIndex, int i, int value, int l)
{
	if(i==0)
		return;
	if(i>=(1<<19))
	{//the node has no children.
	//	printf("Case1: %i\n", treeIndex);
		tree[treeIndex].count+=value;
		tree[treeIndex].max+=value;
		return;
	}

	if(i>=(1<<(20-l)))
	{
	//	printf("Case2: %i %i\n", treeIndex, i);
		//update all leaves under the given node.
		tree[treeIndex].count+=value;
		tree[treeIndex].max+=value;
		tree[treeIndex>>1].max=tree[treeIndex>>1].count+max(tree[treeIndex].max, tree[treeIndex+1].max);
	}

	
	else if(i>=(1<<(19-l)))
	{	
	//	printf("Case3: %i %i\n", treeIndex, i);
		int childIndex=treeIndex<<1;
		//update all leaves under left child
		//update i-l1 leaves under right child.
		tree[childIndex].count+=value;
		tree[childIndex].max+=value;
		add((childIndex)+1, i-(1<<(19-l)), value, l+1);
		tree[treeIndex].max=tree[treeIndex].count+max(tree[childIndex].max, tree[childIndex+1].max);
	}
	else
	{
	//	printf("Case4: %i %i\n", treeIndex, i);
		int childIndex=treeIndex<<1;
		add(childIndex, i, value, l+1);
		tree[treeIndex].max=tree[treeIndex].count+max(tree[childIndex].max, tree[childIndex+1].max);
	}
}

int findmax()
{
	return tree[1].max;
}

int main()
{
	//query system
	char c;
	while(true)
	{
		scanf("%c", &c);
		if(c=='a')
		{
			int i, value;
			scanf("%i %i", &i, &value);
			add(1, i, value,1);
		}
		else
		{
			printf("%i\n", findmax());
		}
		printf("\n\n");
	}
}