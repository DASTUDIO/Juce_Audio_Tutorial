/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyEqAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MyEqAudioProcessorEditor (MyEqAudioProcessor&);
    ~MyEqAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyEqAudioProcessor& processor;
	Slider HF_Vol;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyEqAudioProcessorEditor)
};
