/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * The origin of this IDL file is
 * http://notifications.spec.whatwg.org/
 *
 * Copyright:
 * To the extent possible under law, the editors have waived all copyright and
 * related or neighboring rights to this work.
 */

[Exposed=ServiceWorker,Func="mozilla::dom::Notification::PrefEnabled"]
interface NotificationEvent : ExtendableEvent {
  constructor(DOMString type, NotificationEventInit eventInitDict);

  [BinaryName="notification_"]
  readonly attribute Notification notification;
};

dictionary NotificationEventInit : ExtendableEventInit {
  required Notification notification;
};
