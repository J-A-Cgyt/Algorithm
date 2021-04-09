#include <stdio.h>
#include <math.h>
#include <map>
//��������zernike����ʽ��С����

int m, n;  //zernike����ʽ�ĵĲ��� ����n>m
double R_xishu, R_zhishu;
std::map<double, double> xiang;  //�ؼ���Ϊ�ѵ�ָ�� ֵΪϵ��

int jiecheng(const int &start) {  //�ݹ鲻����������ֵҲ����˵��ֵ���У� ����ȫ��0 �ĳ�ѭ�����ǿ��� ��Ȼ�Ƕ�ε��õ�ʱ���±�����Ϣ��ʡȥ��һ���� Ҳ���� �ƺ������������й�
	if (start == 1 || start == 0) {
		return 1; 
	}
	else {
		int x = 1;
		for (int k = start; k > 1; k--) {
			x = x * k;
		}
		return x;
		//printf("%d\n", start);
		//return start * jiecheng(start - 1);
	}
}

//����double�������ֽ׳˵�ʱ���ƺ������� �����Ǽ���ײ������ ��ʱ��һ�Ű� �����ͬ���������͵����˲�ͬ�Ľ�� �Ǿ�ֻ��˵�� �����������������д�Ĺ�
double test(const double &start) {
	if (start == 1 || start == 0) {
		return 1;
	}
	else {
		//printf("%d\n", start);
		return start * jiecheng(start - 1);
	}
}


int main() {

	n = 3, m = -1;

	if ((n - m) % 2 == 1) {
		R_xishu = 0;
		R_zhishu = 1;
	}
	else {
		int k = 0;
		for (; k <= ((n - m) / 2); k++) {
			R_zhishu = n - 2 * k;
			int fenmu, fenzi;
			fenzi = pow(-1, k) * jiecheng(n - k);
			int q[3];
			q[0] = jiecheng(k);
			q[1] = jiecheng((n + m) / 2 - k);
			q[2] = jiecheng((n - m) / 2 - k);
			fenmu = q[0] * q[1] * q[2];
			R_xishu = fenzi / fenmu;
			xiang[R_zhishu] = R_xishu;
		}
	}

	double s = 0.0;
	s = test(4.0);
	printf("%d\n", s);
	return 0;
}