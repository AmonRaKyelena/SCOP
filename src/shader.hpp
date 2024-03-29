#pragma once

#include "include.hpp"

class Shader
{
private:
    Shader();
    

    unsigned int ID;

    const std::string readShaderFromFile(const char *fileShaderPath, std::ifstream &shaderFile);
    void createAndCompileShader(GLuint &shader, const char *shaderCode, std::string nameShader);
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();
    void use();

    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setId(const unsigned int id);

    const unsigned int getId() const;

};
