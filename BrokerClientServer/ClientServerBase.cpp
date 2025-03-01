#include "ClientServerBase.hpp"


/*
 *  This class resebmles a standard Client-Server combination which only throughputs
 *  requests from bottom to top to request values and vice-versa serves values from top to bottom.
 *  No actual calculation is done or any altering to the values.
 *  It can thought of one side is client, the other is server each to different brokers.
 *  Therefore the methods Consume(...) and Serve(...) form the connection between the sides.
 *
 *  The intention is, that other implementations override the Serve(...) method to form certain
 *  functionality.
 */

ClientServerBase::ClientServerBase()
{

}

void ClientServerBase::GetRequested(int& _itterration)
{
    // Calls the Request() of the Client side of the same object ClientServerBase is inherited to
    // which in turn is the Client to another Server
    Request(_itterration);
}



