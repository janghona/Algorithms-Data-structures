// 프림알고리즘(Prim's algorithm)

#include <iostream>
using namespace std;

#define marked 		-1 		// 방문여부 확인, 싸이클이 형성 방지용
#define NODE_NUM	7 		// 노드(정점)의 수
#define INF 		9999	// 무한대

int primData[NODE_NUM][NODE_NUM] =
{
	{ 0, 14, 22, 21, INF, INF, INF},
	{ 14, 0, 43, INF, INF, INF, 47},
	{ 22, 43, 0, INF, 31, INF, INF},
	{ 21, INF, INF, 0, 50, 55, INF},
	{ INF, INF, 31, 50, 0, INF, 15},
	{ INF, INF, INF, 55, INF, 0, 24},
	{ INF, 47, INF, INF, 15, 24, 0 }
}; // 인접 행렬

void PRIM(int n, int distance[NODE_NUM][NODE_NUM]);// 함수의 정의 변경


int main()
{
	// 아래의 수험번호, 성명 수정하여 입력해야 함
	//system("mode con cols=80 lines=30 | title KOCCA [Problem 2]");
	cout << "■ [문제2] 모범답안 \n■ 수험번호: 213123000002 \n■ 성    명: 나장호\n";
	cout << "\n■  Prim Algrithm ■ \n";

	cout << "==Prim's algorithm MST(Minimum Spanning Tree)==" << endl;
	PRIM(NODE_NUM, primData);

	//scanf_s("%d");
}


void PRIM(int n, int distance[NODE_NUM][NODE_NUM])
{
	int nNodeNum, nCheckPrimNode, nCheckCycleNdoe, nCntPrimNode, primNode[NODE_NUM];
	int nMinDist[NODE_NUM], nNewMin;
	int nSumWeight = 0;

	for (nNodeNum = 1; nNodeNum < n; nNodeNum++) {
		nMinDist[nNodeNum] = distance[0][nNodeNum]; 	// 시작점
		primNode[nNodeNum] = 0; 						//시작 초기값 0번째 정점
	}

	for (nNodeNum = 1; nNodeNum < n; nNodeNum++) {
		nCntPrimNode = 1; 								// 가장 가까운 노드(정점) 값 1
		nNewMin = nMinDist[1];

		for (nCheckPrimNode = 2; nCheckPrimNode < n; nCheckPrimNode++)
			if (nMinDist[nCheckPrimNode] < nNewMin) {
				nNewMin = nMinDist[nCheckPrimNode];
				//* ★
				// 가중치가 작은값이 있을 때 그 값으로 갱신하는 코드 작성
				// ★코드 작성  // 문제 2-1) 10점
				//*/
				nCntPrimNode = nCheckPrimNode; 			// 해당 정점노드를 프림연결노드(정점)로 갱신

			}

		cout << nCntPrimNode << " 번 노드의 가중치(edge):" << " ";
		cout << nNewMin; 								// 가중치 = 최소비용 = 최단거리 = 최소시간
		cout << "\n";

		nSumWeight = nSumWeight + nNewMin; 				// 가중치 합계

		primNode[nCntPrimNode] = marked;				//방문하면 -1로 처리, 싸이클이 형성되지 않게 하기위해서
		nMinDist[nCntPrimNode] = INF; 					//초기값으로 가중치 무한대값 9999 대입

		for (nCheckCycleNdoe = 1; nCheckCycleNdoe < n; nCheckCycleNdoe++) {

			//* ★
			// 인접한 노드 중에서 사이클이 형성되지 않도록 빈곳을 완성하시오.
			if ((primNode[nCheckCycleNdoe] != marked) && (nMinDist[nCheckCycleNdoe] > distance[nCntPrimNode][nCheckCycleNdoe])
				// &&
				// ( ★ 여기에 조건 코드 작성 // 문제 2-2) 5점  )
				)
			{
				nMinDist[nCheckCycleNdoe] = distance[nCntPrimNode][nCheckCycleNdoe];
				// 최소값으로 가중치 갱신하는 코드 작성하시오.
				//
				// ★여기에 코드 작성 // 문제 2-3) 5점
				//
				primNode[nCheckCycleNdoe] = nCntPrimNode;							// 최소값을 가진 가중치의 정점(노드)
			}
		}
	}
	cout << "\n 가중치 합= " << nSumWeight;
}

