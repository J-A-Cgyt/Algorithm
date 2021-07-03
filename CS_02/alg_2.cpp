#include "head.h"
#include <iostream>
#define	SORTANDSEARCH

#ifdef ARRSTR
vector<vector<int>> threeSum(vector<int>& nums);

void setZeroes(vector<vector<int>>& matrix);
#endif // ARRSTR

#ifdef TREE 
//树节点定义
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 //完美二叉树节点定义
struct Node {
	int val;
	Node* left;
	Node* right;
	Node* next;     //多了一个横向指示

	Node() : val(0), left(NULL), right(NULL), next(NULL) {}
	Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
	Node(int _val, Node* _left, Node* _right, Node* _next)
		: val(_val), left(_left), right(_right), next(_next) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);

Node* connect(Node* root);

int numIslands(vector<vector<char>>& grid);
#endif

#ifdef BACKTRACK
vector<string> letterCombinations(string digits);

vector<string> generateParenthesis(int n);

vector<vector<int>> permute(vector<int>& nums);

vector<vector<int>> subsets(vector<int>& nums);

bool exist(vector<vector<char>>& board, string word);

#endif

#ifdef SORTANDSEARCH
void sortColors(vector<int>& nums);

vector<int> topKFrequent(vector<int>& nums, int k);

void max_heapify2(vector<int>& nums, size_t rootIdx);
int findKthLargest(vector<int>& nums, int k);

int findPeakElement(vector<int>& nums);

vector<int> searchRange(vector<int>& nums, int target);

vector<vector<int>> merge(vector<vector<int>>& intervals);
#endif //排序和搜索

int main() {
#ifdef ARRSTR
	vector<int> nums = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,3,1} };
	//auto res = threeSum(nums);
	setZeroes(matrix);
#endif // ARRSTR

#ifdef TREE 
	//生成测试树
	/*
	TreeNode* root = new TreeNode(0);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(6);*/

	//测试生成树2 用于有横向指针的完全二叉树
	Node* root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);

	//auto res = zigzagLevelOrder(root);
	//vector<int> preorder = { 1,2 };  //前序遍历数组
	//vector<int> inorder = { 2,1 };   //中序遍历数组
	//auto res = connect(root);

	vector<vector<char>> grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};

	int res = numIslands(grid);


	{'A', 'B', 'C', 'E'},
	{ 'S','F','C','S' },
	{ 'A','D','E','E' },
#endif

#ifdef BACKTRACK
	//auto res = letterCombinations("23");
	//auto res = generateParenthesis(3);
	//vector<int> nums = { 1,2,3,4,5 };
	vector<vector<char>> board = {
		{'a','b'}
	};
	string word("ab");
	auto res = exist(board, word);
#endif

#ifdef SORTANDSEARCH
	vector<vector<int>> nums = { {1,5},{3,6},{7,9} };
	//topKFrequent(nums, 2);
	//auto res = findPeakElement(nums);
	//auto res = findKthLargest(nums, 9);
	auto res = merge(nums);
#endif //排序和搜索

	return 0;
}

#ifdef ARRSTR

using std::unordered_set;
using std::unordered_multiset;
using std::unordered_map;
using std::unordered_multimap;

vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	if (nums.size() < 3) { return res; }

	for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
		while (i < nums.size() - 2 && i>0 && nums[i - 1] == nums[i]) { i++; }
		int base = nums[i];
		int A = i + 1;
		int B = nums.size() - 1;
		while (A < B) {
			if (nums[A] + nums[B] + nums[i] < 0) {
				A++;
			}
			else if (nums[A] + nums[B] + nums[i] > 0) {
				B--;
			}
			else {
				res.push_back(vector<int>{ nums[A], nums[B], nums[i] });
				while (A < B && (nums[A] == nums[A + 1] || nums[B] == nums[B - 1])) {
					if (nums[A] == nums[A + 1])
					{
						A++;
					}
					if (nums[B] == nums[B - 1])
					{
						B--;
					}
				}
				A++; B--;

			}
		}

	}
	return res;
}

