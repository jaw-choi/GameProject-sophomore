/*--------------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior
written consent of DigiPen Institute of Technology is prohibited.
File Name: Texture.h
Purpose: Wrapper class for doodle::Image
Project: BIT_SAVER
Author: 
Creation date: 2/11/2021
-----------------------------------------------------------------*/
#pragma once
#include<GL/glew.h>
#include<string>
#include<glm/glm.hpp>
#include<map>
class Texture
{
public:
    Texture() = default;
    void Draw(glm::mat3 displayMatrix,std::string mdl_name, std::string shdr_name);
    void Draw(double world_range, std::string mdl_name, std::string shdr_name, glm::vec2 pos, glm::vec2 scale = { 1,1 }, glm::vec2 rotate = { 0,0 });
    glm::vec2 GetSize();
    void setup_texobj(const char* pathname);

private:
    GLuint tex_obj{ 0 };
    glm::vec2 texture_size{ 0,0 };

};
