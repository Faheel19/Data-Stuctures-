#include <iostream>
#include <fstream>
using namespace std;

/*  * Class Declaration  */
class FG{
	public:
		
// Functions
void floyd(int **F,int **W,int n){

  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        if(F[i][j]>(F[i][k]+F[k][j])){
          F[i][j]=F[i][k]+F[k][j];
          W[i][j]=k+1;
        }
      }
    }
  }
 }


//recurisive route
void ShortRoute(int **W,int q,int r){
  if(W[q][r]!=0){
    ShortRoute(W,q,W[q][r]-1);
    cout<<W[q][r]<<" ";
    ShortRoute(W,W[q][r]-1,r);
  }
}

void getRoute(int **W,int i,int j){
  cout<<i+1<<" ";
  ShortRoute(W,i,j);
  cout<<j+1;
}
};

int main() {
  FG list;
  //file name variable
  string filename;
  cout<<"Enter input file name: ";
  cin>>filename;  
  //creating a input fstream
  ifstream f(filename);
  
  //file not found 
  if(!f){
    cout<<"File not found!";
    return 0;
  }
  //getting the first of line integers 
  int n;
  f>>n;
  
  int **F = new int*[n];
  for(int i=0; i<n; i++){
    F[i] = new int[n];
  }

  int **W=new int*[n];
  for(int i=0; i<n; i++){
    W[i]=new int[n];
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      f>>F[i][j]; //taking 
      W[i][j]=0;
    }
  }

  //close the file
  f.close();
  //floyd algrithm 
  list.floyd(F,W,n);
  
  cout<<"\nShortest path lengths:"<<endl;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<F[i][j]<<" ";
    }
    cout<<endl;
  }

  //user input to ask for shortest path
  int v1,v2;
  while(true){
  	
    //taking the both values
    cout<<"\nEnter two vertex numbers: ";
    cin>>v1;
    
    //-1 to quit
    if(v1 == -1) break;  
    cin>>v2;
    cout<<"\tShortest path: ";
    
    list.getRoute(W,v1-1,v2-1);
  }

}
