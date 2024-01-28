#pragma warning(disable: 4996)
#include <iostream>
#include <stack>

int main() {
	using namespace std;
	stack<long long int> Building; //  long long int로 해주어야 함!
	long long int num, floor, i, j, count =0, countsize = 0;
	scanf("%lld", &num);

	/*long long int* arr = new long long int[800001];
	for (i = 0; i < num; i++) {
		scanf("%d", &floor);
		arr[i] = floor;
	}
	for (i = 0; i < num; i++) {
		for (j = i + 1; j < num; j++) {
			if (arr[i] > arr[j]) {
				count++;
			}
			else {
				break;
			}
		}
	}
	cout << count;*/

	for (i = 0; i < num; i++) {
		scanf("%d", &floor);
		if (Building.empty()) {  // 처음 시작 시 비어있으므로 그냥 넣어준다,
			Building.push(floor);
		}
		else {
			if (Building.top() > floor) {  // 스택의 top이 새로운 층보다 클 경우
				Building.push(floor);     //  새로운 층을 넣어주고  countsize를 늘려준다.  
				countsize++;    
				count += countsize;   //카운트에 합산한다.
			}
			else {

				while (true) {  // 스택의 top이 새로운 층보다 작을 경우
					Building.pop();   
					if (Building.empty())      //비어있을 경우 멈추어야지 오류가 안남
						break;
					if (Building.top() > floor) {   //스택의 top이 새로운 층보다 클 경우 멈춘다.
						break;
					}
				}
				countsize = Building.size();  //countsize를 스택size로 초기화해준다.
				Building.push(floor);    //새로운 층을 넣어주고 카운트에 합산한다.
				count += countsize;

			}
		}

	}
	cout << count;

}