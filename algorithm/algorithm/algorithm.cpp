#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int getParent(int set[], int x) {
	if (set[x] == x) return x;
	return set[x] = getParent(set, set[x]);
}

void merge(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

bool isSameParent(int set[], int a, int b) {
	a = getParent(set, a);
	b = getParent(set, b);
	if (a == b) return true;
	else return false;
}

struct Edge {
	int node[2];
	int cost;

	Edge(int v1, int v2, int cost) {
		this->node[0] = v1;
		this->node[1] = v2;
		this->cost = cost;
	}
	bool operator < (const Edge& e1) const {
		return cost < e1.cost;
	}
};

int main(){
	const int n = 7;
	int m = 11;
	vector<Edge> e;

	e.push_back(Edge(1, 7, 12));
	e.push_back(Edge(1, 4, 28));
	e.push_back(Edge(1, 2, 67));
	e.push_back(Edge(1, 5, 17));
	e.push_back(Edge(2, 4, 24));
	e.push_back(Edge(2, 5, 62));
	e.push_back(Edge(3, 5, 20));
	e.push_back(Edge(3, 6, 37));
	e.push_back(Edge(4, 7, 13));
	e.push_back(Edge(5, 6, 45));
	e.push_back(Edge(5, 7, 73));

	sort(e.begin(), e.end());

	int set[n];
	for (int i = 0; i < n; i++) set[i] = i;
	int sum = 0;
	for (int i = 0; i < e.size(); i++) {
		if (!isSameParent(set,e[i].node[0]-1, e[i].node[1] - 1)){
			sum += e[i].cost;
			merge(set, e[i].node[0] - 1, e[i].node[1] - 1);
		}
	}

	printf("MST : %d\n", sum);
}