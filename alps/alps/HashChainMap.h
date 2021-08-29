#include <iostream>
using namespace std;

#define TABLE_SIZE 13

class Record {
protected:
	string key;
	string value;
public:
	Record(string k = "", string v = "") : key(k), value(v) {}
	string getKey() { return key; }
	string getValue() { return value; }
	void setValue(string s) { value = s; }
};

class Node :public Record{
	Node* link;
public:
	Node(string key="", string value="", Node* p=NULL): Record(key, value), link(p) {}
	Node* getLink() { return link; }
	void setLink(Node* p) { link = p; }
};


class HashChainMap {	 
	Node* table[TABLE_SIZE];
public:
	HashChainMap() { for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL; }
	int hashFunc(string s) {
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
			sum += s[i];
		return sum % TABLE_SIZE;
	}
	void insert(string key, string value) {
		int hashValue = hashFunc(key);
		for (Node* n = table[hashValue]; n != NULL; n = n->getLink()) {
			if (n->getKey() == key) {
				printf("already key exists\n");
				return;
			}
		}
		printf("key inserted\n");
		table[hashValue] = new Node(key, value, table[hashValue]);
	}
	void search(string key) {
		int hashValue = hashFunc(key);
		for (Node* n = table[hashValue]; n != NULL; n = n->getLink()) {
			if (n->getKey() == key) {
				printf("found! %s: %s\n", key.c_str(), n->getValue().c_str());
				return;
			}
		}
		printf("Not Exist\n");
	}

	void display() {
		for (int i = 0; i < TABLE_SIZE; i++) {
			for (Node* n = table[i]; n != NULL; n = n->getLink())
				printf("%s ", n->getKey().c_str());
			printf("\n");
		}
	}
};

int main() {
	HashChainMap hash;
	hash.insert("my", "³»");
	hash.insert("dream", "²Þ");
	hash.insert("is", "Àº");
	hash.insert("dream", "¸Þ·Õ");

	hash.insert("123", "¸Þ·Õ");
	hash.insert("456", "¸Þ·Õ");
	hash.insert("789", "¸Þ·Õ4");

	printf("\n");

	//hash.display();

	hash.search("dream");
	hash.search("key");
	hash.search("789");

}