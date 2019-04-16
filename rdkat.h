/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2017 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef RDK_AT_H
#define RDK_AT_H

#include <iostream>
#include <string>
#include <list>

namespace RDK_AT {

struct TTSConfiguration {
    TTSConfiguration() : m_volume(0), m_rate(0) {}
    ~TTSConfiguration() {}

    std::string m_ttsEndPoint;
    std::string m_ttsEndPointSecured;
    std::string m_language;
    std::string m_voice;
    double m_volume;
    uint8_t m_rate;
};

// This callback is set from the caller to facilitate RDK_AT to control media volume on need.
// The callback takes the below params
// data - an opaque pointer data received from the caller on NotifyURLChange()
// volume - volume level ranging [0-1], 0-no volume, 1-full media volume
// restore - a boolean specifying whether the media volume needs to be set or it needs to be reverted.
// back to the old volume. When restore is true, the volume param will be ignored.
typedef void (*MediaVolumeControlCallback)(void *data, float volume, bool restore);

void Initialize();
void EnableVoiceGuidance(bool enableTTS);
void ConfigureTTS(TTSConfiguration &config);
void NotifyURLChange(std::string url, MediaVolumeControlCallback mediaVolumeControlCB, void *data);
void Uninitialize();

}

#endif // RDK_AT_H