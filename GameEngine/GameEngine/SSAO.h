//
//  SSAO.hpp
//  BezierCurve
//
//  Created by Yoon on 5/30/16.
//  Copyright © 2016 Chenxing Ouyang. All rights reserved.
//

#ifndef SSAO_h
#define SSAO_h

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include "OBJObject.h"


class SSAO{
private:
    //Linear Interpolation
    static GLfloat lerp(GLfloat a, GLfloat b, GLfloat f);

    
public:
    //Light Properties
    static glm::vec3 lightPos;
    static glm::vec3 lightColor;
    
    static GLuint ssaoFBO, ssaoBlurFBO;
    static GLuint gBuffer;
    static GLuint gPositionDepth, gNormal, gAlbedo;
    static GLuint rboDepth;
    static GLuint ssaoColorBuffer, ssaoColorBufferBlur;
    static GLuint noiseTexture;
    
    static std::vector<glm::vec3> ssaoKernel;
    
    static void bindSSAOLight(GLint ShaderProgram);
    static void bindSSAO(GLint ShaderProgram);
    static void setupLight(glm::vec3 light_Pos, glm::vec3 light_Color);
    static void setupGBuffer(int width, int height, int kernelSize = 64);
    
    
    static GLint SSAOShaderProgram;
    static GLint SSAOBlurShaderProgram;
    static GLint SSAOGeometryShaderProgram;
    static GLint SSAOLightingShaderProgram;
    

    // Create shaders and set up
    static void init(int width, int height);
    
    static void add_obj(OBJObject * obj);

    
    static void draw();
    
    // Delete the shaders
    static void delete_shaders();
};


#endif /* SSAO_hpp */

