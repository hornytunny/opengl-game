#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int g_window_size_x = 640;
int g_window_size_y = 480;

void glfwWindowSizeCallback(GLFWwindow* pWindow, int width, int height) {
    g_window_size_x = width;
    g_window_size_y = height;
    glViewport(0, 0, g_window_size_x, g_window_size_y);
}

void glfwKeyCallback(GLFWwindow* pWindow, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWindow, GL_TRUE);
    }
}

int main(void) {

    /* Initialize the library */
    if (!glfwInit()) {
        std::cerr << "Can`t init glwf" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // pointer to window
    GLFWwindow* pWindow;

    /* Create a windowed mode window and its OpenGL context */
    pWindow = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);

    if (!pWindow) {
        std::cerr << "Can`t create window!" << std::endl;;
        glfwTerminate();
        return -1;
    }

    glfwSetWindowSizeCallback(pWindow, glfwWindowSizeCallback);
    glfwSetKeyCallback(pWindow, glfwKeyCallback);
    /* Make the window's context current */
    glfwMakeContextCurrent(pWindow);
   
	
	if (!gladLoadGL()) {
		std::cerr << "Gl can`t load" << std::endl;;
	}
	
	std::cout << "OpenGL " << GLVersion.major << "." << GLVersion.minor << std::endl;
    std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "OpenGl version: " << glGetString(GL_VERSION) << std::endl;

	glClearColor(0, 1, 0, 1);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(pWindow)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(pWindow);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}