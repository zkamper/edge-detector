uniform sampler2D texture;

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
    float i = sqrt(gx * gx + gy * gy);

    gl_FragColor = vec4(i,i,i,1.0);
}