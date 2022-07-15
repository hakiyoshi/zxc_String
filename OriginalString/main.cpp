#include <iostream>
#include "string.h"

int main(void)
{
	ghl::string str("abcde");
	str.ends_with("cdae");

	return 0;
}