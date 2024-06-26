/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_URLDecorationStripper_h
#define mozilla_URLDecorationStripper_h

#include "nsStringFwd.h"

class nsIURI;

namespace mozilla {

class URLDecorationStripper final {
 public:
  static nsresult StripTrackingIdentifiers(nsIURI* aURI, nsACString& aOutSpec);

 private:
  static nsresult StripToRegistrableDomain(nsIURI* aURI, nsACString& aOutSpec);
};

}  // namespace mozilla

#endif  // mozilla_URLDecorationStripper_h