void setZeroes(vector<vector<int>>& matrix) {
	bool isZero = true;
	size_t m = matrix.size();     //rows
	size_t n = matrix[0].size();  //cols
	
	bool is1stRowHas0 = false;
	bool is1stColHas0 = false;
	for (int i = 0; i < m; i++) {
		if (matrix[i][0] == 0) {
			is1stColHas0 = true;
		}
	}
	for (int i = 0; i < n; i++) {
		if (matrix[0][i] == 0) {
			is1stRowHas0 = true;
		}
	}

	for (int row = 1; row < m; row++) {
		for (int col = 1; col < n; col++) {
			if (matrix[row][col] == 0) {
				matrix[row][0] = 0;
				matrix[0][col] = 0;
			}
		}
	}

	for (int row = 1; row < m; row++) {
		if (matrix[row][0] == 0) {
			for (int col = 1; col < n; col++) {
				matrix[row][col] = 0;
			}
		}
	}

	for (int col = 1; col < n; col++) {
		if (matrix[0][col] == 0) {
			for (int row = 1; row < m; row++) {
				matrix[row][col] = 0;
			}
		}
	}

	if (is1stRowHas0) {
		for (int i = 0; i < n; i++) {
			matrix[0][i] = 0;
		}
	}

	if (is1stColHas0) {
		for (int i = 0; i < m; i++) {
			matrix[i][0] = 0;
		}
	}

	return;
}



#endif // ARRSTR

#ifdef TREE 
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	if (root == nullptr) { return vector<vector<int>>(); }
	vector<TreeNode*> visitSheet;
	visitSheet.push_back(root);
	vector<size_t> levelCount = { 1 };    //每层有多少节点
	size_t currentLevelCount(0);          //当前层节点数
	size_t preLevelCount(1);
	//压入序列并完成层级计数
	for (size_t x = 0; x < visitSheet.size(); x++) {
		if (visitSheet[x]->left) {
			visitSheet.push_back(visitSheet[x]->left);
			currentLevelCount++;
		}
		if (visitSheet[x]->right) {
			visitSheet.push_back(visitSheet[x]->right);
			currentLevelCount++;
		}
		preLevelCount--;
		if (preLevelCount == 0 && currentLevelCount > 0) {
			levelCount.push_back(currentLevelCount);
			preLevelCount = currentLevelCount;
			currentLevelCount = 0;
		}
	}

	vector<vector<int>> res(levelCount.size());
	size_t levelHead = 0;
	for (size_t i = 0; i < levelCount.size(); i++) {
		if (i % 2 == 0) { //正向读取层
			for (size_t j = levelHead; j < levelHead + levelCount[i]; j++) {
				res[i].push_back(visitSheet[j]->val);
			}
		}
		else {  //反向读取层
			for (size_t j = levelCount[i] + levelHead - 1; j >= levelHead; j--) {
				res[i].push_back(visitSheet[j]->val);
			}
		}
		levelHead = levelHead + levelCount[i];
	}

	return res;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() == 0) { return nullptr; }

	if (preorder.size() == 1) { //特殊情况
		return new TreeNode(preorder[0]);
	}
	
	TreeNode* root = new TreeNode(preorder[0]);

	auto rootInIdx = inorder.begin();            //本层根在中序遍历中的索引
	size_t leftCount = 0;
	while (*rootInIdx != root->val) { 
		rootInIdx++; 
		leftCount++;
	}
	vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftCount);
	vector<int> leftIn(inorder.begin(),rootInIdx);     //左侧子树遍历
	vector<int> rightPre(preorder.begin() + 1 + leftCount, preorder.end()); 
	vector<int> rightIn(rootInIdx + 1, inorder.end());    //右侧子树遍历

	root->left = buildTree(leftPre, leftIn);
	root->right = buildTree(rightPre, rightIn);
	
	return root;
}  //时空效率都不是很好 就是思路比较简单

