#include "Application.hpp"

/**
 * Main.cpp
 * The main entrypoint of the application
 */

Application app;

//this method is called before the update loop
void upload() {
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f
    };

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
}

//this method is called within the update loop
void render() {
    glDrawArrays(GL_TRIANGLES, 0, 3); 
}

int main(void)
{
    app.run(render, upload); //run the application and pass the render and upload methods
    return 0;
}