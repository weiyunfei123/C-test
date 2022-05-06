#include <iostream>
using namespace std;

//案例描述：
//* 利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
//* 排序规则从大到小，排序算法为选择排序
//* 分别利用char数组和int数组进行测试



template<typename T>
void mySwap(T &a, T&b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i)
		{
			mySwap(arr[max], arr[i]);
		}

	}
}

template<typename T>
void myPrint(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}

//对int数组排序的测试
void test01()
{
	int intArr[] = { 1,2,3,4,5,6,7,8,9 };
	int num = sizeof(intArr) / sizeof(intArr[0]);
	mySort(intArr, num);
	myPrint(intArr, num);

}

//对char数组排序的测试
void test02()
{
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(charArr[0]);
	mySort(charArr, num);
	myPrint(charArr, num);


}

int main()
{
	test01();
	test02();

	system("pause");
	return 0;

}