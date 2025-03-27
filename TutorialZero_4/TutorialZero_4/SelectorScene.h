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
		std::cout << "����ѡ�˳���" << std::endl;
	}
	void OnUpdate(int delta) override
	{
		std::cout << "ѡ�˳�����������..." << std::endl;
	}
	void OnDraw() override
	{
		outtextxy(10, 10, _T("ѡ�˳�����������"));
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
		std::cout << "ѡ�˳����˳�" << std::endl;
	}
};

#endif // !_SELECTOR_SCENE_H_
