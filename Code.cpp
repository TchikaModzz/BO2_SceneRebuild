#pragma region Scene_Rebuilding
struct Scene_CustomisationVar {
    struct Color      // Hi ! 
    {                  // You Can Remove me if you have already one color structure of define into your solution.
        float r, g, b, a;
    };

    Color SunColor;
    Color SunInSkyClr;
    Color FogColor;
    vec3_t SkyAngle; // u can use Vector3 if u dont have this one exaclty
    bool fadelightsun;
};
Scene_CustomisationVar sceneeuh;

void SetRenderScene(){
            /* Structure & ptr Definitions */
  uintptr_t ptr /* GfxWorld */ = *reinterpret_cast<uintptr_t*>(0x2B18DFC);uintptr_t SkyCubeMapTechnique = *reinterpret_cast<uintptr_t*>(0x2B18D20); 
  uintptr_t adr_FogColor = 0x2B18DDC;uintptr_t adr_FogIntensity = 0x2B18DBC + 0x04;uintptr_t adr_SunColor = 0x2B18DEC; 
  Color* FogColorScene = (Color*)(adr_FogColor); Color* SunColorScene = (Color*)(ptr + 0x58); Color* SunColorInSky = (Color*)(adr_SunColor);
  vec3_t* SkyAngleScene = (vec3_t*)(SkyCubeMapTechnique + 0x28);

  /* Override Scene Color */
  SunColorScene->r = sceneeuh.SunColor.r;  // Sun Color
  SunColorScene->g = sceneeuh.SunColor.g;
  SunColorScene->b = sceneeuh.SunColor.b;

  FogColorScene->r = sceneeuh.FogColor.r;       // Fog Color
  FogColorScene->g = sceneeuh.FogColor.g;
  FogColorScene->b = sceneeuh.FogColor.b;

  SunColorInSky->r = sceneeuh.SunInSkyClr.r;        // Real SUN Color
  SunColorInSky->g = sceneeuh.SunInSkyClr.g;  
  SunColorInSky->b = sceneeuh.SunInSkyClr.b;

  SkyAngleScene->x = sceneeuh.SkyAngle.x + 1;        // Sky Angle ( not perfect, sorry for my imcompetence)
  SkyAngleScene->y = sceneeuh.SkyAngle.y + 1;
  SkyAngleScene->z = sceneeuh.SkyAngle.z + 1;
                                                                                                                                                                              /* R_RenderScene Reversed and Code Writed By TchikaModz */
                                                                                                                                                                              /*                                              >-==:   */ 
}
#pragma endregion
