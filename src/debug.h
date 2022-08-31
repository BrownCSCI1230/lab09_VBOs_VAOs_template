#pragma once
#include <GL/glew.h>
#include <iostream>

namespace Debug
{
    // TASK 2: Add file name and line number parameters
    inline void glErrorCheck(){
        GLenum error = glGetError();
        while(error != GL_NO_ERROR){
            // Task 2: Edit this print statement to be more descriptive
            std::cout<<error<<std::endl;
            error = glGetError();
        }
    }

    // TASK 3: Add a preprocessor directive to automate the writing of this function
}
