#ifndef LORAWAN_DEV_TOOL_APP_CORE_APP_CONFIG_H_
#define LORAWAN_DEV_TOOL_APP_CORE_APP_CONFIG_H_

namespace conf {

// TODO: Сделать через константу в прошивке (брать с определенного адреса)
constexpr auto kID = 1;
constexpr auto kNChannels = 4;
constexpr auto kStorageSize = 100;
constexpr auto kWdgPeriodMs = 5000;
constexpr auto kAutoRebootTimeMs = 30000;
constexpr auto kWaitAfterGenerationMs = 100;
constexpr auto kFDataLen = 16000
  ;
constexpr auto kFilterLevel = 7;

constexpr auto kFStart = 450;
constexpr auto kFEnd = 1200;
constexpr auto kImpCount = 604;

}

#endif //LORAWAN_DEV_TOOL_APP_CORE_APP_CONFIG_H_
