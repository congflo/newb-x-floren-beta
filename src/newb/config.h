#ifndef NL_CONFIG_H
#define NL_CONFIG_H

/*
  NEWB SHADER MAIN CONFIG
  This part contains base configuration options for the shader.

  TOGGLES
  - If [toggle] is mentioned, then
    options can be commented to disable (by adding '//')
  - eg: #define PLANTS_WAVE    -> this is ON
        //#define PLANTS_WAVE  -> this is OFF

  COLOR VALUES
  - Color format: vec3(red,green,blue)
  - 1.0 means 100%, 0.0 means 0%
  - eg: vec3(1.0,1.0,0.0) = yellow

  VALUES
  - Values must be decimal
  - eg. 32 is wrong, 32.0 is correct

  TYPES
  - Should be integer. options to choose will be mentioned there
  - eg: #define NL_CLOUD_TYPE 2

  Remember to rebuild the shader after making changes.
*/

/* Color correction */
#define NL_TONEMAP_TYPE 4              // 1:Exponential, 2:Reinhard, 3:Extended Reinhard, 4:ACES
#define NL_GAMMA 1.25                  // 0.3 low ~ 2.0 high
//#define NL_EXPOSURE 1.3              // [toggle] 0.5 dark ~ 3.0 bright
#define NL_SATURATION 1.0            // [toggle] 0.0 grayscale ~ 4.0 super saturated
//#define NL_TINT                      // [toggle] enable light/dark tone tinting
#define NL_TINT_LOW  vec3(0.3,0.5,1.4) // color tint for dark tone
#define NL_TINT_HIGH vec3(1.4,0.7,0.3) // color tint for light tone

/* Terrain lighting */
#define NL_SUN_INTENSITY 5.0   // 0.5 weak ~ 5.0 bright
#define NL_TORCH_INTENSITY 2.25  // 0.5 weak ~ 3.0 bright
#define NL_NIGHT_BRIGHTNESS 0.4 // 0.0 dark ~ 2.0 bright
#define NL_CAVE_BRIGHTNESS 0.1  // 0.0 dark ~ 2.0 bright
#define NL_SHADOW_INTENSITY 1.0 // 0.0 no shadow ~ 1.0 strong shadow
#define NL_BLINKING_TORCH     // [toggle] flickering light
//#define NL_CLOUD_SHADOW       // [toggle] cloud shadow (simple clouds only)

/* Sun/moon light color on terrain */
#define NL_MORNING_SUN_COL vec3(0.6,0.2,0.0)
#define NL_NOON_SUN_COL    vec3(1.00,0.83,0.70)
#define NL_NIGHT_SUN_COL   vec3(0.15,0.15,0.15)

/* Ambient light on terrain (light that is added everywhere) */
#define NL_NETHER_AMBIENT vec3(3.0,2.16,1.89)
#define NL_END_AMBIENT vec3(1.98,1.25,2.3)

/* Torch colors */
#define NL_OVERWORLD_TORCH_COL  vec3(0.77,0.29,0.07)
#define NL_UNDERWATER_TORCH_COL vec3(0.94, 0.33, 0.01)
#define NL_NETHER_TORCH_COL     vec3(0.94, 0.33, 0.01)
#define NL_END_TORCH_COL        vec3(0.94, 0.33, 0.01)

/* Fog */
#define NL_FOG 1.                // [toggle] 0.1 subtle ~ 1.0 blend with sky completely
#define NL_MIST_DENSITY 0.005      // 0.0 no mist ~ 1.0 misty
#define NL_RAIN_MIST_OPACITY 0.12 // [toggle] 0.04 very subtle ~ 0.5 thick rain mist blow
#define NL_CLOUDY_FOG 0.0         // [toggle] 0.0 subtle - 0.8 dense fog clouds

/* Sky colors - zenith=top, horizon=bottom */
#define NL_DAY_ZENITH_COL    vec3(0.24,0.47,0.71)
#define NL_DAY_HORIZON_COL   vec3(0.76,0.85,0.91)
#define NL_NIGHT_ZENITH_COL  vec3(0.00,0.10,0.18)
#define NL_NIGHT_HORIZON_COL vec3(0.01,0.12,0.21)
#define NL_RAIN_ZENITH_COL   vec3(0.12,0.12,0.12)
#define NL_RAIN_HORIZON_COL  vec3(0.2,0.2,0.2)
#define NL_END_ZENITH_COL    vec3(0.06,0.48,0.49)
#define NL_END_HORIZON_COL   vec3(0.19,0.26,0.31)
#define NL_DAWN_ZENITH_COL   vec3(0.1,0.45,0.99)
#define NL_DAWN_HORIZON_COL  vec3(1.00,0.83,0.96)
#define NL_DAWN_EDGE_COL     vec3(1.0,0.27,0.0)

