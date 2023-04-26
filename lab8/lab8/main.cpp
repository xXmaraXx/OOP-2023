#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <vector>

class Compare {
public:
	bool operator()(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
		if (a.second != b.second) {
			return a.second < b.second;
		}
		else {
			return a.first > b.first;
		}
	}
};

int main() {

	std::ifstream inputFile("input.txt");
	
	std::string phrase="";
	if (inputFile.is_open()) {
		std::getline(inputFile, phrase);
	}
	else {
		std::cerr << "Failed to open input file." << std::endl;
        return 1;
	}

	std::map<std::string, int> wordCount;
	std::string word="";

	for (auto c : phrase) {
		if (c == ' ' || c == ',' || c == '?' || c == '!' || c == '.') {
			if (!word.empty()) {
				for (auto& ch : word) {
					ch = std::tolower(ch);
				}
				wordCount[word]++;
				word.clear();
			}
		}
		else {
			word.push_back(c);
		}
	}

	if (!word.empty()) {
		for (auto& ch : word) {
			ch = std::tolower(ch);
		}
		wordCount[word]++;
	}

	std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Compare> pq;

	for (const auto& pair : wordCount) {
		pq.push(pair);
	}

	while (!pq.empty()) {
		std::cout << pq.top().first << " => " << pq.top().second << std::endl;
		pq.pop();
	}

	inputFile.close();
	return 0;
}