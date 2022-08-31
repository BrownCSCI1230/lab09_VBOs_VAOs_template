#ifndef GLRENDERER_H
#define GLRENDERER_H

#include "GL/glew.h"
#include <QOpenGLWidget>
#include "glm/glm.hpp"

class GLRenderer : public QOpenGLWidget
{
public:
    GLRenderer(QWidget *parent = nullptr);
    void finish();

protected:
    void initializeGL() override;   //Called once at the start of the program
    void paintGL() override;    //Called every frame in a loop
    void resizeGL(int width, int height) override;  //Called when window size changes

private:
    GLuint m_shader;    //Stores id for shader program
    GLuint m_vbo;   //Stores id for vbo
    GLuint m_vao;   //Stores id for vao
};

#endif // GLRENDERER_H
