/*
* 세 막대
*
<문제>
영선이는 길이가 a, b, c인 세 막대를 가지고 있고, 각 막대의 길이를 마음대로 줄일 수 있다.

영선이는 세 막대를 이용해서 아래 조건을 만족하는 삼각형을 만들려고 한다.

각 막대의 길이는 양의 정수이다
세 막대를 이용해서 넓이가 양수인 삼각형을 만들 수 있어야 한다.
삼각형의 둘레를 최대로 해야 한다.
a, b, c가 주어졌을 때, 만들 수 있는 가장 큰 둘레를 구하는 프로그램을 작성하시오.

<입력>
첫째 줄에 a, b, c (1 ≤ a, b, c ≤ 100)가 주어진다.

<출력>
첫째 줄에 만들 수 있는 가장 큰 삼각형의 둘레를 출력한다.

<예제 입력 1>
1 2 3
<예제 출력 1>
5
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	int m = max({ a, b, c }); // 가장 큰 변의 길이

	int sum = a + b + c - m; // 작은 두변의 길이 합

	if (m >= sum)
	{
		cout << sum + (sum - 1);
	}
	else
	{
		cout << m + sum;
	}
	return 0;
}
