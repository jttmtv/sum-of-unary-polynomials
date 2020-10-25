#include <iostream>
using namespace std;

struct polynomial
{
	int coef;
	int expo;
};

struct node {
	int coef;
	int expo;
	struct node* next;
};

inline node* create_list(polynomial arr[], int n)
{
	node* L = new node;
	if (L) {
		L->coef = 0;
		L->expo = 0;
		L->next = NULL;
	}
	node* temp = L;
	for (int i = 0; i < n; i++) {
		node* p = new node;
		p->coef = arr[i].coef;
		p->expo = arr[i].expo;
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	return L;
}

inline node* Add(node* Pa, node* Pb)
{
	node* p, * q;
	node* prep;
	node* u;

	p = Pa->next;
	q = Pb->next;

	prep = Pa;

	while (p && q)
	{
		if (p->expo < q->expo)
		{
			prep = p;
			p = p->next;
		}
		else if (p->expo > q->expo)
		{
			u = q->next;

			q->next = p;
			prep->next = q;

			prep = q;
			q = u;
		}
		else
		{
			p->coef = p->coef + q->coef;
			if (p->coef == 0)
			{
				node* temp1;
				node* temp2;
				temp1 = p;
				temp2 = q;
				prep->next = p->next;
				p = p->next;
				q = q->next;

				delete temp1;
				delete temp2;
			}
			else
			{
				node* temp2;
				temp2 = q;

				prep = p;
				p = p->next;
				q = q->next;
				delete temp2;
			}
		}
	}
	if (q)
		prep->next = q;
	delete Pb;
	return Pa;
}


inline void print_polynomial(node* L)
{
	std::ios::sync_with_stdio(false);
	node* p = L->next;
	while (p && !(p->coef))
		p = p->next;
	if (!p)
		cout << "0";
	else {
		if (p->coef == 1) {
			if (p->expo == 0) {
				cout << "1";
			}
			else if (p->expo == 1) {
				cout << "x";
			}
			else {
				cout << "x^" << p->expo;
			}
		}
		else if (p->coef == -1) {
			if (p->expo == 0) {
				cout << "-1";
			}
			else if (p->expo == 1) {
				cout << "-x";
			}
			else {
				cout << "-x^" << p->expo;
			}
		}
		else {
			if (p->expo == 0) {
				cout << p->coef;
			}
			else if (p->expo == 1) {
				cout << p->coef << "x";
			}
			else {
				cout << p->coef << "x^" << p->expo;
			}
		}
		p = p->next;
	}
	while (p)
	{
		while (p && !(p->coef)) {
			p = p->next;
		}
		if (p) {
			if (p->coef > 0) {
				if (p->coef == 1) {
					if (p->expo == 0) {
						cout << "+1";
					}
					else if (p->expo == 1) {
						cout << "+x";
					}
					else {
						cout << "+x^" << p->expo;
					}
				}
				else {
					if (p->expo == 0) {
						cout << "+" << p->coef;
					}
					else if (p->expo == 1) {
						cout << "+" << p->coef << "x";
					}
					else {
						cout << "+" << p->coef << "x^" << p->expo;
					}
				}
			}
			else {
				if (p->coef == -1) {
					if (p->expo == 0) {
						cout << "-1";
					}
					else if (p->expo == 1) {
						cout << "-x";
					}
					else {
						cout << "-x^" << p->expo;
					}
				}
				else {
					if (p->expo == 0) {
						cout << p->coef;
					}
					else if (p->expo == 1) {
						cout << p->coef << "x";
					}
					else {
						cout << p->coef << "x^" << p->expo;
					}
				}
			}
			p = p->next;
		}
	}
	cout << "\n";
}

void destroy_list(node* L)
{
	node* p = L;
	while (p) {
		node* temp = p;
		p = p->next;
		delete temp;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		node* L;
		node* L1, * L2;
		int n;
		cin >> n;
		polynomial* poly1 = new polynomial[n];
		for (int i = 0; i < n; i++) {
			cin >> poly1[i].coef >> poly1[i].expo;
		}
		L1 = create_list(poly1, n);
		delete[] poly1;
		int m;
		cin >> m;
		polynomial* poly2 = new polynomial[m];
		for (int i = 0; i < m; i++) {
			cin >> poly2[i].coef >> poly2[i].expo;
		}
		L2 = create_list(poly2, m);
		delete[] poly2;

		L = Add(L1, L2);
		print_polynomial(L);
		destroy_list(L);
	}
	return 0;
}