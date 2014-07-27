#include<stdio.h>
#include<vector>
#include<map>
using namespace std;
int main(){
	int numCol, numRow, pixel;
	while(scanf("%i %i", &numRow, &numCol)!=EOF){
		if(numCol==0)
			break;
		bool **pixels=new bool*[numRow];
		for(int i=0; i<numRow; i++)
			pixels[i]=new bool[numCol];
		//printf("here5\n");

		//		printf("here1\n");
		for(int i=0; i<numRow; i++){
			for(int j=0; j<numCol; j++){
				scanf("%i", &pixel);
				pixels[i][j]=pixel;
			}
		}
		//printf("here2\n");

		int **parts=new int*[numRow];
		for(int i=0; i<numRow; i++)
			parts[i]=new int[numCol];

		for(int i=0; i<numRow; i++)
			for(int j=0; j<numCol; j++)
				parts[i][j]=0;

		vector<int> sizes(1, 0);
		//printf("here3\n");

		int numParts=0;
		for(int i=0; i<numRow; i++){
			for(int j=0; j<numCol; j++){
				//printf("loopvars: %i %i\n", i, j);
				if(pixels[i][j]==false)
					continue;
				if(i>0 && parts[i-1][j] && j>0 && parts[i][j-1]){
					if(parts[i][j-1]==parts[i-1][j]){
						parts[i][j]=parts[i-1][j];
						sizes[parts[i][j]]++;
					}
					else if(parts[i][j-1]>parts[i-1][j]){
						int x=parts[i][j-1];
						sizes[parts[i-1][j]]+=(1+sizes[parts[i][j-1]]);
						sizes[parts[i][j-1]]=0;
						for(int k=0; k<numRow; k++)
							if(parts[k][j-1]==x)
								parts[k][j-1]=parts[i-1][j];
						for(int k=0; k<numCol; k++)
							if(parts[i][k]==x)
								parts[i][k]=parts[i-1][j];
						parts[i][j]=parts[i][j-1]=parts[i-1][j];

					}
					else{	
						int x=parts[i-1][j];
						sizes[parts[i][j-1]]+=(1+sizes[parts[i-1][j]]);
						sizes[parts[i-1][j]]=0;
						for(int k=0; k<numRow; k++)
							if(parts[k][j]==x)
								parts[k][j]=parts[i][j-1];
						for(int k=0; k<numCol; k++)
							if(parts[i-1][k]==x)
								parts[i-1][k]=parts[i][j-1];
						parts[i][j]=parts[i-1][j]=parts[i][j-1];
					}


				}
				else if(j>0 && parts[i][j-1]){
					parts[i][j]=parts[i][j-1];
					sizes[parts[i][j]]++;
				}
				else if(i>0 && parts[i-1][j]){
					parts[i][j]=parts[i-1][j];
					sizes[parts[i][j]]++;
				}
				else{
					parts[i][j]=++numParts;
					sizes.push_back(1);
				}

			}
		}
		//printf("here4\n");
//			/*	
		numParts=0;
		map<int, int> ans;
		for(int i=1; i<sizes.size(); i++)
		{	if(sizes[i]) 
			{
				ans[sizes[i]]++;
				numParts++;
			}
		}
		printf("%i\n", numParts);
		for(map<int, int>::iterator it=ans.begin(); it!=ans.end(); it++)
			printf("%i %i\n", it->first, it->second);
//				 */
		/*
		   for(int i=0; i<numRow; i++){
		   for(int j=0; j<numCol; j++)
		   printf("%i ", parts[i][j]);
		   printf("\n");
		   }
		   printf("\n");
		 */
		for(int i=0; i<numRow; i++){
			delete[] pixels[i];
			delete[] parts[i];
		}
		delete[] pixels;
		delete[] parts;

	}
	return 0;

}


