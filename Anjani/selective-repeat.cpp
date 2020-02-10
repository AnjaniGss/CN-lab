#include<iostream>
#include<windows.h>
#include<cstdlib>
using namespace std;
int s=0;

int receiver(int j,int ws){
	int a=rand()%ws;
	if(j==a)
	return 0;
	cout<<"frame "<<j<< " is received \n";
	return 1;
}
void sender(int j){
	s=s+1;
	cout<<"frame "<<j<<" is sent by the sender \n";

}
int main(){
	int i,n,j,ack,ws;
	cout<<"enter number of messages\n";
	cin>>n;
    cout<<"enter window size\n";
    cin>>ws;
	for(i=0;i<n/ws;i++){
		for(j=0;j<ws;j++){
			sender(j);
			ack=receiver(j,ws);
			if(ack==0){
				cout<<"frame "<<j<<" failed to send,nak is received , resend \n";
				sender(j);
				receiver(j,ws);
				
			}
	
	
	
		
	}
	cout<<"acknowledgement for next frame is received\n";
	}
	cout<<"total no. of times sent : "<<s;

	return 0;
	
	
}
