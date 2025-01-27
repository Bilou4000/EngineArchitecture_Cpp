#pragma once

#include "Scene.h"
#include "Transform/Transform2D.h"
#include "Component.h"

#include <vector>

class RenderComponent;

//All actor possible state
enum class ActorState
{
	Active,
	Paused,
	Dead
};


class Actor
{
public:
	//Functions
	void SetScene(Scene* pScene);
	void AddComponent(Component* pComponent);
	void RemoveComponent(Component* pComponent);

	void SetActive(bool isActive);
	void Render(Renderer* pRenderer);

	virtual void SetupComponents() = 0;
	virtual void Start();
	virtual void Update();
	virtual void Destroy();

	//Variables
	Transform2D mTransform{};

private:
	//Variables
	Scene* mScene = nullptr;
	ActorState mState = ActorState::Active;
	std::vector<Component*> mComponentList{};
	std::vector<RenderComponent*> mRenderComponents{};
};




