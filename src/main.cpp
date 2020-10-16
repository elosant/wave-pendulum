#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

void on_framebuffer_resize(GLFWwindow* window, int width, int height);
void proc_input(GLFWwindow* window);

constexpr unsigned int SCR_HEIGHT = 800;
constexpr unsigned int SCR_WIDTH = 600;

int main(int argc, char **argv)
{
	// Init glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create window, terminate if unsuccessful
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Pendulum Wave", NULL, NULL);
	if (window == NULL) {
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return EXIT_FAILURE;
	}
	glfwMakeContextCurrent(window);

	// Init glew to manage opengl function pointers
	glewInit();

	glfwSetFramebufferSizeCallback(window, on_framebuffer_resize);

	// Render loop
	while (!glfwWindowShouldClose(window))
	{
		proc_input(window);

		glClearColor(0.2, 0.3, 0.3, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return EXIT_SUCCESS;
}

void on_framebuffer_resize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void proc_input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
