#include <iostream>
#include <string>
using namespace std;

string reverse(string str) {
	if (str=="") return str;
	else return reverse(str.substr(1)) + str[0];
}

int main() {
	string str = "1234567";
	
	printf("%s", reverse(str).c_str());
}