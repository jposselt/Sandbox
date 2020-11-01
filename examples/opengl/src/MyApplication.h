/**
 * MyApplication.h
 */

#ifndef OPENGL_CMAKE_MYAPPLICATION_H
#define OPENGL_CMAKE_MYAPPLICATION_H

#include "Application.h"
#include "Shader.h"

class MyApplication : public Application {
 public:
  MyApplication();

 protected:
  virtual void loop();

 private:
  float time = 0.f;
  const int size = 100;

  // shader
  Shader vertexShader;
  Shader fragmentShader;
  ShaderProgram shaderProgram;

  // shader matrix uniform
  glm::mat4 projection = glm::mat4(1.0);
  glm::mat4 view = glm::mat4(1.0);

  // VBO/VAO/ibo
  GLuint vao, vbo, ibo;
};

#endif  // OPENGL_CMAKE_MYAPPLICATION_H
