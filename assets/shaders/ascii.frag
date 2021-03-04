
#version 450 core

uniform sampler2D inputTexture;

// Shader outputs.
layout(location = 0) out vec4 fragColor;

float character(int n, vec2 p) {
    p = floor(p * vec2(4.0, -4.0) + 2.5);
    if (clamp(p.x, 0.0, 4.0) == p.x) {
        if (clamp(p.y, 0.0, 4.0) == p.y) {
            int a = int(round(p.x) + 5.0 * round(p.y));
            if (((n >> a) & 1) == 1) return 1.0f;
        }
    }
    return 0.0f;
}

void main() {
    vec2 pix = gl_FragCoord.xy;
    vec3 col = texture(inputTexture, floor(pix/8.0)*8.0/vec2(2560, 1440)).rgb;

    float gray = 0.3 * col.r + 0.59 * col.g + 0.11 * col.b;

    if (col.r < 0.05f && col.g < 0.05f && col.g < 0.05f) {
        col = vec3(1.0f);
    }


    int n =  4096;                // .
    if (gray > 0.2) n = 65600;    // :
    if (gray > 0.3) n = 332772;   // *
    if (gray > 0.4) n = 15255086; // o
    if (gray > 0.5) n = 23385164; // &
    if (gray > 0.6) n = 15252014; // 8
    if (gray > 0.7) n = 13199452; // @
    if (gray > 0.8) n = 11512810; // #

    vec2 p = mod(pix/4.0, 2.0) - vec2(1.0);

    col = col * character(n, p);

    fragColor = vec4(col, 1.0);
}