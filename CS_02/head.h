#pragma once
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <stack>
#include <algorithm>
#include <complex>       //STL复数库

#ifdef USED
int maxProfit(std::vector<int>& prices);
void rotate(std::vector<int>& nums, int k);
bool containsDuplicate(std::vector<int>& nums);
int singleNumber(std::vector<int>& nums);
std::vector<int> plusOne(std::vector<int>& digits);
void moveZeroes(std::vector<int>& nums);
bool isValid9(const std::vector<char>& group9);
bool isValidSudoku(std::vector<std::vector<char>>& board);
void rotate(std::vector<std::vector<int>>& matrix);
void reverseString(std::vector<char>& s);
int firstUniqChar(std::string s);
bool isAnagram(std::string s, std::string t);
bool isPalindrome(std::string s);
int myAtoi(std::string s);
int strStr(string haystack, string needle);

#endif

using std::string;
using std::vector;
using std::map;
using std::stack;

#ifdef CHAINLIST
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

bool isPalindrome(ListNode* head); //判定是否回文
#endif

#ifdef BINARYTREE
//二叉树节点的基本定义
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//需要写的函数定义
int maxDepth(TreeNode* root);

bool isValidBST(TreeNode* root);

bool isSymmetric(TreeNode* root);

TreeNode* mirrorTree(TreeNode* root);

vector<vector<int>> levelOrder(TreeNode* root);

TreeNode* sortedArrayToBST(vector<int>& nums);
#endif

#ifdef SORTANDSEARCH
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);

#endif

#ifdef DYNAMICPROG
int climbStairs(int n);

int maxProfit(vector<int>& prices);

int maxSubArray(vector<int>& nums);

int rob(vector<int>& nums);
#endif

#ifdef DESIGN
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack():min(0x7FFFFFFF) { 
		topPtr = new ListNode();
		bottomPtr = topPtr;
	}

	void push(int val); 
	void pop();
	int top();
	int getMin();

private:
	int min;
	ListNode* topPtr;
	ListNode* bottomPtr;
};
#endif

#ifdef MATH

int countPrimes(int n);

int romanToInt(string s);

#endif

#ifdef OTHERS
int hammingWeight(uint32_t n);

vector<vector<int>> generate(int numRows);

bool isValid(string s);


#endif