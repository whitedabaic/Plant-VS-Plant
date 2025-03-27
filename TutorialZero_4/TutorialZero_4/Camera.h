#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Timer.h"
#include "Vector2.h"

class Camera
{
public:
	Camera()
	{
		timerShake.SetOneShot(true);
		timerShake.SetCallback([&]()
			{
				isShaking = false;
				Reset();
			});
	}
	~Camera() = default;

	const Vector2& getPosition() const
	{
		return position;
	}

	void Reset()
	{
		position.x = 0;
		position.y = 0;
	}

	void OnUpdate(int delta)
	{
		timerShake.OnUpdate(delta);

		if (isShaking)
		{
			position.x = (-50 + rand() % 100) / 50.0 * shakingStrength;
			position.y = (-50 + rand() % 100) / 50.0 * shakingStrength;
		}
	}

	void Shake(float strength, int duration)
	{
		if (isShaking) return;

		isShaking = true;
		shakingStrength = strength;

		timerShake.SetWaitTime(duration);
		timerShake.Restart();
	}

private:
	Vector2 position;			// 位置
	Timer timerShake;			// 震动计时器
	bool isShaking = false;		// 是否正在震动
	float shakingStrength = 0;	// 震动强度
};

#endif // !_CAMERA_H_
