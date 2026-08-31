#pragma once
#include "UpData.h"
#include <KamataEngine.h>

class MoveBlock {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& pos);

	void Update();

	void Draw();

	KamataEngine::Vector3 GetPosition() const { return worldTransform_.translation_; }

	AABB GetAABB() const;

	KamataEngine::Vector3 GetMove() const { return move_; }

private:
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Model* model_ = nullptr;

	KamataEngine::Camera* camera_ = nullptr;

	float speed_ = 0.03f;
	float moveRange_ = 3.0f;

	float startX_;

	bool isRight_ = true;
	UpData* upData_ = nullptr;

	KamataEngine::Vector3 move_ = {0.0f, 0.0f, 0.0f};
};