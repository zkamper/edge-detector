uniform sampler2D texture;

const int blurRadius = 1;
uniform vec2 screenSize;
mat3 gaussianBlurMatrix = mat3(
        1.0, 2.0, 1.0,
        2.0, 4.0, 2.0,
        1.0, 2.0, 1.0
);

void main(){
    vec2 uv = gl_TexCoord[0].xy;
    vec2 normalize = 1.0 / screenSize;

    vec3 sum = vec3(0.0);
    for(int i = -blurRadius; i <= blurRadius; i++)
    {
        for(int j = -blurRadius; j <= blurRadius; j++)
        {
            sum += texture2D(texture, uv + vec2(i, j) * normalize).rgb * gaussianBlurMatrix[i+blurRadius][j+blurRadius];
        }
    }
    sum /= 16.0;
    gl_FragColor = vec4(sum,1.0);
}