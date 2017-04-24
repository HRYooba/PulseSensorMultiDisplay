#include "PulseSensor.h"

void PulseSensor::setup() {
    
}

void PulseSensor::update() {
    updatePulseList();
    
}

void PulseSensor::updatePulseList() {
    pulseList.push_back(pulseVal);
    if (pulseList.size() > SAMPLE_COUNT) {
        pulseList.pop_back();
    }
}

void PulseSensor::setPulseVal(int input) {
    pulseVal = input;
}

int PulseSensor::calculateBPM() {
    int sum = accumulate(pulseList.begin(), pulseList.end(), 0);
    return 0;
}
