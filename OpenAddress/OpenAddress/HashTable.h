#include<fstream>  
  
using namespace std;  
#define Hash_Size 10000 

struct Open_address
{
	int status; // 0 represent empty, 1 represent occupied, 2 represent deleted
	int key;
};

class HashTable{  
  
private: 
	Open_address containers[Hash_Size];      //
	int HashFunction(const int& e, int index) const;  // Chaining 
    int count;
  
public:  
    HashTable();  
    ~HashTable();  
	int insert_count;
    int index;

    bool Insert(const int& e,int index);  
    bool Find(const int& e,int index) const;  
    bool Delete(const int& e,int index);  
    int Count() const;  // count the number of elements in table
	void HashTable::printTable(std::string filename);   //print the elements in table
}; 