/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyReverbAudioProcessorEditor::MyReverbAudioProcessorEditor (MyReverbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	RoomSize.setRange(0, 1, 0.01);
	RoomSize.setBounds(0, 0, 300, 50);
	RoomSize.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	RoomSize.setTextBoxStyle(Slider::TextBoxBelow,true,100,50);
	
	RoomSize.setValue(processor.reverbParameters.roomSize);
	RoomSize.onValueChange = [this] 
	{
		processor.reverbParameters.roomSize = RoomSize.getValue(); 
		processor.reverbInstance.setParameters(processor.reverbParameters); 
	};

	addAndMakeVisible(RoomSize);
    setSize (400, 300);
}

MyReverbAudioProcessorEditor::~MyReverbAudioProcessorEditor()
{
}

//==============================================================================
void MyReverbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void MyReverbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
