#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>


#define strl 2000
#define TABLE1_MAX 16
#define TABLE2_MAX 32
#define TABLE3_MAX 64
#define TABLE4_MAX 128

using namespace std;



struct node {
	long long int number;
	string name;
	node* next;
};

struct  hashTable
{
	node** items;
	int size;
	int count;
	int collisionCount = 0;
};



int hashFun(int key, int size)
{
	return key % size;
}

node* createNode(long long int key, string s) {
	node* newNode = new node;
	newNode->number = key;
	newNode->name = s;
	newNode->next = NULL;	
	return newNode;
}

hashTable* htCreate(int size) {
	hashTable* htNew = new hashTable;
	htNew->size = size;
	htNew->count = 0;
	htNew->items = new node*[size];
	for (int i = 0; i < size; i++)
		htNew->items[i] = NULL;
	return htNew;
}


void deleteHT(hashTable* table) {
	for(int i = 0 ;i < table->count; i ++)
		delete table->items[i];
	delete table;
}


void put(hashTable* table, long long int key, string name) {
	node* HtItem = createNode(key, name);
	int index = hashFun(key, table->size);
	node* currentItem = table->items[index];
	node* p0;
	if (table->count == table->size) {
		printf("Insert Error: Hash Table is full\n");
		delete HtItem;
		return;
	}
	p0 = table->items[index];
	if (p0 != NULL) {
		table->collisionCount++;
		while (p0->next != NULL)
		{
			if (p0->number == key) {
				p0->name = name;
				return;
			}
			p0 = p0->next;
		}
		if (p0->number == key) {
			p0->name = name;
			return;
		}
		p0->next = HtItem;
	}
	else
		table->items[index] = HtItem;
	table->count++;
	
}



node* find(hashTable* table, long long int key) {
	int index = hashFun(key, table->size);
	node* item = table->items[index];
	if (item == NULL) {
		return NULL;
	}
	while (item->next != NULL) {
		if (item->number == key)
			return item;
		item = item->next;
	}
	if (item->number == key)
		return item;
	return NULL;
}

void showHT(hashTable* table) {
	node* p0;
	for (int i = 0; i < table->size; i++)
	{
		cout << "\nindex" << i << ": ";
		p0 = table->items[i];
		while (p0 != NULL) {
			cout << "number: " << p0->number <<" name: " << p0->name << " ";
			p0 = p0->next;
		}
	}
	cout << "\n\n";
}

void deleteItem(hashTable* table, long long int key) {
	int index = hashFun(key, table->size);
	node* item = find(table, key);
	node* p0 = table->items[index];
	if (p0 == item && item != NULL)
	{
		table->items[index] = item->next;
		delete item;
		return;
	}
	if (item != NULL) {
		while (p0->next != item)
			p0 = p0->next;
		p0->next = item->next;
		delete item;
		table->count--;
	}
	else {
		cout << "not found" << endl;
		return;
	}
}


