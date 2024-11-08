#include <iostream>
using namespace std;

/*
- namespace : 변수 중복 방지
- main()    : 하나의 프로젝트에 하나만 생성 가능
*/

namespace NameSpace1 {
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
}

//int main() {
//	cout << "내가 만든 첫번째 C++ 프로그램" << endl;
//	cout << "----------------------------------------" << endl;
//	cout << "Namespace 출력" << endl;
//	cout << NameSpace1::a << endl;
//	cout << NameSpace1::b << endl;
//	cout << NameSpace1::c << endl;
//	cout << NameSpace1::d << endl;
//}