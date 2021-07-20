#include <stdio.h>
#include "../lib/glad/include/glad/glad.h"
//#include <glad/glad.h>
#include "../lib/glfw/include/GLFW/glfw3.h"

#include "callbacks.h"

int width, height;

int main()
{
  glfwSetErrorCallback(glfw_error_callback);
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  GLFWwindow* window = glfwCreateWindow(800, 600, "Title", NULL, NULL);
  glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  double time = glfwGetTime();
  glfwGetFramebufferSize(window, &width, &height);
  glViewport(0, 0, width, height);
  glfwSwapInterval(1);

  while(!glfwWindowShouldClose(window))
  {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}
