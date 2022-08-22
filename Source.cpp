#include <iostream>             // cout, cerr
#include <cstdlib>              // EXIT_FAILURE
#include <GL/glew.h>            // GLEW library
#include <GLFW/glfw3.h>         // GLFW library
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"       // Image loading Utility functions
#include <corecrt_math_defines.h>
#include <cmath>


// GLM Math Header inclusions
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnOpengl/camera.h> // Camera class

using namespace std; // Standard namespace

/*Shader program Macro*/
#ifndef GLSL
#define GLSL(Version, Source) "#version " #Version " core \n" #Source
#endif

// Unnamed namespace
namespace
{
    const char* const WINDOW_TITLE = "3D-Project"; // Macro for window title

    // Variables for window width and height
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    // Stores the GL data relative to a given mesh
    struct GLMesh
    {
        GLuint planeVAO;
        GLuint planeVBO;
        GLuint nPlaneVertices;

        GLuint creeperVAO;
        GLuint creeperVBO;
        GLuint nCreeperVertices;

        GLuint creepertVAO;
        GLuint creepertVBO;
        GLuint nCreepertVertices;

        GLuint creeperlVAO;
        GLuint creeperlVBO;
        GLuint nCreeperlVertices;

        GLuint creeperl2VAO;
        GLuint creeperl2VBO;
        GLuint nCreeperl2Vertices;

        GLuint creeperl3VAO;
        GLuint creeperl3VBO;
        GLuint nCreeperl3Vertices;

        GLuint creeperl4VAO;
        GLuint creeperl4VBO;
        GLuint nCreeperl4Vertices;

        GLuint creeperStVAO;
        GLuint creeperStVBO;
        GLuint nCreeperStVertices;


        GLuint nintendoVAO;
        GLuint nintendoVBO;
        GLuint nNintendoVertices;

        GLuint VAO2;
        GLuint VBO2;
        GLuint nPokeballVertices;

        GLuint coinVAO;
        GLuint coinVBO;
        GLuint nCoinVertices;

        GLuint pencilVAO;
        GLuint pencilVBO;
        GLuint nPencilVertices;

        GLuint eraserVAO;
        GLuint eraserVBO;
        GLuint nEraserVertices;

        GLuint screenVAO;
        GLuint screenVBO;
        GLuint nScreenVertices;

        GLuint tipVAO;
        GLuint tipVBO;
        GLuint nTipVertices;

        GLuint airpodsVAO;
        GLuint airpodsVBO;
        GLuint nAirpodsVertices;

        GLuint bindingVAO;
        GLuint bindingVBO;
        GLuint nBindingVertices;

        GLuint buttonVAO;
        GLuint buttonVBO;
        GLuint nButtonVertices;

        GLuint button2VAO;
        GLuint button2VBO;
        GLuint nButton2Vertices;   

        GLuint button3VAO;
        GLuint button3VBO;
        GLuint nButton3Vertices; 

        GLuint button4VAO;
        GLuint button4VBO;
        GLuint nButton4Vertices;  

        GLuint button5VAO;
        GLuint button5VBO;
        GLuint nButton5Vertices; 

        GLuint button6VAO;
        GLuint button6VBO;
        GLuint nButton6Vertices;   

        GLuint button7VAO;
        GLuint button7VBO;
        GLuint nButton7Vertices;   

        GLuint button8VAO;
        GLuint button8VBO;
        GLuint nButton8Vertices;   

        GLuint button9VAO;
        GLuint button9VBO;
        GLuint nButton9Vertices;    

        GLuint button1VAO;
        GLuint button1VBO;
        GLuint nButton1Vertices;     

        GLuint button0VAO;
        GLuint button0VBO;
        GLuint nButton0Vertices;

        GLuint buttonnVAO;
        GLuint buttonnVBO;
        GLuint nButtonnVertices;

    };

    // Main GLFW window
    GLFWwindow* gWindow = nullptr;
    // Triangle mesh data
    GLMesh gMesh;
    // Texture id
    GLuint gTextureIdDesk;
    GLuint gTextureIdCreeperSkin;
    GLuint gTextureIdBlock;
    GLuint gTextureIdFace;
    bool gIsFaceOn = true;
    GLuint gTextureIdNintendo;
    GLuint gTextureIdGray;
    GLuint gTextureIdLightg;
    GLuint gTextureIdTip;
    GLuint gTextureIdScreen;
    GLuint gTextureIdCoin;
    GLuint gTextureIdBt;
    // Shader program
    GLuint gProgramId;

    // camera
    Camera gCamera(glm::vec3(0.0f, 0.0f, 3.0f));
    float gLastX = WINDOW_WIDTH / 2.0f;
    float gLastY = WINDOW_HEIGHT / 2.0f;
    bool gFirstMouse = true;

    float angle = 0.0f;
    bool increaseAngle = true;
    bool ortho = false;

    // timing
    float gDeltaTime = 0.0f; // time between current frame and last frame
    float gLastFrame = 0.0f;

}

/* User-defined Function prototypes to:
 * initialize the program, set the window size,
 * redraw graphics on the window when resized,
 * and render graphics on the screen
 */
bool UInitialize(int, char* [], GLFWwindow** window);
void UResizeWindow(GLFWwindow* window, int width, int height);
void UProcessInput(GLFWwindow* window);
void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos);
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void UCreateMesh(GLMesh& mesh);
void UCreateTexturedMesh(GLMesh& mesh);
void UDestroyMesh(GLMesh& mesh);
bool UCreateTexture(const char* filename, GLuint& textureId);
void UDestroyTexture(GLuint textureId);
void URender();
bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId);
void UDestroyShaderProgram(GLuint programId);


/* Vertex Shader Source Code*/
const GLchar* vertexShaderSource = GLSL(440,
    layout(location = 0) in vec3 position;
    layout(location = 2) in vec2 textureCoordinate;

    out vec2 vertexTextureCoordinate;
    

//Global variables for the transform matrices
    uniform mat4 model;
    uniform mat4 view;
    uniform mat4 projection;

    void main()
    {
        gl_Position = projection * view * model * vec4(position, 1.0f); // transforms vertices to clip coordinates
        vertexTextureCoordinate = textureCoordinate;
    }
);

/* Fragment Shader Source Code*/
const GLchar* fragmentShaderSource = GLSL(440,
    in vec2 vertexTextureCoordinate;

    out vec4 fragmentColor;

    uniform sampler2D uTexture;
    uniform sampler2D uTextureExtra;
    uniform bool multipleTextures;

void main()
{
    fragmentColor = texture(uTexture, vertexTextureCoordinate);
    if (multipleTextures)
    {
        vec4 extraTexture = texture(uTextureExtra, vertexTextureCoordinate);
        if (extraTexture.a != 0.0)
            fragmentColor = extraTexture;
    }
}
);

void flipImageVertically(unsigned char* image, int width, int height, int channels)
{
    for (int j = 0; j < height / 2; ++j)
    {
        int index1 = j * width * channels;
        int index2 = (height - 1 - j) * width * channels;

        for (int i = width * channels; i > 0; --i)
        {
            unsigned char tmp = image[index1];
            image[index1] = image[index2];
            image[index2] = tmp;
            ++index1;
            ++index2;
        }
    }
}

