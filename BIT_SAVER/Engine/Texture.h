/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Texture.h
Purpose: Wrapper class for doodle::Image
Project: CS230
Author: Kevin Wright
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once

#include"TransformMatrix.h"  // display matrix
#include<GL/glew.h>
#include<string>
class Texture
{
    //friend class TextureManager;


public:
    Texture() = default;
    void Draw(math::TransformMatrix displayMatrix);
    void Draw(math::TransformMatrix displayMatrix, math::ivec2 texelPos, math::ivec2 frameSize);
    math::ivec2 GetSize();
    unsigned int GetPixel(math::ivec2 texel);
    void setup_texobj(std::string pathname);
    GLuint Get_texture();
private:
  //  Texture(const std::filesystem::path& filePath);
   // Texture(doodle::Image&& doodleImage);

    GLuint tex_obj;
};