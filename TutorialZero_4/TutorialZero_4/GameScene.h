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
		std::cout << "进入游戏场景" << std::endl;
	}
	void OnUpdate(int delta) override
	{
		std::cout << "游戏场景正在运行..." << std::endl;
	}
	void OnDraw() override
	{
		outtextxy(10, 10, _T("游戏场景绘制内容"));
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
		std::cout << "游戏场景退出" << std::endl;
	}
};

#endif // !_GAME_SCENE_H_
