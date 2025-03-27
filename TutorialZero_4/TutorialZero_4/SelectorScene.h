#ifndef _SELECTOR_SCENE_H_
#define _SELECTOR_SCENE_H_

#include "scene.h"
#include "SceneManager.h"

#include <iostream>

extern SceneManager sceneManager;

class SelectorScene : public Scene
{
public:
	SelectorScene() = default;
	~SelectorScene() = default;

	void OnEnter() override
	{
		std::cout << "进入选人场景" << std::endl;
	}
	void OnUpdate(int delta) override
	{
		std::cout << "选人场景正在运行..." << std::endl;
	}
	void OnDraw() override
	{
		outtextxy(10, 10, _T("选人场景绘制内容"));
	}
	void OnInput(const ExMessage& msg) override
	{
		if (msg.message == WM_KEYDOWN)
		{
			sceneManager.SwitchTo(SceneManager::SceneType::Menu);
		}
	}
	void OnExit() override
	{
		std::cout << "选人场景退出" << std::endl;
	}
};

#endif // !_SELECTOR_SCENE_H_
