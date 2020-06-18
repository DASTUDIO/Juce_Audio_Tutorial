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

class MyLookAndFeel : public LookAndFeel_V3
{
public:
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPosProportional, const float rotaryStartAngle, const float rotaryEndAngle, Slider &slider)
    {
        auto img1 =ImageCache::getFromMemory(BinaryData::Knob_png, BinaryData::Knob_pngSize);

        g.drawImageTransformed(img1, AffineTransform::rotation (rotaryEndAngle*slider.getValue(), img1.getWidth()/2, img1.getHeight()/2));

    }
};

class MyImageAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    MyImageAudioProcessorEditor (MyImageAudioProcessor&);
    ~MyImageAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyImageAudioProcessor& processor;
    ImageComponent myImageComponent;
    Slider mySlider;
    MyLookAndFeel* myLookAndFeel;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyImageAudioProcessorEditor)
};