Node* connect(Node* root) { //似乎可以用递归做
	if (root == nullptr) { return root; }
	vector<Node*> visitSheet;
	visitSheet.push_back(root);
	vector<size_t> levelCount = { 1 };    //每层有多少节点
	size_t currentLevelCount(0);          //当前层节点数
	size_t preLevelCount(1);
	//压入序列并完成层级计数
	for (size_t x = 0; x < visitSheet.size(); x++) {
		if (visitSheet[x]->left) {
			visitSheet.push_back(visitSheet[x]->left);
			currentLevelCount++;
		}
		if (visitSheet[x]->right) {
			visitSheet.push_back(visitSheet[x]->right);
			currentLevelCount++;
		}
		preLevelCount--;
		if (preLevelCount == 0 && currentLevelCount > 0) {
			levelCount.push_back(currentLevelCount);
			preLevelCount = currentLevelCount;
			currentLevelCount = 0;
		}
	}

	size_t j = 0;
	for (size_t i = 0; i < levelCount.size(); i++) {
		if (levelCount[i] == 1) { j += levelCount[i] + 1; continue; }
		for (size_t k = 0; k < levelCount[i]-1; k++) {
			visitSheet[j + k - 1]->next = visitSheet[j + k];
		}
		j += levelCount[i];
	}

	return root;
}

typedef std::pair<int, int> cord;

void landExtend(vector<vector<char>>& grid,cord seed, 
				        vector<cord>& land) {
	if (grid[seed.first][seed.second] == '1') {
		land.push_back(seed);
		grid[seed.first][seed.second] = '2';
	}
	else {
		return;
	}

	if (seed.first > 0) {
		cord up = cord(seed.first - 1, seed.second);
		landExtend(grid, up, land);
	}
	if (seed.first < grid.size() - 1) {
		cord down = cord(seed.first + 1, seed.second);
		landExtend(grid, down, land);
	}
	if (seed.second > 0) {
		cord up = cord(seed.first, seed.second - 1);
		landExtend(grid, up, land);
	}
	if (seed.second < grid[0].size() - 1) {
		cord down = cord(seed.first, seed.second + 1);
		landExtend(grid, down, land);
	}
	return;
}

int numIslands(vector<vector<char>>& grid) {
	
	vector<vector<cord>> lands;

	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[0].size(); j++) {
			if (grid[i][j] == '1') {
				vector<cord> land;
				cord seed(i, j);
				landExtend(grid, seed, land);
				lands.push_back(land);
			}
		}
	}

	return lands.size();
}
#endif

#ifdef BACKTRACK
vector<string> letterCombinations(string digits) {
	vector<vector<char>> searchSheet = {
		{'a','b','c'},
		{'d','e','f'},
		{'g','h','i'},
		{'j','k','l'},
		{'m','n','o'},
		{'p','q','r','s'},
		{'t','u','v'},
		{'w','x','y','z'}
	};

	vector<string> temp(1);
	vector<string> res;

	for (size_t i = 0; i < digits.size(); i++) {
		int num = digits[i] - '2';
		for (auto str : temp) {
			for (char x : searchSheet[num]) {
				string strt = str;
				strt.push_back(x);
				res.push_back(strt);
			}

		}
		temp = res;
		res.clear();
	}

	return temp;
}

vector<string> generateParenthesis(int n) {  //顺序不同算错 没必要纠结了应该是还有无需保存前置结果的方法
	string origin("()");
	vector<string> res;
	vector<string> temp;

	res.push_back(origin);
	for (int i = 1; i < n; i++) {
		string add[3];
		for (string src : res) {
			add[0] = src; add[0].push_back('('); add[0].push_back(')');                           //右
			add[1] = src; add[1].insert(add[1].begin(),'('); add[1].push_back(')');               //中
			add[2] = src; add[2].insert(add[2].begin(), ')'); add[2].insert(add[2].begin(), '('); //左
			temp.push_back(add[0]); temp.push_back(add[1]);
			if (add[0] != add[2]) { temp.push_back(add[2]); }
		}
		res = temp;
		temp.clear();
	}
	return res;
}

