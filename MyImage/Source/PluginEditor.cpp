/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyImageAudioProcessorEditor::MyImageAudioProcessorEditor (MyImageAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    myImageComponent.setImage(ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize));
    
    myImageComponent.setImagePlacement(RectanglePlacement(RectanglePlacement::stretchToFit));
    
    addAndMakeVisible(myImageComponent);
    
    myImageComponent.setBounds(getLocalBounds());
    
    setSize (837, 526);
    
    mySlider.setBounds(0, 0, 837, 526);
    mySlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    mySlider.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    mySlider.setRange(0, 1,0.01);
    
    myLookAndFeel = new MyLookAndFeel();
    mySlider.setLookAndFeel(myLookAndFeel);
    addAndMakeVisible(mySlider);
}

MyImageAudioProcessorEditor::~MyImageAudioProcessorEditor()
{
}

//==============================================================================
void MyImageAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
//
//    g.setColour (Colours::white);
//    g.setFont (15.0f);
//    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void MyImageAudioProcessorEditor::resized()
{
    myImageComponent.setBounds(getLocalBounds());
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
