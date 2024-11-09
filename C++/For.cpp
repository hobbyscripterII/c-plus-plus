#include <iostream>	// 입출력 클래스
#include <string>	// string 클래스(기본 타입이 아니기 때문에 제공 x 때문에 끌어써야 한다)

using namespace std;

int total = 0;

int ForTest(int idx) {
	for (int i = 0; i < idx; i++) {
		cout << "i     = " << i << endl;
		total += i;
		cout << "total = " << total << endl;
		cout << " " << endl;
	}

	return total;
}

//int main() {
//	int result = ForTest(10);
//	
//	cout << "ForTest의 결과 값은 " << result << "입니다." << endl;
//}