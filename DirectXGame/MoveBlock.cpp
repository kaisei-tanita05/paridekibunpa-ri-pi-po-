#include "MoveBlock.h"

using namespace KamataEngine;

void MoveBlock::Initialize(Model* model, Camera* camera, const Vector3& pos) {

	model_ = model;
	camera_ = camera;

	worldTransform_.Initialize();
	worldTransform_.translation_ = pos;

	startX_ = pos.x;

	upData_ = new UpData();
}

void MoveBlock::Update() {

	Vector3 oldPos = worldTransform_.translation_;

	if (isRight_) {
		worldTransform_.translation_.x += speed_;

		if (worldTransform_.translation_.x >= startX_ + moveRange_) {
			isRight_ = false;
		}
	} else {
		worldTransform_.translation_.x -= speed_;

		if (worldTransform_.translation_.x <= startX_ - moveRange_) {
			isRight_ = true;
		}
	}

	// 今フレーム移動した量を保存
	move_.x = worldTransform_.translation_.x - oldPos.x;
	move_.y = worldTransform_.translation_.y - oldPos.y;
	move_.z = worldTransform_.translation_.z - oldPos.z;

	upData_->WorldTransformUpData(worldTransform_);
}

AABB MoveBlock::GetAABB() const {

	AABB aabb;

	Vector3 pos = worldTransform_.translation_;

	aabb.min = {pos.x - 0.5f, pos.y - 0.5f, pos.z - 0.5f};

	aabb.max = {pos.x + 0.5f, pos.y + 0.5f, pos.z + 0.5f};

	return aabb;
}

void MoveBlock::Draw() { model_->Draw(worldTransform_, *camera_); }