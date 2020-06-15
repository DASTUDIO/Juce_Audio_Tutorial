/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyEqAudioProcessorEditor::MyEqAudioProcessorEditor (MyEqAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
	HF_Vol.setRange(0.01, 1, 0.01);
	HF_Vol.setBounds(0, 0, 100, 50);
	HF_Vol.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
	HF_Vol.setTextBoxStyle(Slider::TextBoxBelow, true, 100, 30);;
	addAndMakeVisible(HF_Vol);

	HF_Vol.onValueChange = [this] 
	{
		*(processor.myFilter.state) = *(dsp::IIR::Coefficients<float>::makePeakFilter(processor.getSampleRate(),2400.0f,0.7f,HF_Vol.getValue()));
	};

    setSize (400, 300);

	*(processor.myFilter.state) = *(dsp::IIR::Coefficients<float>::makePeakFilter(processor.getSampleRate(), 2400.0f, 0.7f, HF_Vol.getValue()));
}

MyEqAudioProcessorEditor::~MyEqAudioProcessorEditor()
{
}

//==============================================================================
void MyEqAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void MyEqAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
