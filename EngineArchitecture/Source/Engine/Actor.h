#pragma once

#include "Engine/Scene.h"
#include "Engine/Transform2D.h"
#include "Engine/Component.h"

#include <vector>

class RenderComponent;

enum class ActorState
{
	Active,
	Paused,
	Dead
};


class Actor
{
public:
	void SetScene(Scene* pScene);
	void AddComponent(Component* pComponent);
	void RemoveComponent(Component* pComponent);

	void SetActive(bool isActive);
	void Render(Renderer* pRenderer);

	virtual void SetupComponents() = 0;
	virtual void Start();
	virtual void Update();
	virtual void Destroy();

	Transform2D mTransform{};

private:
	Scene* mScene = nullptr;
	ActorState mState = ActorState::Active;
	std::vector<Component*> mComponentList{};
	std::vector<RenderComponent*> mRenderComponents{};
};




