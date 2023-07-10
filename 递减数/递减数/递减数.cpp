#include<iostream>
using namespace std;
//判断一个数是否为递减数的函数（返回true或false）
bool diJianShu(int num) {
	//判断这个数是否为四位自然数
	if (num < 1000) {
		return false;
	}
	else if (num > 9999) {
		return false;
	}
	//判断各个数位上的数字是否互不相等且均不为零
	else {
		//获取各个数位上的数字
		int a = num / 1000;
		int b = num / 100 - 10 * a;
		int c = num / 10 - 100 * a - 10 * b;
		int d = num - 1000 * a - 100 * b - 10 * c;
		//判断各个数位上的数字是否均不为零
		if (a == 0 || b == 0 || c == 0 || d == 0) {
			return false;
		}
		//各个数位上的数字是否互不相等
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
			//判断是否满足递减数的条件
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
	cout << "如果一个四位自然数(abcd)的各数位上的数字互不相等且均不为0，满足(ab)-(bc)=(cd)，那么称这个四位数为“递减数”，例如：四位数4129，41-12=29，∴4129 是“递减数”.又如：四位数5324，53-32=21≠24，所以5324 不是“递减数”." << endl;
	cout << "1.判断一个数是否为递减数;" << endl;
	cout << "2.生成所有的递减数;" << endl;
	cout << "3.生成满足前三个数字组成的三位数(abc)与后三个数字组成的三位数(bcd)的和能被9整除的递减数." << endl;
	cout << "请输入你想要进行的操作的序号：";
	int a, num;
	//a为用户想要进行的操作的序号，num为用户想要判断时输入的数字
	while (1) {
		//输入想要进行的操作的序号
		cin >> a;
		//根据序号的不同，选择不同的代码执行
		if (a == 1) {
			cout << "请输入想要判断的数：";
			//接收用户输入
			cin >> num;
			if (diJianShu(num)) {
				cout << num << "是递减数" << endl;
			}
			else {
				cout << num << "不是递减数" << endl;
			}
			cout << "请再次输入想要进行操作的序号：";
		}
		else if (a == 2) {
			for (int i = 1000; i < 10000; i++) {
				if (diJianShu(i)) {
					cout << i << endl;
				}
			}
			cout << "请再次输入想要进行操作的序号：";
		}
		else if (a == 3) {
			for (int i = 1000; i < 10000; i++) {
				if (diJianShu(i)) {
					//获取各个数位上的数字
					int a = i / 1000;
					int b = i / 100 - 10 * a;
					int c = i / 10 - 100 * a - 10 * b;
					int d = i - 1000 * a - 100 * b - 10 * c;
					//根据题目的条件进行判断
					if ((100 * a + 10 * b + c + 100 * b + 10 * c + d) % 9 == 0) {
						cout << i << endl;
					}
				}
			}
			cout << "请再次输入想要进行操作的序号：";
		}
		else {
			cout << "非法输入，请重新输入：";
		}
	}
	system("pause");
	return 0;
}