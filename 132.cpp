#include <memory>
class Trie {
private:
	bool IsEnd; // end of a word
	void removeUtil(const string& str, bool& HasChild);
public:
	unordered_map<char, shared_ptr<Trie> > children;

	Trie() :IsEnd(false) {};
	bool search(const string& str) const;
	bool searchPrefix(const string& str) const;
	void insert(const string& str);
	void remove(const string& str) {
		bool flag;
		removeUtil(str, flag);
		return;
	};
	// memory is managed by shared pointer
	virtual ~Trie() {}
};

void Trie::insert(const string& str) {
	Trie* currentPtr = this;
	for (int strIdx = 0; strIdx<str.size(); strIdx++) {
		//case 1: char is a children
		if (currentPtr->children.find(str[strIdx]) != currentPtr->children.end()) {
			currentPtr = (currentPtr->children).at(str[strIdx]).get();
		}
		//case 2: char is not a children
		else {
			shared_ptr<Trie> temp(new Trie());
			currentPtr->children.insert(make_pair(str[strIdx], temp));
			currentPtr = (currentPtr->children).at(str[strIdx]).get();
		}
	}
	currentPtr->IsEnd = true;
	return;
}

bool Trie::searchPrefix(const string& str) const {
	bool result = false;
	// if str is empty
	if (str.size() == 0)   return true;

	if (this->children.find(str[0]) != this->children.end()) {
		//cout<<"find "<<str[0]<<endl;
		string tempStr = str.substr(1);
		//cout<<"rest size"<<tempStr<<endl;
		result = (this->children).at(str[0])->searchPrefix(tempStr);
		//cout<< "result is "<<result<<endl;
	}
	//case 2: char is not a children
	else {
		return false;
	}
	return result;
}

bool Trie::search(const string& str) const {
	bool result = false;
	// if str is empty
	if (str.size() == 0)   return this->IsEnd;

	if (this->children.find(str[0]) != this->children.end()) {
		string tempStr = str.substr(1);
		result = (this->children).at(str[0])->search(tempStr);
	}
	//case 2: char is not a children
	else {
		return false;
	}
	return result;
}

void Trie::removeUtil(const string& str, bool& HasChild) {
	Trie* currentPtr = this;

	//case 1: end of the string
	if (str.size() == 0) {
		currentPtr->IsEnd = false;
		if (currentPtr->children.size() == 0)    HasChild = false;
		if (currentPtr->children.size() != 0)    HasChild = true;
		return;
	}

	//case 2: char is a child, do recursive call
	if (currentPtr->children.find(str[0]) != currentPtr->children.end()) {
		string subStr = str.substr(1);
		bool ChildHasChild = true;
		(currentPtr->children).at(str[0])->removeUtil(subStr, ChildHasChild);
		// if the child has no child itself, erase the char from the map
		if (!ChildHasChild) {
			currentPtr->children.erase(str[0]);
		}
		// check if currentPtr has no child
		if (currentPtr->children.size() == 0 && currentPtr->IsEnd == false) {
			HasChild = false;
		}
		else {
			HasChild = true;
		}
	}
	//case 2: char is not a children, do nothing
	else {
		HasChild = true;
	}
	return;
}


class Solution {
public:
	/**
	* @param board: A list of lists of character
	* @param words: A list of string
	* @return: A list of string
	*/

	bool isValidStep(int heightIdx, int widthIdx, vector<vector<bool> >& visited) {
		int boardHeight = visited.size();
		int boardWidth = visited[0].size();
		if (heightIdx >= 0 && heightIdx<boardHeight && widthIdx >= 0 && widthIdx<boardWidth && visited[heightIdx][widthIdx] == false) {
			return true;
		}
		return false;
	}

