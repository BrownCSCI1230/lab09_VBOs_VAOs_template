#include "glrenderer.h"

#include <QCoreApplication>
#include "CS1230Lib/shaderloader.h"

GLRenderer::GLRenderer(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void GLRenderer::finish()
{
    //TASK 19 Clean up you VBO and VAO memory here

    glDeleteProgram(m_shader);
    doneCurrent();
}

void GLRenderer::initializeGL()
{
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    fprintf(stdout, "Using GLEW %s\n", glewGetString(GLEW_VERSION));

    // TASK 4: Set the clear color here

    m_shader = ShaderLoader::createShaderProgram("Resources/Shaders/default.vert", "Resources/Shaders/default.frag"); //Shader setup (DO NOT EDIT)


    // Vertex Buffer Objects //

    // TASK 5: Generate a VBO here and store it in m_vbo

    // TASK 6: Bind the VBO you created here

    // TASK 7: Construct your std::vector of triangle data here | TASK 10: Add colors to your triangle here

    // TASK 8: Pass the triangle vector into your VBO here


    // Vertex Array Objects //

    // TASK 11: Generate a VAO here and store it in m_vao

    // TASK 12: Bind the VAO you created here

    // TASK 13: Add position and color attributes to your VAO here


    // Returning to Default State //

    //TASK 14: Unbind your VBO and VAO here
}

void GLRenderer::paintGL()
{
    //TASK 15: Clear the screen here

    glUseProgram(m_shader);

    //TASK 16: Bind your VAO here

    //TASK 17: Draw your VAO here

    //TASK 18: Unbind your VAO here

    glUseProgram(0);
}

void GLRenderer::resizeGL(int w, int h)
{

}
