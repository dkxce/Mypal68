/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* An enumeration of all possible element types in typed data. */

#ifndef js_ScalarType_h
#define js_ScalarType_h

#include "mozilla/Assertions.h"  // MOZ_CRASH

#include <stddef.h>  // size_t

namespace js {

namespace Scalar {

// Scalar types that can appear in typed arrays and typed objects.
// The enum values must be kept in sync with:
//  * the JS_SCALARTYPEREPR constants
//  * the TYPEDARRAY_KIND constants
//  * the SCTAG_TYPED_ARRAY constants
//  * JS_FOR_EACH_TYPEDARRAY
//  * JS_FOR_PROTOTYPES_
//  * JS_FOR_EACH_UNIQUE_SCALAR_TYPE_REPR_CTYPE
//  * JIT compilation
enum Type {
  Int8 = 0,
  Uint8,
  Int16,
  Uint16,
  Int32,
  Uint32,
  Float32,
  Float64,

  /**
   * Special type that is a uint8_t, but assignments are clamped to [0, 256).
   * Treat the raw data type as a uint8_t.
   */
  Uint8Clamped,

  BigInt64,
  BigUint64,

  /**
   * Types that don't have their own TypedArray equivalent, for now.
   */
  MaxTypedArrayViewType,

  Int64,
};

static inline size_t byteSize(Type atype) {
  switch (atype) {
    case Int8:
    case Uint8:
    case Uint8Clamped:
      return 1;
    case Int16:
    case Uint16:
      return 2;
    case Int32:
    case Uint32:
    case Float32:
      return 4;
    case Int64:
    case Float64:
    case BigInt64:
    case BigUint64:
      return 8;
    case MaxTypedArrayViewType:
      break;
  }
  MOZ_CRASH("invalid scalar type");
}

static inline bool isSignedIntType(Type atype) {
  switch (atype) {
    case Int8:
    case Int16:
    case Int32:
    case Int64:
    case BigInt64:
      return true;
    case Uint8:
    case Uint8Clamped:
    case Uint16:
    case Uint32:
    case Float32:
    case Float64:
    case BigUint64:
      return false;
    case MaxTypedArrayViewType:
      break;
  }
  MOZ_CRASH("invalid scalar type");
}

static inline bool isBigIntType(Type atype) {
  switch (atype) {
    case BigInt64:
    case BigUint64:
      return true;
    case Int8:
    case Int16:
    case Int32:
    case Int64:
    case Uint8:
    case Uint8Clamped:
    case Uint16:
    case Uint32:
    case Float32:
    case Float64:
      return false;
    case MaxTypedArrayViewType:
      break;
  }
  MOZ_CRASH("invalid scalar type");
}

}  // namespace Scalar

}  // namespace js

#endif  // js_ScalarType_h
