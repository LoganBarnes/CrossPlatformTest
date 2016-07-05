#include <iostream>

// THIS IS OPTIONAL AND NOT REQUIRED, ONLY USE THIS IF YOU DON'T WANT GLAD TO INCLUDE windows.h
// GLAD will include windows.h for APIENTRY if it was not previously defined.
// Make sure you have the correct definition for APIENTRY for platforms which define _WIN32 but don't use __stdcall
#ifdef _WIN32
#define APIENTRY __stdcall
#endif

// GLAD
#include <glad/glad.h>

// confirm that GLAD didn't include windows.h
#ifdef _WINDOWS_
#error windows.h was included!
#endif

#define GLFW_INCLUDE_GL_3
#include "GLFW/glfw3.h"


static void error_callback (
                            int         error,
                            const char *description
                            );

static void key_callback (
                          GLFWwindow *window,
                          int         key,
                          int         scancode,
                          int         action,
                          int         mode
                          );

//bool initGLEW ( );


///
/// \brief main
/// \return
///
int
main( void )
{

  std::cout << "Running graphics program" << std::endl;


  GLFWwindow *window;

  if ( !glfwInit( ) )
  {

    std::cerr << "GLFW initialization failed" << std::endl;
    return -1; // failure

  }

  glfwSetErrorCallback( error_callback );
  
  int WIDTH  = 640;
  int HEIGHT = 480;


  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR,                 3 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR,                 2 );
  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT,           GL_TRUE );
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
  glfwWindowHint( GLFW_RESIZABLE,                      GL_FALSE );

  window = glfwCreateWindow( WIDTH, HEIGHT, "Windows Test", 0, 0 );

  if ( !window )
  {

    glfwTerminate( );
    return -1; // failure

  }

  glfwMakeContextCurrent( window );
  glfwSwapInterval( 1 );
  glfwSetKeyCallback( window, key_callback );


  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
	  std::cout << "Failed to initialize OpenGL context" << std::endl;
	  return -1;
  }

  // Define the viewport dimensions and clear color
  glViewport(0, 0, WIDTH, HEIGHT);
  glClearColor(1.f, 0.5f, 0.1f, 1.f);



  std::cout << "Entering main loop" << std::endl;


  while ( !glfwWindowShouldClose( window ) )
  {
	
	glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers( window );
    glfwPollEvents( );

  }


  glfwTerminate( );


  std::cout << "Exiting program..." << std::endl;

} // main



///
/// \brief error_callback
/// \param error
/// \param description
///
void
error_callback(
               int,
               const char *description
               )
{

  std::cerr << "ERROR: " <<  description << std::endl;

}



///
/// \brief key_callback
/// \param window
/// \param key
/// \param action
///
void
key_callback(
             GLFWwindow *window,
             int         key,
             int,
             int         action,
             int
             )
{

  if ( ( key == GLFW_KEY_ESCAPE || key == GLFW_KEY_Q )  && action == GLFW_PRESS )
  {

    glfwSetWindowShouldClose( window, GL_TRUE );

  }

}



/////
///// \brief initGLEW
///// \return
/////
//bool
//initGLEW( )
//{

//  glewExperimental = GL_TRUE;
//  GLenum err = glewInit( );
//  glGetError( );   // Clear errors after call to glewInit

//  if ( GLEW_OK != err )
//  {

//    // Problem: glewInit failed, something is seriously wrong.
//    std::cerr << "Error initializing glew: ";
//    std::cerr << glewGetErrorString( err ) << std::endl;
//    return false;

//  }

//  // Enable depth testing, so that objects are occluded based on depth instead of drawing order.
//  glEnable( GL_DEPTH_TEST );

//  // Move the polygons back a bit so lines are still drawn even though they are coplanar with the
//  // polygons they came from, which will be drawn before them.
//  glEnable( GL_POLYGON_OFFSET_LINE );
//  glPolygonOffset( -1, -1 );

//  // Enable back-face culling, meaning only the front side of every face is rendered.
//  glEnable( GL_CULL_FACE );
//  glCullFace( GL_BACK );

//  // Specify that the front face is represented by vertices in counterclockwise order (this is
//  // the default).
//  glFrontFace( GL_CCW );

//  // Specify the color used when glClear is called
//  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

//  return true;

//} // initGLEW
