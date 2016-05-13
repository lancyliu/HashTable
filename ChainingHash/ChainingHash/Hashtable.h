#include <list>   
#include <algorithm>   
  
using namespace std;  
#define Hash_Size 10000 

class HashTable{  
  
private:  
    list<int> containers[Hash_Size];      //���봢���ַ�����Ϣ�������Զ������ݽṹ������data��key�� function(key)�������������е�λ��
    int HashFunction(const int& e, int index) const;  // Chaining �����У�ͨ��function�Ĳ�ͬ�����Բ�ͬ���͵�hash
    int count;       //the amount of numbers inserted in the hash table
  
public:  
    HashTable();  
    ~HashTable();  

    bool Insert(const int& e , int index);  
    bool Find(const  int& e,int index) const;  
    bool Delete(const int& e,int index);  
    int Count() const;  //��ʾ�����������ݵĸ���
	void printTable(std::string filepath);
//	bool autoInsert(); //�Զ�����һ�������ݡ�
	int collis;    //the collison in the table.
	//int function_type;
}; 