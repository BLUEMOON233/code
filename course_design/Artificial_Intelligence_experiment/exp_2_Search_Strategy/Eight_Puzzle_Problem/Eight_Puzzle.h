#include<iostream>
#include<vector>
#include<stack>
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
	void init_puzzle();
	void DFS();

	std::vector<Node> paths;

private:
	Node node_start = { "130824765" };
	Node node_end = { "123804765" };
	bool target = false;
	
};