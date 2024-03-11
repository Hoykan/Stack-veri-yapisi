#include <iostream>
using namespace std;
class node {
public:
	int deger;
	node* next;
	node(int deger) {
		this->deger = deger;
		next = NULL;
}
};
class stack {
private:
	node* top;
	int count;
public:
	stack(int deger) {
		node* newnode = new node(deger);
		top = newnode;
		count = 1;
	}
	void printAll() {
		node* tmp = top;
		while (tmp != NULL) {
			cout << tmp->deger << endl;
			tmp = tmp->next;
		}

	}
	void printTop() {
		if (count == 0) {
			cout << "Hicbir deger olmadigi icin deger yazdirilamadi!" << endl;
			exit(1);
		}
		else
		cout << "Top Deger:" << top->deger << endl;

	}
	int getcount() {
		cout << "count: " << count << endl;
		return count;
	}
	
	~stack() { //destructor
		node* tmp = top;
		while (top != NULL) {
			top = top->next;
			delete tmp;
			tmp = top;
		}
	}
	void push(int deger) {
		node* newnode = new node(deger);
		newnode->next = top;
		top = newnode;		
		count++;
			
	}
	int pop() {
		/*if (count == 0)
			return -1;*/
		node* tmp = top;
		int deger = top->deger;
		top = top->next;
		delete tmp;
		count--;
		return deger;

	}
	bool isEmpty() {
		if (count == 0)
			return true;
		else if (count != 0)
			return false;

	}
};
int main() {
	cout << "------------------------------" << endl;
	stack* newStack = new stack(1);
	newStack->printAll();
	newStack->printTop();
	newStack->getcount();
	cout << "------------------------------" << endl;
	newStack->push(2);
	newStack->push(3);
	newStack->push(4);
	newStack->push(5);
	newStack->printAll();
	newStack->printTop();
	newStack->getcount();
	cout << "------------------------------" << endl;
	if (newStack->getcount() != 0) {
		cout << "pop edilen deger: " << newStack->pop() << endl;
	}
	cout << "Silme islemi sonrasi degerler: " << endl;
	newStack->printAll();
	newStack->printTop();
	newStack->getcount();
	cout << "------------------------------" << endl;
	cout << newStack->isEmpty() << endl;
	newStack->printAll();

}