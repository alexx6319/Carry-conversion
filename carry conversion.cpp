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


		cout << "�n�ഫ���i��(1)16�i�� (2)10�i�� (3)8�i�� (4)2�i�� (5)���� : ";
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

			while (cout << "��J�n�ഫ���Ʀr:", !(cin >> setbase(carry) >> number))
			{
				//���~:��J�D�Ʀr 
				cout << "�榡���~!�ЦA��J�@��!! \n";
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    // �M�Žw�İ�. 
			}

		}
		else
		{
			cout << "��J�G�i��:";
			cin >> inputbinary;
			number = 0;
			for (unsigned int i = inputbinary.size(), j = 0; i > 0; i--)
			{
				if ((inputbinary[i - 1] - '0') < 2) //�r���ഫ���Ʀr =>�i�H���K�P�_�ϥΪ̿�J���쩳�O���O�Ʀr
				{
					number += (inputbinary[i - 1] - '0')*pow(2, j);
					j++;
				}

			}

			inputbinary.clear();

		}
		cout << "\n";
		cout << "�G�i��:\n";
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

		if (binarynum.size()>0) //�M��vector���e
			binarynum.clear();

		cout << "\n";
		cout << endl << "�K�i��:" << oct << number;
		cout << "\n";
		cout << endl << "�Q�i��:" << dec << number;
		cout << "\n";
		cout << endl << "�Q���i��:" << hex << number << "\n\n";

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