/*
  ==============================================================================

    SawOscillator.cpp
    Created: 2 Sep 2018 11:48:13pm
    Author:  Sebastian Badon

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SawOscillator.h"

//==============================================================================
SawOscillator::SawOscillator(SynthFrameworkAudioProcessor& p) :
processor(p)
{
    sawButton.setClickingTogglesState (true);
    addAndMakeVisible (sawLabel);
    addAndMakeVisible (sawButton);
    sawLabel.setText("Saw", dontSendNotification);
    sawLabel.setFont (Font (12.0f, Font::plain));
    sawLabel.setJustificationType(Justification::centred);
    sawVal = new AudioProcessorValueTreeState::ButtonAttachment (*processor.tree, "sawOsc", sawButton);
    sawButton.addListener(this);
}

SawOscillator::~SawOscillator()
{
}

void SawOscillator::paint (Graphics& g)
{
      g.setColour (getButtonColor(&sawButton));
      g.fillEllipse(17.5, 50,5, 5);
}


void SawOscillator::resized()
{
     sawButton.setBounds (0, 60,40, 40);
    sawLabel.setBounds (0, 17,40, 40);
    

}

Colour SawOscillator::getButtonColor(Button* b){
    if(b->getToggleState()){
        return Colour(0xffbe2932);
    }
    else {
        return Colour(0xff5f525d);
    }
}

void SawOscillator::buttonClicked (Button* button) // [2]
{
    repaint();
}
