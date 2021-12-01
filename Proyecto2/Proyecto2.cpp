#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "clases/shader.h"
// Cambiar entre "camera.h" y "cameraFPS.h"
#include "clases/camera.h"

#include <iostream>

// TODO:
// 1. calcular los vectores normales a los vertices (voy a tener que repetir vertices porque les toca diferentes normales).
// 2. agregar/modificar los indices para que los triangulos estén hechos counterclockwise.
// 3. modificar los shaders para que funcione la iluminación. 

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void reflect(unsigned int vao, int toDraw,Shader ourShader, glm::mat4 transform);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 5.0f));

float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
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
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // configure global opengl state
    // -----------------------------
    glEnable(GL_DEPTH_TEST);

    // build and compile our shader zprogram
    // ------------------------------------
    Shader ourShader("shaders/7.1.camera.vs", "shaders/uniform.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
  
//vamos de adentro a afuera
// Los el índice que me importa es el segundo num i.e. E 1 0 el indice es 0

// Ok tengo 
    //centro amarillo
    unsigned int indicesCentro[] = {
        1,0,5,
        0,2,5,
        2,3,5,
        3,4,5,

        7,6,11,
        6,8,11,
        8,9,11,
        9,10,11,

        0,1,6,
        6,7,1,
        0,2,6,
        6,8,2,
        2,3,8,
        8,9,3,
        3,4,9,
        9,10,4,

    };
    
    float verticesCentro[] = {
        0.025f,0.1f,-0.5f, //E 1 0
        0.0f,0.1f,-0.5f, //J 2 1
        0.07f,0.068f,-0.5f, //F 4 2
        0.1,0.025,-0.5f, //G 6 3 
        0.1f,0.0f,-0.5f, //K 8 4
        0.0f,0.0f,-0.5f, //Cero 16 5

        0.025f,0.1f,-0.4f, //E 1 6
        0.0f,0.1f,-0.4f, //J 2 7
        0.07f,0.068f,-0.4f, //F 4 8
        0.1,0.025,-0.4f, //G 6 9
        0.1f,0.0f,-0.4f, //K 8 10
        0.0f,0.0f,-0.4f, //Cero 16 11
    };
    
    //triangulos amarillos primer cuadrante 
    unsigned int indicesI[] = {  
        0,1,2,
        1,3,4,
        4,5,6,
        6,7,8,

        9,10,11,
        10,12,13,
        13,14,15,
        15,16,17,

        0,2,11,
        11,9,0,
        0,1,10,
        9,10,0,
        1,3,12,
        12,10,1,
        3,4,13,
        13,12,3,
        4,5,14,
        14,13,4,
        6,5,14,
        14,15,6,
        6,7,16,
        16,15,6,
        2,1,10,
        10,11,2,
        1,4,13,
        13,10,1,
        4,6,15,
        15,3,4,
        6,8,17,
        17,15,6
        
    };

    float verticesI[] = {
        0.0f,0.2f,-0.25f, //D 0 
        0.025f,0.1f,-0.25f, //E 1  
        0.0f,0.1f,-0.25f, //J 2 
        0.095f,0.16f,-0.25f, //C 3  
        0.07f,0.068f,-0.25f, //F 4
        0.16f,0.1f,-0.25f, //H 5
        0.1,0.025,-0.25f, //G 6 
        0.2f,0.0f,-0.25f, //I 7 
        0.1f,0.0f,-0.25f, //K 8

        0.0f,0.2f,-0.15f, //D 9 
        0.025f,0.1f,-0.15f, //E 10  
        0.0f,0.1f,-0.15f, //J 11 
        0.095f,0.16f,-0.15f, //C 12  
        0.07f,0.068f,-0.15f, //F 13
        0.16f,0.1f,-0.15f, //H 14
        0.1,0.025,-0.15f, //G 15 
        0.2f,0.0f,-0.15f, //I 16 
        0.1f,0.0f,-0.15f, //K 17
    };

    //triangulos rojos
    unsigned int indicesR[] = {
         0,2,1,
         0,7,2,
         3,2,4,
         2,8,4,
         5,4,6,
         4,9,6,

         10,12,11,
         10,17,12,
         13,12,14,
         12,18,14,
         15,14,16,
         14,19,16,

         0,1,11,
         11,10,0,
         1,2,11,
         11,12,2,
         2,3,13,
         13,12,2,
         3,4,14,
         14,13,3,
         4,5,15,
         15,14,4,
         5,6,16,
         16,15,5,
         6,9,19,
         19,16,6,
         9,4,14,
         14,19,9,
         4,8,18,
         18,14,4,
         8,2,12,
         12,18,8,
         2,7,17,
         17,12,2,
         7,0,10,
         10,17,7

        //  Checar bien esto cuando tenga luz para ver que onda
    };

    float verticesR[] = {
        0.0f,0.2f,0.25f, //D 0 0
        0.025f,0.1f,0.25f, //E 1 1 
        0.095f,0.16f,0.25f, //C 3 2
        0.07f,0.068f,0.25f, //F 4 3 
        0.16f,0.1f,0.25f, //H 5 4
        0.1,0.025,0.25f, //G 6 5 
        0.2f,0.0f,0.25f, //I 7 6
        0.07f,0.26f,0.25f, //L 9 7
        0.2f,0.2f,0.25f, //M 10 8  
        0.26f,0.07f,0.25f, //N 11 9

        0.0f,0.2f,0.35f, //D 0 10
        0.025f,0.1f,0.35f, //E 1 11 
        0.095f,0.16f,0.35f, //C 3 12
        0.07f,0.068f,0.35f, //F 4 13 
        0.16f,0.1f,0.35f, //H 5 14
        0.1,0.025,0.35f, //G 6 15 
        0.2f,0.0f,0.35f, //I 7 16
        0.07f,0.26f,0.35f, //L 9 17
        0.2f,0.2f,0.35f, //M 10 18  
        0.26f,0.07f,0.35f, //N 11 19

    };
        
    //triangulos azules 
    unsigned int indicesA[] = {
        0,7,4,
        1,4,8,
        1,5,8,
        2,5,9,
        2,6,9,
        6,3,10,

        11,18,15,
        12,15,19,
        12,16,19,
        13,16,20,
        13,17,20,
        17,14,21,

        0,4,15,
        15,11,0,
        4,1,12,
        12,15,4,
        1,5,16,
        16,12,1,
        5,2,13,
        13,16,5,
        2,6,17,
        17,13,2,
        6,3,14,
        14,17,6,
        10,6,17,
        17,21,10,
        6,9,20,
        20,17,6,
        9,5,16,
        16,20,9,
        5,8,19,
        19,16,5,
        8,4,15,
        15,19,8,
        4,7,18,
        18,15,4

        // Yep, necesito iluminación para distinguir
        
    };

    float verticesA[] = {
        0.0f,0.2f,0.0f, //D 0 0
        0.095f,0.16f,0.0f, //C 3 1
        0.16f,0.1f,0.0f, //H 5 2
        0.2f,0.0f,0.0f, //I 7 3 
        0.07f,0.26f,0.0f, //L 9 4
        0.2f,0.2f,0.0f, //M 10 5
        0.26f,0.07f,0.0f, //N 11 6 
        0.0f,0.33f,0.0f, //O 12 7 
        0.16f,0.29f,0.0f, //P 13 8
        0.29f,0.16f,0.0f, //Q 14 9 
        0.33f,0.0f,0.0f, //R 15 10

        0.0f,0.2f,0.1f, //D 0 11
        0.095f,0.16f,0.1f, //C 3 12
        0.16f,0.1f,0.1f, //H 5 13
        0.2f,0.0f,0.1f, //I 7 14 
        0.07f,0.26f,0.1f, //L 9 15
        0.2f,0.2f,0.1f, //M 10 16
        0.26f,0.07f,0.1f, //N 11 17 
        0.0f,0.33f,0.1f, //O 12 18 
        0.16f,0.29f,0.1f, //P 13 19
        0.29f,0.16f,0.1f, //Q 14 20 
        0.33f,0.0f,0.1f, //R 15 21
    };


    //Creo los VAOs, VBOs y EBOs
    // ------------------------------------
    unsigned int VBOs[10], VAOs[10], EBOs[10];
    glGenVertexArrays(10, VAOs);
    glGenBuffers(10, VBOs);
    glGenBuffers(10, EBOs);

    //Para los CIRCULOS 
    //==========Primer Circulo==================
    // 1. bind Vertex Array Object
    glBindVertexArray(VAOs[1]);
    // 2. copy our vertices array in a vertex buffer for OpenGL to use
    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesI), verticesI, GL_STATIC_DRAW);
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesR), verticesR, GL_STATIC_DRAW);
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesA), verticesA, GL_STATIC_DRAW);
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
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesCentro), verticesCentro, GL_STATIC_DRAW);
    // 3. copy our index array in a element buffer for OpenGL to use
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[4]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesCentro), indicesCentro, GL_STATIC_DRAW);
    // 4. then set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    ourShader.use();
    
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 

        // activate shader
        ourShader.use();

        // pass projection matrix to shader (note that in this case it could change every frame)
        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        ourShader.setMat4("projection", projection);

        // camera/view transformation
        glm::mat4 view = camera.GetViewMatrix();
        ourShader.setMat4("view", view);

        glm::mat4 transform;

        //==========Primer Circulo==================
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 0.87f, 0.734f, 0.082f, 1.0f);
        glBindVertexArray(VAOs[1]);
        glDrawElements(GL_TRIANGLES, 90, GL_UNSIGNED_INT, 0);
        reflect(VAOs[1], 100, ourShader,transform);

        //========Segundo Circulo pt1===============
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 1.0f, 0.0f, 0.0f, 1.0f);
        glBindVertexArray(VAOs[2]);
        glDrawElements(GL_TRIANGLES, 120, GL_UNSIGNED_INT, 0);
        reflect(VAOs[2], 120, ourShader, transform);
        
        //=========Segundo Circulo pt2==============
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 0.0980f, 0.0980f, 0.439f, 1.0f);
        glBindVertexArray(VAOs[3]);
        glDrawElements(GL_TRIANGLES, 120, GL_UNSIGNED_INT, 0);
        reflect(VAOs[3], 120, ourShader, transform);

        //================Centro====================
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 0.87f, 0.734f, 0.082f, 1.0f);
        glBindVertexArray(VAOs[4]);
        glDrawElements(GL_TRIANGLES, 48, GL_UNSIGNED_INT, 0);
        reflect(VAOs[4], 48, ourShader,transform);
        

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(10, VAOs);
    glDeleteBuffers(10, VBOs);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
    }

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
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

//g++ 7.4.camera.cpp glad.c -ldl -lglfw