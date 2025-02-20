#ifndef NOISE_H
#define NOISE_H

#include "constants.h"

// hash function for noise (for highp only)
highp float rand(highp vec2 n) {
  return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

// rand with transition
float randt(vec2 n, vec2 t) {
  return smoothstep(t.x, t.y, rand(n));
}

// 1D noise - used in plants,lantern wave
highp float noise1D(highp float x) {
  float x0 = floor(x);
  float t0 = x-x0;
  t0 *= t0*(3.0-2.0*t0);
  return mix(fract(sin(x0)*84.85), fract(sin(x0+1.0)*84.85), t0);
}

// simpler rand for disp, puddles
float fastRand(vec2 n){
  return fract(37.45*sin(dot(n, vec2(4.36, 8.28))));
}

// water displacement map (also used by caustic)
float disp(vec3 pos, highp float t) {
  float val = 0.5 + 0.5*sin(t*1.7 + (pos.x+pos.y)*NL_CONST_PI_HALF);
  return mix(fastRand(pos.xz), fastRand(pos.xz+vec2_splat(1.0)), val);
}
/*
float noise2D(vec2 u) {
  vec2 u0 = floor(u);
  vec2 v = u-u0;
  v = 3.0*v*v - 2.0*v*v*v;

  float c0 = rand(u0);
  float c1 = rand(u0+vec2(1.0, 0.0));
  float c2 = rand(u0+vec2(1.0, 1.0));
  float c3 = rand(u0+vec2(0.0, 1.0));

  float n = mix(mix(c0, c3, v.y),mix(c1, c2, v.y), v.x);
  return n;
}
*/
vec2 mod289(vec2 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}

vec3 mod289(vec3 x)
{
	return x - floor(x * (1.0 / 289.0)) * 289.0;
}

vec3 permute(vec3 x)
{
	return mod289(((x * 34.0) + 1.0) * x);
}

float hash(vec2 p) {
	vec3 p3 = fract(vec3(p.xyx) * 0.13);
	p3 += dot(p3, p3.yzx + 3.333);
	
	return fract((p3.x + p3.y) * p3.z);
}

float noise2D(vec2 x) {
	vec2 i = floor(x);
	vec2 f = fract(x);
	float a = hash(i);
	float b = hash(i+vec2(1.0, 0.0));
	float c = hash(i+vec2(0.0, 1.0));
	float d = hash(i+vec2(1.0, 1.0));
	vec2 u = f * f * (3.0 - 2.0 * f);

	return mix(a, b, u.x) + (c - a) * u.y * (1.0 - u.x) + (d - b) * u.x * u.y;
}

float fbm(vec2 x) {
	float v = 0.0;
	float a = 0.5;
	vec2 shift = vec2(1.0);
	mat2 rot = mat2(cos(0.5), sin(0.5), -sin(0.5), cos(0.50));
	
	for(int i=0;i < 10; ++i) {
		v += a * noise(x);
		//x += frameTimeCounter * 0.02;
		//shift -= frameTimeCounter * 0.02;
		x = rot * x * 2.0 + shift;
		a *= 0.5;
	}
	return v;
}

#endif
