#include "stdafx.h"
#include <iostream>
#include "HashTable.h"  
#include "fstream"
using namespace std;  
// in open addresing the size of hash table is related to the input number. the factor should < 1.

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

HashTable::HashTable()
{
	count = 0; 
	for(int i = 0; i< Hash_Size; ++i)
	{  
		containers[i].status=0;
		containers[i].key=0;
    }
}


HashTable::~HashTable()
{
	count = 0;  
	for(int i = 0; i< Hash_Size; ++i)
	{  
		containers[i].key=0;
		containers[i].status=0;
    }
}

bool HashTable::Insert(const int &e, int index)
{
	const int hashResult = HashFunction(e,index);  
	int Result= hashResult;
	if( Result > Hash_Size ) 
	{  
		cout<<"function error"<<endl;
		return false;
	}
	if(containers[Result].status==0 || containers[Result].status==2)
	   {
		containers[Result].key = e;
		containers[Result].status=1;
		++count;
		return true;
	     }
	else if(containers[Result].status==1)
	{
		int i = 0;
		while(containers[Result].status==1)
		{
		  i++;
		  Result = (Result + 1) % Hash_Size ;  // the functions in open addressing
		  if(i== (Hash_Size-1)) break;
		}
		if(Result != (hashResult - 1))
		{
			containers[Result].status = 1;
			containers[Result].key = e;
			++count;
		    return true;
		}
		else 
		{
			//cout<<"there is no space for this number"<<endl;
			return false;
		}
	}
	else return false;
}

bool HashTable::Find(const int &e, int index) const
{
	const int hashResult = HashFunction(e,index);
	int i ;
	int Result = hashResult;
	if (Result > Hash_Size ) return false;
	for(i=0;i< Hash_Size;i++)
	{
		Result = (Result + 1) % Hash_Size;
		if(containers[Result].key==e) return true;
	//	if(containers[Result].status==0) return false;
	}
    return false; 
}

bool HashTable::Delete(const int &e, int index)
{
	const int hashResult = HashFunction(e,index);
    int i ;
	int Result = hashResult;
	if (Result > Hash_Size ) return false;
	for(i=0;i<=( Hash_Size - i);i++)
	{
		Result = (Result + 1) % Hash_Size;
		if(containers[Result].key==e)
		{
			containers[Result].key= NULL;
			containers[Result].status=2;
			--count;
			return true;
		}
		if(containers[Result].status==0) return false;
	}
}

int HashTable::Count() const
{
    return count;  
}

void HashTable::printTable(std::string filename)
{
	ofstream fout;
	fout.open(filename.c_str());
	fout.clear();
	int i,j;
    j = 0;
	for(i=0; i<Hash_Size; i++)
	{
		if(containers[i].status == 1)
		{
           j=i;
           fout<<"index is  "<<i<<"      ";
           fout<< "element is  "<<containers[i].key<<"  ";
 	       fout<<endl;
		}
		if(containers[i].status == 2)
		{
		   fout<<"deleted"<<endl;
		}
	}
	fout.flush();
	fout.close();
	cout<<"memory that actually used "<< j+1 <<endl;
}