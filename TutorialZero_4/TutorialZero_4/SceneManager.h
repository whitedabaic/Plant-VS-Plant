#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "scene.h"

extern Scene* menuScene;
extern Scene* gameScene;
extern Scene* selectorScene;

class SceneManager
{
public:
	enum class SceneType
	{
		Menu = 0,
		Game,
		Selector
	};

public:
	SceneManager() = default;
	~SceneManager() = default;

	void SetCurrentScene(Scene* scene)
	{
		currentScene = scene;
		currentScene->OnEnter();
	}

	void SwitchTo(SceneType type)
	{
		if (currentScene)
		{
			currentScene->OnExit();
		}

		switch (type)
		{
		case SceneType::Menu:
			currentScene = menuScene;
			break;
		case SceneType::Game:
			currentScene = gameScene;
			break;
		case SceneType::Selector:
			currentScene = selectorScene;
			break;
		default:
			break;
		}
		currentScene->OnEnter();
	}

	void OnUpdate(int delta)
	{
		currentScene->OnUpdate(delta);
	}

	void OnDraw()
	{
		currentScene->OnDraw();
	}

	void OnInput(const ExMessage& msg)
	{
		currentScene->OnInput(msg);
	}

private:
	Scene* currentScene = nullptr;
};

#endif // !_SCENE_MANAGER_H_
