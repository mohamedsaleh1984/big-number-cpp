#include "BigNumber.h"
/*

*/
char* BigNumber::toCharStar()
{
	//Allocate...
	char* strValue = new char[MAX_ARRAY_SIZE];
	//Free
	memset(strValue, '\0', MAX_ARRAY_SIZE);

	for (int i = 0; i < this->strValue.size(); i++)
		strValue[i] = this->strValue.at(i);

	return strValue;
}

//Return Precisely the length of given string szBuff
int BigNumber::stringLength(char* szBuff)
{
	int iLen = 0;
	int i = 0;
	char tmp = szBuff[i];

	while (isdigit(tmp))
	{
		iLen++;
		tmp = szBuff[i];
		i++;
	}

	--iLen;
	return iLen;
}


void BigNumber::modifiyMultRows(char** szBuffer, int nElements)
{
	int iShiftLeft = 0;
	int resLen = 0;

	for (int i = 0; i < nElements; i++)
	{
		resLen = stringLength(szBuffer[i]);

		szBuffer[i] = shiftLeftColumn(szBuffer[i], iShiftLeft);

		iShiftLeft++;
	}
}



char* BigNumber::subString(char* string, int start, int end)
{
	char* szBuff = new char[end - start];
	memset(szBuff, '\0', end - start);

	int iCounter = 0;

	for (int i = start; i <= end; i++)
	{
		szBuff[iCounter] = string[i];
		iCounter++;
	}

	return szBuff;
}






int BigNumber::maxBuffLength(char** szBuffer, int nElements)
{
	int max = -1;
	int len = 0;

	for (int i = 0; i <= nElements; i++)
	{
		len = stringLength(szBuffer[i]);
		if (len > max)
			max = len;
	}

	return max;
}

int BigNumber::IntChar(char* string, int index)
{
	short i = (char)string[index];

	if (i == 48)
		return 0;
	else if (i == 49)
		return 1;
	else if (i == 50)
		return 2;
	else if (i == 51)
		return 3;
	else if (i == 52)
		return 4;
	else if (i == 53)
		return 5;
	else if (i == 54)
		return 6;
	else if (i == 55)
		return 7;
	else if (i == 56)
		return 8;
	else if (i == 57)
		return 9;
	else
		return 0;
}

char* BigNumber::ReverseStr(char* szString)
{
	int len = stringLength(szString);
	int iCount = 0;
	char* szRev = new char[len];

	memset(szRev, '\0', len);

	for (int i = len - 1; i >= 0; i--)
	{
		szRev[iCount] = szString[i];
		iCount++;
	}
	//Fuck You Damn LINE...And I GOT YOU haahhaaahaaaaaaaaaaaa :))))))))))))))))))))))))))
	szRev[len] = '\0';

	return szRev;
}

bool BigNumber::exceedRange(unsigned long int n)
{
	return (n > 2147483647) ? true : false;
}

char* BigNumber::convertIntToStr(int n)
{
	char* szBuffer = new char[10];
	//Free ~~~~.....
	memset(szBuffer, '\0', 10);
	//Convert the given number to char style with DECIMAL notation.
	itoa(n, szBuffer, 10);
	//return the bufffer.
	return szBuffer;
}

bool BigNumber::isDigit(char x)
{
	short i = x;
	if (i >= 48 && i <= 57)
		return true;
	return false;
}

void BigNumber::clearBuffer(char* szBuffer, int iBuffLen)
{
	memset(szBuffer, '\0', iBuffLen);
}


int BigNumber::lenFunc(unsigned long int n)
{
	//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
	if (n > 2147483647)
	{
		cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ LEN FUNC";
		return 0;
	}

	char* szBuff = new char[10];
	//Free...
	memset(szBuff, '\0', 10);
	//Convert the given number to char style with DECIMAL notation.
	itoa(n, szBuff, 10);

	int len = 0;
	char tmp = '\0';
	tmp = szBuff[0];

	int i = 0;
	while (tmp != '\0')
	{
		tmp = szBuff[i];
		len++;
		i++;
	}

	return len - 1;
}

