# HashTable
Implementation of several kind of hash table and test their performance. 
Developed by Visual Studio 2008. 
This file includes two project. 
file /ChainingHash : This hash table use linked list to solve the collisiin problem. 
file /OpenAddress:  This hash table use open addressing to solve the collision problem.

There three hash functions used in this two hash table: 
1. division function
2. middle square function
3. fibonacci function

For debugging: you can use VS2008 open this project.
            Or you can copy the file 1. \ChainingHash\ChainingHash\HashTable.h, 
                                       \ChainingHash\ChainingHash\HashTable.cpp,
                                       \ChainingHash\ChainingHash\ChainingHash.cpp
                                     2.\OpenAddress\OpenAddress\HashTable.h,
                                       \OpenAddress\OpenAddress\HashTable.cpp.
                                       \OpenAddress\OpenAddress\OpenAddress.cpp
            This file includes all the code to implement the hash table.
  For different IDE, may need some modification.
  
  The structure of the project:
  Using class structure to implement the hash table. 
  The HashTable class in this two project has the same sturcture. The class include:
  
int HashFunction(const int& e, int index) const;  
// This function implement different hash function in this hash table

bool Insert(const int& e,int index);  
//Insert an element in this hash table.

bool Find(const int& e,int index) const;
//Find an element in this hash table

bool Delete(const int& e,int index);
//delete an element in this hash table

int Count() const;  
// count the number of elements in this hashtable

void printTable(std::string filename);
//print elements in the hash table, show the result in a .txt file. Use this function we can check which element were failed to insert to the hash table.

In the main function:
user can choose one hash function. 
user can choose to insert elements or delete elements by themself. Or user can choose to insert elements automatically and the time costs and rate of successful inserting will be shown to the user.
