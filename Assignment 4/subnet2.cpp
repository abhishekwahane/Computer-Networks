//Devesh Bhogre
//TY-CSE-PANEL-2-Batch-B1-PB43

#include<bits/stdc++.h>
#include<sstream>
using namespace std;

void DecToBinary(int n) 
{ 
  if(n==0)
        {
            cout<<0;      
        }
  else{
  int binaryNum[32]; 
  int i = 0; 
  while (n > 0) 
        { 
             binaryNum[i] = n % 2; 
              n = n / 2; 
              i++; 
        } 
  for (int j = i - 1; j >= 0; j--) 
             cout << binaryNum[j];
       } 
} 

int main()
{
	string ip;
	char ch;
	int i,pos[10],j=0;
	cout<<"Enter the ip address: ";
	cin>>ip;
	int len=ip.length();
	for(i=0;i<len;i++)
	{
		if(ip[i]=='.')
		{			
			pos[j]=i;
			j++;
		}	
	}
	
	/*for(j=0;j<3;j++)
	{
		cout<<pos[j]<<endl;
	}*/
	string temp=ip.substr(0,pos[0]);
	int a[4];
	stringstream obj(temp);
	obj>>a[0];
	stringstream obj1(ip.substr(pos[0]+1,pos[1]));
	obj1>>a[1];
	stringstream obj2(ip.substr(pos[1]+1,pos[2]));
	obj2>>a[2];
	stringstream obj3(ip.substr(pos[2]+1,len));
	obj3>>a[3];
	char arr1[32],arr2[32],arrr3[32],arr4[32];
	if(a[0]>=0 && a[0]<=126)                    
	{
	              ch='A';
		cout<<"Class A"<<endl;
		cout<<"subnet mask: 255.0.0.0"<<endl;
		cout<<"Network id: "<<ip.substr(0,pos[0])<<".0.0.0"<<endl;
		cout<<"Host id range: "<<ip.substr(0,pos[0])<<".0.0.0"<<" - "<<ip.substr(0,pos[0])<<".255.255.255"<<endl; 
	}                                                            
	else if(a[0]>=128 && a[0]<=191)
	{
	              ch='B';
		cout<<"Class B"<<endl;
		cout<<"subnet mask: 255.255.0.0"<<endl;
		cout<<"Network id: "<<ip.substr(0,pos[1])<<".0.0"<<endl;
		cout<<"Host id range: "<<ip.substr(0,pos[1])<<".0.0"<<" - "<<ip.substr(0,pos[1])<<".255.255"<<endl;
	}
	else if(a[0]>=192 && a[0]<=224)
	{
	              ch='C';
		cout<<"Class c"<<endl;
		cout<<"subnet mask: 255.255.255.0"<<endl;
		cout<<"Network id: "<<ip.substr(0,pos[2])<<".0"<<endl;
		cout<<"Host id range: "<<ip.substr(0,pos[2])<<".0"<<" - "<<ip.substr(0,pos[2])<<".255"<<endl;
	}
	else if(a[0]>=224 && a[0]<=239)
	{
	              ch='D';
		cout<<"Class D"<<endl;
		cout<<"subnet mask: Reserved"<<endl;
	}
	else if(a[0]==127)
	{
		cout<<"Reserved IP Address"<<endl;	
	}
	cout<<"Binary Equivalent of IP Address is- "<<endl;
	for(int i=0;i<4;i++)
	{
	              DecToBinary(a[i]);
	    if(i!=3)
	            {
	                cout<<".";        
	            }
	 }
	cout<<endl;
	int subs,div,div1,rem;
	cout<<"Enter the number of subnets"<<endl;
	cin>>subs;
	div=(int)log2(subs);
	if(pow(2,div)<subs)
	{
	  subs=pow(2,div+1);
	}
	cout<<"The starting address of host id: ";
	if(ch=='C')
	{
	    if(subs>pow(2,8))
	            {
	                cout<<"Out of Range"<<endl ;  
	            }
	    else
	            {
	                  cout<<a[0]<<"."<<a[1]<<"."<<a[2]<<"."<<0<<endl;
	            }
	    cout<<"The number of addresses in every subnet is: "<<256/subs<<endl;
	}
	if(ch=='B')
	{
	    if(subs>pow(2,16))
	            {
	                cout<<"Out of Range"<<endl;   
	            }
	    else
	            {
	                 cout<<a[0]<<"."<<a[1]<<"."<<0<<"."<<0<<endl;
	            }
	    cout<<"The number of addresses in every subnet is: "<<pow(2,16)/subs<<endl;
	}
	if(ch=='A')
	{
	        cout<<a[0]<<"."<<0<<"."<<0<<"."<<0<<endl;
	        cout<<"The number of addresses in every subnet is: "<<pow(2,24)/subs<<endl;   
	}
	
	return 0;
}

