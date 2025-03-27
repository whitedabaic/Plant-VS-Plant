#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_

#include "scene.h"
#include "Atlas.h"
#include "Timer.h"
#include "Camera.h"
#include "Animation.h"
#include "SceneManager.h"

#include <iostream>

extern Atlas atlasPeashooterRunRight;

extern SceneManager sceneManager;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void OnEnter() override
	{
		animationPeashooterRunRight.SetAtlas(&atlasPeashooterRunRight);
		animationPeashooterRunRight.setInterval(75);
		animationPeashooterRunRight.setLoop(true);

		//timer.SetWaitTime(1000);
		//timer.SetOneShot(false);
		//timer.SetCallback([]()
		//	{
		//		std::cout << "定时器回调" << std::endl;
		//	});
	}

	void OnUpdate(int delta) override
	{
		camera.OnUpdate(delta);
		animationPeashooterRunRight.OnUpdate(delta);
	}

	void OnDraw() override
	{
		const Vector2& posCamera = camera.getPosition();
		animationPeashooterRunRight.OnDraw((int)(100 - posCamera.x), (int)(100 - posCamera.y));
	}

	void OnInput(const ExMessage& msg) override
	{
		if (msg.message == WM_KEYDOWN)
		{
			camera.Shake(10, 350);
		}
	}

	void OnExit() override
	{
		std::cout << "主菜单退出" << std::endl;
	}

private:
	Timer timer;
	Camera camera;
	Animation animationPeashooterRunRight;
};

#endif // !_MENU_SCENE_H_