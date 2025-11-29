#version 330 core

in vec4 vertex;
in vec4 color;
in vec4 normal;

// Values that stay constant for the whole mesh.
uniform mat4 matrix;
uniform mat4 perspective;


void main(){
	vec4 vertColor = color;
	vec4 vertNormal = normal;
	gl_Position = perspective * matrix * vertex;
}

