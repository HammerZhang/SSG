

#ifndef _FILE_SEARCH_
#define _FILE_SEARCH_

#include <iostream>
#include <vector>
#include <Windows.h>

namespace FO
{
	void FindAllFiles(const char* filePath, std::vector<std::string>& files, const char* fileFormat);
}

#endif