/*
** EPITECH PROJECT, 2022
** Graphics.cpp
** File description:
** Graphics
*/

#include "Graphics.hpp"

using namespace neo;

Graphics::Graphics(std::shared_ptr<MessageBus> messageBus) : Node(messageBus)
{
    std::cout << "Graphics module created" << std::endl;
    SetTraceLogLevel(LOG_NONE);
    InitWindow(600, 600, "Neo");
    SetTargetFPS(60);
    this->_functionTab = {
        std::bind(&Graphics::receivePos, this, std::placeholders::_1),
    };
}

Graphics::~Graphics()
{
    CloseWindow();
}

void Graphics::onNotify(Message message)
{
    Packet data = message.getData();
    int status = message.getStatus();

    if (status >= 0 && status < this->_functionTab.size())
        this->_functionTab[status](data);
    // from data, draw elements on screen
}

void Graphics::draw()
{
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("neo genesis evangelion 3.0 + 1.0", 100, 100, 20, LIGHTGRAY);
        DrawText(this->_text.c_str(), 100, 200, 20, LIGHTGRAY);
    EndDrawing();
}

void Graphics::receivePos(Packet data)
{
    data >> this->_text;
}
