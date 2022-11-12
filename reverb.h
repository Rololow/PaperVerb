#pragma once

#include <vector>
#include "JuceHeader.h"

class reverb
{
public:

	void setRoomSize(float roomSize);
	void setDamping(float damping);
	void setWetLevel(float wetLevel);
	void setDryLevel(float dryLevel);
	void setWidth(float width);
	void setFreezeMode(bool freezeMode);

	void processBlock(juce::AudioBuffer<float>& buffer);

private:
	float samplingRate;
	std::vector<float> dnBuffer;

	juce::Reverb::Parameters parameters;

	juce::Reverb reverb;
};

