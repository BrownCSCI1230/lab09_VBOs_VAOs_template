#include "glrenderer.h"
#include "debug.h"

#include <QCoreApplication>
#include "shaderloader.h"

GLRenderer::GLRenderer(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

void GLRenderer::finish()
{
    makeCurrent();

    // Task 19: Clean up your VBO and VAO memory here

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

    // Shader setup (DO NOT EDIT)
    m_shader = ShaderLoader::createShaderProgram(":/resources/shaders/default.vert", ":/resources/shaders/default.frag");

    // ================== Vertex Buffer Objects

    // Task 5: Generate a VBO here and store it in m_vbo

    // Task 6: Bind the VBO you created here

    // Task 8: Construct your std::vector of triangle data here | TASK 10: Add colors to your triangle here

    // Task 9: Pass the triangle vector into your VBO here

    // ================== Vertex Array Objects

    // Task 11: Generate a VAO here and store it in m_vao

    // Task 12: Bind the VAO you created here

    // Task 13: Add position and color attributes to your VAO here

    // Task 13: Verify your position and color attributes with our verifyVAO function

    // ================== Returning to Default State

    // Task 14: Unbind your VBO and VAO here
}

void GLRenderer::paintGL()
{
    // Task 15: Clear the screen here

    // Bind the shader
    glUseProgram(m_shader);

    // Task 16: Bind your VAO here

    // Task 17: Draw your VAO here

    // Task 18: Unbind your VAO here

    // Unbind the shader
    glUseProgram(0);
}

void GLRenderer::resizeGL(int w, int h) {}
