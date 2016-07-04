#version 410 core

in vec2 pos;

out vec4 fragColor;

void main( void )
{

  fragColor = vec4( pos, 0.0, 1.0 );

}
