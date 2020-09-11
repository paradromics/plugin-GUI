#include "ReadNIOB.h" // DOES NOT EXIST
#include "NIOBEditor.h" // DOES NOT EXIST
#include <stdexcept>

DataThread* NIOBThread::createDataThread(SourceNode *sn)
{
    return new NIOBThread(sn);
}

//GenericEditor* NIOBThread::createEditor(SourceNode* sn)
//{
//    return new NIOBEditor(sn, this, true);
//}

NIOBThread::NIOBThread(SourceNode* sn) : DataThread(sn), inputAvailable(false)
{

//    dm = new NIOBmxDeviceManager();
//
//    dm->scanForDevices();
//
//    if (dm->getNumAvailableDevices() == 0)
//    {
//        //Okay for now as plugin-GUI handles source init runtime errors.
//        throw std::runtime_error("No NIOB devices detected!");
//    }

    inputAvailable = true;
    openConnection();

}


this is a test to see if it break s on compile


NIOBThread::~NIOBThread()
{
}

int NIOBThread::openConnection()
{

//    mNIOB = new NIOBmx(STR2CHR(dm->getDeviceFromIndex(0)));
//
//    sourceBuffers.add(new DataBuffer(getNumAnalogInputs(), 10000));
//
//    mNIOB->aiBuffer = sourceBuffers.getLast();
//
//    sampleRateIndex = mNIOB->sampleRates.size() - 1;
//    setSampleRate(sampleRateIndex);
//
//    voltageRangeIndex = mNIOB->aiVRanges.size() - 1;
//    setVoltageRange(voltageRangeIndex);

    return 0;

}

//int NIOBThread::getNumAvailableDevices()
//{
//    return dm->getNumAvailableDevices();
//}67


//void NIOBThread::toggleSourceType(int id)
//{
//    NIOB->toggleSourceType(id);
//}
//
//SOURCE_TYPE NIOBThread::getSourceTypeForInput(int index)
//{
//    return NIOB->st[index];
//}

void NIOBThread::closeConnection()
{
}

//int NIOBThread::getNumAnalogInputs() const
//{
//    return mNIOB->ai.size();
//}
//
//int NIOBThread::getNumDigitalInputs() const
//{
//    return mNIOB->di.size();
//}
//
//void NIOBThread::toggleAIChannel(int index)
//{
//    mNIOB->aiChannelEnabled.set(index, !mNIOB->aiChannelEnabled[index]);
//}
//
//void NIOBThread::toggleDIChannel(int index)
//{
//    mNIOB->diChannelEnabled.set(index, !mNIOB->diChannelEnabled[index]);
//}
//
//void NIOBThread::setVoltageRange(int rangeIndex)
//{
//    voltageRangeIndex = rangeIndex;
//    mNIOB->voltageRange = mNIOB->aiVRanges[rangeIndex];
//}

//void NIOBThread::setSampleRate(int rateIndex)
//{
//    sampleRateIndex = rateIndex;
//    mNIOB->samplerate = mNIOB->sampleRates[rateIndex];
//}
//
//int NIOBThread::getVoltageRangeIndex()
//{
//    return voltageRangeIndex;
//}
//
//int NIOBThread::getSampleRateIndex()
//{
//    return sampleRateIndex;
//}
//
//Array<String> NIOBThread::getVoltageRanges()
//{
//    Array<String> voltageRanges;
//    for (auto range : mNIOB->aiVRanges)
//    {
//        voltageRanges.add(String(range.vmin) + "-" + String(range.vmax) + " V");
//    }
//    return voltageRanges;
//}
//
//Array<String> NIOBThread::getSampleRates()
//{
//    Array<String> sampleRates;
//    for (auto rate : mNIOB->sampleRates)
//    {
//        sampleRates.add(String(rate) + " S/s");
//    }
//    return sampleRates;
//}

//bool NIOBThread::foundInputSource()
//{
//    return inputAvailable;
//}

/** Initializes data transfer.*/
bool NIOBThread::startAcquisition()
{
    this->startThread();
    return true;
}

/** Stops data transfer.*/
bool NIOBThread::stopAcquisition()
{

    if (isThreadRunning())
    {
        signalThreadShouldExit();
    }
    if (NIOB->isThreadRunning())
    {
        NIOB->signalThreadShouldExit();
    }
    return true;
}
//
//void NIOBThread::setDefaultChannelNames()
//{
//
//    for (int i = 0; i < getNumAnalogInputs(); i++)
//    {
//        ChannelCustomInfo info;
//        info.name = "AI" + String(i + 1);
//        info.gain = mNIOB->voltageRange.vmax / float(0x7fff);
//        channelInfo.set(i, info);
//    }
//
//}

//bool NIOBThread::usesCustomNames() const
//{
//    return true;
//}

/** Returns the number of virtual subprocessors this source can generate */
unsigned int NIOBThread::getNumSubProcessors() const
{
    return 1;
}



///** Returns the number of TTL channels that each subprocessor generates*/
//int NIOBThread::getNumTTLOutputs(int subProcessorIdx) const
//{
//    return getNumDigitalInputs();
//}

/** Returns the sample rate of the data source.*/
float NIOBThread::getSampleRate(int subProcessorIdx) const
{
    return 42;
}

float NIOBThread::getBitVolts(const DataChannel* chan) const
{
    return 4242;
}


bool NIOBThread::updateBuffer()
{
    return true;
}
