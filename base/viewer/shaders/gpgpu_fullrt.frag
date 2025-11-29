#version 410

uniform sampler2D computeResult;

in vec2 textCoords;

out vec4 fragColor;

void main(void)
{
    fragColor = texture(computeResult, textCoords);
}
