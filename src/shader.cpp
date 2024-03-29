#include "shader.hpp"

Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
	std::string	vertexCode;
	std::string	fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{	
		vertexCode = readShaderFromFile(vertexPath, vShaderFile);
		fragmentCode = readShaderFromFile(fragmentPath, fShaderFile);
	}
	catch(std::ifstream::failure &e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
	}

	const char *vShaderCode = vertexCode.c_str();
	const char *fShaderCode = fragmentCode.c_str();

	GLuint vertex, fragment;
	createAndCompileShader(vertex, vShaderCode, "vertex");
	createAndCompileShader(fragment, fShaderCode, "fragment");

	int success;
	char infoLog[512];
	this->ID = glCreateProgram();
	glAttachShader(this->ID, vertex);
	glAttachShader(this->ID, fragment);
	glLinkProgram(this->ID);

	glGetProgramiv(this->ID, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void Shader::createAndCompileShader(GLuint &shader, const char *shaderCode, std::string nameShader)
{
	int success;
	char infoLog[512];

	if(nameShader == "vertex")
		shader = glCreateShader(GL_VERTEX_SHADER);
	else if(nameShader == "fragment")
		shader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(shader, 1, &shaderCode, NULL);
	glCompileShader(shader);

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

const std::string Shader::readShaderFromFile(const char *fileShaderPath, std::ifstream &shaderFile)
{
	shaderFile.open(fileShaderPath);
	std::stringstream shaderStream;
	shaderStream << shaderFile.rdbuf();
	shaderFile.close();
	return shaderStream.str();
}

void Shader::use()
{
	glUseProgram(this->ID);
}

void Shader::setBool(const std::string &name, bool value) const
{         
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), (int)value); 
}
void Shader::setInt(const std::string &name, int value) const
{ 
    glUniform1i(glGetUniformLocation(this->ID, name.c_str()), value); 
}
void Shader::setFloat(const std::string &name, float value) const
{ 
    glUniform1f(glGetUniformLocation(this->ID, name.c_str()), value); 
}

const unsigned int Shader::getId() const
{
	return this->ID;
}


Shader::~Shader()
{

}