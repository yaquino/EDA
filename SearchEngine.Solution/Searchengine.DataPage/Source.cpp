#include <iostream>
#include <stdio.h>


int main()
{
	FILE *stream1;
	fopen_s(&stream1, "Luis.txt", "w");
	fputs("Hola Mundo \n", stream1);
	return 0;
}