#include<iostream>
using namespace std;
//�ж�һ�����Ƿ�Ϊ�ݼ����ĺ���������true��false��
bool diJianShu(int num) {
	//�ж�������Ƿ�Ϊ��λ��Ȼ��
	if (num < 1000) {
		return false;
	}
	else if (num > 9999) {
		return false;
	}
	//�жϸ�����λ�ϵ������Ƿ񻥲�����Ҿ���Ϊ��
	else {
		//��ȡ������λ�ϵ�����
		int a = num / 1000;
		int b = num / 100 - 10 * a;
		int c = num / 10 - 100 * a - 10 * b;
		int d = num - 1000 * a - 100 * b - 10 * c;
		//�жϸ�����λ�ϵ������Ƿ����Ϊ��
		if (a == 0 || b == 0 || c == 0 || d == 0) {
			return false;
		}
		//������λ�ϵ������Ƿ񻥲����
		else if (a == b || a == c || a == d) {
			return false;
		}
		else if (b == c || b == d) {
			return false;
		}
		else if (c == d) {
			return false;
		}
		else {
			//�ж��Ƿ�����ݼ���������
			if (10 * a + b - 10 * b - c == 10 * c + d) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
int main() {
	cout << "���һ����λ��Ȼ��(abcd)�ĸ���λ�ϵ����ֻ�������Ҿ���Ϊ0������(ab)-(bc)=(cd)����ô�������λ��Ϊ���ݼ����������磺��λ��4129��41-12=29����4129 �ǡ��ݼ�����.���磺��λ��5324��53-32=21��24������5324 ���ǡ��ݼ�����." << endl;
	cout << "1.�ж�һ�����Ƿ�Ϊ�ݼ���;" << endl;
	cout << "2.�������еĵݼ���;" << endl;
	cout << "3.��������ǰ����������ɵ���λ��(abc)�������������ɵ���λ��(bcd)�ĺ��ܱ�9�����ĵݼ���." << endl;
	cout << "����������Ҫ���еĲ�������ţ�";
	int a, num;
	//aΪ�û���Ҫ���еĲ�������ţ�numΪ�û���Ҫ�ж�ʱ���������
	while (1) {
		//������Ҫ���еĲ��������
		cin >> a;
		//������ŵĲ�ͬ��ѡ��ͬ�Ĵ���ִ��
		if (a == 1) {
			cout << "��������Ҫ�жϵ�����";
			//�����û�����
			cin >> num;
			if (diJianShu(num)) {
				cout << num << "�ǵݼ���" << endl;
			}
			else {
				cout << num << "���ǵݼ���" << endl;
			}
			cout << "���ٴ�������Ҫ���в�������ţ�";
		}
		else if (a == 2) {
			for (int i = 1000; i < 10000; i++) {
				if (diJianShu(i)) {
					cout << i << endl;
				}
			}
			cout << "���ٴ�������Ҫ���в�������ţ�";
		}
		else if (a == 3) {
			for (int i = 1000; i < 10000; i++) {
				if (diJianShu(i)) {
					//��ȡ������λ�ϵ�����
					int a = i / 1000;
					int b = i / 100 - 10 * a;
					int c = i / 10 - 100 * a - 10 * b;
					int d = i - 1000 * a - 100 * b - 10 * c;
					//������Ŀ�����������ж�
					if ((100 * a + 10 * b + c + 100 * b + 10 * c + d) % 9 == 0) {
						cout << i << endl;
					}
				}
			}
			cout << "���ٴ�������Ҫ���в�������ţ�";
		}
		else {
			cout << "�Ƿ����룬���������룺";
		}
	}
	system("pause");
	return 0;
}