#ifndef _TIMER_H_
#define _TIMER_H_

#include <functional>

class Timer
{
public:
	Timer() = default;
	~Timer() = default;
	
	void Restart()
	{
		passTime = 0;
		shotted = false;
	}

	void SetWaitTime(int val)
	{
		waitTime = val;
	}

	void SetOneShot(bool flag)
	{
		oneShot = flag;
	}

	void SetCallback(std::function<void()> callback)
	{
		this->callback = callback;
	}

	void Pause()
	{
		paused = true;
	}

	void Resume()
	{
		paused = false;
	}

	void OnUpdate(int delta)
	{
		if (paused) return;

		passTime += delta;
		if (passTime >= waitTime)
		{
			if ((!oneShot || (oneShot && !shotted)) && callback)
				callback();
			shotted = true;
			passTime = 0;
		}
	}

private:
	int passTime = 0;		// 已过时间
	int waitTime = 0;		// 等待时间
	bool paused = false;	// 是否暂停
	bool shotted = false;	// 是否已触发
	bool oneShot = false;	// 是否一次性
	std::function<void()> callback;

};

#endif // !_TIMER_H_
