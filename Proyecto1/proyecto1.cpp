#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.h"

#include <iostream>

//Todo esto es para las matrices de transformacion
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//Todo esto es para medir el tiempo
#include <chrono>
#include <ctime> 

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // build and compile our shader program
    // ------------------------------------
    // Shader ourShader("shaders/shadertest.vs", "shaders/shadertest.fs"); // you can name your shader files however you like

    //Vertices
    // ------------------------------------
    float vertices1[] = {
        0.0f, 0.2f, 0.0f,//0

        -0.027f,0.1f,0.0f,//1
        0.027f,0.1f,0.0f,//2
        0.1f, 0.1723f,0.0f,//3

        0.07814f, 0.0714f,0.0f,//4
        0.2f, 0.0f, 0.0f,//5
        0.1f,-0.027f,0.0f,//6

        0.1f,0.027f,0.0f,//7
        0.173f,0.1f,0.0f,//8
        0.0745f, 0.272f,0.0f,//9

        0.2005f,0.195f,0.0f, //10
        0.273f,0.074f,0.0f,//11
        0.0f, 0.35f,0.0f,//12

        0.35f,0.0f,0.0f,//13
        0.175f,0.295f,0.0f,//14
        0.2973f,0.1739f,0.0f,//15

        0.106f,0.371f,0.0f,//16
        0.275f,0.27f,0.0f,//17
        0.3735f,0.104f,0.0f,//18
    };

    float verticesProta[] = {
        -0.9f, 0.05f, 0.0f,//0

        -0.927f,-0.05f,0.0f,//1
        -0.873f,-0.05f,0.0f,//2
        0.9f, 0.5f,0.0f,//3

        0.927f,-0.05f,0.0f,//4
        0.873f,-0.05f,0.0f,//5
    };

    

    //Indices
    // ------------------------------------

    unsigned int indicesProta[] = {  // note that we start from 0!
        0,1,2,
        3,4,5
        
    };

    //Circulo 1
    unsigned int indices1[] = {  // note that we start from 0!
        0,1,2,
        2,3,4,
        5,6,7,
        7,8,4,
    };

    //Circulo 2 parte 1
    unsigned int indices2[] = {  // note that we start from 0!
        0,2,3,
        4,3,8,
        7,8,5,
    };

    //Circulo 2 parte 2
    unsigned int indices3[] = {  // note that we start from 0!
        0,3,9,
        3,8,10,
        5,8,11,
    };

    //Circulo 3 parte 1
    unsigned int indices4[] = {  // note that we start from 0!
        9,3,10,
        8,10,11,
        12,9,0, 
        5,11,13,
    };

    //Circulo 3 parte 2
    unsigned int indices5[] = {  // note that we start from 0!
        14,9,10,
        10,11,15
    };

    
    //Creo los VAOs, VBOs y EBOs
    // ------------------------------------
    unsigned int VBOs[10], VAOs[10], EBOs[10];
    glGenVertexArrays(10, VAOs);
    glGenBuffers(10, VBOs);
    glGenBuffers(10, EBOs);

    //==========Triangulo Prota==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[0]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesProta), verticesProta, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesProta), indicesProta, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);


    //==========Primer Circulo==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[1]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Segundo Circulo pt1==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[2]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Segundo Circulo pt2==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[3]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Tercer Circulo pt1==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[4]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[4]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices4), indices4, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Tercer Circulo pt2==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[5]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[5]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[5]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices5), indices5, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    int div = 2;
    int fase = 0;

    Shader ourShader("shaders/shadertest.vs", "shaders/shadertest.fs"); //Modifico

    while (!glfwWindowShouldClose(window))
    {
        std::cout << "Fase: " << fase << "\n";
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;

        // Indicador de fases
        if((elapsed_seconds.count()/div)>0.9 && (elapsed_seconds.count()/div)<1.8){
            fase = 1;
        }else if((elapsed_seconds.count()/div)>1.8 && (elapsed_seconds.count()/div)<2.7){
            fase = 2;
        }else if((elapsed_seconds.count()/div)>2.7 && (elapsed_seconds.count()/div)<3.6){
            fase = 3;   
        }else if((elapsed_seconds.count()/div)>3.6 && (elapsed_seconds.count()/div)<4.5){
            fase = 4;   
        }else if((elapsed_seconds.count()/div)>4.5 && (elapsed_seconds.count()/div)<5.4){
            fase = 5;   
        }
        
        // input
        // -----
        processInput(window);
        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Creo matriz identidad
        glm::mat4 transform = glm::mat4(1.0f);

        //Acciones prota
        // Shader ourShader("shaders/shadertest.vs", "shaders/shadertest.fs"); //Modifico
        ourShader.use();

        // create transformations
        if(fase==0){
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(elapsed_seconds.count()/div, 0.0f, 0.0f));
        }else if(fase>0){
            transform = glm::translate(transform, glm::vec3(0.9, -0.0f, 0.0f)); // switched the order   
        }
        // get matrix's uniform location and set matrix
        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // render container
        glBindVertexArray(VAOs[0]);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        // //Primer circulo
        transform = glm::mat4(1.0f);
        if(0<fase){
            Shader ourShader("shaders/shadertest.vs", "shaders/shaderAmarillo.fs"); //Modifico
            ourShader.use();
            transform = glm::rotate(transform, (-1)*(float)glfwGetTime()/div, glm::vec3(0.0f, 0.0f, 1.0f));
            // get matrix's uniform location and set matrix
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            // render container
            glBindVertexArray(VAOs[1]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        }

        //Segundo Circulo pt1
        transform = glm::mat4(1.0f);
        if(1<fase){
            Shader ourShader("shaders/shadertest.vs", "shaders/shaderRojo.fs"); //Modifico
            ourShader.use();
            transform = glm::rotate(transform, (float)glfwGetTime()/div, glm::vec3(0.0f, 0.0f, 1.0f));
            // get matrix's uniform location and set matrix
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            // render container
            glBindVertexArray(VAOs[2]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        }

        //Segundo Circulo pt2
        transform = glm::mat4(1.0f);
        if(2<fase){
            Shader ourShader("shaders/shadertest.vs", "shaders/shaderRojo.fs"); //Modifico
            ourShader.use();
            transform = glm::rotate(transform, (-1)*(float)glfwGetTime()/div, glm::vec3(0.0f, 0.0f, 1.0f));
            // get matrix's uniform location and set matrix
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            // render container
            glBindVertexArray(VAOs[3]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        }

        //Tercer Circulo pt1
        transform = glm::mat4(1.0f);
        if(3<fase){
            Shader ourShader("shaders/shadertest.vs", "shaders/shaderMoradoClaro.fs"); //Modifico
            ourShader.use();
            transform = glm::rotate(transform, (float)glfwGetTime()/div, glm::vec3(0.0f, 0.0f, 1.0f));
            // get matrix's uniform location and set matrix
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            // render container
            glBindVertexArray(VAOs[4]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        }

        //Tercer Circulo pt2
        transform = glm::mat4(1.0f);
        if(4<fase){
            Shader ourShader("shaders/shadertest.vs", "shaders/shaderMoradoClaro.fs"); //Modifico
            ourShader.use();
            transform = glm::rotate(transform, (-1)*(float)glfwGetTime()/div, glm::vec3(0.0f, 0.0f, 1.0f));
            // get matrix's uniform location and set matrix
            unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
            glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
            // render container
            glBindVertexArray(VAOs[5]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        }

        // //Ejemplo de lo que tengo que hacer
        // // get matrix's uniform location and set matrix
        // ourShader.use();
        // // create transformations
        // glm::mat4 transform = glm::mat4(1.0f);
        // //transform = glm::rotate(transform, (-1)*(float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f)); // switched the order
        // transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f)); // switched the order 

        // // get matrix's uniform location and set matrix
        // unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        // glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // // render container
        // glBindVertexArray(VAO);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();

        // auto end = std::chrono::system_clock::now();
        // std::chrono::duration<double> elapsed_seconds = end-start;

        // std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, VAOs);
    glDeleteBuffers(1, VBOs);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
//g++ proyecto1.cpp glad.c -ldl -lglfw