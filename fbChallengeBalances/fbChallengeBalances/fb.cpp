#include<stdio.h>
#include<vector>
using namespace std;

struct bal{
	double leftWeight, rightWeight;
	vector<int> leftBalances, rightBalances;
};

double calcWeight(int i, bal state[], double arr[][2], double weights[])
{
	if(weights[i]!=-1)
		return weights[i];
	else{
		double leftWeights=0, rightWeights=0;

		for(int j=0; j<state[i].leftBalances.size(); j++)
			leftWeights+=calcWeight(state[i].leftBalances[j], state, arr, weights);

		for(int j=0; j<state[i].rightBalances.size(); j++)
			rightWeights+=calcWeight(state[i].rightBalances[j], state, arr, weights);

		weights[i]=state[i].leftWeight+state[i].rightWeight+leftWeights+rightWeights+10;
		return weights[i];
	}
}

void balance(int i, bal state[], double arr[][2], double weights[])
{
	for(int j=0; j<state[i].leftBalances.size(); j++)
		balance(state[i].leftBalances[j], state, arr, weights);

	for(int j=0; j<state[i].rightBalances.size(); j++)
		balance(state[i].rightBalances[j], state, arr, weights);

	double totalLeftWeight=state[i].leftWeight;

	for(int j=0; j<state[i].leftBalances.size(); j++)
		totalLeftWeight+=calcWeight(state[i].leftBalances[j], state, arr, weights);

	double totalRightWeight=state[i].rightWeight;

	for(int j=0; j<state[i].rightBalances.size(); j++)
		totalRightWeight+=calcWeight(state[i].rightBalances[j], state, arr, weights);

	if(totalLeftWeight > totalRightWeight)
	{
		arr[i][1]+=(totalLeftWeight-totalRightWeight);
		state[i].rightWeight+=arr[i][1];
		if(weights[i]!=-1)
			weights[i]+=arr[i][1];
	}
	else if(totalLeftWeight < totalRightWeight)
	{
		arr[i][0]+=(totalRightWeight-totalLeftWeight);
		state[i].leftWeight+=arr[i][0];
		if(weights[i]!=-1)
			weights[i]=arr[i][0];
	}
	else
	{
		//printf("i=%icase 3\n", i);
		//arr[i][0]=0;
		//arr[i][0]=0;
	}
}


int main()
{
	int n;
	scanf("%i", &n);
	double arr[n][2];
	bal state[n];
	double weights[n];

	for(int i=0; i<n; i++)
	{
		arr[i][0]=0;
		arr[i][1]=0;
		weights[i]=-1;
	}
	for(int i=0; i<n; i++)
	{
		scanf("%lf", &state[i].leftWeight);
		while(1)
		{
			char c;
			scanf("%c", &c);
			if(c=='\n')
				break;
			int balNo;
			scanf("%i", &balNo);
			state[i].leftBalances.push_back(balNo);
		}
		scanf("%lf", &state[i].rightWeight);
		while(1)
		{
			char c;
			scanf("%c", &c);
			if(c=='\n')
				break;
			int balNo;
			scanf("%i", &balNo);
			state[i].rightBalances.push_back(balNo);
		}
	}

	for(int i=0; i<n; i++)
	{
		balance(i, state, arr, weights);
	}
	

	for(int i=0; i<n; i++)
	{
		printf("%i: %.lf %.lf\n", i, arr[i][0], arr[i][1]);
	}

}



	/*printf("%i\n", n);
	for(int i=0; i<n; i++)
	{
		printf("%.lf ", (state[i]).leftWeight);
		for(int j=0; j<((state[i]).leftBalances).size(); j++)
		{
			printf("%i ", (state[i]).leftBalances[j]);
		}
		printf("\n");
		printf("%.lf ", (state[i]).rightWeight);
		for(int j=0; j<((state[i]).rightBalances).size(); j++)
		{
			printf("%i ", (state[i]).rightBalances[j]);
		}
		printf("\n");
	}*/