vector<vector<int>> permute(vector<int>& nums) {
	if (nums.size() == 0) {
		return vector<vector<int>>();
	}
	vector<vector<int>> res;
	if (nums.size() == 1) {
		res.push_back(nums);
		return res;
	}
	if (nums.size() > 1) {
		for (size_t i = 0; i < nums.size(); i++) {
			vector<int> tempVec = nums;
			int tempNum = tempVec[i];
			tempVec.erase(tempVec.begin() + i);
			decltype(res) tempRes = permute(tempVec);
			for (size_t j = 0; j < tempRes.size(); j++) {
				tempRes[j].push_back(tempNum);
			}
			res.insert(res.end(),tempRes.begin(), tempRes.end());
		}
	}
	return res;
}

void  specSizeSubsets(vector<vector<int>>& dst, int nsize, vector<int>& nums) {
	if (nsize == 0) { return; }
	int loop = nums.size() - nsize;
	vector<vector<int>> tempDst;   //暂存的部分结果
	vector<vector<int>> tempRes;
	for (int i = 0; i <= loop; i++) {
		tempDst = dst;
		vector<int> tempNums(nums.begin() + 1 + i,nums.end());
		for (int j = 0; j < tempDst.size(); j++) {
			tempDst[j].push_back(nums[i]);
		}
		specSizeSubsets(tempDst, nsize - 1, tempNums);
		tempRes.insert(tempRes.end(), tempDst.begin(), tempDst.end());
	}
	dst = tempRes;
	return;
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> res(1);
	vector<vector<int>> Dst(1);
	size_t subsetSize = 0;
	//基本循环应该是一致的
	for (size_t i(1); i < nums.size(); i++) {
		Dst = vector<vector<int>>(1);
		specSizeSubsets(Dst, i, nums);
		res.insert(res.end(), Dst.begin(), Dst.end());
	}
	res.push_back(nums);
	return res;
}

bool expand(vector<vector<char>> boardCpy, int iStart, int jStart, string word, int wordIdx) {
	if (wordIdx == word.size()-1 && word[wordIdx] == boardCpy[iStart][jStart]) { return true; }
	if (boardCpy[iStart][jStart] != word[wordIdx]) { 
		return false; 
	}  //这也算剪枝吧？
	std::cout << boardCpy[iStart][jStart];
	boardCpy[iStart][jStart] = 0xff;
	bool res = false;
	if (iStart > 0 && boardCpy[iStart - 1][jStart] != 0xff) {
		res = res || expand(boardCpy, iStart - 1, jStart, word, wordIdx + 1);
	}
	if (jStart > 0 && boardCpy[iStart][jStart - 1] != 0xff) {
		res = res || expand(boardCpy, iStart, jStart - 1, word, wordIdx + 1);
	}
	if (iStart < boardCpy.size() - 1 && boardCpy[iStart + 1][jStart] != 0xff) {
		res = res || expand(boardCpy, iStart + 1, jStart, word, wordIdx + 1);
	}
	if (jStart < boardCpy[0].size() - 1 && boardCpy[iStart][jStart + 1] != 0xff) {
		res = res || expand(boardCpy, iStart, jStart + 1, word, wordIdx + 1);
	}
	return res;
}

bool exist(vector<vector<char>>& board, string word) {
	//全都大写
	for (int i = 0;i<word.size();i++) {
		word[i] = toupper(word[i]);
	}
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			board[i][j] = toupper(board[i][j]);
		}
	}
	for (int k = 0; k < word.size(); k++) {
		bool you = false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == word[k]) {
					you = true;
				}
			}
		}
		if (!you) { return false; }
	}

	bool res = false;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (board[i][j] == word[0]) {
				//进程2 扩展
				res = res || expand(board, i, j, word, 0);
				if (res) { 
					return res; 
				}
			}
		}
	}

	return res;
}
#endif