int BigNumber::sum()
{
	int sum = 0;
	char tmp = '\0';

	for (int i = 0; i < stringLength(strValue); i++)
	{
		tmp = strValue[i];
		if (isDigit(tmp) && tmp != '0')
			sum += IntChar(strValue, i);
	}

	return sum;
}

void BigNumber::toString()
{
	if (strValue == NULL)
	{
		cout << "ERROR, NO ASSIGNED VALUE... _ toStr FUNC" << endl;
		return;
	}

	cout << "Final Result is : ";
	char x = strValue[0];
	int iCounter = 0;

	while (x != '\0')
	{
		if (isDigit(x))
		{
			cout << x;
		}

		iCounter++;
		x = strValue[iCounter];
	}

	cout << "\n";
}

BigNumber::BigNumber()
{
	iInitalValue = 0;
	//Allocate...
	strValue = new char[MAX_ARRAY_SIZE];
	//Free ~~~~.....
	memset(strValue, '\0', MAX_ARRAY_SIZE);
	//view
	//cout << "Stored number is :" << strValue << endl;
}

BigNumber::BigNumber(char* szNumber)
{
	//Allocate...
	strValue = new char[MAX_ARRAY_SIZE];
	//Free ~~~~.....
	memset(strValue, '\0', MAX_ARRAY_SIZE);
	//Copy
	strcpy(strValue, szNumber);
	//view
	//cout << "Stored number is :" << strValue << endl;
}

BigNumber::BigNumber(int iValue)
{
	//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
	if (iValue > 2147483647)
	{
		cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ NON-DEFAULT CONS FUNC";
		return;
	}

	//Allocate...
	strValue = new char[MAX_ARRAY_SIZE];
	//Free ~~~~.....
	memset(strValue, '\0', MAX_ARRAY_SIZE);
	//Convert the given number to char style with DECIMAL notation.
	itoa(iValue, strValue, 10);
	//view
	this->iInitalValue = iValue;
	//	cout << "Stored number is :" << strValue << endl;
}



//In Case: Default Constructor Has Called...
void BigNumber::Insert(int initNumber)
{
	//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
	if (initNumber > 2147483647)
	{
		cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ INSERT FUNC";
		return;
	}
	else
	{
		//In Case : there was a value...
		if (strValue != NULL)
		{
			memset(strValue, '\0', MAX_ARRAY_SIZE);
		}
		//Convert the given number to char style with DECIMAL notation.
		itoa(initNumber, strValue, 10);
		//
		this->iInitalValue = initNumber;
	}
}

//In Case: Default Constructor Has Called...
void BigNumber::Insert(char* szBuff)
{
	//MAX UNSIGNED LONG INT		4294967295 10 Bytes, 10 Characters.
	if (szBuff == NULL)
	{
		cout << "ERROR, NULL POINTER _ INSERT FUNC";
		return;
	}
	else
	{
		//In Case : there was a value...
		memcpy(strValue, szBuff, stringLength(szBuff) + 1);
	}
}




