#include<iostream>

int main()
{

	int l, N;

	std::cin >> N;

	while (N > 0)
	{
		int zongshijian = 0;

		int n = 0;
		int s = 0;


		for (; N > 0; N--)
		{
			std::cin >> l;
			if (n < l)
				s = (l - n) * 6;
			else
			{
				s = (n - l) * 4;

			}
			n = l;
			zongshijian = zongshijian + s + 5;

		}
		std::cout << zongshijian << std::endl;
		std::cin >> N;
	}



	return 0;


}
