# HashTable
Implementation of several kind of hash table and test their performance.

Developed by Visual Studio 2008 in Windows 8. 

In this document only contains the source code(.h and .cpp file)

This file includes two kinds of hash table. 

ChainingHash : This hash table use linked list to solve the collisiin problem. 

OpenAddress:  This hash table use open addressing to solve the collision problem.

There three hash functions used in this two hash table: 

1. division function
2. middle square function
3. fibonacci function

            
For different IDE and OS, may need some modification.
 
 The structure of the project:
  Using class structure to implement the hash table. 
  The HashTable class in this two project has the same sturcture. The class include:
  
int HashFunction(const int& e, int index) const;  
This function implement different hash function in this hash table

bool Insert(const int& e,int index);  
Insert an element in this hash table.

bool Find(const int& e,int index) const;
Find an element in this hash table

bool Delete(const int& e,int index);
delete an element in this hash table

int Count() const;  
count the number of elements in this hashtable

void printTable(std::string filename);
print elements in the hash table, show the result in a .txt file. Use this function we can check which element were failed to insert to the hash table.

In the main function:
user can choose one hash function. 
user can choose to insert elements or delete elements by themself. Or user can choose to insert elements automatically and the time costs and rate of successful inserting will be shown to the user.
