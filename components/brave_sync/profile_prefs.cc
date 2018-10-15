/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */
#include "brave/components/brave_sync/profile_prefs.h"

#include "base/debug/stack_trace.h"
#include "brave/components/brave_sync/debug.h"
#include "brave/components/brave_sync/pref_names.h"
#include "brave/components/brave_sync/settings.h"
#include "chrome/browser/profiles/profile.h"
#include "components/prefs/pref_service.h"
#include "content/public/browser/browser_thread.h"

namespace brave_sync {

namespace prefs {

Prefs::Prefs(Profile* profile) : pref_service_(nullptr) {
  DCHECK(profile);
  pref_service_ = profile->GetPrefs();
}

std::string Prefs::GetSeed() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetString(kSeed);
}

void Prefs::SetSeed(const std::string& seed) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  DCHECK(!seed.empty());
  pref_service_->SetString(kSeed, seed);
}

std::string Prefs::GetThisDeviceId() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetString(kThisDeviceId);
}

void Prefs::SetThisDeviceId(const std::string& device_id) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  DCHECK(!device_id.empty());
  pref_service_->SetString(kThisDeviceId, device_id);
}

std::string Prefs::GetThisDeviceName() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetString(kThisDeviceName);
}

void Prefs::SetThisDeviceName(const std::string& device_name) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  DCHECK(!device_name.empty());
  pref_service_->SetString(kThisDeviceName, device_name);
}
std::string Prefs::GetBookmarksBaseOrder() {
  return pref_service_->GetString(kBookmarksBaseOrder);
}
void Prefs::SetBookmarksBaseOrder(const std::string& order) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  DCHECK(ValidateBookmarksBaseOrder(order));
  pref_service_->SetString(kBookmarksBaseOrder, order);
}

bool Prefs::GetSyncThisDevice() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetBoolean(kSyncThisDeviceEnabled);
}

void Prefs::SetSyncThisDevice(const bool sync_this_device) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->SetBoolean(kSyncThisDeviceEnabled, sync_this_device);
}

bool Prefs::GetSyncBookmarksEnabled() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetBoolean(kSyncBookmarksEnabled);
}

void Prefs::SetSyncBookmarksEnabled(const bool sync_bookmarks_enabled) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->SetBoolean(kSyncBookmarksEnabled, sync_bookmarks_enabled);
}

bool Prefs::GetSyncSiteSettingsEnabled() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetBoolean(kSiteSettingsEnabled);
}

void Prefs::SetSyncSiteSettingsEnabled(const bool sync_site_settings_enabled) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->SetBoolean(kSiteSettingsEnabled, sync_site_settings_enabled);
}

bool Prefs::GetSyncHistoryEnabled() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetBoolean(kHistoryEnabled);
}

void Prefs::SetSyncHistoryEnabled(const bool sync_history_enabled) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->SetBoolean(kHistoryEnabled, sync_history_enabled);
}

std::unique_ptr<brave_sync::Settings> Prefs::GetBraveSyncSettings() const {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  auto settings = std::make_unique<brave_sync::Settings>();

  settings->this_device_name_ = GetThisDeviceName();
  settings->sync_this_device_ = GetSyncThisDevice();
  settings->sync_bookmarks_ = GetSyncBookmarksEnabled();
  settings->sync_settings_ = GetSyncSiteSettingsEnabled();
  settings->sync_history_ = GetSyncHistoryEnabled();

  settings->sync_configured_ =
      !GetSeed().empty() && !GetThisDeviceName().empty();

  return settings;
}

void Prefs::SetLatestRecordTime(const base::Time &time) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->SetTime(kLatestRecordTime, time);
}

base::Time Prefs::GetLatestRecordTime() {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetTime(kLatestRecordTime);
}

void Prefs::SetLastFetchTime(const base::Time &time) {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->SetTime(kLastFetchTime, time);
}

base::Time Prefs::GetLastFetchTime() {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  return pref_service_->GetTime(kLastFetchTime);
}

void Prefs::Clear() {
  DCHECK_CURRENTLY_ON(content::BrowserThread::UI);
  pref_service_->ClearPref(kThisDeviceId);
  pref_service_->ClearPref(kSeed);
  pref_service_->ClearPref(kThisDeviceName);
  pref_service_->ClearPref(kSyncThisDeviceEnabled);
  pref_service_->ClearPref(kSyncBookmarksEnabled);
  pref_service_->ClearPref(kSiteSettingsEnabled);
  pref_service_->ClearPref(kHistoryEnabled);
  pref_service_->ClearPref(kLatestRecordTime);
  pref_service_->ClearPref(kLastFetchTime);
}

} // namespace prefs

} // namespace brave_sync
