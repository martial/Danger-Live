#extension GL_ARB_texture_rectangle : enable
uniform sampler2DRect src_tex_unit0;

uniform float brightness;
uniform float saturation;
uniform float contrast;

void main()
{ 
	
	vec4 colorbuffer4;
	vec3 colorbuffer3;
	vec3 result;
    vec4 sum = vec4(0);
    vec2 st = gl_TexCoord[0].st;
   
	
	colorbuffer4 = texture2DRect(src_tex_unit0, st);
	
	colorbuffer3.r = colorbuffer4.r;
	colorbuffer3.g = colorbuffer4.g;
	colorbuffer3.b = colorbuffer4.b;
	
	const float AvgLumR = 0.5;
	const float AvgLumG = 0.5;
	const float AvgLumB = 0.5;
	
	const vec3 LumCoeff = vec3(0.2125, 0.7154, 0.0721);
	
	vec3 AvgLumin = vec3(AvgLumR, AvgLumG, AvgLumB);
	vec3 brtColor = colorbuffer3 * brightness;
	vec3 intensity = vec3(dot(brtColor, LumCoeff));
	vec3 satColor = mix(intensity, brtColor, saturation);
	vec3 conColor = mix(AvgLumin, satColor, contrast);
	
	colorbuffer4.r = conColor.r;
	colorbuffer4.g = conColor.g;
	colorbuffer4.b = conColor.b;
	
	gl_FragColor = colorbuffer4;
	
  	
}