int main(int argc, char* argv[])
{
    if (!UInitialize(argc, argv, &gWindow))
        return EXIT_FAILURE;

    // Create the mesh
    UCreateTexturedMesh(gMesh);

    // Create the shader program
    if (!UCreateShaderProgram(vertexShaderSource, fragmentShaderSource, gProgramId))
        return EXIT_FAILURE;

    // Load textures
    const char* texFilename = "resources/textures/desk2.png";
    if (!UCreateTexture(texFilename, gTextureIdDesk))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/creeperskin.png";
    if (!UCreateTexture(texFilename, gTextureIdCreeperSkin))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/minecraftF.png";
    if (!UCreateTexture(texFilename, gTextureIdFace))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/block.png";
    if (!UCreateTexture(texFilename, gTextureIdBlock))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/pokemon.png";
    if (!UCreateTexture(texFilename, gTextureIdNintendo))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/pencilT.png";
    if (!UCreateTexture(texFilename, gTextureIdGray))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/greyy.png";
    if (!UCreateTexture(texFilename, gTextureIdLightg))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/dark-grey.png";
    if (!UCreateTexture(texFilename, gTextureIdTip))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/nintendo.png";
    if (!UCreateTexture(texFilename, gTextureIdScreen))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/goldy.png";
    if (!UCreateTexture(texFilename, gTextureIdCoin))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }
    texFilename = "resources/textures/goldy.png";
    if (!UCreateTexture(texFilename, gTextureIdBt))
    {
        cout << "Failed to load texture " << texFilename << endl;
        return EXIT_FAILURE;
    }

    // Tell OpenGL for each sampler which texture unit it belongs to (only has to be done once).
    glUseProgram(gProgramId);
    // We set the texture as texture unit 0.
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureDesk"), 0);
    // We set the texture as texture unit 1.
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureCreeperSkin"), 1);
    // We set the texture as texture unit 2
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureExtra"), 2);
    // We set the texture as texture unit 3
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureBlock"), 3);
    // We set the texture as texture unit 4
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureNintendo"), 4);
    // We set the texture as texture unit 5
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureGray"), 5);
    // We set the texture as texture unit 6
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureLightG"), 6);
    // We set the texture as texture unit 7
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureCoin"), 7);
    // We set the texture as texture unit 8
    glUniform1i(glGetUniformLocation(gProgramId, "uTextureBt"), 8);

    // Sets the background color of the window to black (it will be implicitely used by glClear)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(gWindow))
    {
        // per-frame timing
        // --------------------
        float currentFrame = glfwGetTime();
        gDeltaTime = currentFrame - gLastFrame;
        gLastFrame = currentFrame;

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
        gluPerspective(100, (double)WINDOW_WIDTH / (double)WINDOW_HEIGHT, 0.1, 100);

        glMatrixMode(GL_MODELVIEW_MATRIX);
        glTranslatef(0, 0, -5);

        // input
        // -----
        UProcessInput(gWindow);

        // Render this frame
        URender();

        glfwPollEvents();
    }

    // Release mesh data
    UDestroyMesh(gMesh);

    // Release mesh data
    UDestroyTexture(gTextureIdDesk);
    UDestroyTexture(gTextureIdCreeperSkin);
    UDestroyTexture(gTextureIdFace);
    UDestroyTexture(gTextureIdBlock);
    UDestroyTexture(gTextureIdNintendo);
    UDestroyTexture(gTextureIdGray);
    UDestroyTexture(gTextureIdLightg);
    UDestroyTexture(gTextureIdTip);
    UDestroyTexture(gTextureIdScreen);
    UDestroyTexture(gTextureIdCoin);
    UDestroyTexture(gTextureIdBt);
    // Release shader program
    UDestroyShaderProgram(gProgramId);

    exit(EXIT_SUCCESS); // Terminates the program successfully
}


