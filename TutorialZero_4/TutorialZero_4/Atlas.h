#ifndef _ATLAS_H_
#define _ATLAS_H_

#include <vector>
#include <graphics.h>

class Atlas
{
public:
	Atlas() = default;
	~Atlas() = default;

	void LoadFromFile(LPCTSTR pathTemplate, int num)
	{
		imgList.clear();
		imgList.resize(num);

		TCHAR pathFile[256];
		for (int i = 0; i < num; i++)
		{
			_stprintf_s(pathFile, pathTemplate, i + 1);
			loadimage(&imgList[i], pathFile);
		}
	}

	void clear()
	{
		imgList.clear();
	}

	int getSize()
	{
		return (int)imgList.size();
	}

	IMAGE* GetImage(int idx)
	{
		if (idx < 0 || idx >= imgList.size())
			return nullptr;

		return &imgList[idx];
	}

	void addImage(const IMAGE& img)
	{
		imgList.push_back(img);
	}

public:
	std::vector<IMAGE> imgList;
};

#endif // !_ATLAS_H_
