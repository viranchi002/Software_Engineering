#include <bits/stdc++.h>
using namespace std;

int usercnt=0;

class passanger
{
	public:
	string name;
	int age;
	string sex;	
};

class train
{
	public:
	string name;
	string number;
	string type;
	string quota;
	string start,dest;
	int availibleseat,totalseat,sleeper,ac2,ac3,fares,fare3ac,fare2ac,sz;
	string stations[15];
		
};

class user
{
	public:
	string id;
	string password;
	string name;
	//string address[100];
	int dd,mm,yy;
};

user A[1000];

int trains;

train tt[100];

int main()
{   begin:
	printf("Enter\n 1)For existing Users\n 2) For New users \n3) For Admin\n");
	
	int choice,i;
	scanf("%d",&choice);
	
	if(choice==3)
	{
		g1:printf("Enter Admin Id and password\n");
		string s1,s2;
		cin>>s1>>s2;
		
		if(s1!="Het" || s2!="12345678")
		{
			printf("Invalid ID\n");
			goto g1;
		}
		
		
		
		while(1)
		{   printf("Enter 1 to continue/2 to stop entering Train Details\n");
			int f;
			cin>>f;
			
			if(f==2)
			    goto begin;
			cout<<"enter name\n";
			string nam;
			cin>>nam;
			
			cout<<"Enter Starting Point And Destination\n";
			
			string s,e;
			cin>>s>>e;
			
			int i,N;
			
			cout<<"Enter No. of stations\n";
			cin>>N;
			
			string X[12];
			
			for (i=0;i<N;i++)
			cin>>X[i];
			
			trains++;
			
			tt[trains].sz=N;
			tt[trains].name=nam;
			tt[trains].start=s;
			tt[trains].dest=e;
			tt[trains].stations[0]=s;
			for (i=1;i<=N;i++)
			tt[trains].stations[i]=X[i+1];
			tt[trains].stations[i]=e;
			tt[trains].sz++;
			cout<<"Enter Available seats for 1)sleeper 2)3rd AC 3) 2nd AC\n";
			cin>>tt[trains].sleeper>>tt[trains].ac3>>tt[trains].ac3;
			
			cout<<"Enter Cost for 1)sleeper 2)3rd AC 3) 2nd AC\n";
			cin>>tt[trains].fares>>tt[trains].fare3ac>>tt[trains].fare2ac;
			
		}
		
		
	}
	
	if(choice==1)
	{
		f1:printf("Enter Id & Password\n");
		string s1,s2;
		cin>>s1>>s2;
		
		int p=-1;
		for (i=1;i<=usercnt;i++)
		{
			if(A[i].id==s1 && A[i].password==s2)
			{
				p=i;
				break;
			}
		}
		
		if(p==-1)
		{
			printf("Invalid Username Or Password\n");
			goto f1;
		}
		
		printf("Welcome ");
		cout<<A[p].name<<endl;
	}
	
	else
	{
		f2:printf("Enter A unique id\n");
		
		string s1,s2,s3,s4,s5;
		
		cin>>s1;
		
		int p=-1;
		for (i=1;i<=usercnt;i++)
		{
			if(s1==A[i].id)
			{
				p=i;
				break;
			}
		}
		
		if(p!=-1)
		{
			printf("User ID is already Taken\n");
			goto f2;
		}
		
		f3:printf("Enter Password\n");
		cin>>s2;
		
		if(s2.size()<6)
		{
			cout<<"Password is too short\n";
			goto f3;
		}
		
		f4:printf("Re-enter password :");
		cin>>s3;
		
		if(s3!=s2)
		{
			printf("Both passwords are not matching\n");
			goto f4;
		}
		
		cout<<"Enter Name\n";
		cin>>s4;
		int d,m,y;
		
		cout<<"Enter Date Month and Year of Birth\n";
		cin>>d>>m>>y;
		
		usercnt++;
		int c=usercnt;
		
		printf("Successfully created ID for user ");
		cout<<s4<<endl;
		
		A[c].id=s1;
		A[c].password=s2;
		A[c].name=s4;
		A[c].dd=d;
		A[c].mm=m;
		A[c].yy=y;
		
	}
	
	string s,e;
	
	cout<<"Enter Starting Point of Journey And End Point Of Journey\n";
	cin>>s>>e;
	int j;
	vector<int>indx;
	indx.clear();
	cout<<"no of trains="<<trains<<endl;
	for (i=1;i<=trains;i++)
	{   
		int found=0;
		for (j=0;j<=tt[i].sz;j++)
		{   cout<<tt[i].stations[j]<<"::";   
			if(!found)
			{
				if(tt[i].stations[j]==s)
				{
					found++;
				}
			}
			
			else
			{
				if(tt[i].stations[j]==e)
				{
					found++;
				}
			}
			
			if(found==2)
			break;
		}
		
		if(found==2)
		indx.push_back(i);
		
	}
	
	cout<<"Enter Class 1) For sleeper 2) For 3AC 3) for 2AC\n";
	
	int z;
	cin>>z;
	
	int req;
	cout<<"Enter Required seat\n";
	cin>>req;
	
	vector<int>ok;
	ok.clear();
	
	if(z==1)
	{
		for (i=0;i<indx.size();i++)
		{
			if(tt[indx[i]].sleeper>=req)
			ok.push_back(indx[i]);
		}	
	}
	
	if(z==2)
	{
		for (i=0;i<indx.size();i++)
		{
			if(tt[indx[i]].ac3>=req)
			ok.push_back(indx[i]);
		}	
	}
	
	if(z==3)
	{
		for (i=0;i<indx.size();i++)
		{
			if(tt[indx[i]].ac2>=req)
			ok.push_back(indx[i]);
		}	
	}
	
	if(!ok.size())
	{
		cout<<"No Suitable Friend found\n";
		return 0;
	}
	
	cout<<"Suitable Trains and fares\n";
	for (i=0;i<ok.size();i++)
	{
		cout<<tt[ok[i]].number<<" "<<tt[ok[i]].name<<" ";
		
		if(z==1)
		{
			cout<<tt[ok[i]].fares*req<<endl;
		}
		
		else if(z==2)
		{
			cout<<tt[ok[i]].fare3ac*req<<endl;
		}
		
		else
		cout<<tt[ok[i]].fare2ac*req<<endl;
		
	}
	
	passanger h[req+5];
	cout<<"Enter User Details to proceed\n";
	
	cout<<"Enter Name,age and sex\n";
	
	for (i=1;i<=req;i++)
	cin>>h[i].name>>h[i].age>>h[i].sex;
	
	cout<<"Choose one of the option for payment 1) Net banking 2) credit card 3)Debit card\n";
	int opt;
	
	cin>>opt;
	
	if(opt==1)
	{
		cout<<"Enter Id & Password\n";
		
		string z1,z2;
		cin>>z1>>z2;
		
		if(z1=="admin" && z2=="admin")
		{
			printf("Amount deducted and transaction successfully completed\n");
		}
		
		else cout<<"Error in username/password\n";
	}
	
	else
	{
		cout<<"Enter PIN\n";
		
		int pin;
		cin>>pin;
		
		if(pin==1234)
		{
				printf("Amount deducted and transaction successfully completed\n");
		}
		
		
			else cout<<"Error in username/password\n";
		
	}
	
}
