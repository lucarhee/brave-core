/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/features/text_classification/text_classification_features.h"

#include "base/metrics/field_trial_params.h"
#include "bat/ads/internal/ad_targeting/processors/text_classification/text_classification_processor_values.h"

namespace ads {
namespace features {

const base::Feature kTextClassification {
  "TextClassification",
  base::FEATURE_ENABLED_BY_DEFAULT
};

bool IsTextClassificationEnabled() {
  return base::FeatureList::IsEnabled(kTextClassification);
}

int GetTextClassificationProbabilitiesHistorySize() {
  return GetFieldTrialParamByFeatureAsInt(kTextClassification,
      "page_probabilities_history_size",
          ad_targeting::processor::kDefaultProbabilitiesHistorySize);
}

}  // namespace features
}  // namespace ads
