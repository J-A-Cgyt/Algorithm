#include "head.h"
//初级算法在此练习

#define MAX(a,b) a>b?a:b
#define ROW cord.first    //旋转矩阵用宏定义 下一行也是
#define COL cord.second


int main() {

#ifdef USED
	rotate(matrix);
	std::vector<std::vector<char>> board = { line1,line2,line3,line4,line5,line6,line7,line8,line9 };
	bool flag = isValidSudoku(board);
	std::vector<int> prices = {1,2,2,3,4,5,0,8,0,8,5,0 };
	return maxProfit(prices);
	rotate(prices, 3);
	func(0);
	plusOne(prices);
	moveZeroes(prices);
	std::vector<char> s = { 'h','e','l','l','o','w' };
	reverseString(s);
	int x = firstUniqChar(s);	
	std::string t("abaa");
	bool flag = isAnagram(s, t);
	std::string s("-2147483647");
	int x = myAtoi(s);
	string haystack("hello");
	string needle("er");
	int x = strStr(haystack, needle);
#endif

#ifdef CHAINLIST
	ListNode *temp;
	ListNode *head1 = new ListNode(1);
	head1->next = new ListNode(3);
	temp = head1->next;
	temp->next = new ListNode(3);
	//temp = temp->next;
	//temp->next = new ListNode(1);

	//ListNode *head2 = new ListNode(1);
	//head2->next = new ListNode(1);
	//temp = head2->next;
	//temp->next = new ListNode(4);
	//temp = temp->next;
	//temp->next = new ListNode(6);
	//temp = mergeTwoLists(head1, head2);
	bool x = isPalindrome(head1);
#endif // CHAINLIST

#ifdef BINARYTREE
	//建立一棵树
	TreeNode *root = new TreeNode(5);
	TreeNode *nodePtr;
	root->left = new TreeNode(4);
	nodePtr = root->left;
	nodePtr->right = new TreeNode(1);
	nodePtr = nodePtr->right;
	nodePtr->left = new TreeNode(2);

	root->right = new TreeNode(1);
	nodePtr = root->right;
	nodePtr->right = new TreeNode(4);
	nodePtr = nodePtr->right;
	nodePtr->left = new TreeNode(2);


#endif

	//int Depth = maxDepth(root);
	//bool x = isValidBST(root);
	bool x = isSymmetric(root);

	//tempRoot = mirrorTree(root);

	return 0;
}

#ifdef BOOK
//钢条切割-动态规划 算法导论chp15-1 //未完成
int bottom2up_Cut_Rod(int* p, int n) {  //注意 此方法很危险，没有考虑内存溢出
	int* r = new int[n];
	r[0] = 0;  //最优解序列

	for (int j = 0; j < n; j++) {
		int q(0x80000000);
		for (int i = 0; i < j; i++) {
			q = MAX(q, p[i] + r[j - i]);
		}
		r[j] = q;
	}

	return r[n-1];
}

void rotate(std::vector<int>& nums, int k) {
	if (k == 1) {
		int temp = nums[nums.size() - 1];
		for (int i = nums.size() - 1.; i > 0; i--) {
			nums[i] = nums[i - 1];
		}
		nums[0] = temp;
	}
	else {
		int temp;
		size_t s = nums.size();
		size_t posR(k), posL(0);
		for (; posR < s; posR++) {
			posL = posL % k;
			temp = nums[posL];
			nums[posL] = nums[posR];
			nums[posR] = temp;
			posL++;
		}
		int newK = k - (s%k);
	}

	return;
}

#endif

#ifdef USED
int maxProfit(std::vector<int>& prices) {
	auto iter(prices.begin());
	decltype(iter) endF = prices.end() - 1;
	int sum = 0;
	for (; iter < endF; iter++) {
		if (iter[1] > *iter) {
			sum = sum + iter[1] - *iter;
		}
	}
	return sum;
}

