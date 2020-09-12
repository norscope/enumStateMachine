#include <iostream>

class StateMachine{
private:
    enum States{
        idle, receiveSingle, receiveStream, transmit,error
    };
    enum Transitions{
        idleToTransmit,
        transmitToReceiveSingle, transmitToReceiveStream, transmitToError,
        receiveSingleToIdle, receiveSingleToTransmit, receiveSingleToError,
        receiveStreamToIdle, receiveStreamToTransmit, receiveStreamToError,
        errorToIdle
    };
    enum Events{

    };
public:
   StateMachine(){}
   ~StateMachine();
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
