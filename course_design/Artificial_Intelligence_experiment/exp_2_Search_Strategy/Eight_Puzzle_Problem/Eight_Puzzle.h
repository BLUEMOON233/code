#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<numeric>
#include<random>

struct Node {
	Node() {}
	Node(std::string init_state) : state(init_state), depth(0) {}
	Node(std::string init_state, int depth) : state(init_state), depth(depth) {}
	std::vector<Node> transfer();
	std::string toString();

	int get_manhattan_distance(Node tar);
	double get_Euclidean_distance(Node tar);
	int get_wrong_position(Node tar);

	bool operator< (const Node& tar) const;

	std::string state = "?????????";
	int depth = 0;
};

typedef std::pair<int, Node> PIN;
typedef std::pair<double, Node> PDN;

class Eight_Puzzle {
public:
	bool init_puzzle();
	std::vector<Node> get_paths();

	bool DFS();
	bool BFS();
	bool a_star_manhatten();
	bool a_star_Euclidean();
	bool a_star_wrongpos();
	bool DFS_iterative_deepening();
	bool a_star_iterative_deepening();
	bool biBFS();

	void set_random_state();
	std::string get_start_state();
	std::string get_end_state();
	int get_node_cnt();
	bool check_target();

private:
	Node node_start = { "130824765" };
	Node node_end = { "123804765" };
	bool target = false;
	long long node_cnt = 0;
	std::vector<Node> paths;
};