#version 410 core

in vec2 uv;

out vec2 pos;

void main( void )
{

  pos = uv;

  gl_Position = vec4( uv, -1, 1 );

}
