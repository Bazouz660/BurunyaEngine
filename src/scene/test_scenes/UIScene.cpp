/*
** EPITECH PROJECT, 2022
** BurunyaEngine
** File description:
** UIScene.cpp
*/

#include "UIScene.hpp"
#include "ResourceManager.hpp"
#include "SceneManager.hpp"
#include "Clock.hpp"
#include "info.hpp"
#include "Button.hpp"
#include "Slider.hpp"
#include "Text.hpp"

namespace bya
{

    UIScene::UIScene()
    {
    }

    void UIScene::init()
    {
        sf::Vector2u winSize = info::getWindowSize();

        std::shared_ptr<ui::Button> button = std::make_shared<ui::Button>();
        button->setLabel("Hello");
        button->setPosition(sf::Vector2f(winSize.x / 2, winSize.y / 2));

        std::shared_ptr<ui::Slider> slider = std::make_shared<ui::Slider>();
        slider->setPosition(sf::Vector2f(winSize.x / 2, winSize.y / 2 + 200));

        std::shared_ptr<ui::Text> text = std::make_shared<ui::Text>("Hello");
        text->setPosition(sf::Vector2f(winSize.x / 2, winSize.y / 2 + 400));

        addUIelement("button", button);
        addUIelement("slider", slider);
        addUIelement("progress", text);
    }

    void UIScene::close()
    {
    }

    void UIScene::reset()
    {
    }

    UIScene::~UIScene()
    {
    }

    void UIScene::handleEvent(sf::Event &event, sf::RenderWindow &window)
    {
        for (auto &[key, elem] : m_UIelements)
            elem->handleEvent(event, window);
    }

    void UIScene::update(float dt)
    {
        auto slider = dynamic_cast<ui::Slider *>(m_UIelements["slider"].get());
        dynamic_cast<ui::Text *>(m_UIelements["progress"].get())->setString(std::to_string(slider->getProgress()));
    }

    void UIScene::render(sf::RenderTarget &target)
    {
        for (auto &[key, elem] : m_UIelements)
            elem->render(target);
    }

    void UIScene::addUIelement(const std::string& id, std::shared_ptr<ui::IUIelement> element)
    {
        m_UIelements.insert(std::make_pair(id, std::move(element)));
    }

}
