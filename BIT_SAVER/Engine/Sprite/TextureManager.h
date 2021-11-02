#pragma once
#include <filesystem>
#include <map>
#include<GL/glew.h>
#include<glm/glm.hpp>
class Texture;
    struct texture_info
    {
        unsigned char* img;
        int width;
        int height;
        int col_chanel;
        GLuint tex_objhdl;
    };
    class TextureManager 
    {
    public:
        Texture* Load(const char* filePath);
        void Unload();
    private:
        
        std::map<std::string, Texture* > images;
    };
