#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform UniformBufferObject {
   vec3 pos;
} light;



layout(location = 0) in vec2 fragTexCoord;
layout(location = 1) in vec3 vertPos;
layout(location = 2) in vec3 normalInterp;

layout(location = 0) out vec4 outColor;





const vec3 lightColor = vec3(1.0, 1.0, 1.0);

const float specularStrength  = 0.5;
const float ambientStrength = 0.1;

const vec3 viewPos =  vec3(1.0, 1.0, 180.0);


void main() {
 
 
 vec3 ambient = ambientStrength * lightColor;
 
 
 
 vec3 norm = normalize(normalInterp);
 vec3 lightDir = normalize(light.pos - vertPos);
 float diff = max(dot(norm,lightDir),0.0);
 vec3 diffuse = diff * lightColor;
 vec3 specular = vec3(1);
 if(diff>0){
 vec3 viewDir = normalize(viewPos - vertPos);
 vec3 reflectDir = reflect(-lightDir, norm);
 float spec = pow(max(dot(viewDir,reflectDir),0.0), 128);
 specular = specularStrength * spec * lightColor;
 }
 
 vec4 tex = vec4(0.0,1.0,0.0,1.0);// texture(texSampler, fragTexCoord);
 vec4 light = vec4((ambient + diffuse + specular), 1.0);
 
 outColor = light * tex;
 
 
 
 
 
}




