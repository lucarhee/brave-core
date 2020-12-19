/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_ADS_INTERNAL_AD_TARGETING_DATA_TYPES_BANDITS_EPSILON_GREEDY_BANDIT_ARMS_H_
#define BAT_ADS_INTERNAL_AD_TARGETING_DATA_TYPES_BANDITS_EPSILON_GREEDY_BANDIT_ARMS_H_

#include <stdint.h>

#include <string>
#include <vector>

#include "base/values.h"
#include "bat/ads/internal/ad_targeting/data_types/bandits/epsilon_greedy_bandit_arm_info.h"

namespace ads {
namespace ad_targeting {

// TODO use map instead of vector
using EpsilonGreedyBanditArmList = std::vector<EpsilonGreedyBanditArmInfo>;

class EpsilonGreedyBanditArms {
 public:
  EpsilonGreedyBanditArms();

  ~EpsilonGreedyBanditArms();

  static EpsilonGreedyBanditArmList FromJson(
      const std::string& json);

  static std::string ToJson(
      const EpsilonGreedyBanditArmList& arms);

 private:
  // TODO(Moritz Haller): private static? better have free functions?
  static EpsilonGreedyBanditArmList GetFromList(
      const base::ListValue* list);

  static bool GetFromDictionary(
      const base::DictionaryValue* dictionary,
      EpsilonGreedyBanditArmInfo* info);
};

}  // namespace ad_targeting
}  // namespace ads

#endif  // BAT_ADS_INTERNAL_AD_TARGETING_DATA_TYPES_BANDITS_EPSILON_GREEDY_BANDIT_ARMS_H_
