#include<bits/stdc++.h>
using namespace std;

int now = 0; //第几个节点
// 哈夫曼树的节点结构
struct HuffmanNode {
	char data; //字符
	int weight; //权值
	int cnt; //出现顺序
	HuffmanNode* left, * right;
	HuffmanNode(char c, int w, int cn) : data(c), weight(w), cnt(cn), left(nullptr), right(nullptr) {}
};

// 用于优先队列中的比较函数
struct Compare {
	bool operator()(const HuffmanNode* a, const HuffmanNode* b) {
		if ('A' <= a->data && a->data <= 'Z' && 'A' <= b->data && b->data <= 'Z') {//都为字母比较权值
			if (a->weight == b->weight) return a->data > b->data;
			else return a->weight > b->weight;
		}
		else { //否则比较先后顺序
			if (a->weight == b->weight) return a->cnt > b->cnt;
			else return a->weight > b->weight;
		}
	}
};

// 生成哈夫曼树
HuffmanNode* buildHuffmanTree(const vector<int>& weights, const vector<char>& characters) {
	priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

	// 创建叶子节点并加入优先队列
	for (int i = 0; i < weights.size(); i++) {
		HuffmanNode* node = new HuffmanNode(characters[i], weights[i], ++now); //++now代表每次节点数都加1
		pq.push(node);
	}

	// 构建哈夫曼树
	while (pq.size() > 1) {
		HuffmanNode* left = pq.top();
		pq.pop();
		HuffmanNode* right = pq.top();
		pq.pop();

		// 创建新节点，权值为左右子节点权值之和
		HuffmanNode* newNode = new HuffmanNode('\0', left->weight + right->weight, ++now);
		newNode->left = left;
		newNode->right = right;

		pq.push(newNode);
	}

	// 返回根节点
	return pq.top();
}

// 遍历哈夫曼树，生成编码表
void generateHuffmanCodes(HuffmanNode* root, string code, vector<string>& codes) {
	if (root == nullptr) {
		return;
	}

	// 叶子节点，保存编码
	if (root->left == nullptr && root->right == nullptr) {
		codes[root->data - 'A'] = code;
	}

	generateHuffmanCodes(root->left, code + "0", codes);
	generateHuffmanCodes(root->right, code + "1", codes);
}

int zimu[26];

int main() {
	string s;
	while (cin >> s) {
		now = 0; //当前节点数置为0
		for (int i = 0; i < 26; i++) zimu[i] = 0;
		for (int i = 0; i < s.size(); i++) {
			if ('a' <= s[i] && s[i] <= 'z') {
				zimu[s[i] - 'a']++;
				s[i] += 'A' - 'a'; //小写转大写
			}
			else {
				zimu[s[i] - 'A']++;
			}
		}
		vector<int> weights;
		vector<char> characters;
		for (int i = 0; i < 26; i++) {
			if (zimu[i] > 0) {
				characters.push_back('A' + i);
				weights.push_back(zimu[i]);
			}
		}

		// 生成哈夫曼树
		HuffmanNode* root = buildHuffmanTree(weights, characters);

		// 生成哈夫曼编码表
		vector<string> codes(26);
		generateHuffmanCodes(root, "", codes);

		// 哈夫曼编码
		// for (int i = 0; i < characters.size(); i++) {
		// 	cout << characters[i] << ": " << codes[characters[i] - 'A'] << endl;
		// }
		for (int i = 0; i < s.size(); i++) {
			cout << codes[s[i] - 'A'];
		}
		cout << '\n';
	}
	return 0;
}
