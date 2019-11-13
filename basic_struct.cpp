#include<iostream>

using namespace std;

/*
±¸Á¶Ã¼ : °ü·ÃÀÖ´Â º¯¼öµéÀ» ¸ğ¾Æ¼­ ÇÏ³ªÀÇ »õ·Î¿î Å¸ÀÔÀ» ¸¸µé¾îÁÖ´Â ±â´ÉÀÌ´Ù.
»ç¿ëÀÚÁ¤ÀÇ º¯¼ö Å¸ÀÔÀÌ´Ù.
ÇüÅÂ : struct ±¸Á¶Ã¼¸í {}; ÀÇ ÇüÅÂ·Î ±¸¼ºµÈ´Ù.
¹è¿­°ú ±¸Á¶Ã¼ÀÇ °øÅëÁ¡
1. µ¥ÀÌÅÍ ÁıÇÕÀÌ´Ù.
2. ¿¬¼ÓµÈ ¸Ş¸ğ¸® ºí·°¿¡ ÇÒ´çµÈ´Ù. ±¸Á¶Ã¼ ¸â¹öµéÀº ¿¬¼ÓµÈ ¸Ş¸ğ¸® ºí·°À¸·Î ÀâÈ÷°Ô µÈ´Ù.
*/
#define NAME_SIZE 32

struct _tagStudent
{
	char	strName[NAME_SIZE];
	int		iNumber;
	int		iKor;
	int		iEng;
	int		iMath;
	int		iTotal;
	float	fAvg;
};

int main()
{
	_tagStudent	tStudent;
	_tagStudent	tStudentArr[100] = {};

	// ±¸Á¶Ã¼ ¸â¹ö¿¡ Á¢±ÙÇÒ¶§´Â . À» ÀÌ¿ëÇØ¼­ Á¢±ÙÇÏ°Ô µÈ´Ù.
	tStudent.iKor = 100;

	// tStudent.strName = "aslkdjfwi";
	// ¹®ÀÚ¿­À» ¹è¿­¿¡ ³Ö¾îÁÙ ¶§¿¡´Â ´Ü¼ø ´ëÀÔÀ¸·Î´Â ºÒ°¡´ÉÇÏ´Ù.
	// strcpy_s ¶ó´Â ÇÔ¼ö¸¦ ÀÌ¿ëÇØ¼­ ¹®ÀÚ¿­À» º¹»çÇØ ÁÖ¾î¾ß ÇÑ´Ù.
	// ÀÌ ÇÔ¼ö´Â ¿À¸¥ÂÊ¿¡ ÀÖ´Â ¹®ÀÚ¿­À» ¿ŞÂÊÀ¸·Î º¹»çÇØÁØ´Ù.
	strcpy_s(tStudent.strName, "°¡³ª´Ù¶ö asdf");

	// strcat_s ÇÔ¼ö´Â ¹®ÀÚ¿­À» ºÙ¿©ÁÖ´Â ±â´ÉÀÌ´Ù.
	// ¿À¸¥ÂÊ¿¡ ÀÖ´Â ¹®ÀÚ¿­À» ¿ŞÂÊ¿¡ ºÙ¿©ÁØ´Ù. srtName¿¡´Â À§¿¡¼­
	// °¡³ª´Ù¶ö asdf ¸¦ ÀúÀåÇØ µÎ¾ú±â ¶§¹®ÀÌ ÀÌ µÚ¿¡ ¿À¸¥ÂÊ ¹®ÀÚ¿­À» ºÙ¿©¼­
	// ¸¸µé¾îÁØ´Ù.
	strcat_s(tStudent.strName, " ¹®ÀÚ¿­ ºÙÀÌ±â");

	// strcmp ÇÔ¼ö´Â µÎ ¹®ÀÚ¿­À» ºñ±³ÇÏ¿© °°À» °æ¿ì 0À» ¹İÈ¯ÇÏ°í ´Ù¸¦ °æ¿ì
	// 0ÀÌ ¾Æ´Ñ °ªÀ» ¹İÈ¯ÇÑ´Ù.
	strcpy_s(tStudent.strName, "È«±æµ¿");

	cout << "ºñ±³ÇÒ ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä : ";
	char	strName[NAME_SIZE] = {};
	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "ÇĞ»ıÀ» ¯¾Ò½À´Ï´Ù." << endl;
	}

	else
		cout << "Ã£´Â ÇĞ»ıÀÌ ¾ø½À½À´Ï´Ù." << endl;
	

	cout << "ÀÌ¸§ ±æÀÌ : " << strlen(tStudent.strName) << endl;

	// ¹®ÀÚ¿­ÀÇ ³¡Àº Ç×»ó 0(NULL)·Î ³¡³ª¾ßÇÑ´Ù. ±×·±µ¥ ¾²·¹±â°ªÀÌ µé¾î°¡ÀÖ´Â
	// »óÅÂ¿¡¼­ ¾Æ·¡Ã³·³ °¢ ¹è¿­ ¿ä¼Ò¿¡ °ªÀ» ³Ö¾îÁÖ°Ô µÇ¸é ±× °ªÀÌ Ãâ·ÂµÇ°í
	// ³Ö¾îÁÖÁö ¾ÊÀº ºÎºĞÀº ¾²·¹±â°ªÀ¸·Î ±×´ë·Î Ãâ·ÂµÈ´Ù. ¿Ö³ÄÇÏ¸é Ãâ·ÂÇÒ¶§
	// ¹®ÀÚ¿­ÀÇ ³¡À» ÀÎ½ÄÇÒ ¼ö ¾ø±â ¶§¹®ÀÌ´Ù. 0ÀÌ µé¾î°¡¾ß ÇÏ´Âµ¥ ¾²·¹±â°ªÀÌ
	// µé¾î°¡ ÀÖ±â ¶§¹®ÀÌ´Ù.
	// tStudent.strName[0] = 'a';
	// tStudent.strName[1] = 'b';
	// tStudent.strName[2] = 0;
		
	cout << "ÀÌ¸§ : " << tStudent.strName << endl;
	cout << "ÇĞ¹ø : " << tStudent.iNumber << endl;
	cout << "±¹¾î : " << tStudent.iKor << endl;
	cout << "¿µ¾î : " << tStudent.iEng << endl;
	cout << "¼öÇĞ : " << tStudent.iMath << endl;
	cout << "ÃÑÁ¡ : " << tStudent.iTotal << endl;
	cout << "Æò±Õ : " << tStudent.fAvg << endl;

	return 0;
}