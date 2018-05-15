// DataStruct.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "EList.h"
int _tmain(int argc, _TCHAR* argv[])
{
	EList<int> iElist;

	for (int i = 0 ;i < 5 ;i++)
	{
		iElist.insert_front(new int(i));
	}

	printf("ilist length:%d\n",iElist.length());
	system("pause");
	return 0;
}

