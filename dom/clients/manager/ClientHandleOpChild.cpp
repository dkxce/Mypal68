/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "ClientHandleOpChild.h"

#include "ClientHandle.h"

namespace mozilla {
namespace dom {

void ClientHandleOpChild::ActorDestroy(ActorDestroyReason aReason) {
  mClientHandle = nullptr;
  CopyableErrorResult rv;
  rv.ThrowAbortError("Client load aborted");
  mRejectCallback(rv);
}

mozilla::ipc::IPCResult ClientHandleOpChild::Recv__delete__(
    const ClientOpResult& aResult) {
  mClientHandle = nullptr;
  if (aResult.type() == ClientOpResult::TCopyableErrorResult &&
      aResult.get_CopyableErrorResult().Failed()) {
    mRejectCallback(aResult.get_CopyableErrorResult());
    return IPC_OK();
  }
  mResolveCallback(aResult);
  return IPC_OK();
}

ClientHandleOpChild::ClientHandleOpChild(
    ClientHandle* aClientHandle, const ClientOpConstructorArgs& aArgs,
    const ClientOpCallback&& aResolveCallback,
    const ClientOpCallback&& aRejectCallback)
    : mClientHandle(aClientHandle),
      mResolveCallback(std::move(aResolveCallback)),
      mRejectCallback(std::move(aRejectCallback)) {
  MOZ_DIAGNOSTIC_ASSERT(mClientHandle);
  MOZ_DIAGNOSTIC_ASSERT(mResolveCallback);
  MOZ_DIAGNOSTIC_ASSERT(mRejectCallback);
}

}  // namespace dom
}  // namespace mozilla
