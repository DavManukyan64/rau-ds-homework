#include <iostream>
#include <utility>
#include <vector>
#include <queue>

int timeRequiredToBuy(std::vector<int> tickets, int k) {
	std::queue<std::pair<int, int>> q;
	for (int i = 0; i < tickets.size(); i++) {
		q.push({ i, tickets[i] });
	}
	int time = 0;
	while (!q.empty()) {
		std::pair<int, int> person = q.front();
		q.pop();
		person.second--;
		time++;
		if (person.second == 0 && person.first == k) {
			return time;
		}
		if (person.second > 0) {
			q.push(person);
		}
	}
	return time;
}


int main() {
	std::vector<int> tickets1 = { 2, 3, 2 };
	std::cout << timeRequiredToBuy(tickets1, 2) << '\n';

	std::vector<int> tickets2 = { 5, 1, 1, 1 };
	std::cout << timeRequiredToBuy(tickets2, 0) << '\n';

	return 0;
}
