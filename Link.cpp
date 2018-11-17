#include <iostream>
using namespace std;
struct Lnode {
	int data;
	Lnode*next;
};
class LinkList {
public:
	LinkList();
	void insert_end(int&item);
	void insertion(int position,int&item);
	void del(int position);
	void find1(int position)const;
	void find2(int val)const;
	void clear();
private:
	Lnode*head;
	int length;
};
LinkList::LinkList() {
	head = new Lnode;
	head->data = 0;
	head->next = NULL;
	length = 0;
}
void LinkList::insert_end(int&item) {
	Lnode*p = new Lnode;
	p->data = item;
	p->next = NULL;
	Lnode*tem = head;
	while (tem->next) {
		tem = tem->next;
	}
	tem->next = p;
	length++;
}
void LinkList::insertion(int position,int&item) {
	Lnode*p = head;
	Lnode*q = new Lnode;
	q->data = item;
	int count=0;
	if (position <= 0 || position > length)
		cout << "Error" << endl;
	else {
		while (count != position-1) {
			p = p->next;
			count++;
		}
		q->next = p->next;
		p->next = q;
		length++;
	}
}
void LinkList::del(int position) {
	int count = 0;
	Lnode*p = head;
	Lnode*pre = head;
	if (position <= 0 || position > length)
		cout << "Error" << endl;
	else {
		while (count != position-1) {
			p = p->next;
			pre = pre->next;
			count++;
		}
		p = p->next;
		cout << p->data;
		pre->next = p->next;
		delete p;
		length--;//头节点和尾节点都为空，不用判断插在头尾节点的情况
	}
}
void LinkList::find1(int position)const {
	Lnode*p = head;
	int count = 0;
	if (position <= 0 || position > length)
		cout << "Error" << endl;
	else {
		while (count != position) {
			p = p->next;
			count++;
		}
		cout << p->data;
	}
}
void LinkList::find2(int val)const {
	int count = 0;
	Lnode*p = head;
	while (val != p->data) {
		p = p->next;
		count++;
	}
	if (p != NULL) {
		cout << count;
	}
	else
		cout << "can not find" << endl;
}
void LinkList::clear() {
	length = 0;
	delete head;
}
int main() {
	int m;int n;
	cin >> m >> n;
	LinkList my;
	for (int i = 0;i < m;++i) {
		int data;
		cin >> data;
		my.insert_end(data);
	}
	char s[100];
	int a[100];
	int b[100];
	for (int i = 0;i < n;++i) {
		cin >> s[i];
		if (s[i] == 'I')
			cin >> a[i] >> b[i];
		else
			cin >> a[i];
		}
	for (int i = 0;i < n;++i) {
		switch (s[i]) {
		case'I':
			my.insertion(a[i], b[i]);
			cout << endl;
			break;
		case'D':
			my.del(a[i]);
			cout << endl;
			break;
		case'G':
			my.find1(a[i]);
			cout << endl;
			break;
		case'L':
			my.find2(a[i]);
			cout << endl;
			break;
		case'C':
			my.clear();
		}
	}
	return 0;
}
