#pragma warning(disable: 4996)
#include <iostream>
#include <stack>

int main() {
	using namespace std;
	stack<long long int> Building; //  long long int�� ���־�� ��!
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
		if (Building.empty()) {  // ó�� ���� �� ��������Ƿ� �׳� �־��ش�,
			Building.push(floor);
		}
		else {
			if (Building.top() > floor) {  // ������ top�� ���ο� ������ Ŭ ���
				Building.push(floor);     //  ���ο� ���� �־��ְ�  countsize�� �÷��ش�.  
				countsize++;    
				count += countsize;   //ī��Ʈ�� �ջ��Ѵ�.
			}
			else {

				while (true) {  // ������ top�� ���ο� ������ ���� ���
					Building.pop();   
					if (Building.empty())      //������� ��� ���߾���� ������ �ȳ�
						break;
					if (Building.top() > floor) {   //������ top�� ���ο� ������ Ŭ ��� �����.
						break;
					}
				}
				countsize = Building.size();  //countsize�� ����size�� �ʱ�ȭ���ش�.
				Building.push(floor);    //���ο� ���� �־��ְ� ī��Ʈ�� �ջ��Ѵ�.
				count += countsize;

			}
		}

	}
	cout << count;

}