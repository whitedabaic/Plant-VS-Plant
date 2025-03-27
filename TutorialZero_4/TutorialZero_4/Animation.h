#ifndef _ANIMATION_H_
#define _ANIMATION_H_

#include "Util.h"
#include "Atlas.h"

#include <functional>
#include <graphics.h>

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	void Reset()
	{
		timer = 0;
		idxFrame = 0;
	}

	void SetAtlas(Atlas* newAtlas)
	{
		Reset();
		atlas = newAtlas;
	}

	void setLoop(bool flag)
	{
		isLoop = flag;
	}

	void setInterval(int ms)
	{
		interval = ms;
	}

	int GetIdxFrame()
	{
		return idxFrame;
	}

	IMAGE* GetFrame()
	{
		return atlas->GetImage(idxFrame);
	}

	bool CheckFinished()
	{
		if (isLoop) return false;

		return (idxFrame == atlas->getSize() - 1);
	}

	void OnUpdate(int delta)
	{
		timer += delta;
		if (timer >= interval)
		{
			timer = 0;
			idxFrame++;
			if (idxFrame >= atlas->getSize())
			{
				idxFrame = isLoop ? 0 : atlas->getSize() - 1;
				if (!isLoop && callback)
					callback();
			}
		}
	}

	void OnDraw(int x, int y) const
	{
		putimage_alpha(x, y, atlas->GetImage(idxFrame));
	}

	void SetCallback(std::function<void()> cb)
	{
		this->callback = cb;
	}

private:
	int timer = 0;			// 计时器
	int interval = 0;		// 帧间隔
	int idxFrame = 0;		// 当前帧索引
	bool isLoop = true;		// 是否循环播放
	Atlas* atlas = nullptr;
	std::function<void()> callback;
};

#endif // !_ANIMATION_H_
