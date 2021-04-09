#include <stdio.h>
#include <vector>
#include <map>
#include <set>

//初级算法在此练习

#define MAX(a,b) a>b?a:b
int maxProfit(std::vector<int>& prices);
void rotate(std::vector<int>& nums, int k);
bool containsDuplicate(std::vector<int>& nums);
int singleNumber(std::vector<int>& nums);
std::vector<int> plusOne(std::vector<int>& digits);
void moveZeroes(std::vector<int>& nums);

int main() {

	std::vector<int> prices = { 1,0 };
	//return maxProfit(prices);
	//rotate(prices, 3);
	//func(0);
	//plusOne(prices);
	moveZeroes(prices);
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
	auto iterR = nums.begin();
	for (; iterR < nums.end(); iterR++) {
		if (*iterR == 0) {
			auto iterB = iterR + 1;
			for (; *iterB == 0; iterB++) {}
			*iterR = *iterB;
		}
	}
}