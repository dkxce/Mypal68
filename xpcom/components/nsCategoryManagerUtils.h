/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef nsCategoryManagerUtils_h__
#define nsCategoryManagerUtils_h__

void NS_CreateServicesFromCategory(const char* aCategory, nsISupports* aOrigin,
                                   const char* aObserverTopic,
                                   const char16_t* aObserverData = nullptr);

#endif