void trueRO(std::vector<int>::iterator& iterB, const std::vector<int>::iterator& iterE,int k) {
	size_t nSize = iterE - iterB;	
	if (k%nSize==0) {
		return;
	}
	else if (k == 1) {
		//size_t nSize = iterE - iterB;
		for (int j = 0; j < k; j++) {
			int temp = iterB[nSize - 1];
			for (int i = nSize - 1.; i > 0; i--) {
				iterB[i] = iterB[i - 1];
			}
			iterB[0] = temp;
		}	
		return;
	}
	else {
		int temp;
		k = k % nSize;
		size_t posR(k), posL(0);
		for (; posR < nSize; posR++) {
			posL = posL % k;
			temp = iterB[posL];
			iterB[posL] = iterB[posR];
			iterB[posR] = temp;
			posL++;
		}
		int newK = k - (nSize % k);
		auto newiterE = iterB + k;
		trueRO(iterB, newiterE, newK);
	}
}

void rotate(std::vector<int>& nums, int k) {
	auto iterB = nums.begin();
	auto iterE = nums.end();
	trueRO(iterB, iterE, k);
}

bool containsDuplicate(std::vector<int>& nums) {
	std::set<int> numberCount;
	for (auto number : nums) {
		//返回类型是迭代器+一个真假指示，即是否已存在值
		if (!numberCount.insert(number).second) {
			return true;
		}
	}
	return false;
}

int singleNumber(std::vector<int>& nums) { //注意最快的方法是逐个异或（按位） 相同为0不同为自身 这确实想不到
	size_t N = nums.size();
	int sum1(0), sum2(0);
	int diff[4] = { 0 };
	for (int i = 0; i < N; i++) {
		if (i < N / 2 + 1) {
			sum1 += nums[i];
		}
		else {
			sum2 += nums[i];
		}
		diff[0] = sum1 - sum2;
	}
	return 0;
}

std::vector<int> plusOne(std::vector<int>& digits) {
	auto iter = digits.end()-1;
	(*iter)++;
	for (; iter > digits.begin(); iter--) {
		if (*iter == 10)
		{
			*iter = 0;
			(*(iter - 1))++;
		}
		else {
			break;
		}
	}

	if (digits[0] == 10) {

		digits[0] = 0;
		digits.insert(digits.begin(), 1);
	}

	return digits;
}

void moveZeroes(std::vector<int>& nums) {
	size_t A(0), B(0);
	size_t sLength(nums.size());

	for (; A < sLength; A++) {
		if (nums[A] == 0) {
			B = A + 1;
			if (B == sLength) { break; }
			while (nums[B] == 0) {
				if (B == sLength - 1) { break; };
				B++;
			}		
			nums[A] = nums[B];
			nums[B] = 0;
			if (B == sLength-1) { break; }
		}
	}
}

bool isValid9(const std::vector<char>& group9) {
	bool flag[9] = { 1,1,1,1,1,1,1,1,1 };
	for (int i = 0; i < 9; i++) {
		if (group9[i] == '.') { continue; }
		else if (flag[group9[i] - '1']) {
			flag[group9[i] - '1'] = false;
		}
		else {
			return false;
		}
	}
	return true;
}

bool isValidSudoku(std::vector<std::vector<char>>& board) {
	for (int i = 0; i < 9; i++) {

		if (!isValid9(board[i])) { return false; };
		if (!isValid9(std::vector<char>{
			board[0][i], board[1][i], board[2][i],
			board[3][i], board[4][i], board[5][i],
			board[6][i], board[7][i], board[8][i] }))
		{
			//return false;
		}
	}
		
	std::vector<std::vector<char>> blocks(9);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i < 3 && j < 3) {
				blocks[0].push_back(board[i][j]);
			}
			else if (i < 3 && 2 < j && j < 6) {
				blocks[1].push_back(board[i][j]);
			}
			else if (i < 3 && 5 < j) {
				blocks[2].push_back(board[i][j]);
			}
			else if (2 < i && i < 6 && j < 3) {
				blocks[3].push_back(board[i][j]);
			}
			else if (2 < i && i < 6 && 2 < j && j < 6) {
				blocks[4].push_back(board[i][j]);
			}
			else if (2 < i && i < 6 && 5 < j) {
				blocks[5].push_back(board[i][j]);
			}
			else if (5 < i && j < 3) {
				blocks[6].push_back(board[i][j]);
			}
			else if (5 < i && 2 < j && j < 6) {
				blocks[7].push_back(board[i][j]);
			}
			else {
				blocks[8].push_back(board[i][j]);
			}
		}

	}

	for (int i = 0; i < 9; i++) {
		if(!isValid9(blocks[i])) { return false; };
	}

	return true;
}

