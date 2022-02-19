#include "iostream"
#include <windows.h>
#include <locale.h>
using namespace std;
int cinInt(int* a) {
	cout << "������� �����: ";
	cin >> *a;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "!!�������� ������ �����!!" << endl;
		cout << "������� �����: ";
		cin >> *a;
	}
	return *a;
}
struct list {
	int v = -9999999;
	list* next = nullptr;
};
class queue {
	size_t size = 0;
	size_t maxSize = 5;
	list* first = nullptr;
	list* last = nullptr;
public:
	queue() {
		size = 0;
		maxSize = 5;
		first = nullptr;
		last = nullptr;
	}
	void output() {
		cout << "���� ������� -> ";
		if (!size) {
			cout << "(�����)" << endl;
			return;
		}
		list* tmp = first;
		for (int i = 0; i < size; i++) {
			cout << tmp->v << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
	char* is_empty() {
		return (size ? ((char*)"������� �� �����") : ((char*)"������� �����"));
	}
	bool add() {
		if (maxSize==0) {
			cout << "�������� ������������ ������" << endl;
			Sleep(2000);
			return 0;
		}
		list* l = new list;
		cinInt(&(l->v));
		if (first == nullptr) {
			first = l;
			last = l;
		}
		else {
			last->next = l;
			last = l;
		}
		maxSize--;
		size++;
		return 1;
	}
	void del() {
		list* l = first;
		list* tmp;
		for (int i = 0; i < size; i++) {
			tmp = l->next;
			free(l);
			l = tmp;
		}
		size = 0;
		first = nullptr;
		last = nullptr;

	}
	char* retFirst() {
		char* p = (char*)malloc(40);
		if (!p) {
			cout << "���������� �������� ������" << endl;
			Sleep(2000);
			return nullptr;
		}
		return (first ? _itoa(first->v, p, 10) : ((char*)"������� �����"));
	}
	char* pop() {
		int tmp;
		char* p = (char*)malloc(40);
		if (!p) {
			cout << "���������� �������� ������" << endl;
			Sleep(2000);
			return nullptr;
		}
		list* tmp2;
		if (!size) {
			cout << "������� �����" << endl;
			Sleep(2000);
			return ((char*)"");
		}
		tmp2 = first;
		tmp = first->v;
		if (size > 1) {
			first = first->next;
			free(tmp2);
		}
		else {
			first = last = nullptr;
		}
		size--;
		
		return _itoa(tmp, p, 10);
	}
	void changeSt() {
		int f;
		if (!size) {
			cout << "������� �����" << endl;
			Sleep(2000);
			return;
		}
		cout << "���� ������ �������� ������, ";
		cinInt(&f);
		first->v = f;
	}
	bool menu() {
		char choice;
		static bool zero = true;
		if (zero) {
			cout << "0 - ������   * - �����" << endl;
		}
		else {
			cout << "0 - �������� ����  1 - �������� �������" <<
				"   2 - ������� �������� ��-�� �� ������   3 - ����������" <<
				"   4 - �������� �� �������   5 - ������� ������ �������" <<
				"   6 - ����� ��-� �� ������   7 - �������� �������� ������" <<
				"   8 - ����������� �������" << endl;
			cout << endl;
			output();
		}
		cin >> choice;
		switch (choice) {
		case '0':
			if (zero) {
				zero = false;
			}
			else {
				zero = true;
			}
			break;
		case '1':
			if (!zero) {
				add();
			}
			break;
		case '2':
			if (!zero) {
				cout << endl << "��� ������� -> " << retFirst() << endl;
				Sleep(2000);
			}
			break;
		case '3':
			if (!zero) {
				del();
			}
			break;
		case '4':
			if (!zero) {
				cout << endl << is_empty() << endl;
				Sleep(2000);
			}
			break;
		case '5':
			if (!zero) {
				pop();
			}
			break;
		case '6':
			if (!zero) {
				cout << endl << "��� ������� -> " << pop() << endl;
				Sleep(2000);
			}
			break;
		case '7':
			if (!zero) {

				changeSt();
			}
			break;
		case '8':
			if (!zero) {
				output();
				Sleep(2000);
			}
			break;
		default:
			if (zero) {
				system("cls");
				return 0;
			}
		}
		system("cls");
		return 1;
	}
	bool operator == (bool v2) {
		if (v2 && this->size || !v2 && !this->size) {
			return 1;
		}
		return 0;
	}
};
struct list2 {
	queue v;
	list2* next = nullptr;
};
class matrix {
	int sizeN = 0;
	int sizeM = 0;
	list2* first = nullptr;
	list2* last = nullptr;
public:
	void set_N_M() {
		cout << "���� ���������� ������, ";
		cinInt(&sizeN);
		cout << "���� ���������� ��������, ";
		cinInt(&sizeM);
	}
	queue* getNM() {
		int n, m;
		if (sizeN == 0 || sizeM == 0) {
			return nullptr;
		}
		while (1) {
			cout << "���� N, ";
			cinInt(&n);
			cout << "���� M, ";
			cinInt(&m);
			if (n > sizeN - 1 || m > sizeM - 1 || m < 0 || n < 0) {
				cout << "!!������� ������!!" << endl;
			}
			else {
				break;
			}
		}
		list2* l = first;
		for (int i = 0; i < sizeN; i++) {
			for (int j = 0; j < sizeM; j++) {
				if (i == n && j == m) {
					return &(l->v);
				}
				l = l->next;
			}
		}
		return nullptr;
	}
	bool isEmpty() {
		return (sizeN || sizeM);
	}
	void add_el2(list2* cur) {
		list2* d = (list2*)malloc(sizeof(list2));
		if (!d) {
			cout << "���������� �������� ������" << endl;
			return;
		}
		(d->v) = queue();
		d->v.add();
		if (first == nullptr) {
			first = d;
			last = d;
			return;
		}
		if (cur == last) {
			cur->next = d;
			last = d;
			return;
		}
		d->next = cur->next;
		cur->next = d;
	}
	void del_el2(list2* cur) {
		list2* l = first;
		if (cur == last) {
			for (int i = 0; i < sizeN * sizeM; i++) {
				if ((l->next) == last) {
					break;
				}
				l = l->next;
			}
			last = l;
			free(cur);
		}
		else if (cur == first) {
			cur->next = first;
			free(cur);
		}
		else {
			for (int i = 0; i < sizeN * sizeM; i++) {
				if ((l->next) == cur) {
					break;
				}
				l = l->next;
			}
			l->next = cur->next;
			free(cur);
		}
	}
	void del_matrix() {
		list2* l = first;
		list2* tmp;
		for (int i = 0; i < sizeN * sizeM; i++) {
			tmp = l->next;
			free(l);
			l = tmp;
		}
		sizeN = sizeM = 0;
		first = last = nullptr;
	}
	void makeMatrix(int type = 0) {
		if (!first || !sizeN || !sizeM) {
			list2* d = (list2*)malloc(sizeof(list2));
			if (!d) {
				cout << "���������� �������� ������" << endl;
				return;
			}
			(d->v) = queue();
			d->v.add();
			first = d;
			last = d;
			sizeN = sizeM = 1;
			return;
		}
		if (type != -1) {
			list2* l = first;
			for (int i = 0; i < sizeN; i++) {
				for (int j = 0; j < sizeM; j++) {
					if (j == sizeM - 1) {
						add_el2(l);
						l = l->next;
					}
					l = l->next;
				}
			}
			sizeM++;
		}
		else {
			for (int i = 0; i < sizeM; i++) {
				add_el2(last);
			}
			sizeN++;
		}
	}
	void del(int type = 0) {
		if (type != -1) {
			if (!sizeM) {
				cout << "������� �����" << endl; Sleep(2000);
				return;
			}
			list2* l = first;
			list2* l2 = first;
			sizeM--;
			for (int i = 0; i < sizeN; i++) {
				for (int j = 0; j < sizeM + 1; j++) {
					l2 = l->next;
					if (j == sizeM) {
						del_el2(l);
					}
					l = l2;
				}
			}
		}
		else {
			if (!sizeN) {
				cout << "������� �����" << endl; Sleep(2000);
				return;
			}
			for (int i = 0; i < sizeM; i++) {
				del_el2(last);
			}
			sizeN--;
		}

	}
	queue* retColrOrStr(int mode = 0) {
		int num, counter = 0;
		queue* q;
		if (!sizeM || !sizeN) {
			cout << "������� �����" << endl;
			return nullptr;
		}
		if (mode == 1) {
			cout << "����� ������, ";
			cinInt(&num);
			if (num >= sizeN || num < 0) {
				cout << "�������� ����� ������" << endl;
				return nullptr;
			}
			output(-1, -1, num, -1);
			q = (queue*)malloc(sizeM * sizeof(queue));
		}
		else {
			cout << "����� �������, ";
			cinInt(&num);
			if (num >= sizeM || num < 0) {
				cout << "�������� ����� �������" << endl;
				return nullptr;
			}
			output(-1, -1, -1, num);
			q = (queue*)malloc(sizeN * sizeof(queue));
		}
		if (!q) {
			cout << "���������� �������� ������" << endl;
			return nullptr;
		}
		list2* l = first;
		list2* l2 = first;
		for (int i = 0; i < sizeN; i++) {
			for (int j = 0; j < sizeM; j++) {
				if (j == num && mode == -1) {
					*(q + counter) = (l->v);
					counter++;
				}
				if (i == num && mode == 1) {
					*(q + counter) = (l->v);
					counter++;
				}
				l = l->next;
			}
		}
		return q;
	}
	void showColOrStr(int mode = 0) {
		int num;
		if (!sizeM || !sizeN) {
			cout << "������� �����" << endl;
			return;
		}
		if (mode == 1) {
			cout << "����� ������, ";
			cinInt(&num);
			if (num >= sizeN || num < 0) {

				cout << "�������� ����� ������" << endl;

			}
			output(-1, -1, num, -1);
		}
		else {
			cout << "����� �������, ";
			cinInt(&num);
			if (num >= sizeM || num < 0) {

				cout << "�������� ����� �������" << endl;

			}
			output(-1, -1, -1, num);
		}
	}
	void output(int cur_n = -1, int cur_m = -1, int showN = -1, int showM = -1) {
		list2* tmp = first;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (int i = 0; i < sizeN; i++) {
			for (int j = 0; j < sizeM; j++) {
				if (showM == j || showN == i) {
					SetConsoleTextAttribute(hConsole, 13);
				}
				else if (i == cur_n && j == cur_m) {
					SetConsoleTextAttribute(hConsole, 14);
				}
				else if ((tmp->v) == 1) {
					SetConsoleTextAttribute(hConsole, 10);
				}
				else {
					SetConsoleTextAttribute(hConsole, 12);
				}
				cout << "[" << i << "x" << j << "]" << " ";
				tmp = tmp->next;
			}
			cout << endl;
			cout << endl;
		}
		SetConsoleTextAttribute(hConsole, 15);
	}
	bool menu() {
		char choice[20];
		static bool zero = true;
		if (zero) {
			cout << "0 - ������   * - �����" << endl;
		}
		else {
			cout << "0 - �������� ����                1 - ����������" << endl <<
				"2 - �������� �� �������          3 - ���-�� �����" << endl <<
				"4 - ���-�� ��������              5 - �������� ��-�� NxM" << endl <<
				"6 - ����� ��-� NxM               7 - �������� �������� ��-�� NxM" << endl <<
				"8 - �������� ������ N            9 - �������� ������� M" << endl <<
				"10 - ������� ������ ���������   11 - ������� ������� ���������" << endl <<
				"12 - ����� ������ N             13 - ����� ������� M" << endl <<
				"14 - �������� ������            15 - �������� �������" << endl <<
				"16 - ����������� �������" << endl;
			cout << endl;
			output();
		}
		cin >> choice;
		if (!strcmp(choice, "0")) {
			if (zero) {
				zero = false;
			}
			else {
				zero = true;
			}
		}
		else if (!zero) {
			if (!strcmp(choice, "1")) {
				del_matrix();
				sizeN = sizeM = 0;
			}
			else if (!strcmp(choice, "2")) {
				if (isEmpty()) {
					cout << endl << "������� �� �����" << endl;
				}
				else {
					cout << endl << "������� �����" << endl;
				}Sleep(2000);
			}
			else if (!strcmp(choice, "3")) {
				cout << "���-�� �����: " << sizeN << endl;
				Sleep(2000);
			}
			else if (!strcmp(choice, "4")) {
				cout << "���-�� ��������: " << sizeM << endl;
				Sleep(2000);
			}
			else if (!strcmp(choice, "5")) {
				queue* tmp;
				if (tmp = getNM()) {
					tmp->output();
				}
				else {
					cout << "������� �����" << sizeN << endl;
				}Sleep(2000);
			}
			else if (!strcmp(choice, "6")) {
				queue* tmp;
				if (tmp = getNM()) {
					cout << tmp->retFirst() << endl;
				}
				else {
					cout << "������� �����" << sizeN << endl;
				}Sleep(2000);
			}
			else if (!strcmp(choice, "7")) {
				queue* tmp;
				if (tmp = getNM()) {
					while (tmp->menu()) {}
				}
				else {
					cout << "������� �����" << sizeN << endl;
					Sleep(2000);
				}; 
			}
			else if (!strcmp(choice, "8")) {
				showColOrStr(1);
				Sleep(2000);
			}
			else if (!strcmp(choice, "9")) {
				showColOrStr(-1);
				Sleep(2000);
			}
			else if (!strcmp(choice, "10")) {
				del(-1);
			}
			else if (!strcmp(choice, "11")) {
				del(1);
			}
			else if (!strcmp(choice, "12")) {
				queue* p;
				p = retColrOrStr(1);
				if (p != nullptr) {
					for (int i = 0; i < sizeM; i++) {
						(p + i)->output();
					}
				}
				Sleep(2000);
			}
			else if (!strcmp(choice, "13")) {
				queue* p;
				p = retColrOrStr(-1);
				if (p != nullptr) {
					for (int i = 0; i < sizeN; i++) {
						(p + i)->output();
					}
				}
				Sleep(2000);
			}
			else if (!strcmp(choice, "14")) {
				makeMatrix(-1);
			}
			else if (!strcmp(choice, "15")) {
				makeMatrix(1);
			}
			else if (!strcmp(choice, "16")) {
				if (!sizeM || !sizeN) {
					cout << "������� �����" << endl;
					
				}
				output();
				Sleep(2000);
			}
		}
		else {
			system("cls");
			return 0;
		}
		system("cls");
		return 1;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	matrix f;
	while (f.menu()) {}
	return 0;
}