/* Rainbow */
//#define NL_RAINBOW         // [toggle] enable rainbow in sky
#define NL_RAINBOW_CLEAR 0.0 // 0.3 subtle ~ 1.7 bright during clear
#define NL_RAINBOW_RAIN 1.0  // 0.5 subtle ~ 2.0 bright during rain

/* Ore glow intensity */
#define NL_GLOW_TEX 8.0    // 0.4 weak ~ 8.0 bright
//#define NL_GLOW_SHIMMER    // [toggle] shimmer effect
#define NL_GLOW_LEAK 0.18 // [toggle] 0.08 subtle ~ 1.0 100% brightness of NL_GLOW_TEX

/* Waving */
#define NL_PLANTS_WAVE 0.062    // [toggle] 0.02 gentle ~ 0.4 violent
#define NL_LANTERN_WAVE 0.16   // [toggle] 0.05 subtle ~ 0.4 large swing
#define NL_WAVE_SPEED 1.35      // 0.5 slow wave ~ 5.0 very fast wave
//#define NL_EXTRA_PLANTS_WAVE // [toggle] !dont use! wave using texture coords (1.21.0 vanilla 2048x1024)

/* Water */
#define NL_WATER_TRANSPARENCY 0.6 // 0.0 transparent ~ 1.0 normal
#define NL_WATER_BUMP 0.01256789        // 0.001 plain ~ 0.2 bumpy water
#define NL_WATER_TEX_OPACITY 0.79  // 0.1 plain water ~ 1.0 vanilla water texture
#define NL_WATER_WAVE             // [toggle] wave effect
#define NL_WATER_FOG_FADE         // [toggle] fog fade for water
//#define NL_WATER_CLOUD_REFLECTION // [toggle] simple clouds/aurora reflection
//#define NL_WATER_REFL_MASK      // [toggle] fake water reflection mask
#define NL_WATER_TINT vec3(0.92,0.97,1.00) //vec3(0.83,0.86,0.6)

/* Underwater */
#define NL_UNDERWATER_BRIGHTNESS 0.85         // 0.0 dark ~ 3.0 bright
#define NL_CAUSTIC_INTENSITY 5.0             // 0.5 weak ~ 5.0 bright
#define NL_UNDERWATER_WAVE 0.1               // [toggle] 0.02 subtle ~ 0.6 trippy
#define NL_UNDERWATER_STREAKS 2.0            // [toggle] 0.8 subtle - 2.0 bright streaks from top
#define NL_UNDERWATER_TINT vec3(0.92,0.97,1.00) // fog tint color when underwater

/* Cloud type */
#define NL_CLOUD_TYPE 2 // 0:vanilla, 1:soft, 2:rounded

/* Vanilla cloud settings - make sure to remove clouds.png when using this */
#define NL_CLOUD0_THICKNESS 2.1      // 0.5 slim ~ 8.0 fat
#define NL_CLOUD0_RAIN_THICKNESS 4.0 // 0.5 slim ~ 8.0 fat
#define NL_CLOUD0_OPACITY 1.        // 0.0 invisible ~ 1.0 opaque
#define NL_CLOUD0_MULTILAYER         // [toggle] extra cloud layer

/* Soft cloud settings */
#define NL_CLOUD1_SCALE 0.015 //vec2(0.016, 0.022) 0.003 large ~ 0.2 tiny
#define NL_CLOUD1_DEPTH 1.3                // 0.0 no bump ~ 10.0 large bumps
#define NL_CLOUD1_SPEED 0.04               // 0.0 static ~ 0.4 fast moving
#define NL_CLOUD1_DENSITY 0.54             // 0.1 less clouds ~ 0.8 more clouds
#define NL_CLOUD1_OPACITY 0.9              // 0.0 invisible ~ 1.0 opaque

/* Rounded cloud Settings */
#define NL_CLOUD2_THICKNESS 2.32      // 0.5 slim ~ 5.0 fat
#define NL_CLOUD2_RAIN_THICKNESS 3.5 // 0.5 slim ~ 5.0 fat
#define NL_CLOUD2_STEPS 8            // 3 low quality ~ 16 high quality
#define NL_CLOUD2_SCALE 0.033        // 0.003 large ~ 0.3 tiny
#define NL_CLOUD2_SHAPE 0.67          // 0.0 round ~ 1.0 box
#define NL_CLOUD2_DENSITY 42.5       // 1.0 blurry ~ 100.0 sharp
#define NL_CLOUD2_VELOCITY 1.68       // 0.0 static ~ 4.0 very fast
//#define NL_CLOUD2_MULTILAYER       // [toggle] extra cloud layer