void rotate(std::vector<std::vector<int>>& matrix) {
	size_t n(matrix.size());
	std::pair<int, int> cord(0,0);
	int temp(0);

	for (int r(0); r < ((n + 1) / 2);r++) {
		for (int c(0); c < (n / 2); c++) {
			ROW = r;
			COL = c;
			temp = matrix[ROW][COL];
			for (int k(0); k < 3; k++) {
				matrix[ROW][COL] = matrix[n - 1 - COL][ROW];
				int a = n - 1 - COL;
				int b = ROW;
				cord.first = a;
				cord.second = b;
			}
			matrix[ROW][COL] = temp;
		}

	}
}


void reverseString(std::vector<char>& s) {
	char temp;
	size_t n = s.size();
	for (size_t index(0); index < n / 2; index++) {
		temp = s[index];
		s[index] = s[n - index - 1];
		s[n - index - 1] = temp;
	}
}

int firstUniqChar(std::string s) {
	std::map<char, int> charCount;
	for (int x = 0; x < s.size(); x++) {
		charCount[s[x]]++;
	}
	for (int i = 0; i < s.size(); i++) {
		if (charCount[s[i]] == 1) {
			return i;
		}
	}
}

bool isAnagram(std::string s, std::string t) {
	if (s.size() != t.size()) { return false; }
	size_t sSize = s.size();
	int charCountS[26];
	int charCountT[26];
	for (int i(0); i < 26; i++) {
		charCountS[i] = 0;
		charCountT[i] = 0;
	}
	for (size_t i(0); i < sSize; i++) {
		charCountS[s[i] - 'a']++;
		charCountT[t[i] - 'a']++;
	}
	for (int i(0); i < 26; i++) {
		if (charCountS[i] != charCountT[i])
		{
			return false;
		}
	}
	return true;
}

bool isPalindrome(std::string s) {
	if (s.size() == 0) { return true; }
	for (char& x : s) {
		if (x > 0x40 && x < 0x5B) {
			x = x - 0x41 + 0x61;
		}
	}
	size_t indexS(0);
	size_t indexE(s.size() - 1);
	while (indexS != indexE) {
		while (!((s[indexS] > 0x2F && s[indexS] < 0x3A) ||
			(s[indexS] > 0x60 && s[indexS] < 0x7B)) && indexS < indexE) {
			indexS++;
		};
		while (!((s[indexE] > 0x2F && s[indexE] < 0x3A) ||
			(s[indexE] > 0x60 && s[indexE] < 0x7B)) && indexS < indexE) {
			indexE--;
		};
		if (s[indexE] != s[indexS]) {
			return false;
		}

		if (indexE == indexS || indexE == indexS + 1) {
			break;
		}

		indexE--;
		indexS++;

	}
	return true;
}

int myAtoi(std::string s) {  //妈的智障
	int idx = 0;
	int flag = 1;
	bool flagChanged = false;
	int res = 0;

	int limitF(0x7FFFFFFF / 10);  //正数限制
	int limitN(0x80000000 / 10);  //复数限制

	if (s[0] != ' ' && (s[0] < '0' || s[0]>'9')) {
		if (s[0] != '-' && s[0] != '+') {
			return 0;
		}
	}

	for (int idx = 0; idx < s.size(); idx++) {
		if (s[idx] == ' ') {
			if (flagChanged) { break; }
		}
		else if (s[idx] == '+') {
			if (flagChanged) { break; }
			flag = 1;
			flagChanged = true;
		}
		else if (s[idx] == '-') {
			if (flagChanged) { break; }
			flag = -1;
			flagChanged = true;
		}
		else if (s[idx]<'0' || s[idx]>'9') {
			break;
			//continue;
		}
		else {
			if (flag == 1) {
				if (res > limitF || (res == limitF && (s[idx] - '0') >= 7)) {
					return 0x7FFFFFFF;
				}
			}
			if (flag == -1) {
				if (res > limitF || (res == limitF && (s[idx] - '0') >= 8)) {
					return 0x80000000;
				}
			}
			flagChanged = true;
			res = res * 10 + (int)(s[idx] - '0');
		}
	}

	return res * flag;

}

