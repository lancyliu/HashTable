#include <list>   
#include <algorithm>   
  
using namespace std;  
#define Hash_Size 10000 

class HashTable{  
  
private:  
    list<int> containers[Hash_Size];      //若想储存字符等信息，可以自定义数据结构，加入data和key， function(key)用来找在链表中的位置
    int HashFunction(const int& e, int index) const;  // Chaining 方法中，通过function的不同来测试不同类型的hash
    int count;       //the amount of numbers inserted in the hash table
  
public:  
    HashTable();  
    ~HashTable();  

    bool Insert(const int& e , int index);  
    bool Find(const  int& e,int index) const;  
    bool Delete(const int& e,int index);  
    int Count() const;  //显示表中所有数据的个数
	void printTable(std::string filepath);
//	bool autoInsert(); //自动插入一部分数据。
	int collis;    //the collison in the table.
	//int function_type;
}; 