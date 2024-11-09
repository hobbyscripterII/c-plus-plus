#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace std;

int random(int min, int max) {
	static random_device rd;
	static mt19937 mt(rd());
	uniform_int_distribution<> dis(min, max);

	return dis(mt);
}

class IntSave {
private:
	int* arr;						  // 동적 배열을 저장하는 포인터
	int size;						  // main에서 객체 생성(초기화 시) 저장되는 배열의 최대 개수
	int idx			 = random(1, 10); // 배열 index의 값
	int removeIdxCnt = 0;			  // 삭제해야 할 index 개수
public:
	// IntSave 클래스의 생성자
	IntSave(int size) {
		this->size = size;
		arr = new int[size]; // 동적 배열 할당
	}

	// 배열 생성을 담당하는 메소드
	void addArr() {
		// 디버깅용
		cout << "=====================" << endl;
		cout << "arr 배열 사이즈  : " << size << endl;
		cout << "for문의 index    : " << idx << endl;
		cout << "=====================" << endl;

		for (int i = 0; i < idx; i++) {
			// 생성자에서 지정했던 배열의 최대 개수와 일치할 경우 공간을 늘린다.
			if (i == size) {
				arrExpand();
			}

			// 1 ~ 100까지의 랜덤 값이 할당된다.
			arr[i] = random(1, 100);

			// 디버깅용
			cout << "arr[i]           : " << arr[i] << endl;
		}
	}

	// 호출 시점의 배열 값을 확인할 수 있는 메소드
	void printArr() {
		cout << "arr [ ";

		for (int i = 0; i < idx; i++) {
			cout << arr[i] << " ";
		}

		cout << "]" << endl;
	}

	// 공간 확장 시 호출하는 메소드
	void arrExpand() {
		int newSize = size * 2;			// 공간 2배 확장용
		int* newArr = new int[newSize];	// temp용 배열
		
		// 백업
		for (int i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}

		delete[] arr;		// 기존에 있던 배열 메모리 해제
		int temp = size;
		arr		 = newArr;  // temp용 배열에 있던 정수를 원래 있던 배열로 옮김
		size	 = newSize; // 위 맥락과 같음

		cout << "*********************" << endl;
		cout << "배열이 꽉 찼으므로 공간을 2배로 확장합니다." << endl;
		cout << " " << endl;
		cout << "이전 배열 사이즈 : " << temp << endl;
		cout << "현재 배열 사이즈 : " << size << endl;
		cout << "*********************" << endl;
	}

	int minNum() {
		if (size == 0) return -1;
		return *min_element(arr, arr + idx);
	}

	int maxNum() {
		if (size == 0) return -1;
		return *max_element(arr, arr + idx);
	}

	int oldNum() {
		if (idx == 0) return -1;
		return arr[0];
	}

	int newNum() {
		if (idx == 0) return -1;
		return arr[idx - 1];
	}

	int avgNum() {
		int result = 0;

		for (int i = 0; i < idx; i++) {
			result += arr[i];		// 총 계
		}
		result = (result / idx);	// 총 계 = 총 계 / 배열 index 길이
		return result;				// 평균 값
	}

	void removeArrNum(int num) {
		for (int i = 0; i < idx; i++) {
			cout << "arr[i] = " << arr[i] << " num = " << num << endl;

			if (arr[i] == num) {
				arr[i] = 0;			// 맥락 상의 remove
				removeIdxCnt++;
				break;
			}
		}
	}

	void numRemoveTask() {
		cout << "=====================" << endl;
		int minNum = this->minNum();
		int maxNum = this->maxNum();
		int oldNum = this->oldNum();
		int newNum = this->newNum();
		int avgNum = this->avgNum();

		cout << "가장 작은 숫자          : " << minNum << endl;
		cout << "가장 큰 숫자            : " << maxNum << endl;
		cout << "가장 먼저 들어온 숫자   : " << oldNum << endl;
		cout << "가장 나중에 들어온 숫자 : " << newNum << endl;
		cout << "배열 정수 값의 평균 값  : " << avgNum << endl;
		cout << "=====================" << endl;
		cout << "조건에 맞는 인덱스의 정수를 삭제합니다." << endl;
		cout << " " << endl;
		this->removeArrNum(minNum);
		this->removeArrNum(maxNum);
		this->removeArrNum(oldNum);
		this->removeArrNum(newNum);
		this->removeArrNum(avgNum);
		cout << "=====================" << endl;
	}
};

int main() {
	int size = random(1, 10);
	IntSave intSave(size);		// 객체 생성
	intSave.addArr();			// 배열 값 초기화
	intSave.numRemoveTask();	// 배열 값 삭제
	intSave.printArr();			// 배열 출력
}