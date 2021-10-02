/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: GameObject.cpp
Project: CS230
Author: Hyosang Jung
Creation date: 4/16/2021
-----------------------------------------------------------------*/
#include"GameObject.h"

GameObject::GameObject(glm::vec2 position) : GameObject(position, 0, { 1, 1 }) {}

GameObject::GameObject(glm::vec2 position, double rotation, glm::vec2 scale)
    : velocity{ 0,0 }, position(position), updateMatrix(true),
    scale(scale), rotation(rotation), currState(&state_nothing) {
}

void GameObject::Update(double dt)
{
    //currState->Update(this, dt);
    ////sprite.Update(dt);
    //if (velocity.x != 0 || velocity.y != 0)
    //{
    //    UpdatePosition({ velocity.x * dt, velocity.y * dt });
    //}
    //currState->TestForExit(this);
}

void GameObject::Draw() 
{
    //sprite.Draw(cameraMatrix * GetMatrix());
}

const math::TransformMatrix& GameObject::GetMatrix()
{
    if (updateMatrix == true) 
    {
        objectMatrix = math::TranslateMatrix(position) * math::RotateMatrix(rotation) * math::ScaleMatrix(scale);
        updateMatrix = false;
    }
    return objectMatrix;
}

void GameObject::SetPosition(glm::vec2 newPosition) {
    position = newPosition;
    updateMatrix = true;
}

void GameObject::SetVelocity(glm::vec2 newVelocity) {
    velocity = newVelocity;
}

void GameObject::UpdatePosition(glm::vec2 adjustPosition) {
    position += adjustPosition;
    updateMatrix = true;
}

const glm::vec2& GameObject::GetPosition() const { return position; }

const glm::vec2& GameObject::GetVelocity() const
{
    return velocity;
}

const glm::vec2& GameObject::GetScale() const
{
    return scale;
}

double GameObject::GetRotation() const
{
    return rotation;
}

void GameObject::UpdateVelocity(glm::vec2 adjustPosition)
{
    velocity += adjustPosition;
}

void GameObject::SetScale(glm::vec2 newScale)
{
    scale = newScale;
    updateMatrix = true;
}

void GameObject::SetRotation(double newRotationAmount)
{
    rotation = newRotationAmount;
    updateMatrix = true;
}

void GameObject::UpdateRotation(double newRotationAmount)
{
    rotation += newRotationAmount;
    updateMatrix = true;
}

void GameObject::ChangeState(State* newState) {
    currState = newState;
    currState->Enter(this);
}