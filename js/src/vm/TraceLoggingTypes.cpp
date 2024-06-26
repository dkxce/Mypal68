/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "vm/TraceLoggingTypes.h"

#include "vm/StringType.h"

class JSLinearString;

uint32_t TLStringToTextId(JSLinearString* str) {
#define NAME(textId) \
  if (js::StringEqualsLiteral(str, #textId)) return TraceLogger_##textId;
  TRACELOGGER_TREE_ITEMS(NAME)
  TRACELOGGER_LOG_ITEMS(NAME)
#undef NAME
  return TraceLogger_Error;
}
