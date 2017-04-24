#include "ofMain.h"

class PulseSensor {
private:
    void updatePulseList();
    int calculateBPM();
    vector<int> pulseList;
    int pulseVal;
    const int SAMPLE_COUNT = 60 * 6;
public:
    void setup();
    void update();
    void setPulseVal(int input);
};
