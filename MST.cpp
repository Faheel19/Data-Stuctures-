#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

	
/*  * Class Declaration  */
class MST{
	public:
		int n=7;
		int parent[7];
		
// Functions
		int find(int i){
			while (parent[i] != i)
			i = parent[i];
			return i;
		}		
		void union_(int i, int j){
			int a = find(i);
			int b = find(j);
			parent[a] = b;
		}
		void kruskal(int n,int cost_M[][100]){
			int mincost = 0; // Cost of min MST.
			// Initialize sets of disjoint sets.
			for (int i = 0; i < n; i++)
				parent[i] = i;
			// Include minimum weight edges one by one
			int count = 0;
			cout<<"THE Minimum Spanning Tree :"<<endl;
			while (count < n - 1) {
				int min = INT_MAX, a = -1, b = -1;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < n; j++) {
						if (find(i) != find(j) && cost_M[i][j] < min) {
							min = cost_M[i][j];
							a = i;
							b = j;
						}
					}
				}		
  
		union_(a, b);
		cout<<"Edge "<<count++<<"= (v"<<a<<","<<b<<"); Cost= "<<min<<endl;
		mincost += min;
			}
	printf("\n Minimum cost= %d \n", mincost);
		}
};

int main() {
   MST list;
   ifstream inFile("input.txt");
   string line;
   int n;
   inFile>>n; //get data
   int cost[n][100];
   int j,i,data;
   //initialize next matrix as intmax
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
       cost[i][j]=INT_MAX;
       }
   }
   //fill next  matrix with data 
   while(getline(inFile,line)){
       stringstream ss(line);
       ss >> i;
       ss >> j;
       ss >> data;
       cost[i][j]=data;
   cost[j][i]=data;
   }

  
   list.kruskal(n,cost);
}
