/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_ACCOUNT_WALLET_WALLET_H_
#define BAT_ADS_INTERNAL_ACCOUNT_WALLET_WALLET_H_

#include <string>

#include "bat/ads/internal/account/wallet/wallet_info.h"

namespace ads {

class Wallet {
 public:
  Wallet();

  ~Wallet();

  bool Set(
      const std::string& id,
      const std::string& seed);

  WalletInfo Get() const;

 private:
  WalletInfo wallet_;
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_ACCOUNT_WALLET_WALLET_H_
