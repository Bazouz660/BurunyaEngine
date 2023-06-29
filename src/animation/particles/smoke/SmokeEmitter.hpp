/*
** EPITECH PROJECT, 2023
** BurunyaEngine
** File description:
** SmokeEmitter
*/

#pragma once

#include "AParticleEmitter.hpp"

namespace bya::effects {

    class SmokeEmitter : public AParticleEmitter {

        public:
            SmokeEmitter(sf::Texture& texture);
            ~SmokeEmitter() = default;

            void update(float dt) override;
            void draw(sf::RenderTarget &target) override;

            void setEjectForce(float mult);

        private:
            void addPart();

        private:
            sf::Texture& m_texture;
            sf::VertexArray m_va;
            float m_ejectForce;
    };

}