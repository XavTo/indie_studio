/*
** EPITECH PROJECT, 2022
** MenuScene.cpp
** File description:
** MenuScene
*/

#include "MenuScene.hpp"

using namespace neo;

MenuScene::MenuScene()
{
    this->_objects.insert(std::make_pair(0, std::make_unique<GameObject>(0, "ressources/models/FloofFox.dae", (Vector2){1, 1})));
    this->_buttons.insert(std::make_pair(0, std::make_unique<GameObject>(0, "red", (Vector2){25, 10}, (Vector2){100, 50})));
}

MenuScene::~MenuScene()
{
    for (auto &object : this->_objects)
        object.second.reset();
    for (auto &button : this->_buttons)
        button.second.reset();
}

void MenuScene::update(std::shared_ptr<MessageBus> messageBus)
{
}

void MenuScene::loadScene(std::shared_ptr<MessageBus> messageBus)
{
    Packet packet;

    for (auto &object : this->_objects)
        packet << 0 << object.first << *object.second;
    for (auto &button : this->_buttons)
        packet << 2 <<  button.first << *button.second;
    messageBus->sendMessage(Message(packet, GraphicsCommand::LOAD, Module::GRAPHICS));
}

void MenuScene::handleKeyPressed(int playerNb, std::string action)
{
}

void MenuScene::handleKeyReleased(int playerNb, std::string action)
{
}
