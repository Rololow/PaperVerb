#include "reverb.h"

void reverb::setRoomSize(float roomSize)
{
	this->parameters.roomSize = roomSize;
}

void reverb::setDamping(float damping)
{
	this->parameters.damping = damping;
}

void reverb::setWetLevel(float wetLevel)
{
	this->parameters.wetLevel = wetLevel;
}

void reverb::setDryLevel(float dryLevel)
{
	this->parameters.dryLevel = dryLevel;
}

void reverb::setWidth(float width)
{
	this->parameters.width = width;
}

void reverb::setFreezeMode(bool freezeMode)
{
	this->parameters.freezeMode = freezeMode;
}

void reverb::processBlock(juce::AudioBuffer<float>& buffer)
{

    this->reverb.setParameters(this->parameters);

    juce::ScopedNoDenormals noDenormals;

    const int totalNumInputChannels = juce::AudioProcessor::getTotalNumInputChannels();
    const int totalNumOutputChannels = juce::AudioProcessor::getTotalNumOutputChannels();

    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());


    const auto numChannels = juce::jmin(totalNumInputChannels, totalNumOutputChannels);

    if (numChannels == 1)
        reverb.processMono(buffer.getWritePointer(0), buffer.getNumSamples());

    else if (numChannels == 2)
        reverb.processStereo(buffer.getWritePointer(0), buffer.getWritePointer(1), buffer.getNumSamples());

}


