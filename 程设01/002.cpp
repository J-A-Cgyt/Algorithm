#include<iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;
	int max = a;
	int min = a;
	while (a%min || b%min || c%min)
		min--;
	while (max%a || max%b || max%c)
		max += a;
	std::cout << min << " " << max << std::endl;
	return 0;
}
