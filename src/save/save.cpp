#include "save.h"

#include <nlohmann/json.hpp>

#include <fstream>
#include <iostream>

using json = nlohmann::json;

bool loadObjects(
    std::vector<Object> &objects,
    const std::string &filePath)
{
    std::ifstream file(filePath);

    if (!file.is_open())
    {
        std::cerr << "Could not open objects file: "
                  << filePath << std::endl;

        return false;
    }

    try
    {
        json data;

        file >> data;

        for (const auto &objectData : data["objects"])
        {
            Object object;

            object.name = objectData["name"];
            object.isBlackHole = objectData["isBlackHole"];

            object.mass = objectData["mass"];
            object.size = objectData["size"];

            object.x = objectData["x"];
            object.y = objectData["y"];

            object.velocityX = objectData["velocityX"];
            object.velocityY = objectData["velocityY"];

            object.isAlive = objectData["isAlive"];

            object.color = sf::Color::Black;

            objects.push_back(object);
        }
    }
    catch (const json::exception &error)
    {
        std::cerr << "JSON error while loading objects: "
                  << error.what() << std::endl;

        return false;
    }

    return true;
}

bool saveObjects(
    const std::vector<Object> &objects,
    const std::string &filePath)
{
    std::ofstream file(filePath);

    if (!file.is_open())
    {
        std::cerr << "Could not open objects file for writing: "
                  << filePath << std::endl;

        return false;
    }

    json data;

    data["objects"] = json::array();

    for (const Object &object : objects)
    {
        json objectData;

        objectData["name"] = object.name;
        objectData["isBlackHole"] = object.isBlackHole;

        objectData["mass"] = object.mass;
        objectData["size"] = object.size;

        objectData["x"] = object.x;
        objectData["y"] = object.y;

        objectData["velocityX"] = object.velocityX;
        objectData["velocityY"] = object.velocityY;

        objectData["isAlive"] = object.isAlive;

        data["objects"].push_back(objectData);
    }

    file << data.dump(4);

    return true;
}