int strStr(string haystack, string needle) {
	if (needle.size() == 0) { return 0; }
	if (haystack.size() < needle.size()) { return -1; }
	int res = -1;
	for (int idh = 0; idh <= haystack.size() - needle.size(); idh++) {
		if (haystack[idh] == needle[0]) {
			for (int idn = 0; idn < needle.size(); idn++) {
				if (haystack[idh + idn] != needle[idn]) {
					res = -1;
					break;
				}
				else {
					res = idh;
				}
			}
			if (res == idh) {
				break;
			}

		}
	}
	return res;
}
#endif

#ifdef CHAINLIST

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

	//特殊情况A 如果存在空链表
	if (l2 == nullptr) {
		return l1;
	}
	else if(l1 == nullptr) {
		return l2;
	} 

	ListNode *Dst = l1->val > l2->val ? l2 : l1;  //头大的往头小的复制 避免从最前面插
	ListNode *Src = l1->val > l2->val ? l1 : l2;
	ListNode *resHead = Dst;                      //用于返回的链表头

	//特殊情况 某列只有一个元素时
	if (l1->next == nullptr || l2->next == nullptr) {
		Dst = l1->next == nullptr ? l2 : l1;
		Src = l1->next == nullptr ? l1 : l2;

		resHead = Dst;

		if (Src->val < Dst->val) {  //若小于Dst的所有值
			Src->next = Dst;
			return Src;
		}

		//否则寻找合适的位置插入
		while ( Dst->next != nullptr && Src->val >= Dst->next->val ) {
			Dst = Dst->next;
		}

		Src->next = Dst->next;
		Dst->next = Src;

		return resHead;
	}

	ListNode *start(nullptr), *end(nullptr);  //插入的头尾标志 src
	ListNode *insertPos(nullptr);             //可以插入的位置标记（在其后插入）dst

	while (true) {  //此循环需要重写
		start = Src;
		end = Src;
		insertPos = Dst;

		//DST中寻找可插入的位置
		while (true) {
			if ((insertPos->next==nullptr &&insertPos->val <= start->val) || insertPos->next->val>start->val) { break; }
			else { insertPos = insertPos->next; }
		}
		//SRC中寻找可插入的片段
		if (insertPos->next == nullptr) { //如果插入标记在DST队尾 则直接将后面的全部插入 即END也到队尾
			while (end->next != nullptr)
			{
				end = end->next;
			}
		}
		else {
			while (true) {
				if (end->next == nullptr || insertPos->next->val < end->next->val) { 
					break; 
				}
				else { 
					end = end->next; 
				}
			}
		}

		//插入动作
		Src = end->next;  //保留下一个起始坐标点
		Dst = insertPos->next; //保留下一个插入标记
		//更改next指针
		end->next = insertPos->next;	
		insertPos->next = start;

		if (Src == nullptr) { break; }
	}

	return resHead;
}

