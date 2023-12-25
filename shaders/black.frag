uniform sampler2D texture;

void main(){
    vec4 color = texture2D(texture,gl_TexCoord[0].xy);

    float grayscale = dot(color.rgb, vec3(0.299,0.587, 0.114));

    gl_FragColor = vec4(grayscale,grayscale,grayscale,color.a);
}