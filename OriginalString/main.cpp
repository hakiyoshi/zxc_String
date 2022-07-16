#include <iostream>
#include "bace_string.h"

int main(void)
{
	zxc::string str("aaaaa");
	zxc::string str2("bbbbb");

	zxc::string str3 = str + 10;

	zxc::wstring wstr(L"aaaaa");
	zxc::wstring wstr2(L"bbbbb");

	auto wstr3 = wstr + 10;

	zxc::string erase("Hello World");
	auto erase1 = zxc::erase_if(erase, [](char c){return c == ' ';});

	zxc::string strr = zxc::string("aaa") + 10.3 + 3 + 5 + 28;

	//str = zxc::convWString(wstr2);
	wstr2 = zxc::convString(str);

	return 0;
}