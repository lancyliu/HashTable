#include "stdafx.h"
#include <list>   
#include <algorithm>  
#include <iostream>
#include <fstream>
#include "Hashtable.h"  
using namespace std;  

int HashTable::HashFunction(const int &e, int index) const
{
	/***division function**/
	if(index==1)
	{
	   return e%9973;  
	}
	/*** middle quare function **/
	else if(index==2)
	{
		    char str[11];   
	itoa(e*e, str, 10);
	int sl = strlen(str);
	long r;
	switch(sl)
	{
	case 0:
		r = 0;
		break;
	case 1:
		r = 0;
		break;
	case 2:
		r = 0;
		break;
	case 3:
		r = 0;
		break;
	case 4:
		r = (long)(str[0]-48);
		// r = x/1000;
		break;
	case 5:   
		r =(long)((str[0]-48)*10+(str[1]-48));	
		break;
	case 6:
		r = (long)((str[0]-48)*100 + (str[1]-48)*10 + str[2]-48);
		break;
	case 7:
		r = (long)((str[0]-48)*1000 + (str[1]-48)*100 + (str[2]-48)*10 + str[3]-48);
		break;
	case 8:
		r= (long)((str[1]-48)*1000 + (str[2]-48)*100 + (str[3]-48)*10 + str[4]-48);
		break;
	case 9:
		r =(long)(( str[2]-48)*1000 + (str[3]-48)*100 + (str[4]-48)*10 + str[5]-48);
		break;
	case 10:
		r = (long)((str[3]-48)*1000 + (str[4]-48)*100 + (str[5]-48)*10 + str[6]-48);
		break;
	default:
		cout<<"input error";
		break;
	}
	int result = (int) r;
	return result;
	}
	/**fibonacci function***/
	else if(index==3)
	{
		char str[11];   
	itoa(e*40503, str, 10);
	int sl = strlen(str);
	long r;
	switch(sl)
	{
	case 0:
		r = 0;
		break;
	case 1:
		r = 0;
		break;
	case 2:
		r = 0;
		break;
	case 3:
		r = 0;
		break;
	case 4:
		r = (long)(str[0]-48);
		// r = x/1000;
		break;
	case 5:   
		r =(long)((str[0]-48)*10+(str[1]-48));	
		break;
	case 6:
		r = (long)((str[0]-48)*100 + (str[1]-48)*10 + str[2]-48);
		break;
	case 7:
		r = (long)((str[0]-48)*1000 + (str[1]-48)*100 + (str[2]-48)*10 + str[3]-48);
		break;
	case 8:
		r= (long)((str[1]-48)*1000 + (str[2]-48)*100 + (str[3]-48)*10 + str[4]-48);
		break;
	case 9:
		r =(long)(( str[2]-48)*1000 + (str[3]-48)*100 + (str[4]-48)*10 + str[5]-48);
		break;
	case 10:
		r = (long)((str[3]-48)*1000 + (str[4]-48)*100 + (str[5]-48)*10 + str[6]-48);
		break;
	default:
		cout<<"input error";
		break;
	}
	int result = (int) r;
	return result;
	}
	else
	{
	  cout<<"There is no such function "<<endl;
	  return false;
	}
}


HashTable::HashTable(){  
    count = 0;  
	collis = 0;
	for(int i = 0; i< Hash_Size; ++i){  
        containers[i].clear();  
    } 
	//function_type=0;
}  
  
HashTable::~HashTable(){  
    count = 0;  
    for(int i = 0; i< Hash_Size; ++i){  
        containers[i].clear();  
    }  
} 


bool HashTable::Insert(const int &e , int index)
{
	const int hashResult = HashFunction(e, index); 
    if(hashResult > Hash_Size) return false;
	else {
	containers[hashResult].push_back(e);  
	++count;
	} 
	return true;
}

bool HashTable::Find(const int &e, int index) const
{
	 const int hashResult = HashFunction(e,index); 
	  if(hashResult > Hash_Size) return false;
    list<int>::const_iterator itr = find(containers[hashResult].begin(),  
        containers[hashResult].end(), e);  
    if(itr != containers[hashResult].end()){  
        return true;  
    }else{  
        return  false ;  
    }  
}

bool HashTable::Delete(const int &e, int index)
{
	const int hashResult = HashFunction(e, index); 
	 if(hashResult > Hash_Size) return false;
    list<int>::iterator itr = find(containers[hashResult].begin(),  
        containers[hashResult].end(), e);  
    if(itr != containers[hashResult].end())
	{  
        containers[hashResult].erase(itr);  
        --count;  
        return true;  
    }
	else
	{  
        return false;  
    }  
}

int HashTable::Count() const
{
	return count;  
}

void HashTable::printTable(std::string filepath)
{
	ofstream fout;
	fout.open(filepath.c_str());
	fout.clear();
	collis = 0;
	int i,j;
    j = 0;
	list<int>::iterator itr; 
	for(i=0; i<Hash_Size; i++)
	{
		fout<<"index is  "<<i<<"      ";
		if(!containers[i].empty())
		{
           j=i;
          	for(itr = containers[i].begin(); itr !=containers[i].end(); itr++)
			{
			  fout<< *itr<<" ";
			  collis = collis +1; 
			}
			collis = collis -1;
 	       fout<<endl;
		}
		else
		{
		  fout<<"empty ";
		  fout<<endl;
		}
	}
	fout.flush();
	fout.close();
	cout<<"the amount number we supposed to insert " << count<<endl;
	cout<<"memory that actually used "<< j+1 <<endl;
	cout<<"total number of collosion is " <<collis<<endl;
}