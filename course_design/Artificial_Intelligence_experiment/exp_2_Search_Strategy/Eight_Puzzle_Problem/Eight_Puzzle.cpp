#include"Eight_Puzzle.h"

std::vector<Node> Node::transfer() {
	std::vector<Node> ret;
	for (int index = 0; index < 9; index++) if (this->state[index] == '0') {
		int r = index / 3, c = index % 3;
		if (r - 1 >= 0) {
			std::string now = this->state;
			int tar = (r - 1) * 3 + c;
			std::swap(now[index], now[tar]);
			ret.emplace_back(now, this->depth + 1);
		}
		if (r + 1 < 3) {
			std::string now = this->state;
			int tar = (r + 1) * 3 + c;
			std::swap(now[index], now[tar]);
			ret.emplace_back(now, this->depth + 1);
		}
		if (c - 1 >= 0) {
			std::string now = this->state;
			int tar = r * 3 + (c - 1);
			std::swap(now[index], now[tar]);
			ret.emplace_back(now, this->depth + 1);
		}
		if (c + 1 < 3) {
			std::string now = this->state;
			int tar = r * 3 + (c + 1);
			std::swap(now[index], now[tar]);
			ret.emplace_back(now, this->depth + 1);
		}
	}
	return ret;
}

std::string Node::toString() {
	std::string ret = "\n";
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			ret += this->state[r * 3 + c];
			if (r < 3) ret += " \n"[c == 2];
			else if (c < 2) ret += ' ';
		}
	}
	return ret;
}

int Node::get_manhattan_distance(Node tar) {
	int cost = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (tar.state[j] == this->state[i]) {
				int rx = i / 3, cx = i % 3;
				int ry = j / 3, cy = j % 3;
				cost += abs(rx - ry) + abs(cx - cy);
			}
		}
	}
	return cost;
}

double Node::get_Euclidean_distance(Node tar) {
	double cost = 0.0;
	auto get_dis = [](double x1, double y1, double x2, double y2) -> double {
		double ret = 0.0;
		ret += (x1 - x2) * (x1 - x2);
		ret += (y1 - y2) * (y1 - y2);
		return sqrt(ret);
		};
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (tar.state[j] == this->state[i]) {
				int rx = i / 3, cx = i % 3;
				int ry = j / 3, cy = j % 3;
				cost += get_dis(rx, cx, ry, cy);
			}
		}
	}
	return cost;
}

int Node::get_wrong_position(Node tar) {
	int cost = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (tar.state[j] != this->state[i]) {
				cost++;
			}
		}
	}
	return cost;
}

bool Node::operator< (const Node& tar) const {
	return this->depth < tar.depth;
}

bool Eight_Puzzle::init_puzzle() {
	node_cnt = 0;
	target = false;
	paths.clear();
	int flag_start = 0, flag_end = 0;
	std::vector<char> st, en;
	for (char ch : node_start.state) if (ch != '0') st.emplace_back(ch);
	for (char ch : node_end.state) if (ch != '0')  en.emplace_back(ch);
	for (int l = 0; l < 8; l++) for (int r = l + 1; r < 8; r++) {
		if (st[l] > st[r]) flag_start++;
		if (en[l] > en[r]) flag_end++;
	}
	target = true;
	if (flag_start % 2 != flag_end % 2)
		target = false;
	return target;
}

std::vector<Node> Eight_Puzzle::get_paths() {
	return this->paths;
}

bool Eight_Puzzle::DFS() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::stack<Node> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push(node_start);
	this->node_cnt++;
	while (!table_open.empty()) {
		Node now = table_open.top();

		if (now.state == node_end.state) {
			std::string now_state = now.state;
			while (now_state != node_start.state) {
				this->paths.emplace_back(now_state);
				now_state = table_close[now_state];
			}
			this->paths.emplace_back(now_state);
			std::reverse(paths.begin(), paths.end());
			break;
		}

		bool isFinished = true;
		std::vector<Node> next_states = now.transfer();
		for (Node nxt : next_states) {
			if (!table_close[nxt.state].empty()) continue;
			isFinished = false;
			table_open.push(nxt);
			table_close[nxt.state] = now.state;
			this->node_cnt++;
			break;
		}
		if (isFinished) table_open.pop();
	}
	return true;
}

bool Eight_Puzzle::BFS() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::queue<Node> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push(node_start);
	while (!table_open.empty()) {
		Node now = table_open.front();
		table_open.pop();
		this->node_cnt++;

		if (now.state == node_end.state) {
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
	return true;
}

bool Eight_Puzzle::a_star_manhatten() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::priority_queue<PIN, std::vector<PIN>, std::greater<PIN>> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push({ 0, node_start });
	while (!table_open.empty()) {
		auto [cost, now] = table_open.top();
		table_open.pop();
		this->node_cnt++;

		if (now.state == node_end.state) {
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
			int nxt_cost = nxt.depth + nxt.get_manhattan_distance(node_end);
			table_open.push({ nxt_cost, nxt });
			table_close[nxt.state] = now.state;
		}
	}
	return true;
}


bool Eight_Puzzle::a_star_Euclidean() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::priority_queue<PDN, std::vector<PDN>, std::greater<PDN>> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push({ 0, node_start });
	while (!table_open.empty()) {
		auto [cost, now] = table_open.top();
		table_open.pop();
		this->node_cnt++;

		if (now.state == node_end.state) {
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
			double nxt_cost = nxt.depth + nxt.get_Euclidean_distance(node_end);
			table_open.push({ nxt_cost, nxt });
			table_close[nxt.state] = now.state;
		}
	}
	return true;
}

