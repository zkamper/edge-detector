uniform sampler2D texture;

uniform float threshold;

void main(){
    vec4 color = texture2D(texture,gl_TexCoord[0].xy);
    if(color.r > threshold){
        gl_FragColor = vec4(1.0,1.0,1.0,color.a);
    }
    else{
        gl_FragColor = vec4(0.0,0.0,0.0,color.a);
    }
}