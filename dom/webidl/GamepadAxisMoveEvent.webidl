/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 */

[Pref="dom.gamepad.non_standard_events.enabled",
 Exposed=Window]
interface GamepadAxisMoveEvent : GamepadEvent
{
  constructor(DOMString type,
              optional GamepadAxisMoveEventInit eventInitDict = {});

  readonly attribute unsigned long axis;
  readonly attribute double value;
};

dictionary GamepadAxisMoveEventInit : GamepadEventInit
{
  unsigned long axis = 0;
  double value = 0;
};