	void searchFast(int heightIdx, int widthIdx, Trie& dictionary, unordered_set<string>& resultSet, vector<vector<bool> >& visited, vector<vector<char> > &board, string& partialResult) {

		// search the partialResult+[]
		char centerChar = board[heightIdx][widthIdx];
		partialResult.push_back(centerChar);
		visited[heightIdx][widthIdx] = true;
		string partialResultTail;
		partialResultTail.push_back(centerChar);
		if (dictionary.search(partialResultTail)) {
			//cout<<"find"<<partialResult<<endl;
			resultSet.insert(partialResult);
			dictionary.remove(partialResultTail);
		}

		// if is prefix, search neighbors
		if (dictionary.searchPrefix(partialResultTail)) {
			// for each direction & current, check if it is in dict
			int Neighbor[2][4] = { { 0,0,1,-1 },{ 1,-1,0,0 } };
			for (int i = 0; i<4; i++) {
				if (isValidStep(heightIdx + Neighbor[0][i], widthIdx + Neighbor[1][i], visited)) {
					searchFast(heightIdx + Neighbor[0][i], widthIdx + Neighbor[1][i], *(dictionary.children[centerChar].get()), resultSet, visited, board, partialResult);
				}
			}
		}
		// if not a prefix, do nothing

		// reset the result
		partialResult.pop_back();
		visited[heightIdx][widthIdx] = false;

	}

	void search(int heightIdx, int widthIdx, Trie& dictionary, unordered_set<string>& resultSet, vector<vector<bool> >& visited, vector<vector<char> > &board, string& partialResult) {

		// search the partialResult+[]
		partialResult.push_back(board[heightIdx][widthIdx]);
		visited[heightIdx][widthIdx] = true;
		if (dictionary.search(partialResult)) {
			resultSet.insert(partialResult);
			dictionary.remove(partialResult);
		}

		// if is prefix, search neighbors
		//cout<<"prefix "<< partialResult<<endl;
		if (dictionary.searchPrefix(partialResult)) {
			//cout<<partialResult<<" is a valid prefix"<<endl;
			// for each direction & current, check if it is in dict
			int Neighbor[2][4] = { { 0,0,1,-1 },{ 1,-1,0,0 } };
			for (int i = 0; i<4; i++) {
				if (isValidStep(heightIdx + Neighbor[0][i], widthIdx + Neighbor[1][i], visited)) {
					//cout<<"valid step"<< heightIdx+Neighbor[0][i]<<" "<<widthIdx+Neighbor[1][i]<<endl;
					search(heightIdx + Neighbor[0][i], widthIdx + Neighbor[1][i], dictionary, resultSet, visited, board, partialResult);
				}
			}
		}
		// if not a prefix, do nothing

		// reset the result
		partialResult.pop_back();
		visited[heightIdx][widthIdx] = false;

	}

	vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words) {
		// write your code here
		unordered_set<string> resultSet;
		vector<string> resultVec;
		if (board.size() == 0 || board[0].size() == 0 || words.size() == 0)    return resultVec;

		vector<vector<bool> >   visited;
		int boardHeight = board.size();
		int boardWidth = board[0].size();

		// initilize the trie and a bool map to record visited pos
		Trie dictionary;
		for (auto const& i : words) {
			dictionary.insert(i);
		}
		for (int i = 0; i<boardHeight; i++) {
			vector<bool> tempRow(boardWidth, false);
			visited.push_back(tempRow);
		}
		//cout<<"dog in set? "<<dictionary.search("dog")<<endl;
		//cout<<"d a prefix? "<<dictionary.searchPrefix("d")<<endl;
		//cout<<"  a prefix? "<<dictionary.searchPrefix("")<<endl;
		//cout<<"do a prefix? "<<dictionary.searchPrefix("do")<<endl;


		string partialResult;
		// do a search
		for (int i = 0; i<boardHeight; i++) {
			for (int j = 0; j<boardWidth; j++) {
				//search(i,j, dictionary, resultSet, visited, board, partialResult);
				searchFast(i, j, dictionary, resultSet, visited, board, partialResult);
			}
		}
		//cout<<resultSet.size()<<endl;
		// convert result;
		for (auto&i : resultSet)
			resultVec.push_back(i);

		return resultVec;

	}

};