#ifdef SORTANDSEARCH
void sortColors(vector<int>& nums) {
	size_t n = nums.size();
	int buffer[3] = { 0 };
	for (int i = 0; i < n; i++) {
		buffer[nums[i]]++;
	}
	for (int i = 0; i < n; i++) {
		if (i < buffer[0]) {
			nums[i] = 0;
		}
		else if (i < buffer[0] + buffer[1]) {
			nums[i] = 1;
		}
		else {
			nums[i] = 2;
		}
	}
	return;
}

using std::unordered_map;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int,size_t> element_count;
	for (int i = 0; i < nums.size(); i++) {
		element_count[nums[i]]++;
	}
	vector<int> res;

	for (int i = 0; i < k; i++) {
		int temp = element_count.begin()->first;
		for (auto x = element_count.begin(); x != element_count.end(); x++) {
			if (x->second > element_count[temp]) {
				temp = x->first;
			}
		}
		res.push_back(temp);
		element_count.erase(temp);
	}

	return res;
}

//复习一下堆排序
#define LEFT(i) (2*i+1)
#define RIGHT(i) (2*i+2)
//最大堆维护 注意这个维护 外部运行一次只能将一个叶节点放至原位 若被放置的目标不是叶节点 则无法保证整个最大堆的性质
void max_heapify2(vector<int>& nums, size_t rootIdx) {
	size_t left = LEFT(rootIdx);
	size_t right = RIGHT(rootIdx);
	size_t max(rootIdx);
	if (left < nums.size() && nums[max] < nums[left]) {
		max = left;
	}
	if (right < nums.size() && nums[max] < nums[right]) {
		max = right;
	}

	if (max != rootIdx) {
		int temp = nums[max];
		nums[max] = nums[rootIdx];
		nums[rootIdx] = temp;
		max_heapify2(nums, max);
	}
}

int findKthLargest(vector<int>& nums, int k) {
	//int temp(0);
	size_t level = nums.size()/2-1;
	for (int i = level; i >= 0; i--) {
		max_heapify2(nums, i);
	}
	for (int i = 1; i < k; i++) { //堆排序+输出 注意最大堆性质的维护需要破坏掉原有的最大堆性质 但保证只有一个叶节点不在原位
		std::cout << nums[0] << ',';
		std::swap(*(nums.begin()), *(nums.end()-1));
		nums.erase(nums.end() - 1);
		max_heapify2(nums, 0);
		int x = 0;
	}

	return nums[0];
}

int findPeakElement(vector<int>& nums) {
	size_t startPos = nums.size() / 2;
	size_t nowPos = startPos;
	//特殊情况 处理
	if (nums.size() == 2) {
		return nums[1] > nums[0] ? 1 : 0;
	}
	while (true) {
		if (nowPos == 0 || nowPos == nums.size() - 1) { return nowPos; }
		if (nums[nowPos - 1] < nums[nowPos] && nums[nowPos + 1] < nums[nowPos]) {
			return nowPos;
		} //目标点不满足条件时往坡上爬 如果一直上坡，则边缘必然算一个峰值
		else if (nums[nowPos - 1] > nums[nowPos]) {
			nowPos--;
		}
		else {
			nowPos++;
		}
	}
}

vector<int> searchRange(vector<int>& nums, int target) {
	
	size_t idx = 0;
	size_t end = 0;
	vector<int> res = { -1,-1 };

	for (; idx < nums.size(); idx++) {
		if (nums[idx] == target) { break; }
		else if (nums[idx] > target) {
			return res;
		}
	}

	if (idx == nums.size()) {
		return res;
	}

	for(end=idx;end<nums.size() && nums[end]==target;end++){}

	res[0] = idx;
	res[1] = end - 1;

	return res;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {

}
#endif //排序和搜索