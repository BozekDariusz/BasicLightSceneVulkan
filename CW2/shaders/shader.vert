#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 0) uniform UniformBufferObject {
    mat4 view;
    mat4 proj;
} ubo;

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inNormCoord;
layout(location = 2) in vec2 inTexCoord;


layout(location = 0) out vec2 fragTexCoord;
layout(location = 1) out vec3 vertPos;
layout(location = 2) out vec3 normalInterp;

void main() {
    gl_Position = ubo.proj * ubo.view * vec4(inPosition, 1.0);
	vec4 vertPos4 = ubo.view * vec4(inPosition, 1.0);
    fragTexCoord = inTexCoord;
	vertPos = vec3(vertPos4) / vertPos4.w;
    normalInterp = vec3(inNormCoord);
}