int main() 
{
	srand(time(0));
	clock_t startTime;
	clock_t endTime;
	int size;
	cout << "size: ";
	cin >> size;
	hashTable* tableX16 = htCreate(size);
	hashTable* tableX16t= htCreate(TABLE1_MAX);
	hashTable* tableX32t= htCreate(TABLE2_MAX);
	hashTable* tableX64t = htCreate(TABLE3_MAX);
	hashTable* tableX128t = htCreate(TABLE4_MAX);
	node* item;
	int action = 1;
	string name;
	long long int number, key;
	char x;
	auto begin = chrono::steady_clock::now();
	auto end = chrono::steady_clock::now();
	cout << " 1 - add\n 2 - find\n 3 - collision count\n 4 - show ht\n 5 - del item\n 0-exit \n";
	while (action != 0) {
		cin >> action;
		switch (action)
		{
		case 0:
			break;
		case 1:
			cin >> number;
			cin.get(x);
			getline(cin, name);
			if (number > 32767) {
				cout << "error " << number << "> 32767" << endl;
			}else {
				put(tableX16, number, name);
			}
			
			break;
		case 2:
			cin >> number;
			if (number > 32767) {
				cout << "error " << number << " > 32767" << endl;
			}
			else {
				begin = chrono::steady_clock::now();
				item = find(tableX16, number);
				end = chrono::steady_clock::now();
				if (item != NULL)
				{
					cout << item->number << " " << item->name << endl;
					cout << "time " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "nanos\n";
				}
				else
					cout << "not found" << endl;
			}
			
			break;
			
		case 3:
			cout <<"collision: " << tableX16->collisionCount << endl;
			break;
		case 4:
			showHT(tableX16);
			break;
		case 5:
			cin >> number;
			if (number > 32767) {
				cout << "error " << number << "> 32767" << endl;
			}
			else
			deleteItem(tableX16, number);
			break;
		case 6:
			deleteHT(tableX16t);
			deleteHT(tableX32t);
			deleteHT(tableX64t);
			deleteHT(tableX128t);
			tableX16t = htCreate(TABLE1_MAX);
			tableX32t = htCreate(TABLE2_MAX);
			tableX64t = htCreate(TABLE3_MAX);
			tableX128t = htCreate(TABLE4_MAX);
			for (int i = 0; i < 16; i ++) {
				key = rand() % (32767);
				put(tableX16t, key, "info");
			}
			cout << "16 collision: " << tableX16t->collisionCount << endl;
			for (int i = 0; i < 32; i++) {
				key = rand() % (32767);
				put(tableX32t, key, "info");
			}
			cout << "32 collision: " << tableX32t->collisionCount << endl;
			for (int i = 0; i < 64; i++) {
				key = rand() % (32767);
				put(tableX64t, key, "info");
			}
			cout << "64 collision: " << tableX64t->collisionCount << endl;
			for (int i = 0; i < 128; i++) {
				key = rand() % (32767);
				put(tableX128t, key, "info");
			}
			cout << "128 collision: " << tableX128t->collisionCount << endl;
			break;
		case 7:cin >> number;
			cout << "16" << endl;
			startTime = clock();
			item = find(tableX16t, number);
			endTime = clock();
			if (item != NULL)
			{
				cout << item->number << " " << item->name << endl;
				cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
			}
			else
				cout << "not found" << endl;
			cout << "32" << endl;
			startTime = clock();
			item = find(tableX32t, number);
			endTime = clock();
			if (item != NULL)
			{
				cout << item->number << " " << item->name << endl;
				cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
			}
			else
				cout << "not found" << endl;
			cout << "64" << endl;
			startTime = clock();
			item = find(tableX64t, number);
			endTime = clock();
			if (item != NULL)
			{
				cout << item->number << " " << item->name << endl;
				cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
			}
			else
				cout << "not found" << endl;
			cout << "128" << endl;
			startTime = clock();
			item = find(tableX128t, number);
			endTime = clock();
			if (item != NULL)
			{
				cout << item->number << " " << item->name << endl;
				cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
			}
			else
				cout << "not found" << endl;
			break;
		case 8:
			cout << "16" << endl;
			showHT(tableX16t);
			cout << "32" << endl;
			showHT(tableX32t);
			cout << "64" << endl;
			showHT(tableX64t);
			cout << "128" << endl;
			showHT(tableX128t);
			break;
		case 9:
			for (int i = 0; i < 32767; i++) {
				number = i;
				startTime = clock();
				item = find(tableX16t, number);
				endTime = clock();
				if (item != NULL)
				{
					cout << "16" << endl;
					cout << item->number << " " << item->name << endl;
					cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
				}
				startTime = clock();
				item = find(tableX32t, number);
				endTime = clock();
				if (item != NULL)
				{
					cout << "32" << endl;
					cout << item->number << " " << item->name << endl;
					cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
				}
				
				startTime = clock();
				item = find(tableX64t, number);
				endTime = clock();
				if (item != NULL)
				{
					cout << "64" << endl;
					cout << item->number << " " << item->name << endl;
					cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
				}
			
				startTime = clock();
				item = find(tableX128t, number);
				endTime = clock();
				if (item != NULL)
				{
					cout << "128" << endl;
					cout << item->number << " " << item->name << endl;
					cout << "time " << double(endTime - startTime) / CLOCKS_PER_SEC * 100 << "ms\n";
				}
			}
			break;
		default:
			cout << "error command" << endl;
			break;
		}	

	}
	deleteHT(tableX16);
	deleteHT(tableX16t);
	deleteHT(tableX32t);
	deleteHT(tableX64t);
	deleteHT(tableX128t);
}