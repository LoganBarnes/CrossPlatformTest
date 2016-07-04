#define GLFW_INCLUDE_GL_3
#include <iostream>
//#include "GL/glew.h"
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


  glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR,                 3 );
  glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR,                 2 );
  glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT,           GL_TRUE );
  glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
  glfwWindowHint( GLFW_RESIZABLE,                      GL_FALSE );

  window = glfwCreateWindow( 640, 480, "Windows Test", 0, 0 );

  if ( !window )
  {

    glfwTerminate( );
    return -1; // failure

  }

  glfwMakeContextCurrent( window );
  glfwSwapInterval( 1 );
  glfwSetKeyCallback( window, key_callback );


//  if ( !initGLEW( ) )
//  {

//    return -1;

//  }



  std::cout << "Entering main loop" << std::endl;


  while ( !glfwWindowShouldClose( window ) )
  {

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
