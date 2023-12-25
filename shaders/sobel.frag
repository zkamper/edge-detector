uniform sampler2D texture;

const int blurRadius = 1;
const float PI = 3.1415926535;
uniform vec2 screenSize;

mat3 sobel_gx = mat3(
    -1.0, 0.0, 1.0,
    -2.0, 0.0, 2.0,
    -1.0, 0.0, 1.0
);

mat3 sobel_gy = mat3(
    -1.0, -2.0,- 1.0,
    0.0, 0.0, 0.0,
    1.0, 2.0, 1.0
);

void main(){
    vec2 uv = gl_TexCoord[0].xy;
    vec2 normalize = 1.0 / screenSize;

    float gx = 0.0;
    float gy = 0.0;

    for(int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            gx += texture2D(texture, uv + vec2(i, j) * normalize).r * sobel_gx[i+1][j+1];
            gy += texture2D(texture, uv + vec2(i, j) * normalize).r * sobel_gy[i+1][j+1];
        }
    }
    float dir = atan(gy,gx);
    float intensity = sqrt(gx * gx + gy * gy);
    float r_val = (cos(dir) + 1.0) / 2.0 * intensity;
    float g_val = (cos(dir + 2.0 / 3.0 * PI) + 1.0) / 2.0 * intensity;
    float b_val = (cos(dir + 4.0 / 3.0 * PI) + 1.0) / 2.0 * intensity;

    gl_FragColor = vec4(r_val,g_val,b_val,1.0);
}