// Initialize GLFW, GLEW, and create a window
bool UInitialize(int argc, char* argv[], GLFWwindow** window)
{
    // GLFW: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // GLFW: window creation
    // ---------------------
    * window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (*window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(*window);
    glfwSetFramebufferSizeCallback(*window, UResizeWindow);
    glfwSetCursorPosCallback(*window, UMousePositionCallback);
    glfwSetScrollCallback(*window, UMouseScrollCallback);
    glfwSetMouseButtonCallback(*window, UMouseButtonCallback);

    // tell GLFW to capture our mouse
    glfwSetInputMode(*window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // GLEW: initialize
    // ----------------
    // Note: if using GLEW version 1.13 or earlier
    glewExperimental = GL_TRUE;
    GLenum GlewInitResult = glewInit();

    if (GLEW_OK != GlewInitResult)
    {
        std::cerr << glewGetErrorString(GlewInitResult) << std::endl;
        return false;
    }

    // Displays GPU OpenGL version
    cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;

    return true;
}


// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
void UProcessInput(GLFWwindow* window)
{
    static const float cameraSpeed = 2.5f;

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        gCamera.ProcessKeyboard(FORWARD, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        gCamera.ProcessKeyboard(BACKWARD, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        gCamera.ProcessKeyboard(LEFT, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        gCamera.ProcessKeyboard(RIGHT, gDeltaTime);
    //moves camera up and down
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        gCamera.ProcessKeyboard(UP, gDeltaTime);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        gCamera.ProcessKeyboard(DOWN, gDeltaTime);

    //changes from ortho to perspective camera
    if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS)
        ortho = true;
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
        ortho = false;

    if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS && !gIsFaceOn)
        gIsFaceOn = true;
    else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS && gIsFaceOn)
        gIsFaceOn = false;

}


// glfw: whenever the window size changed (by OS or user resize) this callback function executes
void UResizeWindow(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void UMousePositionCallback(GLFWwindow* window, double xpos, double ypos)
{
    if (gFirstMouse)
    {
        gLastX = xpos;
        gLastY = ypos;
        gFirstMouse = false;
    }

    float xoffset = xpos - gLastX;
    float yoffset = gLastY - ypos; // reversed since y-coordinates go from bottom to top

    gLastX = xpos;
    gLastY = ypos;

    gCamera.ProcessMouseMovement(xoffset, yoffset);
}


// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void UMouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
    gCamera.ProcessMouseScroll(yoffset);
}

// glfw: handle mouse button events
// --------------------------------
void UMouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    switch (button)
    {
    case GLFW_MOUSE_BUTTON_LEFT:
    {
        if (action == GLFW_PRESS)
            cout << "Left mouse button pressed" << endl;
        else
            cout << "Left mouse button released" << endl;
    }
    break;

    case GLFW_MOUSE_BUTTON_MIDDLE:
    {
        if (action == GLFW_PRESS)
            cout << "Middle mouse button pressed" << endl;
        else
            cout << "Middle mouse button released" << endl;
    }
    break;

    case GLFW_MOUSE_BUTTON_RIGHT:
    {
        if (action == GLFW_PRESS)
            cout << "Right mouse button pressed" << endl;
        else
            cout << "Right mouse button released" << endl;
    }
    break;

    default:
        cout << "Unhandled mouse button event" << endl;
        break;
    }
}


// Function called to render a frame
void URender()
{

    // Enable z-depth
    glEnable(GL_DEPTH_TEST);

    // Clear the frame and z buffers
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // 1. Scales the object by 2
    glm::mat4 scale = glm::scale(glm::vec3(1.0f, 1.0f, 1.0f));
    // 2. Rotates shape by 15 degrees in the x axis
    glm::mat4 rotation = glm::rotate(0.0f, glm::vec3(1.0, 1.0f, 1.0f));
    // 3. Place object at the origin
    glm::mat4 translation = glm::translate(glm::vec3(0.0f, -1.0f, 0.0f));
    // Model matrix: transformations are applied right-to-left order
    glm::mat4 model = translation * rotation * scale;

    // camera/view transformation
    glm::mat4 view = gCamera.GetViewMatrix();

    // Creates a perspective projection
    glm::mat4 projection = glm::ortho(-10.0f, 10.0f, -10.0f, 100.0f, -100.0f, 100.0f);
    if (!ortho) {
        projection = glm::perspective(glm::radians(gCamera.Zoom), (GLfloat)WINDOW_WIDTH / (GLfloat)WINDOW_HEIGHT, 0.1f, 100.0f);
    }
    if (ortho) {
        projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -10.0f, 10.0f);
    };

    // Set the shader to be used
    glUseProgram(gProgramId);


    // Retrieves and passes transform matrices to the Shader program
    GLint modelLoc = glGetUniformLocation(gProgramId, "model");
    GLint viewLoc = glGetUniformLocation(gProgramId, "view");
    GLint projLoc = glGetUniformLocation(gProgramId, "projection");
    GLuint multipleTexturesLoc = glGetUniformLocation(gProgramId, "multipleTextures");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));


    //render boxes

     //plane
    glBindVertexArray(gMesh.planeVAO);
    model = glm::mat4(1.0f);


    glBindTexture(GL_TEXTURE_2D, gTextureIdDesk);

    //Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nPlaneVertices);

    ////////////////////////////////////////creeper head
    glm::mat4 creeperScale = glm::scale(glm::vec3(1.5f, 1.6f, 1.3f));
    glm::mat4 creeperRotation = glm::rotate(90.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 creeperTranslation = glm::translate(glm::vec3(5.5f, -6.99f, -4.2f));
    glm::mat4 creeperModel = creeperTranslation * creeperRotation * creeperScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creeperModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creeperViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creeperProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creeperModelLoc, 1, GL_FALSE, glm::value_ptr(creeperModel));
    glUniformMatrix4fv(creeperViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creeperProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    //creeper
    glBindVertexArray(gMesh.creeperVAO);
    model = glm::mat4(1.0f);

    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCreeperSkin);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, gTextureIdFace);
    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreeperVertices);


    ////////////////////////////////////////creeper torso
    glm::mat4 creepertScale = glm::scale(glm::vec3(1.9f, 2.4f, 4.1f));
    glm::mat4 creepertRotation = glm::rotate(90.0f, glm::vec3(2.0f,2.0f, 2.0f));
    glm::mat4 creepertTranslation = glm::translate(glm::vec3(5.5f, -8.3f, -4.2f));
    glm::mat4 creepertModel = creepertTranslation * creepertRotation * creepertScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creepertModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creepertViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creepertProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creepertModelLoc, 1, GL_FALSE, glm::value_ptr(creepertModel));
    glUniformMatrix4fv(creepertViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creepertProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.creepertVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCreeperSkin);

    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreepertVertices);


    ////////////////////////////////////////creeper leg
    glm::mat4 creeperlScale = glm::scale(glm::vec3(3.5f, 3.5f, 3.5f));
    glm::mat4 creeperlRotation = glm::rotate(90.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 creeperlTranslation = glm::translate(glm::vec3(5.1f, -8.98f, -3.7f));
    glm::mat4 creeperlModel = creeperlTranslation * creeperlRotation * creeperlScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creeperlModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creeperlViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creeperlProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creeperlModelLoc, 1, GL_FALSE, glm::value_ptr(creeperlModel));
    glUniformMatrix4fv(creeperlViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creeperlProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.creeperlVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCreeperSkin);

    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreeperlVertices);

    ////////////////////////////////////////creeper leg
    glm::mat4 creeperl2Scale = glm::scale(glm::vec3(3.5f, 3.5f, 3.5f));
    glm::mat4 creeperl2Rotation = glm::rotate(0.0f, glm::vec3(3.0f, 1.0f, 1.0f));
    glm::mat4 creeperl2Translation = glm::translate(glm::vec3(5.1f, -8.98f, -4.7f));
    glm::mat4 creeperl2Model = creeperl2Translation * creeperl2Rotation * creeperl2Scale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creeperl2ModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creeperl2ViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creeperl2ProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creeperl2ModelLoc, 1, GL_FALSE, glm::value_ptr(creeperl2Model));
    glUniformMatrix4fv(creeperl2ViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creeperl2ProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.creeperl2VAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCreeperSkin);

    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreeperl2Vertices);

    ////////////////////////////////////////creeper leg
    glm::mat4 creeperl3Scale = glm::scale(glm::vec3(3.5f, 3.5f, 3.5f));
    glm::mat4 creeperl3Rotation = glm::rotate(90.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 creeperl3Translation = glm::translate(glm::vec3(6.1f, -8.98f, -4.7f));
    glm::mat4 creeperl3Model = creeperl3Translation * creeperl3Rotation * creeperl3Scale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creeperl3ModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creeperl3ViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creeperl3ProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creeperl3ModelLoc, 1, GL_FALSE, glm::value_ptr(creeperl3Model));
    glUniformMatrix4fv(creeperl3ViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creeperl3ProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.creeperl3VAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCreeperSkin);

    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreeperl3Vertices);

    ////////////////////////////////////////creeper leg
    glm::mat4 creeperl4Scale = glm::scale(glm::vec3(3.5f, 3.5f, 3.5f));
    glm::mat4 creeperl4Rotation = glm::rotate(90.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 creeperl4Translation = glm::translate(glm::vec3(6.1f, -8.98f, -3.7f));
    glm::mat4 creeperl4Model = creeperl4Translation * creeperl4Rotation * creeperl4Scale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creeperl4ModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creeperl4ViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creeperl4ProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creeperl4ModelLoc, 1, GL_FALSE, glm::value_ptr(creeperl4Model));
    glUniformMatrix4fv(creeperl4ViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creeperl4ProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.creeperl4VAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCreeperSkin);

    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreeperl4Vertices);

    ////////////////////////////////////////creeper stand
    glm::mat4 creeperStScale = glm::scale(glm::vec3(-1.5f, -4.0f, -4.0f));
    glm::mat4 creeperStRotation = glm::rotate(90.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 creeperStTranslation = glm::translate(glm::vec3(5.5f, -10.1f, -4.2f));
    glm::mat4 creeperStModel = creeperStTranslation * creeperStRotation * creeperStScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint creeperStModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint creeperStViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint creeperStProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(creeperStModelLoc, 1, GL_FALSE, glm::value_ptr(creeperStModel));
    glUniformMatrix4fv(creeperStViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(creeperStProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.creeperStVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdBlock);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCreeperStVertices);

    ////////////////////////////////////////nintendo
    glm::mat4 ninScale = glm::scale(glm::vec3(5.5f, 0.15f,2.2f));
    glm::mat4 ninRotation = glm::rotate(0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 ninTranslation = glm::translate(glm::vec3(1.5f, -10.7f, -2.2f));
    glm::mat4 ninModel = ninTranslation * ninRotation * ninScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint ninModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint ninViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint ninProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(ninModelLoc, 1, GL_FALSE, glm::value_ptr(ninModel));
    glUniformMatrix4fv(ninViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(ninProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.nintendoVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdNintendo);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nNintendoVertices);

    ////////////////////////////////////////pencil
    glm::mat4 pScale = glm::scale(glm::vec3(0.035f, 0.048f, 0.035f));
    glm::mat4 pRotation = glm::rotate(3.0f, glm::vec3(0.0f, 1.0f, 1.0f));
    glm::mat4 pTranslation = glm::translate(glm::vec3(-1.0f, -10.75f, -3.5f));
    glm::mat4 pModel = pTranslation * pRotation * pScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint pModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint pViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint pProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(pModelLoc, 1, GL_FALSE, glm::value_ptr(pModel));
    glUniformMatrix4fv(pViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(pProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.pencilVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdGray);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nPencilVertices);
    ////////////////////////////////////////eraser
    glm::mat4 erScale = glm::scale(glm::vec3(.035f, 0.006f, .035f));
    glm::mat4 erRotation = glm::rotate(3.0f, glm::vec3(0.0f, 1.0f, 1.0f));
    glm::mat4 erTranslation = glm::translate(glm::vec3(-0.892f, -10.75f, -4.55f));
    glm::mat4 erModel = erTranslation * erRotation * erScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint erModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint erViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint erProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(erModelLoc, 1, GL_FALSE, glm::value_ptr(erModel));
    glUniformMatrix4fv(erViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(erProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.eraserVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdLightg);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nEraserVertices);

    ////////////////////////////////////////tip
    glm::mat4 tScale = glm::scale(glm::vec3(.037f, 0.047f, .037f));
    glm::mat4 tRotation = glm::rotate(3.0f, glm::vec3(0.0f, 1.0f, 1.0f));
    glm::mat4 tTranslation = glm::translate(glm::vec3(-1.0f, -10.75f, -3.5f));
    glm::mat4 tModel = tTranslation * tRotation * tScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint tModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint tViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint tProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(tModelLoc, 1, GL_FALSE, glm::value_ptr(tModel));
    glUniformMatrix4fv(tViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(tProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.tipVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdTip);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nTipVertices);

    ////////////////////////////////////////screen
    glm::mat4 scScale = glm::scale(glm::vec3(1.2f, 1.0f, 1.8f));
    glm::mat4 scRotation = glm::rotate(0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 scTranslation = glm::translate(glm::vec3(1.5f, -9.4f, -2.2f));
    glm::mat4 scModel = scTranslation * scRotation * scScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint scModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint scViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint scProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(scModelLoc, 1, GL_FALSE, glm::value_ptr(scModel));
    glUniformMatrix4fv(scViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(scProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.screenVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdScreen);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nScreenVertices);

    ////////////////////////////////////////coin
    glm::mat4 cnScale = glm::scale(glm::vec3(0.20f, 0.002f, 0.175F));
    glm::mat4 cnRotation = glm::rotate(0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 cnTranslation = glm::translate(glm::vec3(2.5f, -10.75f, -6.8f));
    glm::mat4 cnModel = cnTranslation * cnRotation * cnScale;

    // Retrieves and passes transform matrices to the Shader program
    GLint cnModelLoc = glGetUniformLocation(gProgramId, "model");
    GLint cnViewLoc = glGetUniformLocation(gProgramId, "view");
    GLint cnProjLoc = glGetUniformLocation(gProgramId, "projection");

    glUniformMatrix4fv(cnModelLoc, 1, GL_FALSE, glm::value_ptr(cnModel));
    glUniformMatrix4fv(cnViewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(cnProjLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Activate the VBOs contained within the mesh's VAO
    glBindVertexArray(gMesh.eraserVAO);
    model = glm::mat4(1.0f);

    //bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, gTextureIdCoin);


    // Draws the triangles
    glDrawArrays(GL_TRIANGLES, 0, gMesh.nCoinVertices);

    // Deactivate the Vertex Array Object
    glBindVertexArray(0);


    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    glfwSwapBuffers(gWindow);    // Flips the the back buffer with the front buffer every frame.
}


// Implements the UCreateMesh function
void UCreateTexturedMesh(GLMesh& mesh)
{
    // Vertex data
    GLfloat planeVerts[] = {
        // Vertex Positions    // Texture Coordinates
         -10.0f, -9.9f, -10.0f, 0.0f,0.0f,
          10.0f, -9.9f, -10.0f, 1.0f,0.0f,
          10.0f, -9.9f,  10.0f, 1.0f,1.0f,
          10.0f, -9.9f,  10.0f, 1.0f,1.0f,
         -10.0f, -9.9f,  10.0f, 0.0f,1.0f,
         -10.0f, -9.9f, -10.0f, 0.0f,0.0f

    };

    GLfloat creeperVerts[] = {
        // Vertex Positions    // Texture Coordinates
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, 
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

       -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
       -0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

       -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 0.0f

    };
    GLfloat creepertVerts[] = {
        //Vertex Positions    // Texture Coordinates
       -0.3f, -0.2f, -0.1f,  0.0f, 0.0f,
        0.3f, -0.2f, -0.1f,  1.0f, 0.0f,
        0.3f,  0.2f, -0.1f,  1.0f, 1.0f,
        0.3f,  0.2f, -0.1f,  1.0f, 1.0f,
       -0.3f,  0.2f, -0.1f,  0.0f, 1.0f,
       -0.3f, -0.2f, -0.1f,  0.0f, 0.0f,

       -0.3f, -0.2f,  0.1f,  0.0f, 0.0f,
        0.3f, -0.2f,  0.1f,  1.0f, 0.0f,
        0.3f,  0.2f,  0.1f,  1.0f, 1.0f,
        0.3f,  0.2f,  0.1f,  1.0f, 1.0f,
       -0.3f,  0.2f,  0.1f,  0.0f, 1.0f,
       -0.3f, -0.2f,  0.1f,  0.0f, 0.0f,

       -0.3f,  0.2f,  0.1f,  0.0f, 0.0f,
       -0.3f,  0.2f, -0.1f,  1.0f, 0.0f,
       -0.3f, -0.2f, -0.1f,  1.0f, 1.0f,
       -0.3f, -0.2f, -0.1f,  1.0f, 1.0f,
       -0.3f, -0.2f,  0.1f,  0.0f, 1.0f,
       -0.3f,  0.2f,  0.1f,  0.0f, 0.0f,

        0.3f,  0.2f,  0.1f,  0.0f, 0.0f,
        0.3f,  0.2f, -0.1f,  1.0f, 0.0f,
        0.3f, -0.2f, -0.1f,  1.0f, 1.0f,
        0.3f, -0.2f, -0.1f,  1.0f, 1.0f,
        0.3f, -0.2f,  0.1f,  0.0f, 1.0f,
        0.3f,  0.2f,  0.1f,  0.0f, 0.0f,

       -0.3f, -0.2f, -0.1f,  0.0f, 0.0f,
        0.3f, -0.2f, -0.1f,  1.0f, 0.0f,
        0.3f, -0.2f,  0.1f,  1.0f, 1.0f,
        0.3f, -0.2f,  0.1f,  1.0f, 1.0f,
       -0.3f, -0.2f,  0.1f,  0.0f, 1.0f,
       -0.3f, -0.2f, -0.1f,  0.0f, 0.0f,

       -0.3f,  0.2f, -0.1f,  0.0f, 0.0f,
        0.3f,  0.2f, -0.1f,  1.0f, 0.0f,
        0.3f,  0.2f,  0.1f,  1.0f, 1.0f,
        0.3f,  0.2f,  0.1f,  1.0f, 1.0f,
       -0.3f,  0.2f,  0.1f,  0.0f, 1.0f,
       -0.3f,  0.2f, -0.1f,  0.0f, 0.0f

    };

    GLfloat creeperlVerts[] = {
        //Vertex Positions    // Texture Coordinates
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
       -0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
       -0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f
    };
    
    GLfloat creeperStVerts[] = {
        // Vertex Positions    // Texture Coordinates
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

       -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
       -0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
       -0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

       -0.5f,  0.5f, -0.5f,  0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
       -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
       -0.5f,  0.5f, -0.5f,  0.0f, 0.0f

    };

    GLfloat creeperl2Verts[] = {
        //Vertex Positions    // Texture Coordinates
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
       -0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
       -0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f
    };

    GLfloat creeperl3Verts[] = {
        //Vertex Positions    // Texture Coordinates
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
       -0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
       -0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f
    };

    GLfloat creeperl4Verts[] = {
        //Vertex Positions    // Texture Coordinates
       -0.1f, -0.1f, -0.1f,  1.0f, 0.0f, 
        0.1f, -0.1f, -0.1f,  1.0f, 0.0f,  
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,  
        0.1f,  0.1f, -0.1f,  1.0f, 1.0f,  
       -0.1f,  0.1f, -0.1f,  0.0f, 1.0f,  
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,  

       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 0.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f, -0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  0.0f, 0.0f,

       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f, -0.1f,  0.0f, 0.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
        0.1f, -0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f, -0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f, -0.1f, -0.1f,  0.0f, 0.0f,

       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f,
        0.1f,  0.1f, -0.1f,  1.0f, 0.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
        0.1f,  0.1f,  0.1f,  1.0f, 1.0f,
       -0.1f,  0.1f,  0.1f,  0.0f, 1.0f,
       -0.1f,  0.1f, -0.1f,  0.0f, 0.0f
    };

    GLfloat nintendoVerts[] = {
        // Vertex Positions    // Texture Coordinates
       -0.3f, -1.5f, -1.5f,  0.0f, 0.0f,
        0.3f, -1.5f, -1.5f,  1.0f, 0.0f,
        0.3f,  1.5f, -1.5f,  1.0f, 1.0f,
        0.3f,  1.5f, -1.5f,  1.0f, 1.0f,
       -0.3f,  1.5f, -1.5f,  0.0f, 1.0f,
       -0.3f, -1.5f, -1.5f,  0.0f, 0.0f,

       -0.3f, -1.5f,  1.5f,  0.0f, 0.0f,
        0.3f, -1.5f,  1.5f,  1.0f, 0.0f,
        0.3f,  1.5f,  1.5f,  1.0f, 1.0f,
        0.3f,  1.5f,  1.5f,  1.0f, 1.0f,
       -0.3f,  1.5f,  1.5f,  0.0f, 1.0f,
       -0.3f, -1.5f,  1.5f,  0.0f, 0.0f,

       -0.3f,  1.5f,  1.5f,  0.0f, 0.0f,
       -0.3f,  1.5f, -1.5f,  1.0f, 0.0f,
       -0.3f, -1.5f, -1.5f,  1.0f, 1.0f,
       -0.3f, -1.5f, -1.5f,  1.0f, 1.0f,
       -0.3f, -1.5f,  1.5f,  0.0f, 1.0f,
       -0.3f,  1.5f,  1.5f,  0.0f, 0.0f,
    
        0.3f,  1.5f,  1.5f,  0.0f, 0.0f,
        0.3f,  1.5f, -1.5f,  1.0f, 0.0f,
        0.3f, -1.5f, -1.5f,  1.0f, 1.0f,
        0.3f, -1.5f, -1.5f,  1.0f, 1.0f,
        0.3f, -1.5f,  1.5f,  0.0f, 1.0f,
        0.3f,  1.5f,  1.5f,  0.0f, 0.0f,
    
       -0.3f, -1.5f, -1.5f,  0.0f, 0.0f,
        0.3f, -1.5f, -1.5f,  1.0f, 0.0f,
        0.3f, -1.5f,  1.5f,  1.0f, 1.0f,
        0.3f, -1.5f,  1.5f,  1.0f, 1.0f,
       -0.3f, -1.5f,  1.5f,  0.0f, 1.0f,
       -0.3f, -1.5f, -1.5f,  0.0f, 0.0f,

       -0.3f,  1.5f, -1.5f,  0.0f, 0.0f,
        0.3f,  1.5f, -1.5f,  1.0f, 0.0f,
        0.3f,  1.5f,  1.5f,  1.0f, 1.0f,
        0.3f,  1.5f,  1.5f,  1.0f, 1.0f,
       -0.3f,  1.5f,  1.5f,  0.0f, 1.0f,
       -0.3f,  1.5f, -1.5f,  0.0f, 0.0f

    };

    GLfloat pencilVerts[] = {
        -3.0f, -20.0f,  0.0f, 0.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 1.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 1.0f,
         0.0f, -20.0f,  0.0f, 0.0f, 1.0f,
         3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 0.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 0.0f,



        -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 1.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 1.0f,
         0.0f,  60.0f,  4.0f, 0.0f, 1.0f,
        -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,

         0.0f,  60.0f,  4.0f, 0.0f, 0.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 0.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
         3.0f,  60.0f,  3.0f, 0.0f, 1.0f,
         0.0f,  60.0f,  4.0f, 0.0f, 0.0f,

         3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
         4.0f,  60.0f,  0.0f, 0.0f, 1.0f,
         3.0f,  60.0f,  3.0f, 0.0f, 0.0f,

         4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
         3.0f,  60.0f, -3.0f, 0.0f, 1.0f,
         4.0f,  60.0f,  0.0f, 0.0f, 0.0f,

         3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 1.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 1.0f,
         0.0f,  60.0f, -4.0f, 0.0f, 1.0f,
         3.0f,  60.0f, -3.0f, 0.0f, 0.0f,

         0.0f,  60.0f, -4.0f, 0.0f, 0.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 0.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
        -3.0f,  60.0f, -3.0f, 0.0f, 1.0f,
         0.0f,  60.0f, -4.0f, 0.0f, 0.0f,

        -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
        -4.0f,  60.0f,  0.0f, 0.0f, 1.0f,
        -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,

        -4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
        -3.0f,  60.0f,  3.0f, 0.0f, 1.0f,
        -4.0f,  60.0f,  0.0f, 0.0f, 0.0f,



        -3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
         0.0f, 60.0f,  4.0f, 0.0f, 0.0f,
         0.0f, 60.0f,  4.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
         3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
         3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
         4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
         4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
         3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
         3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
         0.0f, 60.0f, -4.0f, 0.0f, 0.0f,
         0.0f, 60.0f, -4.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
        -3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
        -3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
        -4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
        -4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
         0.0f, 75.0f,  0.0f, 0.0f, 0.0f,
        -3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
    };
    GLfloat eraserVerts[] = {
    -3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  4.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  4.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
     3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
     3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     0.0f, -20.0f, -4.0f, 1.0f, 0.0f,
     0.0f, -20.0f, -4.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
    -3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
    -3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
    -4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
    -4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
     0.0f, -20.0f,  0.0f, 1.0f, 0.0f,
    -3.0f, -20.0f,  3.0f, 1.0f, 0.0f,



    -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
    -3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
     0.0f, -20.0f,  4.0f, 0.0f, 0.0f,
     0.0f, -20.0f,  4.0f, 0.0f, 0.0f,
     0.0f,  60.0f,  4.0f, 0.0f, 0.0f,
    -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,

     0.0f,  60.0f,  4.0f, 0.0f, 0.0f,
     0.0f, -20.0f,  4.0f, 0.0f, 0.0f,
     3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
     3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
     3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
     0.0f,  60.0f,  4.0f, 0.0f, 0.0f,

     3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
     3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
     4.0f, -20.0f,  0.0f, 0.0f, 0.0f,
     4.0f, -20.0f,  0.0f, 0.0f, 0.0f,
     4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
     3.0f,  60.0f,  3.0f, 0.0f, 0.0f,

     4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
     4.0f, -20.0f,  0.0f, 0.0f, 0.0f,
     3.0f, -20.0f, -3.0f, 0.0f, 0.0f,
     3.0f, -20.0f, -3.0f, 0.0f, 0.0f,
     3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
     4.0f,  60.0f,  0.0f, 0.0f, 0.0f,

     3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
     3.0f, -20.0f, -3.0f, 0.0f, 0.0f,
     0.0f, -20.0f, -4.0f, 0.0f, 0.0f,
     0.0f, -20.0f, -4.0f, 0.0f, 0.0f,
     0.0f,  60.0f, -4.0f, 0.0f, 0.0f,
     3.0f,  60.0f, -3.0f, 0.0f, 0.0f,

     0.0f,  60.0f, -4.0f, 0.0f, 0.0f,
     0.0f, -20.0f, -4.0f, 0.0f, 0.0f,
    -3.0f, -20.0f, -3.0f, 0.0f, 0.0f,
    -3.0f, -20.0f, -3.0f, 0.0f, 0.0f,
    -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
     0.0f,  60.0f, -4.0f, 0.0f, 0.0f,

    -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
    -3.0f, -20.0f, -3.0f, 0.0f, 0.0f,
    -4.0f, -20.0f,  0.0f, 0.0f, 0.0f,
    -4.0f, -20.0f,  0.0f, 0.0f, 0.0f,
    -4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
    -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,

    -4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
    -4.0f, -20.0f,  0.0f, 0.0f, 0.0f,
    -3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
    -3.0f, -20.0f,  3.0f, 0.0f, 0.0f,
    -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
    -4.0f,  60.0f,  0.0f, 0.0f, 0.0f,



    -3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  4.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  4.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
     3.0f, 60.0f,  3.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
     3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     0.0f, 60.0f, -4.0f, 0.0f, 0.0f,
     0.0f, 60.0f, -4.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
    -3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
    -3.0f, 60.0f, -3.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
    -4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
    -4.0f, 60.0f,  0.0f, 0.0f, 0.0f,
     0.0f, 60.0f,  0.0f, 0.0f, 0.0f,
    -3.0f, 60.0f,  3.0f, 0.0f, 0.0f,

    };

    GLfloat tipVerts[] = {
             -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 1.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 1.0f,
         0.0f,  60.0f,  4.0f, 0.0f, 1.0f,
        -3.0f,  60.0f,  3.0f, 0.0f, 0.0f,

         0.0f,  60.0f,  4.0f, 0.0f, 0.0f,
         0.0f, -20.0f,  4.0f, 1.0f, 0.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
         3.0f,  60.0f,  3.0f, 0.0f, 1.0f,
         0.0f,  60.0f,  4.0f, 0.0f, 0.0f,

         3.0f,  60.0f,  3.0f, 0.0f, 0.0f,
         3.0f, -20.0f,  3.0f, 1.0f, 0.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
         4.0f,  60.0f,  0.0f, 0.0f, 1.0f,
         3.0f,  60.0f,  3.0f, 0.0f, 0.0f,

         4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
         4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
         3.0f,  60.0f, -3.0f, 0.0f, 1.0f,
         4.0f,  60.0f,  0.0f, 0.0f, 0.0f,

         3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
         3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 1.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 1.0f,
         0.0f,  60.0f, -4.0f, 0.0f, 1.0f,
         3.0f,  60.0f, -3.0f, 0.0f, 0.0f,

         0.0f,  60.0f, -4.0f, 0.0f, 0.0f,
         0.0f, -20.0f, -4.0f, 1.0f, 0.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 1.0f,
        -3.0f,  60.0f, -3.0f, 0.0f, 1.0f,
         0.0f,  60.0f, -4.0f, 0.0f, 0.0f,

        -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,
        -3.0f, -20.0f, -3.0f, 1.0f, 0.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 1.0f,
        -4.0f,  60.0f,  0.0f, 0.0f, 1.0f,
        -3.0f,  60.0f, -3.0f, 0.0f, 0.0f,

        -4.0f,  60.0f,  0.0f, 0.0f, 0.0f,
        -4.0f, -20.0f,  0.0f, 1.0f, 0.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
        -3.0f, -20.0f,  3.0f, 1.0f, 1.0f,
        -3.0f,  60.0f,  3.0f, 0.0f, 1.0f,
        -4.0f,  60.0f,  0.0f, 0.0f, 0.0f

    };

    GLfloat screenVerts[] = {
        // Vertex Positions    // Texture Coordinates
         -1.0f, -1.0f, -1.0f, 0.0f,0.0f,
          1.0f, -1.0f, -1.0f, 0.0f,1.0f,
          1.0f, -1.0f,  1.0f, 1.0f,1.0f,
          1.0f, -1.0f,  1.0f, 1.0f,1.0f,
         -1.0f, -1.0f,  1.0f, 1.0f,0.0f,
         -1.0f, -1.0f, -1.0f, 0.0f,0.0f
    }; 

    GLfloat coinVerts[] = {
        -3.0f, 10.0f,  3.0f, 0.0f, 0.0f,
        -3.0f,  0.0f,  3.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  4.0f, 1.0f, 1.0f,
         0.0f,  0.0f,  4.0f, 1.0f, 1.0f,
         0.0f, 10.0f,  4.0f, 0.0f, 1.0f,
        -3.0f, 10.0f,  3.0f, 0.0f, 0.0f,

         0.0f, 10.0f,  4.0f, 0.0f, 0.0f,
         0.0f,  0.0f,  4.0f, 1.0f, 0.0f,
         3.0f,  0.0f,  3.0f, 1.0f, 1.0f,
         3.0f,  0.0f,  3.0f, 1.0f, 1.0f,
         3.0f, 10.0f,  3.0f, 0.0f, 1.0f,
         0.0f, 10.0f,  4.0f, 1.0f, 0.0f,

         3.0f, 10.0f,  3.0f, 1.0f, 0.0f,
         3.0f,  0.0f,  3.0f, 1.0f, 1.0f,
         4.0f,  0.0f,  0.0f, 0.0f, 1.0f,
         4.0f,  0.0f,  0.0f, 0.0f, 1.0f,
         4.0f, 10.0f,  0.0f, 0.0f, 0.0f,
         3.0f, 10.0f,  3.0f, 1.0f, 0.0f,

         4.0f, 10.0f,  0.0f, 0.0f, 1.0f,
         4.0f,  0.0f,  0.0f, 1.0f, 1.0f,
         3.0f,  0.0f, -3.0f, 1.0f, 0.0f,
         3.0f,  0.0f, -3.0f, 1.0f, 0.0f,
         3.0f, 10.0f, -3.0f, 0.0f, 0.0f,
         4.0f, 10.0f,  0.0f, 0.0f, 1.0f,

         3.0f, 10.0f, -3.0f, 0.0f, 1.0f,
         3.0f,  0.0f, -3.0f, 1.0f, 1.0f,
         0.0f,  0.0f, -4.0f, 1.0f, 0.0f,
         0.0f,  0.0f, -4.0f, 1.0f, 0.0f,
         0.0f, 10.0f, -4.0f, 0.0f, 0.0f,
         3.0f, 10.0f, -3.0f, 0.0f, 1.0f,

         0.0f, 10.0f, -4.0f, 1.0f, 1.0f,
         0.0f,  0.0f, -4.0f, 1.0f, 1.0f,
        -3.0f,  0.0f, -3.0f, 1.0f, 1.0f,
        -3.0f,  0.0f, -3.0f, 1.0f, 1.0f,
        -3.0f, 10.0f, -3.0f, 1.0f, 1.0f,
         0.0f, 10.0f, -4.0f, 1.0f, 1.0f,

        -3.0f, 10.0f, -3.0f, 1.0f, 1.0f,
        -3.0f,  0.0f, -3.0f, 1.0f, 1.0f,
        -4.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        -4.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        -4.0f, 10.0f,  0.0f, 1.0f, 1.0f,
        -3.0f, 10.0f, -3.0f, 1.0f, 1.0f,

        -4.0f, 10.0f,  0.0f, 0.0f, 1.0f,
        -4.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        -3.0f,  0.0f,  3.0f, 1.0f, 0.0f,
        -3.0f,  0.0f,  3.0f, 0.0f, 0.0f,
        -3.0f, 10.0f,  3.0f, 0.0f, 0.0f,
        -4.0f, 10.0f,  0.0f, 1.0f, 1.0f,
        ////////////////////////////////
        -6.0f, 10.0f,  6.0f, 0.0f, 0.0f,
        -6.0f,  0.0f,  6.0f, 1.0f, 0.0f,
         0.0f,  0.0f,  8.0f, 1.0f, 1.0f,
         0.0f,  0.0f,  8.0f, 1.0f, 1.0f,
         0.0f, 10.0f,  8.0f, 0.0f, 1.0f,
        -6.0f, 10.0f,  6.0f, 0.0f, 0.0f,

         0.0f, 10.0f,  8.0f, 1.0f, 1.0f,
         0.0f,  0.0f,  8.0f, 1.0f, 1.0f,
         6.0f,  0.0f,  6.0f, 1.0f, 1.0f,
         6.0f,  0.0f,  6.0f, 1.0f, 1.0f,
         6.0f, 10.0f,  6.0f, 1.0f, 1.0f,
         0.0f, 10.0f,  8.0f, 1.0f, 1.0f,

         6.0f, 10.0f,  6.0f, 1.0f, 1.0f,
         6.0f,  0.0f,  6.0f, 1.0f, 1.0f,
         8.0f,  0.0f,  0.0f, 1.0f, 1.0f,
         8.0f,  0.0f,  0.0f, 1.0f, 1.0f,
         8.0f, 10.0f,  0.0f, 1.0f, 1.0f,
         6.0f, 10.0f,  6.0f, 1.0f, 1.0f,

         8.0f, 10.0f,  0.0f, 1.0f, 1.0f,
         8.0f,  0.0f,  0.0f, 1.0f, 1.0f,
         6.0f,  0.0f, -6.0f, 1.0f, 1.0f,
         6.0f,  0.0f, -6.0f, 1.0f, 1.0f,
         6.0f, 10.0f, -6.0f, 1.0f, 1.0f,
         8.0f, 10.0f,  0.0f, 1.0f, 1.0f,

         6.0f, 10.0f, -6.0f, 1.0f, 1.0f,
         6.0f,  0.0f, -6.0f, 1.0f, 1.0f,
         0.0f,  0.0f, -8.0f, 1.0f, 1.0f,
         0.0f,  0.0f, -8.0f, 1.0f, 1.0f,
         0.0f, 10.0f, -8.0f, 1.0f, 1.0f,
         6.0f, 10.0f, -6.0f, 1.0f, 1.0f,

         0.0f, 10.0f, -8.0f, 1.0f, 0.0f,
         0.0f,  0.0f, -8.0f, 1.0f, 1.0f,
        -6.0f,  0.0f, -6.0f, 0.0f, 1.0f,
        -6.0f,  0.0f, -6.0f, 0.0f, 1.0f,
        -6.0f, 10.0f, -6.0f, 0.0f, 0.0f,
         0.0f, 10.0f, -8.0f, 1.0f, 0.0f,

        -6.0f, 10.0f, -6.0f, 0.0f, 1.0f,
        -6.0f,  0.0f, -6.0f, 1.0f, 1.0f,
        -8.0f,  0.0f,  0.0f, 1.0f, 0.0f,
        -8.0f,  0.0f,  0.0f, 1.0f, 0.0f,
        -8.0f, 10.0f,  0.0f, 0.0f, 0.0f,
        -6.0f, 10.0f, -6.0f, 0.0f, 1.0f,

        -8.0f, 10.0f,  0.0f, 0.0f, 1.0f,
        -8.0f,  0.0f,  0.0f, 1.0f, 1.0f,
        -6.0f,  0.0f,  6.0f, 1.0f, 0.0f,
        -6.0f,  0.0f,  6.0f, 1.0f, 0.0f,
        -6.0f, 10.0f,  6.0f, 0.0f, 0.0f,
        -8.0f, 10.0f,  0.0f, 0.0f, 1.0f
    };

    const GLuint floatsPerVertex = 3;
    const GLuint floatsPerUV = 2;



    mesh.nPlaneVertices = sizeof(planeVerts) / (sizeof(planeVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.planeVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.planeVAO);


    // Create VBO
    glGenBuffers(1, &mesh.planeVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.planeVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(planeVerts), planeVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Strides between vertex coordinates
    GLint stride = sizeof(float) * (floatsPerVertex + floatsPerUV);

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(2);
    ///////////////////////////////////////////
    mesh.nCreeperVertices = sizeof(creeperVerts) / (sizeof(creeperVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creeperVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creeperVAO);


    // Create VBO
    glGenBuffers(1, &mesh.creeperVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creeperVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creeperVerts), creeperVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(2);
    ///////////////////////////////////////////
    mesh.nCreepertVertices = sizeof(creepertVerts) / (sizeof(creepertVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creepertVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creepertVAO);


    // Create VBO
    glGenBuffers(1, &mesh.creepertVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creepertVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creepertVerts), creepertVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(2);
    ////////////////////////////////////////
    mesh.nCreeperlVertices = sizeof(creeperlVerts) / (sizeof(creeperlVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creeperlVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creeperlVAO);


    // Create VBO
    glGenBuffers(1, &mesh.creeperlVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creeperlVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creeperlVerts), creeperlVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float) * floatsPerVertex));
    glEnableVertexAttribArray(2);

    ////////////////////////////////////////
    mesh.nCreeperl2Vertices = sizeof(creeperl2Verts) / (sizeof(creeperl2Verts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creeperl2VAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creeperl2VAO);


    // Create VBO
    glGenBuffers(1, &mesh.creeperl2VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creeperl2VBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creeperl2Verts), creeperl2Verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    ////////////////////////////////////////
    mesh.nCreeperl3Vertices = sizeof(creeperl3Verts) / (sizeof(creeperl3Verts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creeperl3VAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creeperl3VAO);


    // Create VBO
    glGenBuffers(1, &mesh.creeperl3VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creeperl3VBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creeperl3Verts), creeperl3Verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    ////////////////////////////////////////
    mesh.nCreeperl4Vertices = sizeof(creeperl4Verts) / (sizeof(creeperl4Verts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creeperl4VAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creeperl4VAO);


    // Create VBO
    glGenBuffers(1, &mesh.creeperl4VBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creeperl4VBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creeperl4Verts), creeperl4Verts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);


    mesh.nCreeperStVertices = sizeof(creeperStVerts) / (sizeof(creeperStVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.creeperStVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.creeperStVAO);


    // Create VBO
    glGenBuffers(1, &mesh.creeperStVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.creeperStVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(creeperlVerts), creeperStVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    mesh.nNintendoVertices = sizeof(nintendoVerts) / (sizeof(nintendoVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.nintendoVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.nintendoVAO);


    // Create VBO
    glGenBuffers(1, &mesh.nintendoVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.nintendoVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(nintendoVerts), nintendoVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

     // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    mesh.nPencilVertices = sizeof(pencilVerts) / (sizeof(pencilVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.pencilVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.pencilVAO);

    // Create VBO
    glGenBuffers(1, &mesh.pencilVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.pencilVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(pencilVerts), pencilVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    mesh.nEraserVertices = sizeof(eraserVerts) / (sizeof(eraserVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.eraserVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.eraserVAO);

    // Create VBO
    glGenBuffers(1, &mesh.eraserVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.eraserVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(eraserVerts), eraserVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    mesh.nTipVertices = sizeof(tipVerts) / (sizeof(tipVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.tipVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.tipVAO);

    // Create VBO
    glGenBuffers(1, &mesh.tipVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.tipVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(tipVerts), tipVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    mesh.nScreenVertices = sizeof(screenVerts) / (sizeof(screenVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.screenVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.screenVAO);

    // Create VBO
    glGenBuffers(1, &mesh.screenVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.screenVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(screenVerts), screenVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    //////////////////////binding
    mesh.nBindingVertices = sizeof(tipVerts) / (sizeof(tipVerts[0]) * (floatsPerVertex + floatsPerUV));

    glGenVertexArrays(1, &mesh.bindingVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.bindingVAO);


    // Create VBO
    glGenBuffers(1, &mesh.bindingVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.bindingVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(tipVerts), tipVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

    //////////////////////coin
    mesh.nCoinVertices = sizeof(coinVerts) / (sizeof(coinVerts[0]) * (floatsPerVertex + floatsPerUV));
    glGenVertexArrays(1, &mesh.coinVAO); // we can also generate multiple VAOs or buffers at the same time
    glBindVertexArray(mesh.coinVAO);

    // Create VBO
    glGenBuffers(1, &mesh.coinVBO);
    glBindBuffer(GL_ARRAY_BUFFER, mesh.coinVBO); // Activates the buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(coinVerts), coinVerts, GL_STATIC_DRAW); // Sends vertex or coordinate data to the GPU

    // Create Vertex Attribute Pointers
    glVertexAttribPointer(0, floatsPerVertex, GL_FLOAT, GL_FALSE, stride, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, floatsPerUV, GL_FLOAT, GL_FALSE, stride, (char*)(sizeof(float)* floatsPerVertex));
    glEnableVertexAttribArray(2);

}



void UDestroyMesh(GLMesh& mesh)
{
    glDeleteVertexArrays(1, &mesh.planeVAO);
    glDeleteBuffers(1, &mesh.planeVBO);
    glDeleteVertexArrays(1, &mesh.creeperVAO);
    glDeleteBuffers(1, &mesh.creeperVBO);
    glDeleteVertexArrays(1, &mesh.creepertVAO);
    glDeleteBuffers(1, &mesh.creepertVBO);
    glDeleteVertexArrays(1, &mesh.creeperlVAO);
    glDeleteBuffers(1, &mesh.creeperlVBO);
    glDeleteVertexArrays(1, &mesh.creeperStVAO);
    glDeleteBuffers(1, &mesh.creeperStVBO);
    glDeleteVertexArrays(1, &mesh.nintendoVAO);
    glDeleteBuffers(1, &mesh.nintendoVBO);
    glDeleteVertexArrays(1, &mesh.pencilVAO);
    glDeleteBuffers(1, &mesh.pencilVBO);
    glDeleteVertexArrays(1, &mesh.eraserVAO);
    glDeleteBuffers(1, &mesh.eraserVBO);
    glDeleteVertexArrays(1, &mesh.tipVAO);
    glDeleteBuffers(1, &mesh.tipVBO);
    glDeleteVertexArrays(1, &mesh.screenVAO);
    glDeleteBuffers(1, &mesh.screenVBO);
    glDeleteVertexArrays(1, &mesh.bindingVAO);
    glDeleteBuffers(1, &mesh.bindingVBO);
    glDeleteVertexArrays(1, &mesh.coinVAO);
    glDeleteBuffers(1, &mesh.coinVBO);
    glDeleteVertexArrays(1, &mesh.buttonVAO);
    glDeleteBuffers(1, &mesh.buttonVBO);
    glDeleteVertexArrays(1, &mesh.buttonnVAO);
    glDeleteBuffers(1, &mesh.buttonnVBO);
    glDeleteVertexArrays(1, &mesh.button0VAO);
    glDeleteBuffers(1, &mesh.button0VBO);
    glDeleteVertexArrays(1, &mesh.button1VAO);
    glDeleteBuffers(1, &mesh.button1VBO);
    glDeleteVertexArrays(1, &mesh.button2VAO);
    glDeleteBuffers(1, &mesh.button2VBO);
    glDeleteVertexArrays(1, &mesh.button3VAO);
    glDeleteBuffers(1, &mesh.button3VBO);
    glDeleteVertexArrays(1, &mesh.button4VAO);
    glDeleteBuffers(1, &mesh.button4VBO);
    glDeleteVertexArrays(1, &mesh.button5VAO);
    glDeleteBuffers(1, &mesh.button5VBO);
    glDeleteVertexArrays(1, &mesh.button6VAO);
    glDeleteBuffers(1, &mesh.button6VBO);
    glDeleteVertexArrays(1, &mesh.button7VAO);
    glDeleteBuffers(1, &mesh.button7VBO);
    glDeleteVertexArrays(1, &mesh.button8VAO);
    glDeleteBuffers(1, &mesh.button8VBO);
    glDeleteVertexArrays(1, &mesh.button9VAO);
    glDeleteBuffers(1, &mesh.button9VBO);

}


/*Generate and load the texture*/
bool UCreateTexture(const char* filename, GLuint& textureId)
{
    int width, height, channels;
    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
    if (image)
    {
        flipImageVertically(image, width, height, channels);

        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        // set the texture wrapping parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        // set texture filtering parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


        if (channels == 3)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
        else if (channels == 4)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
        else
        {
            cout << "Not implemented to handle image with " << channels << " channels" << endl;
            return false;
        }

        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(image);
        glBindTexture(GL_TEXTURE_2D, 0); // Unbind the texture

        return true;
    }

    // Error loading the image
    return false;
}

void UDestroyTexture(GLuint textureId)
{
    glGenTextures(1, &textureId);
}

// Implements the UCreateShaders function
bool UCreateShaderProgram(const char* vtxShaderSource, const char* fragShaderSource, GLuint& programId)
{
    // Compilation and linkage error reporting
    int success = 0;
    char infoLog[512];

    // Create a Shader program object.
    programId = glCreateProgram();

    // Create the vertex and fragment shader objects
    GLuint vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

    // Retrive the shader source
    glShaderSource(vertexShaderId, 1, &vtxShaderSource, NULL);
    glShaderSource(fragmentShaderId, 1, &fragShaderSource, NULL);

    // Compile the vertex shader, and print compilation errors (if any)
    glCompileShader(vertexShaderId); // compile the vertex shader
    // check for shader compile errors
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;

        return false;
    }

    glCompileShader(fragmentShaderId); // compile the fragment shader
    // check for shader compile errors
    glGetShaderiv(fragmentShaderId, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShaderId, sizeof(infoLog), NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;

        return false;
    }

    // Attached compiled shaders to the shader program
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);

    glLinkProgram(programId);   // links the shader program
    // check for linking errors
    glGetProgramiv(programId, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(programId, sizeof(infoLog), NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;

        return false;
    }

    glUseProgram(programId);    // Uses the shader program

    return true;
}


void UDestroyShaderProgram(GLuint programId)
{
    glDeleteProgram(programId);
}