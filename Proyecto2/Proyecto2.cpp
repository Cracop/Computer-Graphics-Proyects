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


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void reflect(unsigned int vao, int toDraw,Shader ourShader, glm::mat4 transform);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));

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
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        reflect(VAOs[1], 12, ourShader,transform);

        //========Segundo Circulo pt1===============
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 1.0f, 0.0f, 0.0f, 1.0f);
        glBindVertexArray(VAOs[2]);
        glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
        reflect(VAOs[2], 18, ourShader, transform);
        
        //=========Segundo Circulo pt2==============
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 0.0980f, 0.0980f, 0.439f, 1.0f);
        glBindVertexArray(VAOs[3]);
        glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
        reflect(VAOs[3], 18, ourShader, transform);

        //================Centro====================
        transform = glm::mat4(1.0f);
        ourShader.setMat4("transform", transform);
        ourShader.setVec4("ourColor", 0.87f, 0.734f, 0.082f, 1.0f);
        glBindVertexArray(VAOs[4]);
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
        reflect(VAOs[4], 12, ourShader,transform);
        

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