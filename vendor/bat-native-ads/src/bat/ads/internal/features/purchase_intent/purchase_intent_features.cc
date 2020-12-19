/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/features/purchase_intent/purchase_intent_features.h"

// #include "base/metrics/field_trial.h"
#include "base/metrics/field_trial_params.h"
#include "bat/ads/internal/ad_serving/ad_targeting/models/purchase_intent/purchase_intent_model_values.h"

namespace ads {
namespace features {

const base::Feature kPurchaseIntent {
  "PurchaseIntent",
  base::FEATURE_ENABLED_BY_DEFAULT
};

bool IsPurchaseIntentEnabled() {
  return base::FeatureList::IsEnabled(kPurchaseIntent);
}

// TODO(Moritz Haller): Type ok here or use int?
uint16_t GetPurchaseIntentTreshold() {
  return GetFieldTrialParamByFeatureAsInt(kPurchaseIntent,
      "threshold", ad_targeting::model::kThreshold);
}

int64_t GetPurchaseIntentTimeWindowInSeconds() {
  return GetFieldTrialParamByFeatureAsInt(kPurchaseIntent,
      "time_window_in_seconds", ad_targeting::model::kTimeWindowInSeconds);
}

}  // namespace features
}  // namespace ads
