#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "scene.h"

#include <iostream>

class GameScene : public Scene
{
public:
	GameScene() = default;
	~GameScene() = default;

	void OnEnter() override
	{
		std::cout << "������Ϸ����" << std::endl;
	}
	void OnUpdate(int delta) override
	{
		std::cout << "��Ϸ������������..." << std::endl;
	}
	void OnDraw() override
	{
		outtextxy(10, 10, _T("��Ϸ������������"));
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
		std::cout << "��Ϸ�����˳�" << std::endl;
	}
};

#endif // !_GAME_SCENE_H_
