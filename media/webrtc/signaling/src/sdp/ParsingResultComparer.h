/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef _PARSINGRESULTCOMPARER_H_
#define _PARSINGRESULTCOMPARER_H_

#include "signaling/src/sdp/SdpParser.h"

#include <string>

namespace mozilla {

class Sdp;
class SdpMediaSection;
class SdpAttributeList;

enum class SdpComparisonResult {
  Inequal = false,
  Equal = true,
};

class ParsingResultComparer {
 public:
  using Results = UniquePtr<SdpParser::Results>;

  ParsingResultComparer() = default;

  static bool Compare(const Results& aResA, const Results& aResB,
                      const std::string& aOrignalSdp);
  bool Compare(const Sdp& rsdparsaSdp, const Sdp& sipccSdp,
               const std::string& aOriginalSdp,
               const SdpComparisonResult expect = SdpComparisonResult::Equal);
  bool CompareMediaSections(
      const SdpMediaSection& rustMediaSection,
      const SdpMediaSection& sipccMediaSection,
      const SdpComparisonResult expect = SdpComparisonResult::Equal) const;
  bool CompareAttrLists(
      const SdpAttributeList& rustAttrlist,
      const SdpAttributeList& sipccAttrlist, int level,
      const SdpComparisonResult expect = SdpComparisonResult::Equal) const;
  void TrackRustParsingFailed(size_t sipccErrorCount) const;
  void TrackSipccParsingFailed(size_t rustErrorCount) const;

 private:
  std::string mOriginalSdp;

  std::string GetAttributeLines(const std::string& attrType, int level) const;
};

}  // namespace mozilla

#endif  // _PARSINGRESULTCOMPARER_H_
