#include <iostream>

class StateMachine{
private:
    enum class States{
        /** The idle state is entry state of the FSM. Handles events to setting the
         * OP code, if retry is set and if poll again is set.
         */
        Idle,
        /**
         * The receive single state  responsible for handling server replies that
         * is only a single packet
         */
        ReceiveSingle,
        /**
         * The receive stream is responsible for server stream and full stream
         * packets.
         */
        ReceiveStream,
        /**
         * The transmit state handles sending OP codes to the server
         */
        Transmit,

        Error
    };
    enum class Transitions{
      //Idle
        IdleToTransmit,
      //Transmit
        TransmitToReceiveSingle, TransmitToReceiveStream, TransmitToError,
      //ReceiveSingle
        ReceiveSingleToIdle, ReceiveSingleToTransmit, ReceiveSingleToError,
      //ReceiveStream
        ReceiveStreamToIdle, ReceiveStreamToTransmit, ReceiveStreamToError,
      //Error
       ErrorToIdle
    };
    enum class Events{
      Set_RQS,
      Set_RQFS,
      Set_RQR,
      Set_GS,
      Set_ABRT,
      Set_THROTTLE,
      Set_Retry,
      Set_Poll_Again,
      Get_WRITE,
      Get_STREAM,
      Get_EOS,
      Get_STATUS,
      SOCK_ERROR,
      Got_Data,
      DisplayError,
      Idle
    };
    States state = States::Idle;
    Events event = Events::Idle;
  public:
   StateMachine(){}
   ~StateMachine(){};

   void Run_States(){
     bool run = true;
     while(run) {
       switch (state) {
       case States::Idle:
         std::cout << "enter idle \n";
         switch (event) {
         case Events::Set_RQS:
           state = States::Transmit;
           break;
         }
         break;
       case States::ReceiveSingle:
         std::cout << "enter ReceiveSingle \n";
         break;
       case States::ReceiveStream:
         std::cout << "enter ReceiveStream \n";
         break;
       case States::Transmit:
         std::cout << "enter Transmit \n";
         run = false;
         break;
       case States::Error:
         std::cout << "enter Error \n";
         break;
       }
     }
   }
   void Set_Start_Event(){
    event = Events::Set_RQS;
   }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    StateMachine m;
    m.Set_Start_Event();
    m.Run_States();
    return 0;
}