void BigNumber::add(unsigned long int num)
{
	if (num > 2147483647)
	{
		cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ ADD FUNC";
		return;
	}
	//Carried value len...
	int ilenOld = stringLength(strValue);//strlen(strValue);

	//Result....
	char* szFinalRes = new char[MAX_ARRAY_SIZE];
	memset(szFinalRes, '\0', MAX_ARRAY_SIZE);

	//Copy the old value into temp...
	char* szBuffOldNum = new char[MAX_ARRAY_SIZE];
	memset(szBuffOldNum, '\0', MAX_ARRAY_SIZE);
	memcpy(szBuffOldNum, strValue, ilenOld + 1);

	//----------------------------------------------------
	//Get the length of Given number...
	int ilenGiven = this->lenFunc(num);

	//----------------------------------------------------
	//Convert Given Int to String...
	char* szGivenNum = new char[ilenGiven + 1];
	memset(szGivenNum, '\0', ilenGiven + 1);
	itoa(num, szGivenNum, 10);
	//----------------------------------------------------

	int iresult = 0;				//Operation Result....
	int iOldRem = 0, iRem = 0;		//Reminder...

	//Decrement it to start specificly from the last index
	ilenGiven--;
	ilenOld--;

	int i = 0;
	if (ilenGiven > ilenOld)
		i = ilenGiven;
	else
		i = ilenOld;

	for (; i >= 0; i--)
	{
		if (iRem)
		{
			iresult = this->IntChar(szBuffOldNum, ilenOld) + this->IntChar(szGivenNum, i) + iRem;
			iRem = 0;
		}
		else
		{
			iresult = this->IntChar(szBuffOldNum, ilenOld) + this->IntChar(szGivenNum, i);
		}


		char szTmpBuf[2];
		memset(szTmpBuf, '\0', 2);

		if (iresult > 9)
		{
			iRem = iresult / 10;
			iOldRem = iresult % 10;
			itoa(iOldRem, szTmpBuf, 10);
		}
		else
		{
			itoa(iresult, szTmpBuf, 10);
		}

		strcat(szFinalRes, szTmpBuf);

		if (i == 0 && iRem != 0)
		{
			memset(szTmpBuf, '\0', 2);
			itoa(iRem, szTmpBuf, 10);
			strcat(szFinalRes, szTmpBuf);
		}

		ilenOld--;
	}


	strValue = ReverseStr(szFinalRes);
	//		free szFinalRes;
}

void BigNumber::add(char* szBuff)
{
	if (szBuff == NULL)
	{
		cout << "ERROR, NULL POINTER _ ADD FUNC";
		return;
	}
	//Carried value len...
	int ilenOld = stringLength(strValue);

	//Result....
	char* szFinalRes = new char[MAX_ARRAY_SIZE];
	memset(szFinalRes, '\0', MAX_ARRAY_SIZE);

	//Copy the old value into temp...
	char* szBuffOldNum = new char[MAX_ARRAY_SIZE];
	memset(szBuffOldNum, '\0', MAX_ARRAY_SIZE);
	//I added 1 for '\0' the termination character...
	memcpy(szBuffOldNum, strValue, ilenOld + 1);

	//----------------------------------------------------
	//Get the length of Given Buffer...
	int ilenGiven = stringLength(szBuff);
	//----------------------------------------------------

	int iresult = 0;				//Operation Result....
	int iOldRem = 0, iRem = 0;		//Reminder...

	//Decrement it to start specificly from the last index
	ilenGiven--;
	ilenOld--;

	int i = 0;
	if (ilenGiven > ilenOld)
		i = ilenGiven;
	else
		i = ilenOld;

	for (; i >= 0; i--)
	{
		if (iRem)
		{
			iresult = this->IntChar(szBuffOldNum, ilenOld) + this->IntChar(szBuff, ilenGiven) + iRem;
			iRem = 0;
		}
		else
		{
			iresult = this->IntChar(szBuffOldNum, ilenOld) + this->IntChar(szBuff, ilenGiven);
		}


		char szTmpBuf[2];
		memset(szTmpBuf, '\0', 2);

		if (iresult > 9)
		{
			iRem = iresult / 10;
			iOldRem = iresult % 10;
			itoa(iOldRem, szTmpBuf, 10);
		}
		else
		{
			itoa(iresult, szTmpBuf, 10);
		}

		strcat(szFinalRes, szTmpBuf);

		if (i == 0 && iRem != 0)
		{
			memset(szTmpBuf, '\0', 2);
			itoa(iRem, szTmpBuf, 10);
			strcat(szFinalRes, szTmpBuf);
		}

		ilenOld--;
		ilenGiven--;
	}


	strValue = ReverseStr(szFinalRes);
}

