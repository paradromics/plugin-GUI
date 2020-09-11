//This prevents include loops. We recommend changing the macro to a name suitable for your plugin
#ifndef ReadNIOB_H_DEFINED
#define ReadNIOB_H_DEFINED

#include <DataThreadHeaders.h>
#include <stdio.h>
#include <string.h>

//namespace must be an unique name for your plugin
namespace ReadNIOBSpace
{
	class ReadNIOB : public GenericProcessor
	{
	public:
		/** The class constructor, used to initialize any members. */
		ReadNIOB();

		/** The class destructor, used to deallocate memory */
		~ReadNIOB();
        


		/** Handles events received by the processor

		Called automatically for each received event whenever checkForEvents() is called from process()		
		*/
		//void handleEvent(const EventChannel* eventInfo, const MidiMessage& event, int samplePosition) override;

		/** Handles spikes received by the processor

		Called automatically for each received event whenever checkForEvents(true) is called from process()
		*/
		//void handleSpike(const SpikeChannel* spikeInfo, const MidiMessage& event, int samplePosition) override;

		/** The method that standard controls on the editor will call.
		It is recommended that any variables used by the "process" function
		are modified only through this method while data acquisition is active. */
		//void setParameter(int parameterIndex, float newValue) override;

		/** Saving custom settings to XML. */
		//void saveCustomParametersToXml(XmlElement* parentElement) override;

		/** Load custom settings from XML*/
		//void loadCustomParametersFromXml() override;

		/** Optional method called every time the signal chain is refreshed or changed in any way.

		Allows the processor to handle variations in the channel configuration or any other parameter
		passed down the signal chain. The processor can also modify here the settings structure, which contains
		information regarding the input and output channels as well as other signal related parameters. Said
		structure shouldn't be manipulated outside of this method.

		*/
		//void updateSettings() override;

	};
class NIOBThread : public DataThread, public Timer
{

public:

    NIOBThread(SourceNode* sn);
    ~NIOBThread();

    bool updateBuffer();

    void updateChannels();

    /** Returns true if the data source is connected, false otherwise.*/
    bool foundInputSource();

    /** Returns version and serial number info for hardware and API as a string.*/
    String getInfoString();

    /** Returns version and serial number info for hardware and API as XML.*/
    XmlElement getInfoXml();

    void openConnection();

    /** Initializes data transfer.*/
    bool startAcquisition() override;

    /** Stops data transfer.*/
    bool stopAcquisition() override;

    // DataThread Methods

//    /** Returns the number of virtual subprocessors this source can generate */
//    unsigned int getNumSubProcessors() const override;
//
//    /** Returns the number of continuous headstage channels the data source can provide.*/
//    int getNumDataOutputs(DataChannel::DataChannelTypes type, int subProcessorIdx) const override;
//
//    /** Returns the number of TTL channels that each subprocessor generates*/
//    int getNumTTLOutputs(int subProcessorIdx) const override;
//
//    /** Returns the sample rate of the data source.*/
//    float getSampleRate(int subProcessorIdx) const override;
//
//    /** Returns the volts per bit of the data source.*/
//    float getBitVolts(const DataChannel* chan) const override;
//
//    /** Used to set default channel names.*/
//    void setDefaultChannelNames() override;
//
//    /** Used to override default channel names.*/
//    bool usesCustomNames() const override;
//
//    /** Selects which electrode is connected to each channel. */
//    void selectElectrodes(unsigned char slot, signed char port, Array<int> channelStatus);
//
//    /** Selects which reference is used for each channel. */
//    void setAllReferences(unsigned char slot, signed char port, int refId);
//
//    /** Sets the gain for each channel. */
//    void setAllGains(unsigned char slot, signed char port, unsigned char apGain, unsigned char lfpGain);
//
//    /** Sets the filter for all channels. */
//    void setFilter(unsigned char slot, signed char port, bool filterState);
//
//    /** Toggles between internal and external triggering. */
//    void setTriggerMode(bool trigger);
//
//    /** Toggles between saving to NPX file. */
//    void setRecordMode(bool record);
//
//    /** Select directory for saving NPX files. */
//    void setDirectoryForSlot(int slotIndex, File directory);
//
//    /** Select directory for saving NPX files. */
//    File getDirectoryForSlot(int slotIndex);
//
//    /** Toggles between auto-restart setting. */
//    void setAutoRestart(bool restart);
//
//    /** Starts data acquisition after a certain time.*/
//    void timerCallback();

    /** Starts recording.*/
    void startRecording();

    /** Stops recording.*/
    void stopRecording();

//    CriticalSection* getMutex()
//    {
//        return &displayMutex;
//    }
//
//    static DataThread* createDataThread(SourceNode* sn);
//
//    GenericEditor* createEditor(SourceNode* sn);
//
//    int getNumBasestations();
//
//    void setMasterSync(int slotIndex);
//    void setSyncOutput(int slotIndex);
//
//    Array<int> getSyncFrequencies();
//    void setSyncFrequency(int slotIndex, int freqIndex);
//
//    ProbeStatus getProbeStatus(unsigned char slot, signed char port);
//    void setSelectedProbe(unsigned char slot, signed char probe);
//    bool isSelectedProbe(unsigned char slot, signed char probe);
//
//    bool checkSlotAndPortCombo(int slotIndex, int portIndex);
//    unsigned char getSlotForIndex(int slotIndex, int portIndex);
//    signed char getPortForIndex(int slotIndex, int portIndex);
//
//    bool runBist(unsigned char slot, signed char port, int bistIndex);
//
//    float getFillPercentage(unsigned char slot);
//
//    ScopedPointer<ProgressBar> progressBar;
//    double initializationProgress;
//
//    /* Helper for loading probes in the background */
//    struct probeSettings {
//        unsigned char slot;
//        signed char port;
//        Array<int> channelStatus;
//        int apGainIndex;
//        int lfpGainIndex;
//        int refChannelIndex;
//        bool disableHighPass;
//    } p_settings;
//    Array<probeSettings> probeSettingsUpdateQueue;
//
//    void updateProbeSettingsQueue();
//    void applyProbeSettingsQueue();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NeuropixThread);

private:
//    bool baseStationAvailable;
//    bool internalTrigger;
//    bool autoRestart;

    bool isRecording;

    long int counter;
    int recordingNumber;

//    CriticalSection displayMutex;

    void closeConnection();

//    Array<int> channelMap;
//    Array<bool> outputOn;
//    Array<int> refs;

//    uint64_t probeId;

//    int maxCounter;
//    int numRefs;
//    int totalChans;
//    int totalProbes;

    uint32_t last_niob_timestamp;

//    Array<float> fillPercentage;

//    OwnedArray<Basestation> basestations;

//
//    unsigned char selectedSlot;
//    signed char selectedPort;

    

    //std::vector<unsigned char> connected_basestations;
    //std::vector<std::vector<int>> connected_probes;
    
//    np::bistElectrodeStats stats[960];

    RecordingTimer recordingTimer;

};



}

#endif
