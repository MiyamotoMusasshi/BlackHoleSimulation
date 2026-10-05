#pragma once

#include "../utils/utils.h"

#include <string>
#include <vector>

bool loadObjects(
    std::vector<Object> &objects,
    const std::string &filePath);

bool saveObjects(
    const std::vector<Object> &objects,
    const std::string &filePath);