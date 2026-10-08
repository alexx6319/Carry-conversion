#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

// 字元轉成對應的數值 (0~15)，非法字元回傳 -1
int digitValue(char c)
{
	if (c >= '0' && c <= '9')
		return c - '0';
	if (c >= 'a' && c <= 'f')
		return c - 'a' + 10;
	if (c >= 'A' && c <= 'F')
		return c - 'A' + 10;
	return -1;
}

// 去掉字串前後的空白
string trim(const string& s)
{
	size_t begin = s.find_first_not_of(" \t\r\n");
	if (begin == string::npos)
		return "";
	size_t end = s.find_last_not_of(" \t\r\n");
	return s.substr(begin, end - begin + 1);
}

// 依指定進位解析字串，格式錯誤或超出範圍回傳 false
bool parseNumber(const string& s, int base, unsigned long long& out)
{
	size_t start = 0;
	if (base == 16 && s.size() > 2 && s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
		start = 2;  // 允許 0x 開頭
	if (start >= s.size())
		return false;

	const unsigned long long maxValue = numeric_limits<unsigned long long>::max();
	unsigned long long value = 0;
	for (size_t i = start; i < s.size(); i++)
	{
		int d = digitValue(s[i]);
		if (d < 0 || d >= base)
			return false;
		if (value > (maxValue - d) / base)  // 溢位
			return false;
		value = value * base + d;
	}
	out = value;
	return true;
}

// 回傳二進位各位元，bits[i] 為第 i 位
vector<int> convertToBinary(unsigned long long num)
{
	vector<int> bits;
	do
	{
		bits.push_back(static_cast<int>(num % 2));
		num /= 2;
	} while (num > 0);
	return bits;
}

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);  // 原始檔為 UTF-8，讓主控台正確顯示中文
#endif

	const int bases[] = { 16, 10, 8, 2 };
	const char* baseNames[] = { "十六進位", "十進位", "八進位", "二進位" };

	while (true)
	{
		cout << "要轉換的進位(1)16進位 (2)10進位 (3)8進位 (4)2進位 (5)結束 : ";
		string line;
		if (!getline(cin, line))  // EOF
			break;

		line = trim(line);
		if (line == "5")
			break;
		if (line.size() != 1 || line[0] < '1' || line[0] > '4')
		{
			cout << "請輸入 1~5!\n\n";
			continue;
		}
		int select = line[0] - '0';
		int base = bases[select - 1];

		unsigned long long number = 0;
		bool ok = false;
		while (true)
		{
			cout << "輸入要轉換的" << baseNames[select - 1] << "數字:";
			if (!getline(cin, line))  // EOF
				break;
			if (parseNumber(trim(line), base, number))
			{
				ok = true;
				break;
			}
			cout << "格式錯誤!請再輸入一次!! \n";
		}
		if (!ok)
			break;

		cout << "\n";
		cout << "二進位:\n";
		vector<int> bits = convertToBinary(number);
		for (size_t j = bits.size(); j > 0; j--)
			cout << (j - 1) << " ";
		cout << "\n";
		for (size_t j = bits.size(); j > 0; j--)
			cout << bits[j - 1] << ((j - 1) <= 9 ? " " : "  ");
		cout << "\n";

		cout << "\n八進位:" << oct << number << "\n";
		cout << "\n十進位:" << dec << number << "\n";
		cout << "\n十六進位:" << hex << number << dec << "\n\n";
	}

#ifdef _WIN32
	system("pause");
#endif
	return 0;
}
