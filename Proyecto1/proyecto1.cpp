#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader_s.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>

//Todo esto es para las matrices de transformacion
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void reflect(unsigned int vao, int toDraw,Shader ourShader, glm::mat4 transform);
void fase1(float timeProxy);

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
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Proyecto 1 Graficas", NULL, NULL);
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

    //Vertices de teselacion
    //Alan llena aqui
    float verticesTes[] = {
        0.0f,0.2f,0.0f, //D 0
        0.025f,0.1f,0.0f, //E 1
        0.0f,0.1f,0.0f, //J 2

        0.095f,0.16f,0.0f, //C 3
        0.07f,0.068f,0.0f, //F 4

        0.16f,0.1f,0.0f, //H 5
        0.1,0.025,0.0f, //G 6

        0.2f,0.0f,0.0f, //I 7
        0.1f,0.0f,0.0f, //K 8

        0.07f,0.26f,0.0f, //L 9
        0.2f,0.2f,0.0f, //M 10
        0.26f,0.07f,0.0f, //N 11

        0.0f,0.33f,0.0f, //O 12
        0.16f,0.29f,0.0f, //P 13
        0.29f,0.16f,0.0f, //Q 14
        0.33f,0.0f,0.0f, //R 15

        0.0f,0.0f,0.0f, //Cero 16


    };
    //vamos de adentro a afuera
    //centro amarillo
    unsigned int indicesCentro[] = {
        2,1,16,
        1,4,16,
        4,6,16,
        6,8,16
    };
    //triangulos amarillos primer cuadrante
    unsigned int indicesI[] = {
        0,1,2,
        1,3,4,
        4,5,6,
        6,7,8
    };
    //triangulos rojos
    unsigned int indicesR[] = {
         0,3,1,
         0,9,3,
         4,3,5,
         3,10,5,
         6,5,7,
         5,11,7
    };
    //triangulos azules claros
    unsigned int indicesA[] = {
        0,12,9,
        3,9,13,
        3,10,13,
        5,10,14,
        5,11,14,
        11,7,15
    };

 
 
    //Cuadrado en el centro que crece
    float verticesProta[] = {
        //positions             //texture
        -0.9f, 0.05f, 0.0f,     0.5f,1.0f,//1.0f,0.0f, //arriba-medio
        -0.927f,-0.05f,0.0f,    0.0f,0.0f, //abajo-izquierda
        -0.873f,-0.05f,0.0f,    1.0f,0.0f//0.5f,1.0f  //abajo-derecha
    };
    unsigned int indicesProta[] = {
        0,1,2,
    };


    //Creo los VAOs, VBOs y EBOs
    // ------------------------------------
    unsigned int VBOs[10], VAOs[10], EBOs[10];
    glGenVertexArrays(10, VAOs);
    glGenBuffers(10, VBOs);
    glGenBuffers(10, EBOs);

    //==========Triangulo Prota==================
    //Especial: este va a usar shaders con textura
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[0]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesProta), verticesProta, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[0]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesProta), indicesProta, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);


    //Para los CIRCULOS 
    //==========Primer Circulo==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[1]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTes), verticesTes, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesI), indicesI, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Segundo Circulo pt1==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[2]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTes), verticesTes, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesR), indicesR, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Segundo Circulo pt2==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[3]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTes), verticesTes, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[3]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesA), indicesA, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    //==========Centro==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[4]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTes), verticesTes, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[4]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesCentro), indicesCentro, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

 
    // Cargar textura para PROTA
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load("resources/textures/t.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);

    //Variables para animacion
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    int div = 1;
    int fase = 0;
    float inc = 0.01f;
    float scaleAmount = 1;

    //Shaders
    Shader ourShader("shaders/shader.vs", "shaders/shader.fs");
    Shader shaderTextura("shaders/texture.vs", "shaders/texture.fs");

    while (!glfwWindowShouldClose(window))
    {
        std::cout << "Fase: " << fase << "\n";
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;

        // Indicador de fases
        //Face cero: protagonista camina al centro
        float timeProxy = elapsed_seconds.count() / div;
        if (timeProxy >= 5.0 && timeProxy <= 10) {
            fase = 1; //Fade-in de primeras capas de teselacion
        }
        else if (timeProxy >=10 && timeProxy <=15) {
            fase = 2;  //Fade-in de ultimas caas de teselacioin
        }
        else if (timeProxy >=15 && timeProxy <= 20.0) {
            fase = 3; //Baile
        }
        else if (timeProxy >= 20.0 && timeProxy <=25.0) {
            fase = 4; //Fade out: teselacion se deshace, protagonista regresa
        }


        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        

        //CIRCULOS   
        ourShader.use();
        glm::mat4 transform = glm::mat4(1.0f);
        if (fase>=1) {
            //Color
            float greenValue = sin(glfwGetTime()) / 2.0f + 0.5f;
            ourShader.setVec4("ourColor", 0.87, greenValue, 0.0f, 1.0f);
            //Transformacion
            transform = glm::rotate(transform, (1) * (float)glfwGetTime() / div, glm::vec3(0.0f, 0.0f, 1.0f)); //

            scaleAmount = 1*sin(glfwGetTime());
            transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));

            ourShader.setMat4("transform", transform);
            // render container
            glBindVertexArray(VAOs[1]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
            //reflect
            reflect(VAOs[1], 12, ourShader,transform);

            //Color
            ourShader.setVec4("ourColor", 0.87, greenValue, 0.0f, 1.0f);
            //Transformacion
            transform = glm::mat4(1.0f);
            transform = glm::rotate(transform, (1) * (float)glfwGetTime() / div, glm::vec3(0.0f, 0.0f, 1.0f));

            scaleAmount = 1*sin(glfwGetTime());
            transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));

            ourShader.setMat4("transform", transform);
            // render container
            glBindVertexArray(VAOs[4]);
            glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
            reflect(VAOs[4], 12, ourShader,transform);
        }

        //Segundo Circulo pt1
        transform = glm::mat4(1.0f);
        if (fase>=2) {       
            //Color
            float redValue = sin(glfwGetTime()) / 4.0f + 0.75f;
            ourShader.setVec4("ourColor", redValue, 0.0f, 0.0f, 1.0f);
            //Transformacion
            transform = glm::rotate(transform, (1) * (float)glfwGetTime() / div, glm::vec3(0.0f, 0.0f, 1.0f));//

            scaleAmount = 1*sin(glfwGetTime());
            transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));

            ourShader.setMat4("transform", transform);
            // render container
            glBindVertexArray(VAOs[2]);
            glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);

            reflect(VAOs[2], 18, ourShader, transform);
            
        }

        //Segundo Circulo pt2
        transform = glm::mat4(1.0f);
        if (fase>=3) {
            //Color
            float blueValue = sin(glfwGetTime()) / 4.0f + 0.75f;
            ourShader.setVec4("ourColor", 0.0f, 0.0f, blueValue, 1.0f);
            //Transformacion
            transform = glm::rotate(transform, (-1) * (float)glfwGetTime() / div, glm::vec3(0.0f, 0.0f, 1.0f));

            scaleAmount = 1*sin(glfwGetTime());
            transform = glm::scale(transform, glm::vec3(scaleAmount, scaleAmount, scaleAmount));
            
            ourShader.setMat4("transform", transform);
            // render container
            glBindVertexArray(VAOs[3]);
            glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
            reflect(VAOs[3], 18, ourShader, transform);
        }
        //PROTA
        //Textura
       
        glBindTexture(GL_TEXTURE_2D, texture);
        shaderTextura.use();
        //Creo matriz identidad
        transform = glm::mat4(1.0f);

        // Creamos transformaciones dependiendo de la fase
        if (fase == 0) {
            transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(timeProxy / 5, 0.0f, 0.0f));
        }
        else {
            transform= transform = glm::mat4(1.0f);
            transform = glm::translate(transform, glm::vec3(0.9, -0.0f, 0.0f)); // switched the order 
        }

        shaderTextura.setMat4("transform", transform);
        glBindVertexArray(VAOs[0]);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

        glBindVertexArray(0);
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();


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

//Refleja a todos los cuadrantes
void reflect(unsigned int vao, int toDraw,Shader ourShader, glm::mat4 transform) {
    //glm::mat4 transform = glm::mat4(1.0f);
    //Transformacion (reflexion x)
    transform = glm::scale(transform, glm::vec3(1, -1, 1));
    ourShader.setMat4("transform", transform);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, toDraw, GL_UNSIGNED_INT, 0);
    //Transformacion (reflexion y)
    transform = glm::scale(transform, glm::vec3(-1, 1, 1));
    ourShader.setMat4("transform", transform);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, toDraw, GL_UNSIGNED_INT, 0);
    //Transformacion (reflexion x)
    transform = glm::scale(transform, glm::vec3(1, -1, 1));
    ourShader.setMat4("transform", transform);
    glBindVertexArray(vao);
    glDrawElements(GL_TRIANGLES, toDraw, GL_UNSIGNED_INT, 0);
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