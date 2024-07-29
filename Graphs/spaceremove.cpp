
#include <iostream>
#include <string.h>

using namespace std;
void trim(char *str)
{

	int count = 0;
	for (int i = 0; str[i]; i++){
	    if (str[i] != ' ')
	    {
	       str[count++] = str[i];
	    }
	}
    str[count]='\0';
}

int main()
{
	char str[] = "The quick brown fox jumps over the lazy dog";
	trim(str);
	cout << str;
	return 0;
}