bool isPalindrome(ListNode* head) {
	if (head == nullptr) { return false; }
	ListNode* ptr = head;
	ListNode* middle = head;
	int res=0;
	int number(0);
	//计数循环 
	while (ptr != nullptr) {
		ptr = ptr->next;
		number++;
	}
	int half = (number + 1) / 2;
	for (int i = 0; i < half; i++) {
		middle = middle->next;
	}

	//特殊情况
	if (number == 1) { return true; }
	else if(number / 2 == 1) {
		if (middle->val == head->val) { return true; }
		else { return false; }
	}

	//反转后半部分链表
	ListNode* temp = middle->next;
	ListNode* head2 = middle;
	while (temp->next != nullptr) {
		ListNode* buffer = temp->next;
		temp->next = middle;
		middle = temp;
		temp = buffer;
	}
	temp->next = middle;	
	head2->next = nullptr;
	head2 = temp;

	ptr = head;
	for (int i = 0; i < number/2; i++) {
		if (ptr->val != head2->val) {
			return false;
		}
		ptr = ptr->next;
		head2 = head2->next;
	}

	return true;
}

#endif // CHAINLIST

#ifdef BINARYTREE
//树相关的代码
//1
void findLeaf(TreeNode* root) {  //这事实上是一个遍历代码 而且是后根遍历？
	if (root->left == nullptr && root->right == nullptr) {
		printf("leafReached,%d\n",root->val);
		return;
	}
	else {
		if (root->left != nullptr) {
			findLeaf(root->left);
		}
		if (root->right !=nullptr){
			findLeaf(root->right);
		}
		printf("nodeReached,%d\n", root->val);
	}
}

int maxDepth(TreeNode* root) {
	if (root == nullptr) { return 0; }
	int leftD(0), rightD(0);
	int depth;
	if (root->left == nullptr && root->right == nullptr) {
		printf("leafReached,%d\n", root->val);
		return 1;
	}
	else
	{
		if (root->right != nullptr) {
			rightD = maxDepth(root->right);
		}
		if (root->left != nullptr) {
			leftD = maxDepth(root->left);
		}
		depth = rightD > leftD ? rightD : leftD;
		depth += 1;
		return depth;
	}
}
//2
void Mid_through(TreeNode* root, vector<int>& vals) {
	if (root->left == nullptr && root->right == nullptr) {
		vals.push_back(root->val);
		return;
	}
	else {
		if (root->left != nullptr) {
			Mid_through(root->left, vals);
		}
		vals.push_back(root->val);
		if (root->right != nullptr) {
			Mid_through(root->right, vals);
		}
	}
}

bool isValidBST(TreeNode* root) {  //深度优先搜索验证 树题2 深度优先搜索的中序遍历结果是有序数组

	if (root == nullptr) { return 0; }

	vector<int> vals;
	Mid_through(root, vals);

	for (int i = 0; i < vals.size()-1; i++) {
		if (vals[i] >= vals[i + 1]) {
			return false;
		}
	}
	return true;
}

//3对称二叉树
void forwardThrough(TreeNode* root, vector<int>& vals) {
	if (root != nullptr) {
		vals.push_back(root->val);
		forwardThrough(root->left, vals);
		forwardThrough(root->right, vals);
	}
}

bool isLeaf(TreeNode* root) {
	if (root == nullptr) { return true; }
	if (root->left == nullptr && root->right == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

TreeNode* mirrorTree(TreeNode* root) {
	if (root != nullptr) {
		if (!isLeaf(root) && isLeaf(root->left) && isLeaf(root->right)) {
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
			return root;
		}
		else {
			TreeNode *newR, *newL;
			newR = mirrorTree(root->left);
			newL = mirrorTree(root->right);
			root->left = newL;
			root->right = newR;
			return root;
		}
	}
	else {
		return root;
	}
}

bool isSymmetric(TreeNode* root) {
	vector<int> valsA,valsC;
	vector<int> valsB,valsD;
	forwardThrough(root,valsA);
	Mid_through(root, valsC);
	TreeNode* mirrorR = mirrorTree(root);
	forwardThrough(root, valsB);
	Mid_through(root, valsD);

	for (int i = 0; i < valsA.size(); i++) {
		if (valsA[i] != valsB[i] || valsB[i] != valsD[i]) {
			return false;
		}
	}

	return true;
}

//二叉树层序遍历
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<TreeNode*> visitList;
	//visitList.push_back(root);
	stack<TreeNode*,vector<TreeNode*>> visitStack(visitList); //整一个栈
	while (true) {

	}
}

#endif // 