void BigNumber::multiply(unsigned long int num)
{
	if (num > 2147483647)
	{
		cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ MULTIPLY FUNC";
		return;
	}
	//view
	//cout << strValue << " "<< "Multiply by :" << num << endl;

	//Get the length of Given number...
	int iLenStored = this->stringLength(strValue);
	//Copy stored value into temp...
	char* szStoredOldNum = new char[MAX_ARRAY_SIZE];
	memset(szStoredOldNum, '\0', MAX_ARRAY_SIZE);
	memcpy(szStoredOldNum, strValue, iLenStored);

	//Get the length of Given number...
	int iLenGiven = this->lenFunc(num);
	//----------------------------------------------------
	//Convert Given Int to String...
	char* szGivenNum = new char[iLenGiven];
	memset(szGivenNum, '\0', iLenGiven);
	itoa(num, szGivenNum, 10);
	//----------------------------------------------------
	int iCase = 0;							// iCase = 1 (Easy)		iCase = 2 (Hard)

	//Check Which Case of Multiplication...
	if (iLenGiven == 1 || iLenStored == 1)	//which means 2*8888 or 9999*9
		iCase = 1;
	else
		iCase = 2;

	//----------------------------------------------------
	int iresult = 0;				//Operation Result....
	int iOldRem = 0, iRem = 0;		//Reminder...
	//----------------------------------------------------


	if (iCase == 1)
	{
		//Easy Case

		//Store the Result in this buffer....
		char* szRes = new char[MAX_ARRAY_SIZE];
		memset(szRes, '\0', MAX_ARRAY_SIZE);

		for (int i = iLenStored - 1; i >= 0; i--)
		{
			if (iRem)
			{
				if (iLenStored == 1)
				{
					iresult = this->IntChar(szStoredOldNum, 0) * this->IntChar(szGivenNum, i) + iRem;
					iRem = 0;
				}
				else
				{
					iresult = this->IntChar(szStoredOldNum, i) * this->IntChar(szGivenNum, 0) + iRem;
					iRem = 0;
				}
			}
			else
			{
				if (iLenStored == 1)
					iresult = this->IntChar(szStoredOldNum, 0) * this->IntChar(szGivenNum, i);
				else
					iresult = this->IntChar(szStoredOldNum, i) * this->IntChar(szGivenNum, 0);
			}


			char szTmpBuf[2];
			memset(szTmpBuf, '\0', 2);

			if (iresult > 9)
			{
				iRem = iresult / 10;
				iOldRem = iresult % 10;
				itoa(iOldRem, szTmpBuf, 10);
			}
			else
			{
				itoa(iresult, szTmpBuf, 10);
			}

			strcat(szRes, szTmpBuf);

			if (i == 0 && iRem != 0)
			{
				memset(szTmpBuf, '\0', 2);
				itoa(iRem, szTmpBuf, 10);
				strcat(szRes, szTmpBuf);
				iRem = 0;
			}
		}

		strcpy(strValue, ReverseStr(szRes));
		// cout << strValue << endl;
	}
	else
	{
		//Minimun Number of Rows whatever was the given or stored number LENGTH.
		int iMultiRowsNum = (iLenGiven > iLenStored) ? iLenStored : iLenGiven;

		//If Both are equal, set it to any
		if (iLenGiven == iLenStored)
		{
			iMultiRowsNum = iLenGiven;
		}

		//Declare a pointer array...
		char** szMultipRes = new char*[iMultiRowsNum];
		//Clear the array of pointers...
		for (int c = 0; c < iMultiRowsNum; c++)
		{
			//Initialize the array and clear the buffers....
			szMultipRes[c] = new char[MAX_ARRAY_SIZE];
			clearBuffer(szMultipRes[c], MAX_ARRAY_SIZE);
		}

		//iRowCounter is a counter to define Which Row in Multiplication Operation.
		int iRowCounter = 0;

		//counters for the Multiplication Operation.
		int i = 0, j = 0;

		//if Given and Stored lengths are equal set j,j equal to anyone of them -1 to start from the right
		//side
		if (iLenGiven == iLenStored)
		{
			i = j = iLenGiven - 1;
		}
		else
		{
			//Set i,j
			if (iLenGiven > iLenStored)
			{
				i = iLenStored - 1;
				j = iLenGiven - 1;
			}
			else
			{
				i = iLenGiven - 1;
				j = iLenStored - 1;
			}
		}
		int jReIteValue = j;

		//Start Rows Multiplication....
		//Given Or Stored
		for (; i >= 0; i--)
		{
			//Given Or Stored
			for (j = jReIteValue; j >= 0; j--)
			{
				//Is There a Reminder...
	//			cout << i << ", " << j << endl;

				if (iRem)
				{
					if (iLenGiven > iLenStored)
					{
						iresult = this->IntChar(szGivenNum, j) * this->IntChar(szStoredOldNum, i) + iRem;
						iRem = 0;
					}
					else if (iLenGiven < iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i) + iRem;
						iRem = 0;
					}
					else if (iLenGiven == iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i) + iRem;
						iRem = 0;
					}
				}
				else
				{
					if (iLenGiven > iLenStored)
					{
						iresult = this->IntChar(szGivenNum, j) * this->IntChar(szStoredOldNum, i);
					}
					else if (iLenGiven < iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i);
					}
					else if (iLenGiven == iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i);
					}

				}


				char szTmpBuf[2];
				memset(szTmpBuf, '\0', 2);

				if (iresult > 9)
				{
					iRem = iresult / 10;
					iOldRem = iresult % 10;
					itoa(iOldRem, szTmpBuf, 10);
				}
				else
				{
					itoa(iresult, szTmpBuf, 10);
				}

				strcat(szMultipRes[iRowCounter], szTmpBuf);

				if (j == 0 && iRem != 0)
				{
					memset(szTmpBuf, '\0', 2);
					itoa(iRem, szTmpBuf, 10);
					strcat(szMultipRes[iRowCounter], szTmpBuf);
					iRem = 0;
				}


			}
			szMultipRes[iRowCounter] = ReverseStr(szMultipRes[iRowCounter]);
			iRowCounter++;
		}//End For "HARD CASE..."
		/*
		cout << "Numbers Before Modification" << endl;
		for(int h = 0 ; h < iMultiRowsNum ; h++)
			cout << szMultipRes[h] << endl;
		*/
		//Modify Rows...
		modifiyMultRows(szMultipRes, iMultiRowsNum);

		/*
		cout << "Numbers After Modification" << endl;
		for(h = 0 ; h < iMultiRowsNum ; h++)
			cout << szMultipRes[h] << endl;
		*/
		//addition Operation....
		/*	*//**/

		BigNumber* cls = new BigNumber(szMultipRes[0]);

		for (int P = 1; P < iMultiRowsNum; P++)
		{
			//	cout << "adding number...  " <<  szMultipRes[P] << endl;
			cls->add(szMultipRes[P]);
		}




		strcpy(this->strValue, cls->toCharStar());
	}

}

