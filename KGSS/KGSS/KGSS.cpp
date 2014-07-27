#include<stdio.h>
#include<algorithm>
#include<map>
using namespace std;

/*The problem involves a sequence of 500000 integers. 
We solve the problem by constructing a complete
binary tree of 2^19(=524288) leaves. Total number
of nodes in the tree will be 2^20-1.
*/
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

/*there is no use of tree[0]. Start labelling the nodes
from 1. Left child of i=2*i, right child of i=2*i+1.
Height of the tree is 20. */


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
	/*the number of leaves in the left child=number of 
	leaves in right child=2^(height-level-1). We
	need to calculate the level of the index i. */

	/*Now. The node with index treeIndex is at level
	floor(log2(treeIndex))+1 */

	//int l=level(treeIndex);
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
/*	char c;
	while(true)
	{
		scanf("%c", &c);
		if(c=='a')
		{
			int i, value;
			scanf("%i %i", &i, &value);
			add(1, i, value);
		}
		else
		{
			printf("%i\n", findmax());
		}
		printf("\n\n");
	}
*/
	
}