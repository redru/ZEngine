#version 400
layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_color;

uniform mat4 mvp = mat4(1.0);
uniform mat4 transform = mat4(1.0);
/* mvp[0] = vec4(0.827730298, -0.993682027, -0.687367737, -0.685994387);
mvp[1] = vec4(0.0, 2.07017088, -0.515525818, -0.514495790);
mvp[2] = vec4(-1.10364044, -0.745261550, -0.515525818, -0.514495790);
mvp[3] = vec4(0.0, 0.0, 5.64242601, 5.83095264); */

out vec3 color;

void main () {
	color = vertex_color;
	gl_Position = mvp * transform * vec4(vertex_position, 1.0);
}