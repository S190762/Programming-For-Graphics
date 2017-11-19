#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cstdio>

/**
 * Application.hpp
 * Class which defines an Application object, this class takes care of window creation
 * using the GLFW library. It also handles the main event loop.
 */

class Application {
public:
    void run(void(*r)(), void(*u)()) {
        initWindow();
        initOpenGL();
        setWindowTitle();
        render = r;
        upload = u;
        upload();
        mainLoop();
        cleanup();
    }
protected:
        GLFWwindow* _window;
        char version[256];
        void (*render)(); //function pointer for the render function
        void (*upload)(); //function pointer for the upload function
private:
    void initWindow() {
        glfwInit();

        //Enable 8x MSAA, set OpenGL version to 4.6 compatibility profile
        glfwWindowHint(GLFW_SAMPLES, 8);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); 

        _window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);

        //Center the window
        const GLFWvidmode * mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwSetWindowPos(_window, ((mode->width - 800) / 2), ((mode->height - 600) / 2));
    }
    void setWindowTitle() {
        //Set the window title so that it includes the GL Version
        sprintf(version, "Programming for Graphics OpenGL %s", glGetString(GL_VERSION));
        glfwSetWindowTitle(_window, version);
    }
    void initOpenGL() {
        //Set the opengl context and load GLAD
        glfwMakeContextCurrent(_window);
        gladLoadGL();
    }
    void mainLoop() {
        while (!glfwWindowShouldClose(_window)) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.5f, 0.2f, 0.8f, 1.0f);
            render();
            glfwSwapBuffers(_window);
            glfwPollEvents();
        }
    }
    void cleanup() {
        glfwDestroyWindow(_window);
        glfwTerminate();
    }
};