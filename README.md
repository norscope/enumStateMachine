# enumStateMachine
This is a class that contains a state-machine that is based on enums.
The state-machine implements a custom protocol over UDP.

## Table that shows states,Events and transisions
The cells in the table shows both legal and illegal transisions that can occur in the 
state-machine. 

|Events/States  |Idle    |Transmit      |Receive_single|Receive_stream|Error|
|:-------------:|:------:|:------------:|:------------:|:------------:|:---:|
|Set_RQS        |Transmit|x             |x             |x             |x    |
|Set_RQFS       |Transmit|x             |x             |x             |x    |
|Set_RQR        |Transmit|x             |x             |x             |x    |
|Set_GS         |Transmit|x             |x             |x             |x    |
|Set_ABRT       |x       |x             |x             |Transmit      |x    |
|Set_THROTTLE   |Transmit|x             |x             |Transmit      |x    |
|Set_Retry      |Transmit|x             |x             |x             |x    |
|Set_Poll_Again |Transmit|x             |Transmit      |Transmit      |x    |
|Get_WRITE      |x       |Receive_single|x             |x             |x    |
|Get_STREAM     |x       |Receive_stream|x             |x             |x    |
|Get_EOS        |x       |x             |x             |x             |x    |
|Get_STATUS     |x       |Receive_single|x             |x             |x    |
|SOCK_ERROR     |x       |Error         |Error         |x             |x    |
|Got_Data       |x       |x             |Idle          |x             |x    |
|DisplayError   |x       |x             |x             |x             |Idle |