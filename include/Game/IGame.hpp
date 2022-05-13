/*
** EPITECH PROJECT, 2022
** Game.hpp
** File description:
** Game
*/

#ifndef IGAME_HPP
    #define IGAME_HPP

    #include "includes.hpp"

namespace neo
{
    class IGame
    {
        public:
            virtual ~IGame() = default;

            virtual void update() = 0;
    };
}

#endif // IGAME_HPP
