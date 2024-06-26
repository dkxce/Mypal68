/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

[Exposed=Window]
interface IDBMutableFile : EventTarget {
  readonly attribute DOMString name;
  readonly attribute DOMString type;

  readonly attribute IDBDatabase database;

  [Throws]
  IDBFileHandle open(optional FileMode mode = "readonly");

  attribute EventHandler onabort;
  attribute EventHandler onerror;
};
