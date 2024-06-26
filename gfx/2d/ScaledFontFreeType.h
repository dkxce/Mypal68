/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef MOZILLA_GFX_SCALEDFONTCAIRO_H_
#define MOZILLA_GFX_SCALEDFONTCAIRO_H_

#include "ScaledFontBase.h"

#include <cairo-ft.h>

namespace mozilla {
namespace gfx {

class ScaledFontFreeType : public ScaledFontBase {
 public:
  MOZ_DECLARE_REFCOUNTED_VIRTUAL_TYPENAME(ScaledFontFreeType, override)

  ScaledFontFreeType(cairo_scaled_font_t* aScaledFont, FT_Face aFace,
                     const RefPtr<UnscaledFont>& aUnscaledFont, Float aSize);

  FontType GetType() const override { return FontType::FREETYPE; }

#ifdef USE_SKIA
  virtual SkTypeface* CreateSkTypeface() override;
#endif

  bool CanSerialize() override { return true; }

  bool GetFontInstanceData(FontInstanceDataOutput aCb, void* aBaton) override;

#ifdef MOZ_BUILD_WEBRENDER
  bool GetWRFontInstanceOptions(
      Maybe<wr::FontInstanceOptions>* aOutOptions,
      Maybe<wr::FontInstancePlatformOptions>* aOutPlatformOptions,
      std::vector<FontVariation>* aOutVariations) override;
#endif

  bool HasVariationSettings() override;

 private:
  FT_Face mFace;
};

}  // namespace gfx
}  // namespace mozilla

#endif /* MOZILLA_GFX_SCALEDFONTCAIRO_H_ */
