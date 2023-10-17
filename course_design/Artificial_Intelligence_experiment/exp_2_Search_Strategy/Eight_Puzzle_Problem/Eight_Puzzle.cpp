#include"Eight_Puzzle.h"

std::vector<Node> Node::transfer() {
	std::vector<Node> ret;
	for (int index = 0; index < 9; index++) if (this->state[index] == '0') {
		int r = index / 3, c = index % 3;
		if (r - 1 >= 0) {
			std::string now = this->state;
			int tar = (r - 1) * 3 + c;
			std::swap(now[index], now[tar]);
			ret.emplace_back(now);
		}
		if (r + 1 < 3) {
			std::string now = this->state;
			int tar = (r + 1) * 3 + c;
			std::swap(now[index], now[tar]);
			ret.emplace_back(now);
		}
		if (c - 1 >= 0) {
			std::string now = this->state;
			int tar = r * 3 + (c - 1);
			std::swap(now[index], now[tar]);
			ret.emplace_back(now);
		}
		if (c + 1 < 3) {
			std::string now = this->state;
			int tar = r * 3 + (c + 1);
			std::swap(now[index], now[tar]);
			ret.emplace_back(now);
		}
	}
	return ret;
}

void Node::print() {
	std::cout << '\n';
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			std::cout << this->state[r * 3 + c] << " \n"[c == 2];
		}
	}
}

bool Eight_Puzzle::init_puzzle() {
	target = false;
	paths.clear();
	int flag_start = 0, flag_end = 0;
	for (int l = 0; l < 9; l++) for (int r = l + 1; r < 9; r++) {
		if (this->node_start.state[l] > this->node_start.state[r])
			flag_start++;
		if (this->node_end.state[l] > this->node_end.state[r])
			flag_end++;
	}
	if (flag_start % 2 != flag_end % 2)
		return false;
	return true;
}

std::vector<Node> Eight_Puzzle::get_paths() {
	return this->paths;
}

void Eight_Puzzle::DFS() {
	this->init_puzzle();

	std::stack<Node> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push(node_start);
	while (!table_open.empty()) {
		Node now = table_open.top();
		table_open.pop();

		if (now.state == node_end.state) {
			target = true;
			std::string now_state = now.state;
			while (now_state != node_start.state) {
				this->paths.emplace_back(now_state);
				now_state = table_close[now_state];
			}
			this->paths.emplace_back(now_state);
			std::reverse(paths.begin(), paths.end());
			break;
		}

		std::vector<Node> next_states = now.transfer();
		for (Node nxt : next_states) {
			if (!table_close[nxt.state].empty()) continue;
			table_open.push(nxt);
			table_close[nxt.state] = now.state;
		}
	}
}

void Eight_Puzzle::BFS() {
	this->init_puzzle();

	std::queue<Node> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push(node_start);
	while (!table_open.empty()) {
		Node now = table_open.front();
		table_open.pop();

		if (now.state == node_end.state) {
			target = true;
			std::string now_state = now.state;
			while (now_state != node_start.state) {
				this->paths.emplace_back(now_state);
				now_state = table_close[now_state];
			}
			this->paths.emplace_back(now_state);
			std::reverse(paths.begin(), paths.end());
			break;
		}

		std::vector<Node> next_states = now.transfer();
		for (Node nxt : next_states) {
			if (!table_close[nxt.state].empty()) continue;
			table_open.push(nxt);
			table_close[nxt.state] = now.state;
		}
	}
}