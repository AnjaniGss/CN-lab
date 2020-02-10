#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
 int sum[15]; 
 int comp[15];


int wholebtod(int arr[15]){

	int nsum=0;
	int n=11;
	int i,j;
	for(j=0;j<3;j++){
	int num=0;
	for(i=0;i<4;i++){
		num=num+arr[n]*pow(2,i);
		n--;
	}
	cout<<"num is "<<num<<"\n";
	nsum=nsum+num;
	
    }
    cout<<"sum of num is "<<nsum<<"\n";
    return nsum;
   }
   

 void sum_to_binary(int nsum){
	
 
     int i = 0; 
    while (nsum > 0) { 
  
        sum[i] = nsum % 2; 
        nsum = nsum / 2; 
        i++; 
    } 
    int ndigits=i;
    cout<<"binary number of the sum is ";
    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << sum[j]; 
        
     cout<<"\n";   
    int comp[ndigits];    
    cout<<"one's complement of the binary number is ";
    
    for(i=0;i<ndigits;i++){
    	if(sum[i]==1){
    		comp[i]=0;
		}
		else
		 comp[i]=1;
	}
	 for (int j = ndigits - 1; j >= 0; j--) 
        cout << comp[j];
		cout<<"\n"; 
	
} 
int main(){
	int i,j;
	int arr[15];
	for(i=0;i<12;i++){
		arr[i]=rand()%2;
	}
	for(i=0;i<12;i++)
	cout<<arr[i];
	int nsum=wholebtod(arr);
	sum_to_binary(nsum);
	cout<<"enter msg received which is of size 12 bits ";
	int rec[15];
	for(i=0;i<12;i++){
		cin>>rec[i];
	}
	int nsum1=wholebtod(rec);
	if(nsum1!=nsum)
	cout<<"data is modified";
	
	

}

	
	