void BigNumber::multiply(char* szBuff)
{
	if (szBuff == NULL)
	{
		cout << "ERROR, NULL POINTER _ Multiply FUNC";
		return;
	}
	//view
//	cout << strValue << " "<< "Multiply by :" << num << endl;

	//Get the length of Given number...
	int iLenStored = this->stringLength(strValue);
	//Copy stored value into temp...
	char* szStoredOldNum = new char[MAX_ARRAY_SIZE];
	memset(szStoredOldNum, '\0', MAX_ARRAY_SIZE);
	memcpy(szStoredOldNum, strValue, iLenStored);

	//Get the length of Given number...
	int iLenGiven = stringLength(szBuff);
	//----------------------------------------------------
	//Convert Given Int to String...
	char* szGivenNum = new char[iLenGiven];
	memset(szGivenNum, '\0', iLenGiven);
	strcpy(szGivenNum, szBuff);
	//----------------------------------------------------
	int iCase = 0; // iCase = 1 (Easy)		iCase = 2 (Hard)

	//Check Which Case of Multiplication...
	if (iLenGiven == 1 || iLenStored == 1)	//which means 2*8888 or 9999*9
		iCase = 1;
	else
		iCase = 2;

	//----------------------------------------------------
	int iresult = 0;				//Operation Result....
	int iOldRem = 0, iRem = 0;		//Reminder...
	//----------------------------------------------------


	if (iCase == 1)
	{
		//Easy Case

		//Store the Result in this buffer....
		char* szRes = new char[MAX_ARRAY_SIZE];
		memset(szRes, '\0', MAX_ARRAY_SIZE);

		for (int i = iLenStored - 1; i >= 0; i--)
		{
			if (iRem)
			{
				if (iLenStored == 1)
				{
					iresult = this->IntChar(szStoredOldNum, 0) * this->IntChar(szGivenNum, i) + iRem;
					iRem = 0;
				}
				else
				{
					iresult = this->IntChar(szStoredOldNum, i) * this->IntChar(szGivenNum, 0) + iRem;
					iRem = 0;
				}
			}
			else
			{
				if (iLenStored == 1)
					iresult = this->IntChar(szStoredOldNum, 0) * this->IntChar(szGivenNum, i);
				else
					iresult = this->IntChar(szStoredOldNum, i) * this->IntChar(szGivenNum, 0);
			}


			char szTmpBuf[2];
			memset(szTmpBuf, '\0', 2);

			if (iresult > 9)
			{
				iRem = iresult / 10;
				iOldRem = iresult % 10;
				itoa(iOldRem, szTmpBuf, 10);
			}
			else
			{
				itoa(iresult, szTmpBuf, 10);
			}

			strcat(szRes, szTmpBuf);

			if (i == 0 && iRem != 0)
			{
				memset(szTmpBuf, '\0', 2);
				itoa(iRem, szTmpBuf, 10);
				strcat(szRes, szTmpBuf);
				iRem = 0;
			}
		}

		strcpy(strValue, ReverseStr(szRes));
	}
	else
	{
		//Minimun Number of Rows whatever was the given or stored number LENGTH.
		int iMultiRowsNum = (iLenGiven > iLenStored) ? iLenStored : iLenGiven;

		//If Both are equal, set it to any
		if (iLenGiven == iLenStored)
		{
			iMultiRowsNum = iLenGiven;
		}

		//Declare a pointer array...
		char** szMultipRes = new char*[iMultiRowsNum];
		//Clear the array of pointers...
		for (int c = 0; c < iMultiRowsNum; c++)
		{
			//Initialize the array and clear the buffers....
			szMultipRes[c] = new char[MAX_ARRAY_SIZE];
			clearBuffer(szMultipRes[c], MAX_ARRAY_SIZE);
		}

		//iRowCounter is a counter to define Which Row in Multiplication Operation.
		int iRowCounter = 0;

		//counters for the Multiplication Operation.
		int i = 0, j = 0;

		//if Given and Stored lengths are equal set j,j equal to anyone of them -1 to start from the right
		//side
		if (iLenGiven == iLenStored)
		{
			i = j = iLenGiven - 1;
		}
		else
		{
			//Set i,j
			if (iLenGiven > iLenStored)
			{
				i = iLenStored - 1;
				j = iLenGiven - 1;
			}
			else
			{
				i = iLenGiven - 1;
				j = iLenStored - 1;
			}
		}
		int jReIteValue = j;

		//Start Rows Multiplication....
		//Given Or Stored
		for (; i >= 0; i--)
		{
			//Given Or Stored
			for (j = jReIteValue; j >= 0; j--)
			{
				//Is There a Reminder...
	//			cout << i << ", " << j << endl;

				if (iRem)
				{
					if (iLenGiven > iLenStored)
					{
						iresult = this->IntChar(szGivenNum, j) * this->IntChar(szStoredOldNum, i) + iRem;
						iRem = 0;
					}
					else if (iLenGiven < iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i) + iRem;
						iRem = 0;
					}
					else if (iLenGiven == iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i) + iRem;
						iRem = 0;
					}
				}
				else
				{
					if (iLenGiven > iLenStored)
					{
						iresult = this->IntChar(szGivenNum, j) * this->IntChar(szStoredOldNum, i);
					}
					else if (iLenGiven < iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i);
					}
					else if (iLenGiven == iLenStored)
					{
						iresult = this->IntChar(szStoredOldNum, j) * this->IntChar(szGivenNum, i);
					}

				}


				char szTmpBuf[2];
				memset(szTmpBuf, '\0', 2);

				if (iresult > 9)
				{
					iRem = iresult / 10;
					iOldRem = iresult % 10;
					itoa(iOldRem, szTmpBuf, 10);
				}
				else
				{
					itoa(iresult, szTmpBuf, 10);
				}

				strcat(szMultipRes[iRowCounter], szTmpBuf);

				if (j == 0 && iRem != 0)
				{
					memset(szTmpBuf, '\0', 2);
					itoa(iRem, szTmpBuf, 10);
					strcat(szMultipRes[iRowCounter], szTmpBuf);
					iRem = 0;
				}


			}
			szMultipRes[iRowCounter] = ReverseStr(szMultipRes[iRowCounter]);
			iRowCounter++;
		}//End For "HARD CASE..."
		/*
		cout << "Numbers Before Modification" << endl;
		for(int h = 0 ; h < iMultiRowsNum ; h++)
			cout << szMultipRes[h] << endl;
		*/
		//Modify Rows...
		modifiyMultRows(szMultipRes, iMultiRowsNum);

		/*
		cout << "Numbers After Modification" << endl;
		for(h = 0 ; h < iMultiRowsNum ; h++)
			cout << szMultipRes[h] << endl;
		*/
		//addition Operation....
		/*	*//**/

		BigNumber* cls = new BigNumber(szMultipRes[0]);

		for (int P = 1; P < iMultiRowsNum; P++)
		{
			//	cout << "adding number...  " <<  szMultipRes[P] << endl;
			cls->add(szMultipRes[P]);
		}




		strcpy(this->strValue, cls->toCharStar());
	}

}





