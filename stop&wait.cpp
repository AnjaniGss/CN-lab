#include<iostream>
#include<windows.h>
#include<cstdlib>
using namespace std;
int receiver(string s){
	if(s=="")
	return 0;
	cout<<"message \""<<s<< "\"is received and ack is sent \n";
	return 1;
}
void sender(double tt){
	cout<<"message is sent by the sender and tt is "<<tt<<" seconds\n";

}
int main(){
	int i,ack;
	double tt,tp,a,sum=0,n;
	cout<<"enter number of messages\n";
	cin>>n;

	string s;
	for(i=0;i<n;i++){
		cout<<"enter the msg \n";
		cin>>s;
		tt=rand()%5;
		Sleep(tt*1000);
		sender(tt);
		ack=receiver(s);
		tp=rand()%4;
		Sleep(tp*1000);
	    if(tp>2){
	    	cout<<"time-out and ack not received , resending\n";
	    	sender(tt);
	    	ack=receiver(s);
	    	tp=rand()%4;
	    	Sleep(tp*1000);
	    		if(ack)
		cout<<"ack received and tp is "<<tp<<" seconds\n";
		a=((tt/(tt+2*tp))*100);
		sum=sum+a;
	    	 
		}
		else{
		
		if(ack)
		cout<<"ack received and tp is "<<tp<<"\n";
		a=((tt/(tt+2*tp))*100);
		sum=sum+a;
	}
	}
	
	double e=sum/n;;
	cout<<"efficiency is "<<e;
	return 0;
	
	
}
