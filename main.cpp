#include <iostream>

class StateMachine{
private:
    enum class States{
        Idle, ReceiveSingle, ReceiveStream, Transmit,Error
    };
    enum class Transitions{
        idleToTransmit,
        transmitToReceiveSingle, transmitToReceiveStream, transmitToError,
        receiveSingleToIdle, receiveSingleToTransmit, receiveSingleToError,
        receiveStreamToIdle, receiveStreamToTransmit, receiveStreamToError,
        errorToIdle
    };
    enum class Events{

    };
    States state = States::Idle;
public:
   StateMachine(){}
   ~StateMachine(){};

   void runStates(){
        switch (state) {
            case States::Idle:
                std::cout << "enter idle \n";
                break;
            case States::ReceiveSingle:
                std::cout << "enter ReceiveSingle \n";
                break;
            case States::ReceiveStream:
                std::cout << "enter ReceiveStream \n";
                break;
            case States::Transmit:
                std::cout << "enter Transmit \n";
                break;
            case States::Error:
                std::cout << "enter Error \n";
                break;
        }
   }

   void runTransitions(){

   }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    StateMachine m;
    m.runStates();
    return 0;
}
