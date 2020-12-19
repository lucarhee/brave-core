/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/features/bandits/epsilon_greedy_bandit_features.h"

#include "base/metrics/field_trial_params.h"
#include "bat/ads/internal/ad_serving/ad_targeting/models/bandits/epsilon_greedy_bandit_model_values.h"

namespace ads {
namespace features {

const base::Feature kEpsilonGreedyBandit {
  "EpsilonGreedyBandit",
  base::FEATURE_DISABLED_BY_DEFAULT
};

bool IsEpsilonGreedyBanditEnabled() {
  return base::FeatureList::IsEnabled(kEpsilonGreedyBandit);
}

uint16_t GetEpsilonGreedyBanditEpsilon() {
  return GetFieldTrialParamByFeatureAsInt(kEpsilonGreedyBandit,
      "threshold", ad_targeting::model::kEpsilon);
}


}  // namespace features
}  // namespace ads
