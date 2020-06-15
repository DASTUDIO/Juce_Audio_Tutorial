/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyGateAudioProcessor::MyGateAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	_threshold = new AudioParameterFloat("threshold", "Gate Threshold", 0.0f, 1.0f, 0.0f);
	addParameter(_threshold);
}

MyGateAudioProcessor::~MyGateAudioProcessor()
{
}

//==============================================================================
const String MyGateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MyGateAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MyGateAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MyGateAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MyGateAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyGateAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MyGateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyGateAudioProcessor::setCurrentProgram (int index)
{
}

const String MyGateAudioProcessor::getProgramName (int index)
{
    return {};
}

void MyGateAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MyGateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MyGateAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MyGateAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void MyGateAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    
	auto* channelL = buffer.getWritePointer(0);
	auto* channelR = buffer.getWritePointer(1);

	for (auto sample = 0; sample < buffer.getNumSamples(); sample++) 
	{
		// channelL[sample] = std::abs(channelL[sample]) > _threshold ? channelL[sample] : 0;
		// channelR[sample] = std::abs(channelR[sample]) > _threshold ? channelR[sample] : 0;
		channelL[sample] = std::abs(channelL[sample]) > *_threshold ? channelL[sample] : 0;
		channelR[sample] = std::abs(channelR[sample]) > *_threshold ? channelR[sample] : 0;
	}

}

//==============================================================================
bool MyGateAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MyGateAudioProcessor::createEditor()
{
    return new MyGateAudioProcessorEditor (*this);
}

//==============================================================================
void MyGateAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	MemoryOutputStream(destData, true).writeFloat(*_threshold);
}

void MyGateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	*_threshold = MemoryInputStream(data, static_cast<size_t>(sizeInBytes), false).readFloat();
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyGateAudioProcessor();
}
