#include "glrenderer.h"

#include <QCoreApplication>
#include "shaderloader.h"

GLRenderer::GLRenderer(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void GLRenderer::finish()
{
    makeCurrent();
    // Task 19: Clean up you VBO and VAO memory here

    glDeleteProgram(m_shader);
    doneCurrent();
}

void GLRenderer::initializeGL()
{
    // Initializes the GLEW library/provides access to OpenGL functions
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (GLEW_OK != err) fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    fprintf(stdout, "Using GLEW %s\n", glewGetString(GLEW_VERSION));

    glViewport(0, 0, size().width(), size().height()); // Tells your computer the size of the screen it will draw to

    // Task 4: Set the clear color here

    m_shader = ShaderLoader::createShaderProgram("Resources/Shaders/default.vert", "Resources/Shaders/default.frag"); // Shader setup (DO NOT EDIT)


    // Vertex Buffer Objects //

    // Task 5: Generate a VBO here and store it in m_vbo

    // Task 6: Bind the VBO you created here

    // Task 8: Construct your std::vector of triangle data here | TASK 10: Add colors to your triangle here

    // Task 9: Pass the triangle vector into your VBO here


    // Vertex Array Objects //

    // Task 11: Generate a VAO here and store it in m_vao

    // Task 12: Bind the VAO you created here

    // Task 13: Add position and color attributes to your VAO here


    // Returning to Default State //

    // Task 14: Unbind your VBO and VAO here
}

void GLRenderer::paintGL()
{
    // Task 15: Clear the screen here

    glUseProgram(m_shader);

    // Task 16: Bind your VAO here

    // Task 17: Draw your VAO here

    // Task 18: Unbind your VAO here

    glUseProgram(0);
}

void GLRenderer::resizeGL(int w, int h)
{

}
