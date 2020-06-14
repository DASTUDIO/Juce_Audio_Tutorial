/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyOscAudioProcessor::MyOscAudioProcessor()
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
	//myRate = getSampleRate();
}

MyOscAudioProcessor::~MyOscAudioProcessor()
{
}

//==============================================================================
const String MyOscAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MyOscAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MyOscAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool MyOscAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double MyOscAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MyOscAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MyOscAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MyOscAudioProcessor::setCurrentProgram (int index)
{
}

const String MyOscAudioProcessor::getProgramName (int index)
{
    return {};
}

void MyOscAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MyOscAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MyOscAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MyOscAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void MyOscAudioProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	ScopedNoDenormals noDenormals;

	int pos;

	MidiMessage midi_event;

	for (MidiBuffer::Iterator i(midiMessages); i.getNextEvent(midi_event, pos);)
	{
		if (midi_event.isNoteOn())
		{
			frequency = MidiMessage::getMidiNoteInHertz(midi_event.getNoteNumber());
		}
		else if (midi_event.isNoteOff())
		{
			frequency = -1;
		}
	}

	if (frequency > 0) 
	{
		auto totalNumInputChannels = getTotalNumInputChannels();
		auto totalNumOutputChannels = getTotalNumOutputChannels();

		auto* channelData = buffer.getWritePointer(0);
		auto* channelDataR = buffer.getWritePointer(1);

		auto samepleRate = getSampleRate();

		for (auto sample = 0; sample < buffer.getNumSamples(); ++sample)
		{
			auto sample_pos = (float)std::sin(currentAngle) + (float)std::sin(2 * currentAngle);
			currentAngle += 2 * MathConstants<double>::pi * frequency / samepleRate;

			channelData[sample] = sample_pos * volume;
			channelDataR[sample] = sample_pos * volume;
		}
	}
	
}


//==============================================================================
bool MyOscAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MyOscAudioProcessor::createEditor()
{
    return new MyOscAudioProcessorEditor (*this);
}

//==============================================================================
void MyOscAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MyOscAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MyOscAudioProcessor();
}
