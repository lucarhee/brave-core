/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_SORTS_ADS_HISTORY_SORT_FACTORY_H_
#define BAT_ADS_INTERNAL_SORTS_ADS_HISTORY_SORT_FACTORY_H_

#include <memory>

#include "bat/ads/internal/sorts/ads_history_sort.h"
#include "bat/ads/ads_history.h"

namespace ads {

class AdsHistorySortFactory {
 public:
  static std::unique_ptr<AdsHistorySort> Build(
      const AdsHistory::SortType type);
};

}  // namespace ads

#endif  // BAT_ADS_INTERNAL_SORTS_ADS_HISTORY_SORT_FACTORY_H_
