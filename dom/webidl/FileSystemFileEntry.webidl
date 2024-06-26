/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * https://wicg.github.io/entries-api/#idl-index
 */

callback FileCallback = void (File file);

[Exposed=Window]
interface FileSystemFileEntry : FileSystemEntry {
    [BinaryName="GetFile"]
    void file (FileCallback successCallback,
               optional ErrorCallback errorCallback);
};
