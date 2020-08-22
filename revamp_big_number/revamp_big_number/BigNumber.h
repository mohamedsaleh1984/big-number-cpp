#pragma once
#ifndef __BIG_NUMBER_H__
#define __BIG_NUMBER_H__

#include <string>
using namespace std;

#define MAX_ARRAY_SIZE	8192

class BigNumber
{
public:

	BigNumber();
	BigNumber(std::string szNumber);
	BigNumber(int iValue);
	//In Case: Default Constructor Has Called...
	void Insert(int initNumber);
	//In Case: Default Constructor Has Called...
	void Insert(char *szBuff);
	void add(unsigned long int num);
	void add(char *szBuff);
	void multiply(unsigned long int num = 1);
	void multiply(char *szBuff);
	void Power(int num);

	unsigned long int getIntValue();
	int sum();
	void toString();
	char *toCharStar();
private:
	unsigned long int iInitalValue;
	std::string			strValue;

	//char *toCharStar();
	//Return Precisely the length of given string szBuff
	int stringLength(char *szBuff);
	int maxBuffLength(char **szBuffer, int nElements);
	void modifiyMultRows(char **szBuffer, int nElements);
	std::string shiftLeftColumn(std::string szBuffer, int iCol);
	std::string shiftRightColumn(std::string szBuffer, int iCol);
	char *subString(char *string, int start, int end);
	int IntChar(char *string, int index);
	char *ReverseStr(char *szString);
	bool exceedRange(unsigned long int n);
	char *convertIntToStr(int n);
	bool isDigit(char x);
	void clearBuffer(char *szBuffer, int iBuffLen);
	//Return the length of Given number " n "....
	int lenFunc(unsigned long int n);
};


#endif // !__BIG_NUMBER_H__
