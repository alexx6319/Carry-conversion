#include<iostream>
#include <iomanip>
#include<vector>
#include <string>
using namespace std;

vector<long long> binarynum;


void convertobinary(long long num);

int main()
{
	int carry, select;
	long long number = 0;
	string inputbinary;

	while (1)
	{


		cout << "要轉換的進位(1)16進位 (2)10進位 (3)8進位 (4)2進位 (5)結束 : ";
		cin >> select;
		if (select == 1)
			carry = 16;
		else if (select == 2)
			carry = 10;
		else if (select == 3)
			carry = 8;
		else if (select == 4)
		{
		}
		else
			break;

		if (select < 4)
		{

			while (cout << "輸入要轉換的數字:", !(cin >> setbase(carry) >> number))
			{
				//錯誤:輸入非數字 
				cout << "格式錯誤!請再輸入一次!! \n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // 清空緩衝區. 
			}

		}
		else
		{
			cout << "輸入二進位:";
			cin >> inputbinary;
			number = 0;
			for (unsigned int i = inputbinary.size(), j = 0; i > 0; i--)
			{
				if ((inputbinary[i - 1] - '0') < 2) //字元轉換成數字 =>可以順便判斷使用者輸入的到底是不是數字
				{
					number += (inputbinary[i - 1] - '0')*pow(2, j);
					j++;
				}

			}

			inputbinary.clear();

		}
		cout << "\n";
		cout << "二進位:\n";
		convertobinary(number);
		for (int j = binarynum.size(); j > 0; j--)
		{
			cout << dec << (j - 1) << " ";
		}
		cout << "\n";
		for (int j = binarynum.size(); j > 0; j--)
		{
			if ((j - 1) <= 9)
				cout << dec << binarynum[j - 1] << " ";
			else
				cout << dec << binarynum[j - 1] << "  ";

		}

		if (binarynum.size()>0) //清除vector內容
			binarynum.clear();

		cout << "\n";
		cout << endl << "八進位:" << oct << number;
		cout << "\n";
		cout << endl << "十進位:" << dec << number;
		cout << "\n";
		cout << endl << "十六進位:" << hex << number << "\n\n";

	}

	system("pause");
}

void convertobinary(long long num)
{

	int Remainder = 0;
	if (num < 2)
	{
		binarynum.push_back(num);
		//cout  << num << ", ";
		return;
	}
	Remainder = num % 2;
	num /= 2;
	binarynum.push_back(Remainder);
	convertobinary(num);	

}