/* Aurora settings */
#define NL_AURORA 4.           // [toggle] 0.4 dim ~ 4.0 very bright
#define NL_AURORA_VELOCITY 0.03 // 0.0 static ~ 0.3 very fast
#define NL_AURORA_SCALE 0.02    // 0.002 large ~ 0.4 tiny
#define NL_AURORA_WIDTH 0.3    // 0.04 thin line ~ 0.4 thick lines
#define NL_AURORA_COL1 vec3(0.11, 0.24, 0.43)
#define NL_AURORA_COL2 vec3(0.11, 0.44, 0.53)

/* Shooting star */
#define NL_SHOOTING_STAR 10.        // [toggle] 0.2 dim ~ 1.0 bright
#define NL_SHOOTING_STAR_PERIOD 6.0 // 0.4 fast ~ 12.0 slow (12 secs)
#define NL_SHOOTING_STAR_DELAY 64.0 // 0.0 no delay ~ 100.0 long time (100 secs)

/* Chunk loading slide in animation */
#define NL_CHUNK_LOAD_ANIM -10.0 // [toggle] -600.0 fall from top ~ 600.0 rise from bottom

/* Sun/Moon */
#define NL_SUNMOON_ANGLE 35.0 // [toggle] 0.0 no tilt ~ 90.0 tilt of 90 degrees
#define NL_SUNMOON_SIZE 0.67     // 0.3 tiny ~ 4.0 massive
#define NL_SUN_BLOOM
#define NL_SUN_BLOOM_COL vec3(1.00,0.83,0.70)/5.
#define NL_MOON_BLOOM
#define NL_MOON_BLOOM_COL vec3(0.86,0.96,0.98)/2.5

/* Fake godrays during sunrise/sunset */
//#define NL_GODRAY 0.8 // [toggle] 0.1 subtle ~ 0.8 strong

/* Sky reflection */
#define NL_GROUND_REFL 0.75       // [toggle] 0.2 slightly reflective ~ 1.0 fully reflect sky 
#define NL_GROUND_RAIN_WETNESS 1.0 // 0.0 no wetness ~ 1.0 fully wet blocks when raining
#define NL_GROUND_RAIN_PUDDLES 0.5 // 0.0 no puddles ~ 1.0 puddles
//#define NL_GROUND_AURORA_REFL    // [toggle] aurora reflection on ground

/* Entity (Actor, ItemInHand) */
#define NL_ENTITY_BRIGHTNESS     0.65 // 0.1 dark ~ 1.6 bright
#define NL_ENTITY_EDGE_HIGHLIGHT 0.41 // 0.0 no highlight ~ 1.6 bright highlight

/*
  NEWB SHADER SUBPACK CONFIG
  This part contains custom configuration options for each subpack.

  If a value is already defined,
  then you must undefine it before modifying:
  eg: #undef OPTION_NAME

  Subpack names and flags are inside `pack_config.toml`.
  Build tool will enable corresponding flags when compiling. 
*/

#ifdef MULTILAYER_CLOUDS
  #undef NL_CLOUD2_THICKNESS
  #undef NL_CLOUD2_RAIN_THICKNESS
  #undef NL_CLOUD2_STEPS
  #undef NL_CLOUD2_SCALE
  #undef NL_CLOUD2_SHAPE
  #undef NL_CLOUD2_DENSITY
  #undef NL_CLOUD2_VELOCITY
  #undef NL_CLOUD2_MULTILAYER

  #define NL_CLOUD2_THICKNESS 2.1
  #define NL_CLOUD2_RAIN_THICKNESS 3.5
  #define NL_CLOUD2_STEPS 16
  #define NL_CLOUD2_SCALE 0.067
  #define NL_CLOUD2_SHAPE 0.89
  #define NL_CLOUD2_DENSITY 100.0
  #define NL_CLOUD2_VELOCITY 2.3
  #define NL_CLOUD2_MULTILAYER

#endif

#ifdef EXTRA_MULTILAYER_CLOUDS
  #undef NL_CLOUD2_THICKNESS
  #undef NL_CLOUD2_RAIN_THICKNESS
  #undef NL_CLOUD2_STEPS
  #undef NL_CLOUD2_SCALE
  #undef NL_CLOUD2_SHAPE
  #undef NL_CLOUD2_DENSITY
  #undef NL_CLOUD2_VELOCITY
  #undef NL_CLOUD2_MULTILAYER

  #define NL_CLOUD2_THICKNESS 2.5
  #define NL_CLOUD2_RAIN_THICKNESS 3.5
  #define NL_CLOUD2_STEPS 16
  #define NL_CLOUD2_SCALE 0.067
  #define NL_CLOUD2_SHAPE 0.89
  #define NL_CLOUD2_DENSITY 100.0
  #define NL_CLOUD2_VELOCITY 2.3
  #define NL_CLOUD2_MULTILAYER

#endif

#ifdef SOFT_CLOUDS

  #undef NL_CLOUD_TYPE

  #define NL_CLOUD_TYPE 1

#endif


#endif
