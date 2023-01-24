#include<iostream>
#include<list>
using namespace std;
class HashTable{
	int capacity;
	list<string> *table;
	public:
		HashTable(int v);
		void insertItem(int key, string data);
		void deleteItem(int key, string data);
		void searchItem(int key, string data);
		
		int checkPrime(int n){
			int i;
			if(n == 1 || n == 0){
				return 0;
			}
			
			for(i = 2; i < n/2; i++){
				if(n % i == 0){
					return 0;
				}
			}
			return 1;
		}
		
		int getPrime(int n){
			if(n % 2 == 0){
				n++;
			}
			while(!checkPrime(n)){
				n += 2;
			}
		return n;
		}
		
		int hashFunction(int key){
			return (key % capacity);
		}
		
		void displayHash();
};

HashTable::HashTable(int c){
	int size = getPrime(c);
	this->capacity = size;
	table = new list<string>[capacity];
}

void HashTable::insertItem(int key, string data){
	int index = hashFunction(key);
	table[index].push_back(data);
}

void HashTable::deleteItem(int key, string data){
	int index = hashFunction(key);
	list<string>::iterator i;
	
	for(i = table[index].begin(); i != table[index].end(); i++){
		if(*i == data)
			break;
	}
	if(i != table[index].end())
		table[index].erase(i);
}

void HashTable :: searchItem(int key, string data){
	int index = hashFunction(key);
	list<string> :: iterator i;
	int x = 0;
	bool found = false;
	for (i = table[index].begin(); i != table[index].end(); i++){
		if(*i == data){
			cout << "Found this data at table [" << index << "]-[" << x << "]-->" << data << endl;
			found = true;
			break;
		}
		x++;
	}
	
	if(!found){
		cout << "Record does not exist! " << data << endl;
	}
}

void HashTable :: displayHash(){
	for(int i = 0; i < capacity; i++){
		cout << "table[" << i << "]";
		for (auto x : table[i]){
			cout << " --> " << x;	
		}
		cout << endl;
	}
}

int main(){
	int rollNo[] = {231, 321, 212, 321, 433, 262};
	string data[] = {"Anjum", "Asif", "Asad", "Aslam", "Majid", "Ajaz"};
	
	int size =sizeof(rollNo) / sizeof(rollNo[0]);
	HashTable h(size*2);
	for(int i = 0; i < size; i++){
		h.insertItem(rollNo[i], data[i]);
	}
	
	h.displayHash();
	cout << endl;
	h.searchItem(321, "Asif");
}
