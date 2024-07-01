#include "utils.hpp"

#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#include <cstdlib>
#include <fstream>
#include <iostream>

char* loadShaderSource(const char* filename) {
    const char* shadersPath = getenv("HAZE_SHADERS_PATH");
    char filePath[256];
    sprintf(filePath, "%s/%s", shadersPath, filename);

    std::ifstream file(filePath, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening the file.\n";
        return nullptr;
    }

    file.seekg(0, file.end);
    std::streamsize length = file.tellg();
    file.seekg(0, file.beg);

    char* buffer = new char[length + 1];

    if (file.read(buffer, length)) {
        buffer[length] = '\0';
        return buffer;
    } else {
        std::cerr << "Error reading the file.\n";
        delete[] buffer;
        return nullptr;
    }
}
