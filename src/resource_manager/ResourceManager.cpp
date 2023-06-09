/*
** EPITECH PROJECT, 2023
** RPG3
** File description:
** ResourceManager
*/

#include <filesystem>
#include "ResourceManager.hpp"
#include "parsing.hpp"

namespace bya {

ResourceManager::ResourceManager()
{
    loadAssets();
}

void ResourceManager::loadAssets()
{
    // load default fonts
    loadFont("defaultFont", "asset/font/default/debug_font.ttf");

    // load game fonts
    loadFont("gameFont", "asset/font/game_font.ttf");

    // load default textures
    loadTexture("defaultButton", "asset/texture/default/button.png");
    loadTexture("defaultSliderWagon", "asset/texture/default/wagon.png");
    loadTexture("defaultSliderRail", "asset/texture/default/rail.png");

    // load game textures
    loadTexture("tileset", "asset/texture/tileset/dirt.png");

    // load effects textures
    loadTexture("smoke", "asset/texture/effect/smoke.png");
}

ResourceManager& ResourceManager::getInstance()
{
    static ResourceManager instance;
    return instance;
}

void ResourceManager::loadTexture(const std::string &name, const std::string &filename)
{
    // Create a new texture and load it from the specified file.
    sf::Texture texture;
    texture.loadFromFile(filename);

    std::cout << "Loaded texture as \"" << name << "\" from " << "\"" + filename + "\"" << std::endl;

    // Insert the texture into the map using the name as the key.
    m_textures[name] = texture;
    m_images[name] = texture.copyToImage();
}

sf::Texture& ResourceManager::getTexture(const std::string &name) {
    return m_textures.at(name);
}

sf::Image* ResourceManager::getTextureImage(const std::string &name)
{
    return &m_images.at(name);
}

void ResourceManager::loadTexturesFromFolder(const std::string& directory)
{
    for (const auto & entry : std::filesystem::directory_iterator(directory))
        loadTexture(removeExtension(entry.path().filename()), entry.path().string());
}


void ResourceManager::loadFont(const std::string& name,
const std::string& filePath)
{
    auto& font = m_fonts[name];
    if(!font.loadFromFile(filePath))
        throw std::runtime_error("Failed to load font: " + filePath);
    m_fonts[name] = font;
    std::cout << "Loaded font as \"" << name << "\" from " << "\"" + filePath + "\"" << std::endl;
}

sf::Font& ResourceManager::getFont(const std::string& fontName)
{
    if (m_fonts.count(fontName) == 0)
        m_fonts[fontName].loadFromFile(fontName);
    return m_fonts.at(fontName);
}

void ResourceManager::loadSoundBuffer(const std::string& name,
const std::string& fileName)
{
    sf::SoundBuffer soundBuffer;
    if (!soundBuffer.loadFromFile(fileName))
        throw std::runtime_error("Failed to load sound buffer: " + fileName);
    m_soundBuffers[name] = soundBuffer;
    std::cout << "Loaded font as \"" << name << "\" from " << "\"" + fileName + "\"" << std::endl;
}

sf::SoundBuffer* ResourceManager::getSoundBuffer(const std::string& name) {
    auto it = m_soundBuffers.find(name);
    if (it == m_soundBuffers.end())
        throw std::runtime_error("Sound buffer not found: " + name);
    return &m_soundBuffers.at(name);
}

}