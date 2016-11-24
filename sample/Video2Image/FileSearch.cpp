


#include "FileSearch.h"


// file operation
namespace FO
{
	std::string WChar2Ansi(LPCWSTR pwszSrc)
	{
		int nLen = WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, NULL, 0, NULL, NULL);
		if (nLen <= 0)
			return std::string("");
		char* pszDst = new char[nLen];
		if (NULL == pszDst)
			return std::string("");
		WideCharToMultiByte(CP_ACP, 0, pwszSrc, -1, pszDst, nLen, NULL, NULL);
		pszDst[nLen - 1] = 0;
		std::string strTemp(pszDst);
		delete[] pszDst;
		return strTemp;
	}

	void FindAllFiles(const char* filePath, std::vector<std::string>& files, const char* fileFormat)
	{
		files.clear();
		WIN32_FIND_DATAW file;
		int i = 0;
		char tempFilePath[MAX_PATH + 1];
		char tempFileName[MAX_PATH];

		sprintf_s(tempFilePath, "%s/%s", filePath, fileFormat);
		WCHAR wstr[MAX_PATH] = { 0 };
		MultiByteToWideChar(CP_ACP, 0, tempFilePath, -1, wstr, sizeof(wstr));

		HANDLE handle = FindFirstFileW(wstr, &file);
		if (handle != INVALID_HANDLE_VALUE)
		{
			do
			{
				sprintf(tempFileName, "%s/", filePath);
				files.push_back(WChar2Ansi(file.cFileName));
				files[i].insert(0, tempFileName);
				i++;
			} while (FindNextFileW(handle, &file));
		}
		FindClose(handle);
	}
}