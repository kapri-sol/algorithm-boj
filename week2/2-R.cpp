#include <iostream>
#include <vector>

using namespace std;

int N;
int nodes[50];
int delNode;
int rootNode = -1;
int leafNodeCnt;

void countLeafNode(int node) {
    vector<int> childs;

    for(int i = 0; i < N; i++) {
        if(nodes[i] == -2) continue;
        if(nodes[i] == node) childs.push_back(i);
    }

    if(childs.size() == 0) {
        leafNodeCnt++;
        return;
    }

    for(int i = 0; i < childs.size(); i++)
        countLeafNode(childs[i]);
}

void deleteNode(int node) {
    nodes[node] = -2;

    vector<int> childs;

    for(int i = 0; i < N; i++)
        if(nodes[i] == node) childs.push_back(i);

    if(childs.size() == 0) return;

    for(int i = 0; i < childs.size(); i++)
        deleteNode(childs[i]);
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> nodes[i];
    }

    cin >> delNode;

    deleteNode(delNode);

    for(int i = 0; i < N; i++){
        if(nodes[i] == -1) rootNode = i;
    }

    if(rootNode > -1) {
        countLeafNode(rootNode);
    }

    cout << leafNodeCnt;

    return 0;
}