#include<iostream>
#include<stdlib.h>
using namespace std;

void printfun(int m,int l,int arr[][6]){
	int i,j;
for(i=0;i<m;i++){
		for(j=0;j<l;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void takeip(int m,int l,int arr[][6]){
	int i,j;
	for(i=0;i<m;i++){
		for(j=0;j<l;j++){
			arr[i][j]=rand()%2;
		}
	}
	//printing
		
	
}



void addparity(int m,int l,int arr[][6]){
	int i,j;
	for(i=0;i<m;i++){
		int count=0;
		for(j=0;j<l;j++){
			  count+=arr[i][j];
		}
		if(count%2==0){
			arr[i][l]=0;
		}
		else
		   arr[i][l]=1;
	}
	for(i=0;i<=l;i++){
		int count=0;
		for(j=0;j<m;j++){
			  count+=arr[j][i];
		}
		if(count%2==0){
			arr[m][i]=0;
		}
		else
		   arr[m][i]=1;
	}
	cout<<"after adding parity \n";
	
}

void addnoise(int m,int l,int arr[][6]){
	int i=rand()%m;
	int j=rand()%l;
	cout<<"row n col value are "<<i<<" and "<<j<<"\n";
	if(arr[i][j]==1)
	 arr[i][j]=0;
	else
	  arr[i][j]=1;
}

void check(int m,int l,int arr[][6]){
		int i,j;
	for(i=0;i<m;i++){
		int count=0;
		for(j=0;j<l;j++){
			  count+=arr[i][j];
		}
		if(count%2!=arr[i][l]){
			cout<<"there is an error in row no : "<<i<<"\n";
		}

	}
	for(i=0;i<l;i++){
		int count=0;
		for(j=0;j<m;j++){
			  count+=arr[j][i];
		}
		if(count%2!=arr[m][i]){
		cout<<"there is an error in col no : "<<i<<"\n";
		}
	
	
}
}

int main(){
	int m,l;
	//max size of each msg is 5 n max number of msgs is 5
	cout<<"enter number of messages \n";
	cin>>m;
	cout<<" enter length of each message \n";
	cin>>l;
	
	int arr[6][6];
	
	takeip(m,l,arr);
	printfun(m,l,arr);  
	
	addparity(m,l,arr);
	printfun(m+1,l+1,arr);
	
	addnoise(m,l,arr);
	printfun(m+1,l+1,arr);
	
	check(m,l,arr);
	printfun(m+1,l+1,arr);
	
     return 0;
}
