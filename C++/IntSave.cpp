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
	int* arr;
	int size;
	int idx			 = random(7, 14);
	int removeIdxCnt = 0;
public:
	// IntSave 클래스의 생성자
	IntSave(int size) {
		this->size = size;
		arr		   = new int[size]; // 동적 배열 할당
	}

	~IntSave() {
		delete[] arr;
	}

	void addArr() {
		for (int i = 0; i < idx; i++) {
			// 생성자에서 지정했던 배열의 최대 개수와 일치할 경우 공간을 늘린다.
			if (i == size) {
				arrTask("확장");
			}

			// 1 ~ 100까지의 랜덤 값이 할당된다.
			arr[i] = random(1, 100);
		}
	}

	void printArr() {
		cout << "arr [ ";

		for (int i = 0; i < idx; i++) {
			cout << arr[i] << " ";
		}

		cout << "]" << endl;
	}

	// 공간 확장 시 호출하는 메소드
	//void arrExpand() {
	//	int newSize = size * 2;			// 공간 2배 확장용
	//	int* newArr = new int[newSize];	// temp용 배열
	//	
	//	// 백업
	//	for (int i = 0; i < size; i++) {
	//		newArr[i] = arr[i];
	//	}

	//	delete[] arr;		// 기존에 있던 배열 메모리 해제
	//	int temp = size;
	//	arr		 = newArr;  // temp용 배열에 있던 정수를 원래 있던 배열로 옮김
	//	size	 = newSize; // 위 맥락과 같음

	//	cout << "*********************" << endl;
	//	cout << "배열이 꽉 찼으므로 공간을 2배로 확장합니다." << endl;
	//	cout << " " << endl;
	//	cout << "이전 배열 사이즈 : " << temp << endl;
	//	cout << "현재 배열 사이즈 : " << size << endl;
	//	cout << "*********************" << endl;
	//}

	void arrTask(string fl) {
		int newSize = 0;

		if (fl == "확장") {
			newSize     = size * 2;
			int* newArr = new int[newSize];

			for (int i = 0; i < size; i++) {
				newArr[i] = arr[i];
			}

			delete[] arr;		// 기존에 있던 배열 메모리 해제
			size = newSize;		// 전역 변수 size에 바뀐 size로 업데이트
			arr  = newArr;		// temp용 배열에 있던 정수를 원래 있던 배열로 옮김
		}
		else {
			for (int i = 0; i < size; i++) {
				if (arr[i] > 0) {
					newSize++;
				}
			}

			int* newArr = new int[newSize]();
			int  newIdx = 0;

			for (int i = 0; i < size; i++) {
				if (arr[i] > 0) {
					newArr[newIdx++] = arr[i];
				}
			}

			delete[] arr;		// 기존에 있던 배열 메모리 해제
			size = newSize;		// 전역 변수 size에 바뀐 size로 업데이트
			arr  = newArr;		// temp용 배열에 있던 정수를 원래 있던 배열로 옮김
		}
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
			if (arr[i] == num) {
				cout << "삭제할 값 : " << arr[i] << " 인덱스 : " << i << endl;
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
		this->arrTask("축소");
		cout << "=====================" << endl;
	}
};

int main() {
	int size = random(7, 14);
	IntSave intSave(size);		// 객체 생성
	intSave.addArr();			// 배열 값 초기화
	intSave.printArr();			// 배열 출력
	intSave.numRemoveTask();	// 배열 값 삭제
	intSave.printArr();			// 배열 출력
}