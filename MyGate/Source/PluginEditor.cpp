/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyGateAudioProcessorEditor::MyGateAudioProcessorEditor (MyGateAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	Threshold.setBounds(0, 0, 300, 100);
	Threshold.setRange(0, 1, 0.01);
	Threshold.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	Threshold.setTextBoxStyle(Slider::TextBoxBelow,true,100,50);
	// Threshold.onValueChange = [this] {processor._threshold = Threshold.getValue(); };
	Threshold.onValueChange = [this] {*(processor._threshold) = Threshold.getValue(); };
	Threshold.setValue(*(processor._threshold));
	addAndMakeVisible(Threshold);
    setSize (400, 300);
}

MyGateAudioProcessorEditor::~MyGateAudioProcessorEditor()
{
}

//==============================================================================
void MyGateAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void MyGateAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
