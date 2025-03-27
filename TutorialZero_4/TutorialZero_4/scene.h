#ifndef _SCENE_H_
#define _SCENE_H_

#include <graphics.h>

class Scene
{
public:
	Scene() = default;
	~Scene() = default;

	virtual void OnEnter() { }
	virtual void OnUpdate(int delta) { }
	virtual void OnDraw() { }
	virtual void OnInput(const ExMessage& msg) { }
	virtual void OnExit() { }
private:

};
#endif // !_SCENE_H_
