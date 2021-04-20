#include "head.h"

#define ARRSTR

#ifdef ARRSTR
vector<vector<int>> threeSum(vector<int>& nums);

void setZeroes(vector<vector<int>>& matrix);
#endif // ARRSTR


int main() {
#ifdef ARRSTR
	vector<int> nums = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,3,1} };
	//auto res = threeSum(nums);
	setZeroes(matrix);
#endif // ARRSTR

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

