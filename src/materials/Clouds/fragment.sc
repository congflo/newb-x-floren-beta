$input v_color0
#include <newb/config.h>
#if NL_CLOUD_TYPE == 2
  $input v_color1, v_color2, v_fogColor
#endif

#include <bgfx_shader.sh>
#include <newb/main.sh>

uniform vec4 FogColor;
uniform vec4 FogAndDistanceControl;
uniform vec4 ViewPositionAndTime;

void main() {
  vec4 color = v_color0;
  vec4 wt = worldTimeDetection(FogColor.rgb, FogAndDistanceControl.xyz);

  vec3 getCloudCol = cloudCol(wt.x, wt.z, wt.w);
  
  #if NL_CLOUD_TYPE == 2
    vec3 vDir = normalize(v_color0.xyz);

    color = renderClouds(vDir, v_color0.xyz, v_color1.a, v_color2.a, getCloudCol, v_color1.rgb);

    #ifdef NL_CLOUD2_MULTILAYER
      vec2 parallax = vDir.xz / abs(vDir.y) * 143.0;
      vec3 offsetPos = v_color0.xyz;
      offsetPos.xz += parallax;
      vec4 color2 = renderClouds(vDir, offsetPos, v_color1.a, v_color2.a*2.0, getCloudCol, v_color1.rgb);
      color = mix(color2, color, 0.2 + 0.8*color.a);
    #endif

    #ifdef NL_AURORA
      color += renderAurora(v_color0.xyz, v_color2.a, v_color1.a, v_fogColor)*(1.0-0.95*color.a);
    #endif

    color.a *= v_color0.a;

    color.rgb = colorCorrection(color.rgb);
  #endif

  gl_FragColor = color;
}
