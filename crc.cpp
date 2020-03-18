/*
Name : Sarang Barshikar
Title : CRC (Cyclic Redundancy Check)
*/

#include<iostream>
using namespace std;

int *getdh(int arr1[],int arr2[],int divarr[],int n,int l,int finallen,int flag)
{
	int i,j;
	int k=0;
	int divarr2[10];
	if(l<finallen)
	{

		for(i=0;i<4;i++)
		{

			if(divarr[1] == 1 )
			{
				//if 1 xor with g(x)
					if(arr1[i] == divarr[i+1])
					{						
						divarr2[k] = 0;  					
						k++;
					}
					else if(arr1[i]!= divarr[i+1])
					{
						divarr2[k] = 1;
						k++;  
					}	
			}
			else if(divarr[1] == 0)
			{
				//if 1 xor with 0
				
					if(divarr[i+1]==0)
					{
						divarr2[k] = 0;  
						k++;
					}
					else 
					{
						divarr2[k] = 1;
						k++;  
					}
			}	
		
				
		}
			int o=k+1;
			l=l+1;
			//add next element to array
			divarr2[4] = arr2[l];
			
			n=n+1;
			getdh(arr1,arr2,divarr2,n,l,finallen,flag);		
	}
	else
	{
		//After all the bits are completed 
		
		int p=0,y=0,j=0,k=0,checkzero=0;
		static int remainder[10];

		cout<<endl<<"----------------Remainder--------------- "<<endl;
		for(i=1;i<4;i++)
		{
			cout<<divarr[i];
			if(divarr[i]==0)
			{
				//Check if all the values are 0 
				checkzero++;
			}	
			remainder[p] = divarr[i];
			p++;
		}
		
		cout<<endl<<"-----------------------------------------"<<endl;
		cout<<endl<<endl;
			if(checkzero ==3 && flag==1)
			{
				//if all the values are zero & the flag is 1 i.e the message is reciever the message is correct
				cout<<endl<<"Sender & Receiver Message Match"<<endl;
				return 0;
			}
			else if(checkzero!=3 && flag==1)
			{
				//if all the values are not zero & the flag is 1 i.e the message is reciever the message is incorrect
				cout<<endl<<"Sender & Receiver Message Does Not Match"<<endl;
			}
			
		//append remainder to our actual m(x) without trailing zero
		y=finallen-3;		
		for(i=y;i<y+p;i++)
		{
			if(k==p)
			{
				break;
			}
				
				arr2[i] = remainder[k];
				k++;
		}
		
    	return arr2;
	}
	
}
int main()
{
	int arr1[] = {1,0,1,0};
	int arr2[] = {0,1,0,1,1,1,0,1,0};
	int arr3[]=  {0,1,0,1,1,1,0,0,0,0};
	int arr4[]=  {0,1,0,1,0,0,0,0,1};
	int divarr[10];
	int *n;
	int gx[10],mx[10],degree,glen,mlen;
	int receiver[10],count=0;
	
	mx[0] = 0;
	
	cout<<"Enter the length of g(x) : "<<endl;
	cin>>glen;
	cout<<"Enter the length of m(x) : "<<endl;
	cin>>mlen;
	
	//---------------------------------------------
	cout<<"Enter the G(X) : "<<endl;
	for(int i=0;i<glen;i++)
	{
		cin>>gx[i];
	}
	
	cout<<"Enter the M(X) : "<<endl;
	for(int i=1;i<=mlen;i++)
	{
		cin>>mx[i];
	}
	//--------------------Accept degreee---------------------------
	
	cout<<"Enter the highest degree of the equation - "<<endl;
	cin>>degree;
	 
	 
	 
	//--------------------APPEND TRAILING ZEROES----------------------------------------
	mlen = mlen+1;
	for(int i=mlen;i<=mlen+degree;i++)
	{
		mx[i] = 0;
	}

	//--------------------Get the first four elements----------------------------------------
	for(int i=0;i<glen+1;i++)
	{	
		divarr[i] = mx[i];
	}
	
	//int n= getdh(arr1,arr2,divarr,0,4);
	n= getdh(gx,mx,divarr,0,4,mlen+degree,0);
	
	cout<<"----------------Receiver Message-------------------"<<endl;
	for ( int i = 0; i <10; i++ ) {
     receiver[i]= *(n + i);
     cout<<receiver[i];
     count++;
   }
   
   for(int i=0;i<glen+1;i++)
	{	
		divarr[i] = receiver[i];
	}
	
	//For receiver message
   	n= getdh(gx,receiver,divarr,0,4,count,1);
	

	return 0;
}
