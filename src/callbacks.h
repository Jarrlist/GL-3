#include <stdio.h>


//#ifdef _DEBUG
static void write_log(const char* msg)
{
    FILE *fp;
	fp = fopen("log.txt", "w+");
    fprintf(fp, msg);
	fclose(fp);
}
//#else
//static void write_log(const char* msg)
//{
//}
//#endif



static void glfw_error_callback(int error, const char* description)
{
    write_log(description);
    fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}