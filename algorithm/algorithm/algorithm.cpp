#include <iostream> 
#include <string> 
#include <queue> 
#include <unordered_map> 
using namespace std; 

struct Node {
	char character; 
	int frequency;
	Node *left, *right;
}; 
// 우선순위 큐 정렬을 위한 구조체 
// 빈도수를 기준으로 최소힙으로 정렬한다.
 struct cmp {
 bool operator()(Node* A, Node* B) { 
 return A->frequency > B->frequency;
 }
}; 
class HuffmanTree { 
private:
	Node* root = nullptr;
	unordered_map<char, int> um;
	unordered_map<char, string> info;
	priority_queue<Node*, vector<Node*>, cmp> pq;
public:
	~HuffmanTree(){ 
	ReleaseTree(root); 
	root = nullptr; 
	um.clear(); info.clear(); 
	while (!pq.empty()) pq.pop(); 
	} 

	const unordered_map<char, string>& GetInfo() { 
		// 허프만 트리로 얻은 알파벳 별 이진수 정보를 가져온다. 
	return info; 
} 
// 압축할 문자열 정보를 바탕으로 허프만 트리를 만들어 
// 이진수 정보들을 만든다. 
	void Create(const string& str) {
		// 해쉬 테이블을 이용해 빈도수를 기록 
		for (const auto iter : str) ++um[iter]; 
		for (const auto iter : um) {
			// 해쉬 테이블에서 하나씩 꺼내
			// 정보를 노드에 저장 후
			// 우선순위 큐에 집어 넣는다.
			Node* newNode = new Node; 
			newNode->left = nullptr;
			newNode->right = nullptr;
			newNode->character = iter.first;
			newNode->frequency = iter.second;
			pq.push(newNode); 
		}
		// 우선순위 큐 정보를 바탕으로 트리를 만든다. 
		MakeTree();
		// 트리를 순회하면서 이진수 정보를 입력받는다. 
string tmp = ""; 
FindTree(root, tmp); 
} 

private: 
	void MakeTree() { 
	// 우선 순위 큐를 이용해 빈도수가 작은 순으로 
	// 2개씩 꺼내 두 노드를 담는 노드를 만들어
	// 두 노드의 빈도수를 합치고 큐에 다시 집어 넣는다. 
	int limit = pq.size() - 1; 
	for (int i = 0; i < limit; ++i) { 
		Node* newNode = new Node;
		newNode->character = 0;
		newNode->right = pq.top(); 
		pq.pop(); 
		newNode->left = pq.top(); 
		pq.pop(); 
		newNode->frequency = newNode->right->frequency + newNode->left->frequency; 
		pq.push(newNode); 
	} 
	// 이 작업을 마치면 우선순위 큐에는 한가지 원소만 남는다. 
	// 그것이 허프만 트리의 Root 노드가 된다. 
	root = pq.top(); 
}
void FindTree(Node* p, string str) { 
	if (p == nullptr) return; 
	// 왼쪽은 0, 오른쪽은 1 
	// 순회하면서 정보를 더해간다. 
	FindTree(p->left, str + '0'); 
	FindTree(p->right, str + '1'); 
	// 알파벳 정보를 가진 노드를 만날때까지 순회한다. 
	if (p->character != 0) { info[p->character] = str; }
} 
void ReleaseTree(Node* p) {
	// 후위 순화를 하면서 동적할당 했던 노드들을 
	// 할당 해제 시켜준다. 
if (p == nullptr) return;
ReleaseTree(p->left);
ReleaseTree(p->right); 
delete p;
p = nullptr; 
} 
};
int main() {
	string str = "AAAAAAABBCCCDEEEEFFFFFFG";
	HuffmanTree t; 
	t.Create(str); 
	unordered_map<char, string> info = t.GetInfo(); 
	cout << "압축할 문자열 : " << str << "\n\n"; 
	cout << "이진수 정보 : \n"; 
	for (const auto iter : info) { 
		cout << iter.first << ": " << iter.second << endl; 
	}
	cout << "\n압축된 정보: "; 
	for (const auto iter : str) { 
		cout << info[iter] << ' '; 
	} 
}
