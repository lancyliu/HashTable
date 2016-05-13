// ChainingHash.cpp : 
/***
Use division, mid-square and Fibonacci method
Chaining to solve collisions.
This program is an implemention of chaining hash table,. Included three hash function:
16 bits, from -32768 to 32767. so in fibonacci method, the limit of input is 32767.
**/

#include "stdafx.h"
#include "stdafx.h"
#include <list>   
#include <algorithm>   
#include "Hashtable.h"  
#include<iostream>
using namespace std;  
#include"ctime"
#include"time.h"


#define AUTO_NUMBER 10500   //  This it the amout of test number 
#define CLOCK_PER_SEC ((clock_t)1000)

int _tmain(int argc, _TCHAR* argv[])
{
	HashTable h; 
	int index;
	clock_t start;
	clock_t finish;
	cout<<"-----First of all, choose the hash function-------Follow the description"<<endl;
	cout<<"division:           enter 1"<<endl;
	cout<<"middle square:      enter 2"<<endl;
	cout<<"fibonacci:          enter 3"<<endl;
	cin>>index;
/**following is the auto insert part, randomly choose some number to insert to the hash table ***/	
	cout<<"press 1 to auto insert numbers in hash table    " ;
	int i;
	cin>>i;
	if(i==1)
	{
		srand(time(0));
		int r = 0;
		start = clock();
		while(r < AUTO_NUMBER)
		{
           i = rand();
		   if(index==1) 
		   {
			   h.Insert(i,index);
			   r++;
		   }
		   else if(index==2)
		   {		   
			  if(i< 46300)
		     {
	            h.Insert(i,index);
				 r++;
		      }
		   }
		   else if(index==3)
		   {
		      if(i <= 32767)
			  {
				  h.Insert(i,index);
				  r++;
			  }
		   }
         }
		finish = clock();
		double time = (double)(finish - start);
		cout<<"time  is "<<time<< " ms"<<endl;    //show the running time of this function
		cout<<endl;
		h.printTable("Chaining Talbe.txt");      // save the hash table in Chaining Table.txt
		cout<<endl;
	}

	cout<<"following is the manual search/delete/insert part, in each part you can input 5 numbers."<<endl;
	cout<<"however,the input number should be smaller than 46300 if you choose middle square or fibonacci function"<<endl;
 
	cout<<"now press 1 to insert 5 numbers";
	int judge;
	cin>>judge;
	if(judge==1){
	int insert;
	cout<<"insert some numbers by yourself, you have 5 chances"<<endl;
	for(int j = 0; j< 5 ; j++){
	  cin>>insert;
	  if(h.Insert(insert,index)) cout<<"insert successfully";
	  else cout<<"failed";
	  cout<<endl;
	}
	h.printTable("Chainning Talbe.txt");
	}

	cout<<"press 1 to delete 5 numbers in the table";
	int judge2;
	cin>>judge2;
	if(judge2==1){
	int del;
	cout<<"deleting..............."<<endl;
	for(int j = 0; j < 5; j++)
	{
	  cin>> del;
	  if(h.Delete(del,index)) cout<<"  delete succeeded";
	  else cout<<"  maybe this number does not exist";
	  cout<<endl;
	}
	h.printTable("Chaining Talbe.txt");
	}

	cout<<"now press 1 to search 5 numbers"<<endl;
	int judge3;
	cin>>judge3;
	if(judge3==1){
	int search;
	cout<<"searching............"<<endl;
	for(int j = 0; j< 5 ; j++){
	  cin>>search;
	  start = clock();
	  if(h.Find(search,index))
	  { 
	  cout<<"found it!";
	  finish = clock();
	  double time = (double)(finish - start);
	  cout << "and time is  " << time <<"ms"<<endl;
	  }
	 else 
	 {
	  finish = clock();
	  double time = (double)(finish - start);
	  cout << "failed.  time costs is  " << time <<"ms"<<endl;
	  }
	}
	}


	cout<<"if you want to compare the hash table built by different functions which of the same input, press 1"<<endl;
	int j;
	cin>>j;
	if(j==1)
	{
	 	//srand(time(0));
		int r = 0;
		HashTable h1, h2, h3;

		while(r < AUTO_NUMBER){
           i = rand();
		   if(i<= 32767)
		   {
	          h1.Insert(i,1);
		      h2.Insert(i,2);
			  h3.Insert(i,3);
		      r++;
		   }
         }

		cout<<"information about function 1"<<endl;
		h1.printTable("Chaining division.txt");      // save the hash table

		h2.printTable("Chaining middle.txt");      // save the hash table 
		h3.printTable("Chaining fibonacci.txt");      // save the hash table 
	}


	return 0;
}