void BigNumber::Power(int num)
{
	if (!exceedRange(num))
	{
		BigNumber* cls = new BigNumber(this->strValue);
		char* szNum = new char[MAX_ARRAY_SIZE];
		memset(szNum, '\0', MAX_ARRAY_SIZE);
		strcpy(szNum, this->strValue);

		for (int i = 1; i < num; i++)
		{
			cls->multiply(szNum);
			//			cout << szNum << " Power " << i+1 << " Equal " << cls->toCharStar() << endl;
		}

		strcpy(this->strValue, cls->toCharStar());
	}
	else
	{
		cout << "ERROR, THE NUMBER EXCEEDING THE INITIAL LIMITS _ Power FUNC";
		return;
	}
}

unsigned long int BigNumber::getIntValue()
{
	return this->iInitalValue;
}

std::string BigNumber::shiftLeftColumn(std::string szBuffer, int iCol)
{
	std::string newString;
	newString.resize(MAX_ARRAY_SIZE);
	newString = szBuffer;
	newString = newString.substr(iCol, newString.size());
	newString.shrink_to_fit();
	for (int i = 0; i < iCol; i++)
		newString.append("0");
	return newString;
}

std::string BigNumber::shiftRightColumn(std::string szBuffer, int iCol)
{
	std::string newString;
	newString.resize(MAX_ARRAY_SIZE);
	newString = szBuffer;
	newString = newString.substr(iCol, newString.size());

	for (int i = 0; i < iCol; i++)
		newString.push_back('0');

	return newString;
}