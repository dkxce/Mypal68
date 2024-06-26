/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "AudioScheduledSourceNode.h"

namespace mozilla {
namespace dom {

AudioScheduledSourceNode::AudioScheduledSourceNode(
    AudioContext* aContext, uint32_t aChannelCount,
    ChannelCountMode aChannelCountMode,
    ChannelInterpretation aChannelInterpretation)
    : AudioNode(aContext, aChannelCount, aChannelCountMode,
                aChannelInterpretation) {}
}  // namespace dom
}  // namespace mozilla
