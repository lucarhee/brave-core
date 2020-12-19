/* Copyright (c) 2020 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "bat/ads/internal/features/features.h"
#include "bat/ads/internal/features/bandits/epsilon_greedy_bandit_features.h"
#include "bat/ads/internal/features/purchase_intent/purchase_intent_features.h"
#include "bat/ads/internal/features/text_classification/text_classification_features.h"
#include "base/metrics/field_trial.h"
#include "base/strings/string_number_conversions.h"
#include "bat/ads/internal/logging.h"

namespace ads {
namespace features {

namespace {
// TODO(Moritz Haller): Better than empty string, maybe optional?
const char kActiveStudyName[] = "";
}  // namespace

bool HasActiveStudy() {
  if (!base::FieldTrialList::Find(kActiveStudyName)) {
    return false;
  }

  return true;
}

std::string GetStudy() {
  return kActiveStudyName;
}

std::string GetGroup() {
  std::string group_name;
  base::FieldTrial* field_trial = base::FieldTrialList::Find(kActiveStudyName);
  if (!field_trial) {
    return group_name;
  }

  group_name = field_trial->group_name();
  return group_name;
}

// TODO(Moritz Haller): Maybe not pull out into features_logging.cc
void Log() {
  if (!HasActiveStudy()) {
    BLOG(1, "No active study found");
  } else {
    const std::string study = GetStudy();
    const std::string group = GetGroup();
    BLOG(1, "Running study " << study << " with group " << group);
  }

  if (IsTextClassificationEnabled()) {
    BLOG(1, "Text Classification enabled");
  } else {
    BLOG(1, "Text Classification disabled");
  }

  if (IsEpsilonGreedyBanditEnabled()) {
    BLOG(1, "Epsilon Greedy Bandit enabled");
  } else {
    BLOG(1, "Epsilon Greedy Bandit disabled");
  }

  if (IsPurchaseIntentEnabled()) {
    BLOG(1, "Purchase Intent enabled");
  } else {
    BLOG(1, "Purchase Intent disabled");
  }
}

}  // namespace features
}  // namespace ads
