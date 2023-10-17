#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>

struct Node {
	Node() {}
	Node(std::string init_state) : state(init_state) {}
	std::vector<Node> transfer();
	void print();

	std::string state = "?????????";
};

class Eight_Puzzle {
public:
	bool init_puzzle();
	std::vector<Node> get_paths();
	void DFS();
	void BFS();

private:
	Node node_start = { "130824765" };
	Node node_end = { "123804765" };
	bool target = false;
	std::vector<Node> paths;
};