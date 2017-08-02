/*
Copyright (c) 2015, Dimitri Diakopoulos All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#ifndef AUDIO_DEVICE_H
#define AUDIO_DEVICE_H

// This file implements a simple sound file player based on RtAudio for testing / example purposes.

#include "Util.h"
#include "RingBuffer.h"
#include "rtaudio/RtAudio.h"

#include <iostream>
#include <memory>

static const unsigned int FRAME_SIZE = 512;
static const int CHANNELS = 2;
static const int BUFFER_LENGTH = FRAME_SIZE * CHANNELS;

struct DeviceInfo
{
	int id;
	int numChannels;
	int sampleRate;
	unsigned int frameSize;
	bool isPlaying = false;
};

class AudioDevice
{
	
	NO_MOVE(AudioDevice);
	std::unique_ptr<RtAudio> rtaudio;
	
public:

	static void ListAudioDevices();
	
	AudioDevice(int numChannels, int sampleRate, int deviceId = -1);
	
	~AudioDevice();
	
	bool Open(const int deviceId);
	
	bool Play(const std::vector<float> & data);
	
	DeviceInfo info;
};

#endif
