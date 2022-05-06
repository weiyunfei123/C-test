#include <iostream>
using namespace std;

//����������
//* ���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
//* �������Ӵ�С�������㷨Ϊѡ������
//* �ֱ�����char�����int������в���



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

//��int��������Ĳ���
void test01()
{
	int intArr[] = { 1,2,3,4,5,6,7,8,9 };
	int num = sizeof(intArr) / sizeof(intArr[0]);
	mySort(intArr, num);
	myPrint(intArr, num);

}

//��char��������Ĳ���
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