bool Eight_Puzzle::a_star_wrongpos() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::priority_queue<PIN, std::vector<PIN>, std::greater<PIN>> table_open;
	std::unordered_map <std::string, std::string> table_close;
	table_open.push({ 0, node_start });
	while (!table_open.empty()) {
		auto [cost, now] = table_open.top();
		table_open.pop();
		this->node_cnt++;

		if (now.state == node_end.state) {
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
			int nxt_cost = nxt.depth + nxt.get_wrong_position(node_end);
			table_open.push({ nxt_cost, nxt });
			table_close[nxt.state] = now.state;
		}
	}
	return true;
}

bool Eight_Puzzle::DFS_iterative_deepening() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::stack<Node> table_open;
	std::unordered_map <std::string, std::string> table_close;
	std::queue<Node> wait_queue;
	table_open.push(node_start);
	this->node_cnt++;
	int max_depth = 1;
	bool flag = true;

	while (paths.empty()) {
		while (!wait_queue.empty()) {
			table_open.push(wait_queue.front());
			wait_queue.pop();
		}

		while (!table_open.empty()) {
			Node now = table_open.top();

			if (now.depth > max_depth) {
				wait_queue.push(now);
				table_open.pop();
				continue;
			}
			if (now.state == node_end.state) {
				std::string now_state = now.state;
				while (now_state != node_start.state) {
					this->paths.emplace_back(now_state);
					now_state = table_close[now_state];
				}
				this->paths.emplace_back(now_state);
				std::reverse(paths.begin(), paths.end());
				break;
			}

			bool isFinished = true;
			std::vector<Node> next_states = now.transfer();
			for (Node nxt : next_states) {
				if (!table_close[nxt.state].empty()) continue;
				isFinished = false;
				table_open.push(nxt);
				table_close[nxt.state] = now.state;
				this->node_cnt++;
				break;
			}
			if (isFinished) table_open.pop();
		}
		if (paths.empty()) max_depth <<= 1;
	}
	return true;
}

bool Eight_Puzzle::a_star_iterative_deepening() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::priority_queue<PIN, std::vector<PIN>, std::greater<PIN>> table_open;
	std::unordered_map <std::string, std::string> table_close;
	std::queue<Node> wait_queue;
	table_open.push({ 0, node_start });
	int max_cost = 1;

	while (paths.empty()) {
		while (!wait_queue.empty()) {
			table_open.push({ 0, wait_queue.front() });
			wait_queue.pop();
		}

		while (!table_open.empty()) {
			auto [cost, now] = table_open.top();
			table_open.pop();
			this->node_cnt++;

			if (cost > max_cost) {
				wait_queue.push(now);
				continue;
			}

			if (now.state == node_end.state) {
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
				int nxt_cost = nxt.depth + nxt.get_manhattan_distance(node_end);
				table_open.push({ nxt_cost, nxt });
				table_close[nxt.state] = now.state;
			}
		}

		max_cost <<= 1;
	}
	return true;
}

bool Eight_Puzzle::biBFS() {
	this->init_puzzle();
	if (!this->target)
		return false;

	std::queue<Node> table_open_front, table_open_back;
	std::unordered_map <std::string, std::string> table_close_front, table_close_back;
	table_open_front.push(node_start);
	table_open_back.push(node_end);
	table_close_front[node_start.state] = "end";
	table_close_back[node_end.state] = "end";
	while (!table_open_front.empty() && !table_open_back.empty()) {
		if (table_open_front.size() <= table_open_back.size()) {
			Node now = table_open_front.front();
			table_open_front.pop();
			this->node_cnt++;

			if (!table_close_back[now.state].empty()) {
				std::string now_state = now.state;
				while (now_state != "end") {
					this->paths.emplace_back(now_state);
					now_state = table_close_front[now_state];
				}
				std::reverse(paths.begin(), paths.end());
				now_state = now.state;
				while (now_state != "end") {
					this->paths.emplace_back(now_state);
					now_state = table_close_back[now_state];
				}
				break;
			}

			std::vector<Node> next_states = now.transfer();
			for (Node nxt : next_states) {
				if (!table_close_front[nxt.state].empty()) continue;
				table_open_front.push(nxt);
				table_close_front[nxt.state] = now.state;
			}
		}
		else {
			Node now = table_open_back.front();
			table_open_back.pop();
			this->node_cnt++;

			if (!table_close_front[now.state].empty()) {
				std::string now_state = now.state;
				while (now_state != "end") {
					this->paths.emplace_back(now_state);
					now_state = table_close_front[now_state];
				}
				std::reverse(paths.begin(), paths.end());
				now_state = now.state;
				while (now_state != "end") {
					this->paths.emplace_back(now_state);
					now_state = table_close_back[now_state];
				}
				break;
			}

			std::vector<Node> next_states = now.transfer();
			for (Node nxt : next_states) {
				if (!table_close_back[nxt.state].empty()) continue;
				table_open_back.push(nxt);
				table_close_back[nxt.state] = now.state;
			}
		}
	}
	return true;
}

void Eight_Puzzle::set_random_state() {
	std::vector<int> v(9);
	std::iota(v.begin(), v.end(), 0);
	std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });
	for (int i = 0; i < 9; i++) node_start.state[i] = v[i] + '0';
	std::shuffle(v.begin(), v.end(), std::mt19937{ std::random_device{}() });
	for (int i = 0; i < 9; i++) node_end.state[i] = v[i] + '0';
}

std::string Eight_Puzzle::get_start_state() {
	return this->node_start.state;
}

std::string Eight_Puzzle::get_end_state() {
	return this->node_end.state;
}

int Eight_Puzzle::get_node_cnt() {
	return this->node_cnt;
}

bool Eight_Puzzle::check_target() {
	this->init_puzzle();
	return this->target;
}